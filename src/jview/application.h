#ifndef APPLICATION_H__
#define APPLICATION_H__

#include <QtGui/QApplication>
#include <vector>

class JImageWindow;
class JImageApplication : public QApplication
{
	Q_OBJECT
public:
	JImageApplication(int &argc, char **argv);
	void open(const QString &filename);
protected:
	bool event(QEvent *);
protected slots:
    void openNewImage();
private:
    std::vector<JImageWindow*> windows;
};


#endif // APPLICATION_H__