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
#ifndef APPLE
    if(argc >= 2)
        app.open(argv[1], true);
    else {
        message("usage: jview imagefile");
        return 0;
    }
#endif // APPLE
	return app.exec();
}
