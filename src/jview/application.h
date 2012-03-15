#ifndef APPLICATION_H__
#define APPLICATION_H__

#include <QtGui/QApplication>

class JImageDialog;
class JImageApplication : public QApplication
{
	Q_OBJECT
public:
	JImageApplication(int &argc, char **argv);
	void SetImageDialog(JImageDialog* dlg);
protected:
	bool event(QEvent *);
private:
	JImageDialog *dlg;
};


#endif // APPLICATION_H__