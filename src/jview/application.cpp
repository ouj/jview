#include "application.h"
#include "window.h"
#include <QtGui/QFileOpenEvent>
#include <QtCore/QEvent>

JImageApplication::JImageApplication( int &argc, char **argv )
	: QApplication(argc, argv) {
}


bool JImageApplication::event(QEvent *event)
{
	switch (event->type()) {
        case QEvent::FileOpen: {
            Open(static_cast<QFileOpenEvent *>(event)->file());
            return true; 
        }
	default:
		return QApplication::event(event);
	}
}

void JImageApplication::Open(const QString &filename) {
    JImageWindow *win = new JImageWindow();
    win->show();
    win->setImage(filename);
    windows.push_back(win);
}
