#include "application.h"
#include "dialog.h"
#include <QtGui/QFileOpenEvent>
#include <QtCore/QEvent>

JDiffApplication::JDiffApplication( int &argc, char **argv )
	: QApplication(argc, argv) {

}


bool JDiffApplication::event(QEvent *event)
{
	switch (event->type()) {
        case QEvent::FileOpen: {
//            JImageDialog *dlg = new JImageDialog();
//            dlg->show();
//            dlg->setImage(static_cast<QFileOpenEvent *>(event)->file());
//            return true; 
        }
	default:
		return QApplication::event(event);
	}
}
