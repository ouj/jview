#include <stdio.h>
#include "pam.h"

void loadPnm(const string& filename, rawtype& type,
             int& width, int& height, int& nc,
             float& scale, rawbuffer& buffer) {
	char identifier[4]; 
    bool ascii = false;
    
	FILE *f = fopen(filename.c_str(), "rb");
    if (f == 0) {
        error_if_not_va(f != 0, "failed to open image file %s", filename.c_str());
        nc = width = height = 0;
        buffer = 0;
        return;
    }
    
	error_if_not(fscanf(f, "%s", identifier) == 1, "error reading image file");
	string id = identifier;
	
	if("Pf" == id) { nc = 1; ascii = false; type = 'f'; }
	else if ("PF"  == id) { nc = 3; ascii = false; type = 'f'; }
	else if ("P2"  == id) { nc = 1; ascii = true; type = 'B'; }
	else if ("P3"  == id) { nc = 3; ascii = true; type = 'B'; }
	else if ("P5"  == id) { nc = 1; ascii = false; type = 'B'; }
	else if ("P6"  == id) { nc = 3; ascii = false; type = 'B'; }
	else {	error("unknown image format"); }
    
	error_if_not_va(fscanf(f, "%d%d\n", &width, &height) == 2, "error reading image file %s", filename.c_str());
    if(type == 'B') { 
        buffer = (rawbuffer)(new unsigned char[width*height*nc]); 
        int maxv;
        error_if_not_va(fscanf(f, "%d\n", &maxv) == 1, "error reading image file %s", filename.c_str());
        error_if_not(maxv == 255, "unsupported max value");
        scale = 1.0f / maxv;
        if(!ascii) {
            int bread = (int)fread(buffer, sizeof(unsigned char), width*height*nc, f);
            error_if_not_va(bread == width*height*nc, "error reading image file %s", filename.c_str());
        } else {
            unsigned char* buf = (unsigned char*)buffer;
            for(int i = 0; i < width*height*nc; i ++) {
                int v;
                error_if_not_va(fscanf(f, "%d", &v) == 1, "error reading image file %s", filename.c_str());
                buf[i] = (unsigned char)v;
            }
        }
    } else if(type == 'f') { 
        buffer = (rawbuffer)(new float[width*height*nc]);
        char scale_string[16];
        fgets(scale_string, 16, f);
        sscanf(scale_string, "%f\n", &scale);
        scale = abs(scale);
        // flip y while reading
        for(int j = height-1; j >= 0; j --) {
            float* buf = (float*)buffer;
            int bytes = (int)fread(buf + (j*width*nc), sizeof(float), width*nc, f);
            error_if_not(bytes == width*nc, "error reading image file");
        }
    } else error("unknown type");
    
    fclose(f);
}

sarray2<vec3f> loadPnm3f(const string& filename) {
    int width, height, nc; float scale; rawbuffer buffer; rawtype type;
    loadPnm(filename, type, width, height, nc, scale, buffer);
    if (buffer == 0) {
        error_if_not_va(false, "failed to load image file %s", filename.c_str());
        return sarray2<vec3f>();
    }
    error_if_not_va(type == 'f' || type == 'B', "unsupported image format in file %s", filename.c_str());
    
    sarray2<vec3f> image(width,height);
    if(type == 'f') {
        float* buf = (float*)buffer;
        if (nc == 1) {
            for(int i = 0; i < image.size(); i ++) {
                image.at(i) = makevec3f(buf[i],buf[i],buf[i]) * scale;
            }
        } else if (nc == 3) {
            for(int i = 0; i < image.size(); i ++) {
                image.at(i) = makevec3f(buf[i*3+0],buf[i*3+1],buf[i*3+2]) * scale;
            }
        } else error("unsupported element number");
    } else if(type == 'B') {
        unsigned char* buf = (unsigned char*)buffer;
        for(int i = 0; i < image.size(); i ++) {
            image.at(i) = makevec3f((float)buf[i*3+0],(float)buf[i*3+1],(float)buf[i*3+2]) * scale;
        }        
    }
    if (buffer) delete [] buffer;
    
    return image;
}

void savePnm(const char *filename, rawtype type,
             int width, int height, int nc,
             bool ascii, rawbuffer buffer) {
	FILE *f = fopen(filename, "wb");
	error_if_not_va(f != 0, "failed to create image file %s", filename);

    string magic; 
    int scale = -1; 
    int ds = 0;
    if(type == 'f' && nc == 1 && !ascii) { magic = "Pf"; scale = -1; 
        ds = sizeof(float); }
	else if(type == 'f' && nc == 3 && !ascii) { magic = "PF"; scale = -1; 
        ds = sizeof(float); }
	else if(type == 'B' && nc == 1 && !ascii) { magic = "P5"; scale = 255; 
        ds = sizeof(unsigned char); }
	else if(type == 'B' && nc == 3 && !ascii) { magic = "P6"; scale = 255; 
        ds = sizeof(unsigned char); }
	else if(type == 'B' && nc == 1 && ascii) { magic = "P2"; scale = 255; 
        ds = sizeof(unsigned char); }
	else if(type == 'B' && nc == 3 && ascii) { magic = "P3"; scale = 255; 
        ds = sizeof(unsigned char); }
    else error("unsupported image format");
    
    error_if_not_va(fprintf(f, "%s\n", magic.c_str()) > 0, "error writing file %s", filename);    
    error_if_not_va(fprintf(f, "%d %d\n", width, height) > 0, "error writing file %s", filename);
    error_if_not_va(fprintf(f, "%d\n", scale) > 0, "error writing file %s", filename);

    if(!ascii) {
        if(type == 'f') {
            for(int j = height-1; j >= 0; j --) {
                float* buf = (float*)buffer;
                error_if_not_va((int)fwrite(buf + j*width*nc, ds, width*nc, f) == width*nc, "error writing file %s", filename);
            }
        } else {
            error_if_not_va((int)fwrite(buffer, ds, width*height*nc, f) == width*height*nc, "error writing file %s", filename);
        }
    } else {
        unsigned char* buf = (unsigned char*)buffer;
        for(int i = 0; i < width*height*nc; i ++) {
            int v = buf[i];
            error_if_not_va(fprintf(f, "%d \n", v) != 0, "error writing file %s", filename);
        }
    }
    
	fclose(f);
}

void savePfm(const char* filename, const sarray2<vec3f>& image) {
    savePnm(filename, 'f', image.width(), image.height(), 3, false, (rawbuffer)&image.at(0));
}

void savePfm(const string& filename, const sarray2<vec3f>& image) {
    savePnm(filename.c_str(), 'f', image.width(), image.height(), 3, false, (rawbuffer)&image.at(0));
}

void savePfm(const char* filename, const sarray2<float>& image) {
    savePnm(filename, 'f', image.width(), image.height(), 1, false, (rawbuffer)&image.at(0));
}

void savePfm(const string& filename, const sarray2<float>& image) {
    savePnm(filename.c_str(), 'f', image.width(), image.height(), 1, false, (rawbuffer)&image.at(0));
}

