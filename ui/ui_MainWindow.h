/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "headers/info_widget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *leave_button;
    QLabel *label;
    QLabel *time_label;
    info_widget *kitchen_info;
    info_widget *livingroom_info;
    info_widget *bedroom1_info;
    info_widget *bedroom2_info;
    info_widget *wc_info;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        leave_button = new QPushButton(centralwidget);
        leave_button->setObjectName(QStringLiteral("leave_button"));
        leave_button->setGeometry(QRect(890, 100, 121, 481));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 560, 301, 31));
        time_label = new QLabel(centralwidget);
        time_label->setObjectName(QStringLiteral("time_label"));
        time_label->setGeometry(QRect(790, 10, 221, 71));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        time_label->setFont(font);
        time_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        kitchen_info = new info_widget(centralwidget);
        kitchen_info->setObjectName(QStringLiteral("kitchen_info"));
        kitchen_info->setGeometry(QRect(10, 100, 260, 160));
        livingroom_info = new info_widget(centralwidget);
        livingroom_info->setObjectName(QStringLiteral("livingroom_info"));
        livingroom_info->setGeometry(QRect(300, 100, 260, 160));
        bedroom1_info = new info_widget(centralwidget);
        bedroom1_info->setObjectName(QStringLiteral("bedroom1_info"));
        bedroom1_info->setGeometry(QRect(300, 310, 260, 160));
        bedroom2_info = new info_widget(centralwidget);
        bedroom2_info->setObjectName(QStringLiteral("bedroom2_info"));
        bedroom2_info->setGeometry(QRect(590, 310, 260, 160));
        wc_info = new info_widget(centralwidget);
        wc_info->setObjectName(QStringLiteral("wc_info"));
        wc_info->setGeometry(QRect(590, 100, 260, 160));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        leave_button->setText(QApplication::translate("MainWindow", "Leave", 0));
        label->setText(QApplication::translate("MainWindow", "N/A", 0));
        time_label->setText(QApplication::translate("MainWindow", "N/A", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
