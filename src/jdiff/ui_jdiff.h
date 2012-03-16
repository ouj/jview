/********************************************************************************
** Form generated from reading UI file 'jdiff.ui'
**
** Created: Fri Mar 16 00:16:24 2012
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
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JDiffDialogForm
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *image1Page;
    QWidget *image2Page;
    QWidget *diffPage;
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

    void setupUi(QDialog *JDiffDialogForm)
    {
        if (JDiffDialogForm->objectName().isEmpty())
            JDiffDialogForm->setObjectName(QString::fromUtf8("JDiffDialogForm"));
        JDiffDialogForm->resize(515, 582);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(JDiffDialogForm->sizePolicy().hasHeightForWidth());
        JDiffDialogForm->setSizePolicy(sizePolicy);
        JDiffDialogForm->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(JDiffDialogForm);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 5);
        groupBox = new QGroupBox(JDiffDialogForm);
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
        stackedWidget = new QStackedWidget(groupBox);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setCursor(QCursor(Qt::CrossCursor));
        stackedWidget->setFrameShape(QFrame::Box);
        stackedWidget->setFrameShadow(QFrame::Sunken);
        stackedWidget->setLineWidth(1);
        image1Page = new QWidget();
        image1Page->setObjectName(QString::fromUtf8("image1Page"));
        stackedWidget->addWidget(image1Page);
        image2Page = new QWidget();
        image2Page->setObjectName(QString::fromUtf8("image2Page"));
        stackedWidget->addWidget(image2Page);
        diffPage = new QWidget();
        diffPage->setObjectName(QString::fromUtf8("diffPage"));
        stackedWidget->addWidget(diffPage);

        verticalLayout_3->addWidget(stackedWidget);

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


        retranslateUi(JDiffDialogForm);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(JDiffDialogForm);
    } // setupUi

    void retranslateUi(QDialog *JDiffDialogForm)
    {
        JDiffDialogForm->setWindowTitle(QApplication::translate("JDiffDialogForm", "jdiff", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        groupBox->setWhatsThis(QApplication::translate("JDiffDialogForm", "Additional Image Options", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QString());
        label_6->setText(QApplication::translate("JDiffDialogForm", "coordinate:", 0, QApplication::UnicodeUTF8));
        coordinateLabel->setText(QApplication::translate("JDiffDialogForm", "[0,0]", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("JDiffDialogForm", "value:", 0, QApplication::UnicodeUTF8));
        colorLabel->setText(QApplication::translate("JDiffDialogForm", "[-----, ----- ,-----]", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("JDiffDialogForm", "size:", 0, QApplication::UnicodeUTF8));
        sizeLabel->setText(QApplication::translate("JDiffDialogForm", "(0,0)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("JDiffDialogForm", "scale:", 0, QApplication::UnicodeUTF8));
        scaleLabel->setText(QApplication::translate("JDiffDialogForm", "1.0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("JDiffDialogForm", "exposure:", 0, QApplication::UnicodeUTF8));
        exposureLabel->setText(QApplication::translate("JDiffDialogForm", "0.00", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("JDiffDialogForm", "gamma:", 0, QApplication::UnicodeUTF8));
        gammaLabel->setText(QApplication::translate("JDiffDialogForm", "2.20", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class JDiffDialogForm: public Ui_JDiffDialogForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JDIFF_H
