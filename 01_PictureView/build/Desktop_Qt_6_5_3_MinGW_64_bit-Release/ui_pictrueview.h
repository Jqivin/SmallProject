/********************************************************************************
** Form generated from reading UI file 'pictrueview.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTRUEVIEW_H
#define UI_PICTRUEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PictrueViewClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *btnGray;
    QRadioButton *btnBinary;
    QRadioButton *btnMeanFilter;
    QRadioButton *btnGamma;
    QRadioButton *btnEdgeDetect;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPic;
    QSlider *sliderBinary;
    QSlider *sliderGamma;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PictrueViewClass)
    {
        if (PictrueViewClass->objectName().isEmpty())
            PictrueViewClass->setObjectName("PictrueViewClass");
        PictrueViewClass->resize(613, 499);
        centralWidget = new QWidget(PictrueViewClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 50));
        widget->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnGray = new QRadioButton(widget);
        btnGray->setObjectName("btnGray");

        horizontalLayout_2->addWidget(btnGray);

        btnBinary = new QRadioButton(widget);
        btnBinary->setObjectName("btnBinary");

        horizontalLayout_2->addWidget(btnBinary);

        btnMeanFilter = new QRadioButton(widget);
        btnMeanFilter->setObjectName("btnMeanFilter");

        horizontalLayout_2->addWidget(btnMeanFilter);

        btnGamma = new QRadioButton(widget);
        btnGamma->setObjectName("btnGamma");

        horizontalLayout_2->addWidget(btnGamma);

        btnEdgeDetect = new QRadioButton(widget);
        btnEdgeDetect->setObjectName("btnEdgeDetect");

        horizontalLayout_2->addWidget(btnEdgeDetect);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        labelPic = new QLabel(widget_2);
        labelPic->setObjectName("labelPic");

        horizontalLayout->addWidget(labelPic);

        sliderBinary = new QSlider(widget_2);
        sliderBinary->setObjectName("sliderBinary");
        sliderBinary->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(sliderBinary);

        sliderGamma = new QSlider(widget_2);
        sliderGamma->setObjectName("sliderGamma");
        sliderGamma->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(sliderGamma);


        verticalLayout->addWidget(widget_2);

        PictrueViewClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PictrueViewClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 613, 22));
        PictrueViewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PictrueViewClass);
        mainToolBar->setObjectName("mainToolBar");
        PictrueViewClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PictrueViewClass);
        statusBar->setObjectName("statusBar");
        PictrueViewClass->setStatusBar(statusBar);

        retranslateUi(PictrueViewClass);

        QMetaObject::connectSlotsByName(PictrueViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *PictrueViewClass)
    {
        PictrueViewClass->setWindowTitle(QCoreApplication::translate("PictrueViewClass", "PictrueView", nullptr));
        btnGray->setText(QString());
        btnBinary->setText(QString());
        btnMeanFilter->setText(QString());
        btnGamma->setText(QCoreApplication::translate("PictrueViewClass", "Gamma transform", nullptr));
        btnEdgeDetect->setText(QString());
        labelPic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PictrueViewClass: public Ui_PictrueViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTRUEVIEW_H
