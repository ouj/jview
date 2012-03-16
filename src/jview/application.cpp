#include "application.h"
#include "window.h"
#include <QtGui/QFileOpenEvent>
#include <QtCore/QEvent>
#include <QtGui/QFileDialog>

JImageApplication::JImageApplication( int &argc, char **argv )
	: QApplication(argc, argv) {
}


bool JImageApplication::event(QEvent *event)
{
	switch (event->type()) {
        case QEvent::FileOpen: {
            open(static_cast<QFileOpenEvent *>(event)->file());
            return true; 
        }
	default:
		return QApplication::event(event);
	}
}

void JImageApplication::open(const QString &filename) {
    JImageWindow *win = new JImageWindow();
    win->show();
    win->setImage(filename);
    windows.push_back(win);
}


void JImageApplication::openNewImage() {
    QString fname = 
    QFileDialog::getOpenFileName(NULL,
                                 tr("Open Image"), 
                                 "~", 
                                 tr("ALL Images (*.pfm *.exr *.tga *.png *.jpg *.jpeg *.bmp *.tiff);;"
                                    "HDR Image Files (*.pfm *.exr *.tga);;" 
                                    "LDR Images (*.png *.jpg *.jpeg *.bmp *.tiff)"));
    if (QFile::exists(fname)) {
        static_cast<JImageApplication*>(qApp)->open(fname);
    }
}