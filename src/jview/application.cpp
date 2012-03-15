#include "application.h"
#include "dialog.h"
#include <QtGui/QFileOpenEvent>
#include <QtCore/QEvent>

JImageApplication::JImageApplication( int &argc, char **argv )
	: QApplication(argc, argv), dlg(0)
{

}


bool JImageApplication::event(QEvent *event)
{
	switch (event->type()) {
        case QEvent::FileOpen: {
            JImageDialog *dlg = new JImageDialog();
            dlg->show();
            dlg->setImage(static_cast<QFileOpenEvent *>(event)->file());
            return true; 
        }
	default:
		return QApplication::event(event);
	}
}
