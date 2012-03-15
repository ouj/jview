#ifndef PAM_H
#define PAM_H

#include "raw.h"

// see raw documentation
// only types supported are unsigned byte and float, for now
void loadPnm(const string& filename, rawtype& type,
             int& size1, int& size2, int& nc,
             rawbuffer& maxv, rawbuffer& buffer);
void savePnm(const string& filename, rawtype type,
             int width, int height, int nc,
             bool ascii, rawbuffer buffer);

sarray2<vec3f> loadPnm3f(const string& filename); // auto coverts to float
void savePfm(const char* filename, const sarray2<vec3f>& image);
void savePfm(const string& filename, const sarray2<vec3f>& image);
void savePfm(const char* filename, const sarray2<float>& image);
void savePfm(const string& filename, const sarray2<float>& image);

#endif
