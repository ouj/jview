/********************************************************************************
** Form generated from reading UI file 'jview.ui'
**
** Created: Sun Jul 21 10:28:39 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JVIEW_H
#define UI_JVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "view.h"

QT_BEGIN_NAMESPACE

class Ui_JViewMainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionClose;
    QAction *actionReset;
    QAction *actionSave_HDR;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_6;
    QLabel *coordinateLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_7;
    QLabel *colorLabel;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer3;
    QLabel *label;
    QLabel *sizeLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLabel *scaleLabel;
    QSpacerItem *horizontalSpacer2;
    QLabel *label_3;
    QLabel *exposureLabel;
    QSpacerItem *horizontalSpacer1;
    QLabel *label_4;
    QLabel *gammaLabel;
    QSpacerItem *horizontalSpacer;
    JImageView *viewWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuView;

    void setupUi(QMainWindow *JViewMainWindow)
    {
        if (JViewMainWindow->objectName().isEmpty())
            JViewMainWindow->setObjectName(QString::fromUtf8("JViewMainWindow"));
        JViewMainWindow->resize(512, 600);
        JViewMainWindow->setCursor(QCursor(Qt::CrossCursor));
        JViewMainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        actionOpen = new QAction(JViewMainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(JViewMainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionClose = new QAction(JViewMainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionReset = new QAction(JViewMainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        actionSave_HDR = new QAction(JViewMainWindow);
        actionSave_HDR->setObjectName(QString::fromUtf8("actionSave_HDR"));
        centralwidget = new QWidget(JViewMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(461, 0));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        groupBox->setCheckable(false);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 5, 5, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        coordinateLabel = new QLabel(groupBox);
        coordinateLabel->setObjectName(QString::fromUtf8("coordinateLabel"));
        coordinateLabel->setFrameShape(QFrame::StyledPanel);

        horizontalLayout_2->addWidget(coordinateLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_2->addWidget(label_7);

        colorLabel = new QLabel(groupBox);
        colorLabel->setObjectName(QString::fromUtf8("colorLabel"));
        colorLabel->setFrameShape(QFrame::StyledPanel);

        horizontalLayout_2->addWidget(colorLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer3);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        sizeLabel = new QLabel(groupBox);
        sizeLabel->setObjectName(QString::fromUtf8("sizeLabel"));
        sizeLabel->setFrameShape(QFrame::StyledPanel);

        horizontalLayout->addWidget(sizeLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        scaleLabel = new QLabel(groupBox);
        scaleLabel->setObjectName(QString::fromUtf8("scaleLabel"));
        scaleLabel->setFrameShape(QFrame::StyledPanel);
        scaleLabel->setFrameShadow(QFrame::Plain);

        horizontalLayout->addWidget(scaleLabel);

        horizontalSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        exposureLabel = new QLabel(groupBox);
        exposureLabel->setObjectName(QString::fromUtf8("exposureLabel"));
        exposureLabel->setFrameShape(QFrame::StyledPanel);

        horizontalLayout->addWidget(exposureLabel);

        horizontalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        gammaLabel = new QLabel(groupBox);
        gammaLabel->setObjectName(QString::fromUtf8("gammaLabel"));
        gammaLabel->setFrameShape(QFrame::StyledPanel);

        horizontalLayout->addWidget(gammaLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBox);

        viewWidget = new JImageView(centralwidget);
        viewWidget->setObjectName(QString::fromUtf8("viewWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(viewWidget->sizePolicy().hasHeightForWidth());
        viewWidget->setSizePolicy(sizePolicy1);
        viewWidget->setCursor(QCursor(Qt::CrossCursor));
        viewWidget->setMouseTracking(true);
        viewWidget->setFocusPolicy(Qt::WheelFocus);
        viewWidget->setContextMenuPolicy(Qt::NoContextMenu);

        verticalLayout->addWidget(viewWidget);

        JViewMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(JViewMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 512, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        JViewMainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_HDR);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuView->addAction(actionReset);

        retranslateUi(JViewMainWindow);
        QObject::connect(viewWidget, SIGNAL(coordinateChanged(int,int)), JViewMainWindow, SLOT(setCoordinateLabel(int,int)));
        QObject::connect(viewWidget, SIGNAL(coordinateChanged(int,int)), JViewMainWindow, SLOT(setColorLabel(int,int)));
        QObject::connect(viewWidget, SIGNAL(exposureChanged(float)), JViewMainWindow, SLOT(setExposureLabel(float)));
        QObject::connect(viewWidget, SIGNAL(gammaChanged(float)), JViewMainWindow, SLOT(setGammaLabel(float)));
        QObject::connect(viewWidget, SIGNAL(scaleChanged(float)), JViewMainWindow, SLOT(setScaleLabel(float)));
        QObject::connect(actionOpen, SIGNAL(triggered()), JViewMainWindow, SLOT(openNewImage()));
        QObject::connect(actionClose, SIGNAL(triggered()), JViewMainWindow, SLOT(close()));
        QObject::connect(actionReset, SIGNAL(triggered()), viewWidget, SLOT(reset()));
        QObject::connect(actionSave, SIGNAL(triggered()), JViewMainWindow, SLOT(saveLDRImage()));
        QObject::connect(actionSave_HDR, SIGNAL(triggered()), JViewMainWindow, SLOT(saveHDRImage()));

        QMetaObject::connectSlotsByName(JViewMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *JViewMainWindow)
    {
        JViewMainWindow->setWindowTitle(QApplication::translate("JViewMainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("JViewMainWindow", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("JViewMainWindow", "Open an image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("JViewMainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("JViewMainWindow", "&Save LDR", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("JViewMainWindow", "Save LDR image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("JViewMainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("JViewMainWindow", "Close", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionClose->setToolTip(QApplication::translate("JViewMainWindow", "Close Window", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionClose->setShortcut(QApplication::translate("JViewMainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionReset->setText(QApplication::translate("JViewMainWindow", "Reset", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionReset->setToolTip(QApplication::translate("JViewMainWindow", "Reset Image", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionReset->setShortcut(QApplication::translate("JViewMainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        actionSave_HDR->setText(QApplication::translate("JViewMainWindow", "Save HDR", 0, QApplication::UnicodeUTF8));
        actionSave_HDR->setShortcut(QApplication::translate("JViewMainWindow", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        groupBox->setWhatsThis(QApplication::translate("JViewMainWindow", "Additional Image Options", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QString());
        label_6->setText(QApplication::translate("JViewMainWindow", "coordinate:", 0, QApplication::UnicodeUTF8));
        coordinateLabel->setText(QApplication::translate("JViewMainWindow", "[0,0]", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("JViewMainWindow", "value:", 0, QApplication::UnicodeUTF8));
        colorLabel->setText(QApplication::translate("JViewMainWindow", "[-----, ----- ,-----]", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("JViewMainWindow", "size:", 0, QApplication::UnicodeUTF8));
        sizeLabel->setText(QApplication::translate("JViewMainWindow", "(0,0)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("JViewMainWindow", "scale:", 0, QApplication::UnicodeUTF8));
        scaleLabel->setText(QApplication::translate("JViewMainWindow", "1.0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("JViewMainWindow", "exposure:", 0, QApplication::UnicodeUTF8));
        exposureLabel->setText(QApplication::translate("JViewMainWindow", "0.00", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("JViewMainWindow", "gamma:", 0, QApplication::UnicodeUTF8));
        gammaLabel->setText(QApplication::translate("JViewMainWindow", "2.20", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("JViewMainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("JViewMainWindow", "View", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class JViewMainWindow: public Ui_JViewMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JVIEW_H
