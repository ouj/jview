#ifndef RAW_H
#define RAW_H

#include "array.h"
#include "vec.h"
#include <string>
using std::string;

// modeled loosely on the python array module
// uses simple chars to indicate type information
// accepted types
// b/B -> signed/unsigned byte
// i/I -> signed/unsigned int
// f -> float
// add more later

typedef char rawtype;
typedef unsigned char* rawbuffer;

// low level file handling
void loadRaw(const string& filename, rawtype& type,
             int& size1, int& size2, int& nc,
             rawbuffer& buffer);
void saveRaw(const string& filename, rawtype type,
             int size1, int size2, int nc,
             rawbuffer buffer);

// high level file handling -- add more if needed
void loadRaw(const string& filename, sarray<float>& array);
void loadRaw(const string& filename, sarray<vec2f>& array);
void loadRaw(const string& filename, sarray<vec3f>& array);
void loadRaw(const string& filename, sarray<int>& array);
void loadRaw(const string& filename, sarray<vec3i>& array);
void loadRaw(const string& filename, sarray<vec2i>& array);
void loadRaw(const string& filename, sarray2<float>& array);
void loadRaw(const string& filename, sarray2<vec3f>& array);

void saveRaw(const string& filename, const sarray<vec3f>& array);
void saveRaw(const string& filename, const sarray<vec3i>& array);
void saveRaw(const string& filename, const sarray<vec2f>& array);
    
void saveRaw(const string& filename, const darray<vec3f>& array);
void saveRaw(const string& filename, const darray<vec3i>& array);
void saveRaw(const string& filename, const darray<vec2f>& array);

#endif
