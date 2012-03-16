#ifndef J_DIFF_APPLICATION_H__
#define J_DIFF_APPLICATION_H__

#include <QtGui/QApplication>

//class JImageDialog;
class JDiffApplication : public QApplication
{
	Q_OBJECT
public:
	JDiffApplication(int &argc, char **argv);
	//void SetImageDialog(JImageDialog* dlg);
protected:
	bool event(QEvent *);
};


#endif // J_DIFF_APPLICATION_H__