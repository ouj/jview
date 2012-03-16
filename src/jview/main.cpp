#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

#include <QtGui/QtGui>
#include <QtCore/QtCore>
#include "window.h"
#include "application.h"

using std::string;
using std::vector;

int main(int argc, char** argv)
{
	JImageApplication app(argc, argv);
#ifdef WIN32
	JImageDialog *dlg = new JImageDialog();
    dlg->show();
    if(argc >= 2)
        dlg->setImage(argv[1]);
#endif // APPLE
	return app.exec();
}
