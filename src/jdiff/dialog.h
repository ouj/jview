#ifndef JDIFF_DIALOG
#define JDIFF_DIALOG

#include "ui_jdiff.h"
#include <common/array.h>
#include <common/pam.h>
#include <string>
#include <vector>

using std::vector;
using std::string;

class JDiffDialog : public QDialog
{
	Q_OBJECT
public:
	JDiffDialog(QDialog *parent = 0);
    void                    Init();
	void					setImage(const QString &filename);
    void                    loadImage(const string &filename, bool &isHDR);
    void                    dragEnterEvent(QDragEnterEvent *event);
    void                    dropEvent(QDropEvent *event);
public slots:
    void                    setExposureLabel(float exposure);
    void                    setGammaLabel(float gamma);
    void                    setScaleLabel(float scale);
    void                    setCoordinateLabel(int x, int y);
    void                    setColorLabel(int x, int y);
private:
	sarray2<vec3f>			image;
	QString					filename;
	Ui::JDiffDialogForm     form;
};

#endif //JDIFF_DIALOG