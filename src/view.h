#ifndef _JVIEW_H_
#define _JVIEW_H_
#include <QtGui/QWidget>
#include <common/array.h>
#include <common/vec.h>

class JImageView : public QWidget
{
    Q_OBJECT
public:
    explicit JImageView(QWidget* parent = 0, Qt::WindowFlags f = 0);
    ~JImageView(void);
    void setImage(const sarray2<vec3f> *image);
    void update();
    void paintEvent(QPaintEvent *event); 
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *evntKey);
signals:
    void gammaChanged(float gamma);
    void exposureChanged(float exposure);
    void scaleChanged(float scale);
    void coordinateChanged(int x, int y);
public slots:
    void setGamma(float gamma);
    void setExposure(float exposure);
    void reset();
    void setExposrueGamma( float e, float g );
    void setScale( float scale );
    void center();
private:
    bool                    mousePressed;
    QPoint                  mousePt;
    const sarray2<vec3f>     *image;
    QPoint                  offset;
    double                  scale;                   
    QImage                  qtimage;
    float                   exposure;
    float                   gamma;
};

#endif // _JVIEW_H_
