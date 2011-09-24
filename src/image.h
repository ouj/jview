#ifndef _JVIEW_IMAGE_H_
#define _JVIEW_IMAGE_H_

#include <string>
#include <common/vec.h>
#include <common/array.h>

using std::string;

sarray2<vec3f> loadExr(const string &name);
sarray2<vec3f> loadTga(const string &name);

#endif //_JVIEW_IMAGE_H_