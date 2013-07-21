#include "image.h"
#include <common/pam.h>
#include <common/stddir.h>
#include <QtGui/QImage>
#ifdef WIN32
#define hypotf hypot // For the OpenEXR headers
#endif
#include <ImfInputFile.h>
#include <ImfRgbaFile.h>
#include <ImfChannelList.h>
#include <ImfFrameBuffer.h>
#include <half.h>
using namespace Imf;
using namespace Imath;

sarray2<vec3f> loadExr(const string &name) {
    try {
        InputFile file(name.c_str());
        Box2i dw = file.header().dataWindow();
        int width  = dw.max.x - dw.min.x + 1;
        int height = dw.max.y - dw.min.y + 1;

        half *rgb = new half[3 * width * height];

        FrameBuffer frameBuffer;
        frameBuffer.insert("R", Slice(HALF, (char *)rgb,
                                      3*sizeof(half), width * 3 * sizeof(half), 1, 1, 0.0));
        frameBuffer.insert("G", Slice(HALF, (char *)rgb+sizeof(half),
                                      3*sizeof(half), width * 3 * sizeof(half), 1, 1, 0.0));
        frameBuffer.insert("B", Slice(HALF, (char *)rgb+2*sizeof(half),
                                      3*sizeof(half), width * 3 * sizeof(half), 1, 1, 0.0));

        file.setFrameBuffer(frameBuffer);
        file.readPixels(dw.min.y, dw.max.y);

        sarray2<vec3f> image(width, height);
        for (int i = 0; i < width * height; ++i) {
            image[i] = makevec3f(rgb[3*i], rgb[3*i+1], rgb[3*i+2]);
        }
        delete[] rgb;
        fprintf(stdout, "Read EXR image %s (%d x %d)\n", name.c_str(), width, height);
        return image;
    } catch (const std::exception &e) {
        fprintf(stderr, "Unable to read image file \"%s\": %s\n", name.c_str(),
                e.what());
        return sarray2<vec3f>();
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
typedef uint8_t byte;
typedef unsigned char uchar;

// MACROS ------------------------------------------------------------------

#undef SHORT
#ifdef __BIG_ENDIAN__
#define SHORT(x)            shortSwap(x)
# else // Little-endian.
#define SHORT(x)            (x)
#endif

// TYPES -------------------------------------------------------------------

typedef struct {
    uchar           idLength; // Identification field size in bytes.
    uchar           colorMapType; // Type of the color map.
    uchar           imageType; // Image type code.
} tga_header_t;

// Color map specification.
typedef struct {
    int16_t         index; // Index of first color map entry.
    int16_t         length; // Number of color map entries.
    uchar           entrySize; // Number of bits in a color map entry (16/24/32).
} tga_colormapspec_t;

// Image specification.
typedef struct {
    int16_t         xOrigin; // X coordinate of lower left corner.
    int16_t         yOrigin; // Y coordinate of lower left corner.
    int16_t         width; // Width of the image in pixels.
    int16_t         height; // Height of the image in pixels.
    uchar           pixelDepth; // Number of bits in a pixel (16/24/32).
    uchar           attributeBits;
} tga_imagespec_t;


#ifdef __BIG_ENDIAN__
static int16_t shortSwap(int16_t n)
{
    return ((n & 0xff) << 8) | ((n & 0xff00) >> 8);
}


#endif

static uchar readByte(FILE* f)
{
    uchar v;
    error_if_not(fread(&v, sizeof(v), 1, f) == sizeof(v),
                 "error reading byte");
    return v;
}



static int16_t readShort(FILE* f)
{
    int16_t v;
    error_if_not(fread(&v, sizeof(v), 1, f) == sizeof(v),
                 "error reading short");
    return v;
}

static void readHeader(tga_header_t* dst, FILE* file)
{
    dst->idLength = readByte(file);
    dst->colorMapType = readByte(file);
    dst->imageType = readByte(file);
}

static void readColorMapSpec(tga_colormapspec_t* dst, FILE* file)
{
    dst->index = readShort(file);
    dst->length = readShort(file);
    dst->entrySize = readByte(file);
}

static void readImageSpec(tga_imagespec_t* dst, FILE* file)
{
    dst->xOrigin = readShort(file);
    dst->yOrigin = readShort(file);
    dst->width = readShort(file);
    dst->height = readShort(file);
    dst->pixelDepth = readByte(file);
    dst->attributeBits = readByte(file);
}

inline float Clamp(float val, float low, float high) {
    if (val < low) return low;
    else if (val > high) return high;
    else return val;
}


sarray2<vec3f> loadTga(const string &name) {
    int                 x, y, pixbytes;
    tga_header_t        header;
    tga_colormapspec_t  colorMapSpec;
    tga_imagespec_t     imageSpec;
    uchar*              srcBuf;
    const uchar*        src;

    FILE *file = fopen(name.c_str(), "rb");
    if (!file) {
        fprintf(stderr,"Unable to open TGA file \"%s\"\n", name.c_str());
        return sarray2<vec3f>();
    }

    // Read and check the header.
    readHeader(&header, file);
    readColorMapSpec(&colorMapSpec, file);
    readImageSpec(&imageSpec, file);

    if (((imageSpec.attributeBits & 0xf) != 8 &&  // num attribute bits
         (imageSpec.attributeBits & 0xf) != 0) ||
        ((imageSpec.attributeBits & 0xc0) != 0) || // no interleaving
        (header.imageType == 2 &&
         (imageSpec.pixelDepth != 32 && imageSpec.pixelDepth != 24)) ||
        (header.imageType == 3 &&
         (imageSpec.pixelDepth != 8)) ||
        (header.imageType != 2 && header.imageType != 3)) {
        fprintf(stderr,"ReadImageTGA: I don't know this format "
                "(type=%i pxsize=%i abits=%i)\n", header.imageType,
                imageSpec.pixelDepth,
                imageSpec.attributeBits);
        fclose(file);
        return sarray2<vec3f>();
    }

    int width = imageSpec.width;
    int height = imageSpec.height;

    // Determine format.
    if (imageSpec.pixelDepth == 32)
        pixbytes = 4;
    else if (imageSpec.pixelDepth == 24)
        pixbytes = 3;
    else {
        assert(imageSpec.pixelDepth == 8);
        pixbytes = 1;
    }

    // Read the pixel data.
    int size = width * height * pixbytes;
    srcBuf = (uchar *)malloc(size);
    if (fread(srcBuf, 1, size, file) != (uint32_t)size) {
        fprintf(stderr, "Premature end-of-file when reading TGA image \"%s\"\n", name.c_str());
        free(srcBuf);
        fclose(file);
        return sarray2<vec3f>();
    }

    // "Unpack" the pixels (origin in the lower left corner).
    // TGA pixels are in BGRA format.
    src = srcBuf;
    sarray2<vec3f> image(width, height);
    vec3f *dst = &image[0];
    for (y = height - 1; y >= 0; y--)
        for (x = 0; x < width; x++) {
            if (pixbytes == 1) {
                float c = (*src++) / 255.f;
                *dst++ = makevec3f(c, c, c);
            } else {
                float c[3];
                c[2] = (*src++) / 255.f;
                c[1] = (*src++) / 255.f;
                c[0] = (*src++) / 255.f;
                *dst++ = makevec3f(c[0], c[1], c[2]);
                if (pixbytes == 4)
                    ++src;
            }
        }

    bool flipH = ((imageSpec.attributeBits & 0x10) == 0x10);
    bool flipV = ((imageSpec.attributeBits & 0x20) == 0x20);
    if (flipH) {
        for (y = 0; y < height; ++y)
            for (x = 0; x < width / 2; ++x)
                std::swap(image[y * width + x], image[y * width + (width - 1 - x)]);
    }
    if (flipV) {
        for (y = 0; y < height/2; ++y)
            for (x = 0; x < width; ++x)
                std::swap(image[y * width + x], image[(height - 1 - y) * width + x]);
    }
    free(srcBuf);
    fclose(file);
    fprintf(stdout,"Read TGA image %s (%d x %d)\n", name.c_str(), width, height);
    return image;
}

sarray2<vec3f> loadLdr(const string &name) {
    QImage im;
    if (im.load(name.c_str())) {
        sarray2<vec3f> image(im.width(), im.height());
        for (int j = 0; j < im.height(); j++) {
            for (int i = 0; i < im.width(); i++) {
                QRgb rgb = im.pixel(i, j);
                image.at(i, j) = makevec3f(qRed(rgb) / 255.0f,
                                           qGreen(rgb) / 255.0f,
                                           qBlue(rgb) / 255.0f);
            }
        }
        return image;
    } else {
        fprintf(stderr, "failed to load image %s\n", name.c_str());
        return sarray2<vec3f>();
    }
}



void saveLdr(const sarray2<vec3f> &image, const string& filename) {
    QImage im(image.width(), image.height(), QImage::Format_RGB32);
    for (int j = 0; j < im.height(); j++) {
        for (int i = 0; i < im.width(); i++) {
            vec3f p = image.at(i,j);
            QRgb rgb = qRgb(p.x*255, p.y*255, p.z*255);
            im.setPixel(i, j, rgb);
        }
    }
    im.save(filename.c_str());
}

void saveLdr(const QImage &image, const string& filename) {
    image.save(filename.c_str());
}

void saveHdr(const sarray2<vec3f> &image, const string& filename) {
    savePfm(filename, image);
}

