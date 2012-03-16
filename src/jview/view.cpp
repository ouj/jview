#include "view.h"
#include <QtGui/Qpainter>
#include <QtGui/QWheelEvent>
#include <QtGui/QMouseEvent>
#include <common/func.h>
#include <common/stdmath.h>
#include <QtGui/QMessageBox>
#include "application.h"
#include "window.h"

JImageView::JImageView(QWidget* parent, Qt::WindowFlags f)
    : QWidget(parent, f), mousePressed(false), 
      offset(0, 0), scale(1.0f), exposure(0.0f), 
      gamma(2.2f), showInvalid(false) {
}


JImageView::~JImageView(void) {
}

void JImageView::setImage( const sarray2<vec3f> *image ) {
    this->image = image;
    qtimage = QImage(image->width(), image->height(), QImage::Format_RGB32);
    update();
    qApp->activeWindow()->resize(image->width(), image->height() + 70);
    activateWindow();
    setFocus();
    center();
}

void JImageView::setGamma(float gamma) {
    this->gamma = gamma;
    gammaChanged(this->gamma);
    update();
}

void JImageView::setExposure(float exposure) {
    this->exposure = exposure;
    exposureChanged(this->exposure);
    update();
}

void JImageView::setScale( float nscale ) {
    QPoint ct(width() / 2, height() / 2);
    QPoint d = (ct - offset) / scale;
    offset -= d * (nscale - scale);
    scale = nscale;
    scaleChanged(scale);
    repaint();
}

void JImageView::update() {
    if (image == 0)
        return;
    for (int j = 0; j < qtimage.height(); j++) {
        for (int i = 0; i < qtimage.width(); i++) {
            const vec3f &p = image->at(i, j);
            if (showInvalid && isanynan(p)) {
                qtimage.setPixel(i, j, qRgb(255, 0, 0));
            } else if (showInvalid && isanyneg(p)){ 
                qtimage.setPixel(i, j, qRgb(0, 255, 0));
            } else {
                float scale = pow(2, exposure);
                float power = 1.0f / gamma;
                int r = clamp((int)((pow(scale*p.x,power)) * 255), 0, 255);
                int g = clamp((int)((pow(scale*p.y,power)) * 255), 0, 255);
                int b = clamp((int)((pow(scale*p.z,power)) * 255), 0, 255);
                qtimage.setPixel(i, j, qRgb(r, g, b));
            }
        }
    }
    repaint();
}

void JImageView::paintEvent( QPaintEvent * event ) {
    QPainter painter(this);
    painter.translate(offset);
    painter.scale(scale, scale);
    painter.drawImage(0, 0, qtimage);
}

void JImageView::wheelEvent( QWheelEvent * event ) {
    if(event->modifiers() == Qt::NoModifier) {
        setScale(scale * (1 + (double)event->delta() / 600));
        return;
    }
    
    if(event->modifiers() & Qt::ShiftModifier) {
        exposure += (double)event->delta() / 300;
        exposureChanged(this->exposure);
    }
    
    if(event->modifiers() & Qt::ControlModifier) {
        gamma += (double)event->delta() / 300;
        gammaChanged(this->gamma);
    }
    
    update();
}

void JImageView::mousePressEvent( QMouseEvent *event ) {
    mousePressed = true;
    mousePt = event->globalPos();
}

void JImageView::mouseReleaseEvent( QMouseEvent *event ) {
    if (mousePressed == true)
        mousePressed = false;
}

void JImageView::mouseMoveEvent( QMouseEvent *event ) {
    if (mousePressed == true) {
        QPoint delta = event->globalPos() - mousePt;
        mousePt = event->globalPos();

        offset += delta;
        this->repaint();
    }

    QPoint imgPos = (event->pos() - offset) / scale;
    coordinateChanged(imgPos.x(), imgPos.y());
}

void JImageView::keyPressEvent( QKeyEvent *event ) {
    switch(event->key()) {
        case Qt::Key_1: setExposrueGamma(0.0f, 1.0f); break;
        case Qt::Key_2: setExposrueGamma(0.0f, 2.2f); break;
        case Qt::Key_BracketLeft: setExposure(exposure - 0.1f); break;
        case Qt::Key_BracketRight: setExposure(exposure + 0.1f); break;
        case Qt::Key_Minus: 
        case Qt::Key_hyphen:
            setScale(scale * 0.9f);
            break;
        case Qt::Key_Plus:
        case Qt::Key_Equal: 
            setScale(scale * 1.1f);
            break;
        case Qt::Key_Colon:
        case Qt::Key_Semicolon:
            setGamma(gamma - 0.1f);
            break;
        case Qt::Key_QuoteDbl:
        case Qt::Key_Apostrophe:
            setGamma(gamma + 0.1f);
            break;
        case Qt::Key_C:
            center();
            break;
        case Qt::Key_N:
            showInvalid = !showInvalid;
            update();
            break;
        default: 
            QWidget::keyPressEvent(event); return;
    }
    event->accept();
}

void JImageView::reset() {
    setScale(1.0f);
    center();
    update();
}

void JImageView::setExposrueGamma( float exposure, float gamma ) {
    this->gamma = gamma;
    gammaChanged(this->gamma);
    this->exposure = exposure;
    exposureChanged(this->exposure);
    update();
}

void JImageView::center() {
    QPoint imgSize(qtimage.width(), qtimage.height());
    QPoint viewSize(width(), height());
    offset = (viewSize - imgSize * scale) * 0.5f;
    repaint();
}







