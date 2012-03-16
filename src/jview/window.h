#ifndef JIMAGE_DIALOG_H_
#define JIMAGE_DIALOG_H_

#include "ui_jview.h"
#include <common/array.h>
#include <common/pam.h>
#include <string>
#include <vector>

using std::vector;
using std::string;

class JImageWindow : public QMainWindow
{
	Q_OBJECT
public:
	JImageWindow(QDialog *parent = 0);
    void                    Init();
	void					setImage(const QString &filename);
    void                    loadImage(const string &filename, bool &isHDR);
    void                    saveImage(const string &filename);
    void                    dragEnterEvent(QDragEnterEvent *event);
    void                    dropEvent(QDropEvent *event);
public slots:
    void                    openNewImage();
    void                    saveLDRImage();
    void                    setExposureLabel(float exposure);
    void                    setGammaLabel(float gamma);
    void                    setScaleLabel(float scale);
    void                    setCoordinateLabel(int x, int y);
    void                    setColorLabel(int x, int y);
private:
	sarray2<vec3f>			image;
	QString					filename;
    QString					path;
	Ui::JViewMainWindow     form;
};

#endif //JIMAGE_DIALOG_H_

