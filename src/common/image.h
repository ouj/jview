#ifndef _JVIEW_IMAGE_H_
#define _JVIEW_IMAGE_H_

#include <string>
#include <common/vec.h>
#include <common/array.h>
#include <QtGui/QImage>

using std::string;

sarray2<vec3f> loadExr(const string &name);
sarray2<vec3f> loadTga(const string &name);
sarray2<vec3f> loadLdr(const string &name);
void saveLdr(const sarray2<vec3f> &image, const string& filename);
void saveLdr(const QImage &image, const string& filename);

#endif //_JVIEW_IMAGE_H_