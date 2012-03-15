/********************************************************************************
** Form generated from reading UI file 'jdiff.ui'
**
** Created: Thu Mar 15 16:54:12 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JDIFF_H
#define UI_JDIFF_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "view.h"

QT_BEGIN_NAMESPACE

class Ui_JImageDialogForm
{
public:
    QVBoxLayout *verticalLayout;
    JImageView *viewWidget;
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

    void setupUi(QDialog *JImageDialogForm)
    {
        if (JImageDialogForm->objectName().isEmpty())
            JImageDialogForm->setObjectName(QString::fromUtf8("JImageDialogForm"));
        JImageDialogForm->resize(515, 582);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(JImageDialogForm->sizePolicy().hasHeightForWidth());
        JImageDialogForm->setSizePolicy(sizePolicy);
        JImageDialogForm->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(JImageDialogForm);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 5);
        viewWidget = new JImageView(JImageDialogForm);
        viewWidget->setObjectName(QString::fromUtf8("viewWidget"));
        sizePolicy.setHeightForWidth(viewWidget->sizePolicy().hasHeightForWidth());
        viewWidget->setSizePolicy(sizePolicy);
        viewWidget->setCursor(QCursor(Qt::CrossCursor));
        viewWidget->setMouseTracking(true);
        viewWidget->setFocusPolicy(Qt::WheelFocus);
        viewWidget->setContextMenuPolicy(Qt::NoContextMenu);
        viewWidget->setStyleSheet(QString::fromUtf8("background-color: black;"));

        verticalLayout->addWidget(viewWidget);

        groupBox = new QGroupBox(JImageDialogForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
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


        retranslateUi(JImageDialogForm);
        QObject::connect(viewWidget, SIGNAL(exposureChanged(float)), JImageDialogForm, SLOT(setExposureLabel(float)));
        QObject::connect(viewWidget, SIGNAL(gammaChanged(float)), JImageDialogForm, SLOT(setGammaLabel(float)));
        QObject::connect(viewWidget, SIGNAL(scaleChanged(float)), JImageDialogForm, SLOT(setScaleLabel(float)));
        QObject::connect(viewWidget, SIGNAL(coordinateChanged(int,int)), JImageDialogForm, SLOT(setCoordinateLabel(int,int)));
        QObject::connect(viewWidget, SIGNAL(coordinateChanged(int,int)), JImageDialogForm, SLOT(setColorLabel(int,int)));

        QMetaObject::connectSlotsByName(JImageDialogForm);
    } // setupUi

    void retranslateUi(QDialog *JImageDialogForm)
    {
        JImageDialogForm->setWindowTitle(QApplication::translate("JImageDialogForm", "Jiawei's Image Viewer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        groupBox->setWhatsThis(QApplication::translate("JImageDialogForm", "Additional Image Options", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QString());
        label_6->setText(QApplication::translate("JImageDialogForm", "coordinate:", 0, QApplication::UnicodeUTF8));
        coordinateLabel->setText(QApplication::translate("JImageDialogForm", "[0,0]", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("JImageDialogForm", "value:", 0, QApplication::UnicodeUTF8));
        colorLabel->setText(QApplication::translate("JImageDialogForm", "[-----, ----- ,-----]", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("JImageDialogForm", "size:", 0, QApplication::UnicodeUTF8));
        sizeLabel->setText(QApplication::translate("JImageDialogForm", "(0,0)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("JImageDialogForm", "scale:", 0, QApplication::UnicodeUTF8));
        scaleLabel->setText(QApplication::translate("JImageDialogForm", "1.0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("JImageDialogForm", "exposure:", 0, QApplication::UnicodeUTF8));
        exposureLabel->setText(QApplication::translate("JImageDialogForm", "0.00", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("JImageDialogForm", "gamma:", 0, QApplication::UnicodeUTF8));
        gammaLabel->setText(QApplication::translate("JImageDialogForm", "2.20", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class JImageDialogForm: public Ui_JImageDialogForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JDIFF_H
