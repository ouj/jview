#include "dialog.h"
#include <common/pam.cpp>
#include <QtCore/QFileInfo>
#include <QtGui/QMouseEvent>
#include <QtCore/QUrl>
#include "image.h"

JImageDialog::JImageDialog( QDialog *parent /*= 0*/ ) 
	: QDialog(parent) {
	form.setupUi(this);
    setAcceptDrops(true);
}

void JImageDialog::loadImage(const string &filename, bool &isHDR) {
    string extension = filename.substr(filename.size() - 4);
    if (extension == ".exr") {
        image = loadExr(filename);
        isHDR = true;
    } else if (extension == ".tga") {
        image = loadTga(filename);
        isHDR = false;
    } else if (extension == ".ppm") {
        image = loadPnm3f(filename);
        isHDR = false;
    } else if (extension == ".pfm") {
        image = loadPnm3f(filename);
        isHDR = true;  
    } else {
        image = loadLdr(filename);
        isHDR = false;
    }
}

void JImageDialog::setImage( const QString &f ) {
	filename = QFileInfo(f).fileName();
    bool isHDR = true;
    loadImage(f.toStdString(), isHDR);
	form.viewWidget->setImage(&image);
    if (isHDR) {
        form.viewWidget->setExposrueGamma(0.0f, 2.2f);
    } else {
        form.viewWidget->setExposrueGamma(0.0f, 1.0f);
    }
    setWindowTitle(f);

    int x = image.width();
    int y = image.height();
    QString sizeStr;
    sizeStr.sprintf("(%4d, %4d)", x, y);
    form.sizeLabel->setText(sizeStr);
}


void JImageDialog::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();
}

void JImageDialog::dropEvent(QDropEvent *event) {
    setImage(event->mimeData()->urls()[0].toLocalFile());
    event->acceptProposedAction();
    setFocus();
}

void JImageDialog::setExposureLabel( float exposure ) {
    QString eStr;
    eStr.sprintf("%.2f", exposure);
    form.exposureLabel->setText(eStr);
}

void JImageDialog::setGammaLabel( float gamma ) {
    QString gStr;
    gStr.sprintf("%.2f", gamma);
    form.gammaLabel->setText(gStr);
}

void JImageDialog::setScaleLabel( float scale ) {
    QString sStr;
    sStr.sprintf("%.3f", scale);
    form.scaleLabel->setText(sStr);
}

void JImageDialog::setCoordinateLabel( int x, int y ) {
    QString cStr;
    cStr.sprintf("[%4d, %4d]", x, y);
    form.coordinateLabel->setText(cStr);
}

void formatNumber(float v, QString &f) {
    if (v != 0.0f && (abs(v) < 0.0001 || abs(v) >= 1000))
        f.sprintf("%#9.2e", v);
    else
        f.sprintf("%9.4f", v);
}

void JImageDialog::setColorLabel( int x, int y ) {
    QString str;
    if (x >= 0 && x < image.width() && y >= 0 && y < image.height()) {
        const vec3f &c = image.at(x, y);
        QString fx, fy, fz;
        formatNumber(c.x, fx);
        formatNumber(c.y, fy);
        formatNumber(c.z, fz);
        str.append("[").append(fx).append(", ").append(fy).append(", ").append(fz).append("]");
    } else {
        str = "[-----, -----, -----]";
    }
    form.colorLabel->setText(str);
}
