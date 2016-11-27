/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "QVideoWidget"
#include "headers/info_widget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *leave_button;
    QLabel *build_label;
    QLabel *time_label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *side_menu;
    QStackedWidget *stack_widget;
    QWidget *page_3;
    info_widget *bedroom1_info;
    info_widget *wc_info;
    info_widget *livingroom_info;
    info_widget *kitchen_info;
    info_widget *bedroom2_info;
    QWidget *page;
    QLabel *label_3;
    QWidget *page_2;
    QLabel *label_4;
    QWidget *page_4;
    QPushButton *rec_button;
    QPushButton *take_photo_button;
    QFrame *frame;
    QVideoWidget *video_widget;
    QWidget *page_5;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 600);
        MainWindow->setMinimumSize(QSize(1024, 600));
        MainWindow->setMaximumSize(QSize(1024, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        leave_button = new QPushButton(centralwidget);
        leave_button->setObjectName(QStringLiteral("leave_button"));
        leave_button->setGeometry(QRect(10, 10, 121, 51));
        build_label = new QLabel(centralwidget);
        build_label->setObjectName(QStringLiteral("build_label"));
        build_label->setGeometry(QRect(10, 570, 301, 31));
        time_label = new QLabel(centralwidget);
        time_label->setObjectName(QStringLiteral("time_label"));
        time_label->setGeometry(QRect(710, 10, 301, 71));
        QFont font;
        font.setFamily(QStringLiteral("digitalk"));
        font.setPointSize(48);
        font.setBold(false);
        font.setWeight(50);
        time_label->setFont(font);
        time_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 90, 1011, 481));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        side_menu = new QListWidget(layoutWidget);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/home1.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font1;
        font1.setPointSize(16);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(side_menu);
        __qlistwidgetitem->setFont(font1);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(side_menu);
        __qlistwidgetitem1->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/home-security.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(side_menu);
        __qlistwidgetitem2->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(side_menu);
        __qlistwidgetitem3->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(side_menu);
        __qlistwidgetitem4->setIcon(icon4);
        side_menu->setObjectName(QStringLiteral("side_menu"));
        side_menu->setMaximumSize(QSize(120, 16777215));
        QFont font2;
        font2.setPointSize(12);
        side_menu->setFont(font2);
        side_menu->setSpacing(5);

        horizontalLayout->addWidget(side_menu);

        stack_widget = new QStackedWidget(layoutWidget);
        stack_widget->setObjectName(QStringLiteral("stack_widget"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        bedroom1_info = new info_widget(page_3);
        bedroom1_info->setObjectName(QStringLiteral("bedroom1_info"));
        bedroom1_info->setGeometry(QRect(290, 220, 260, 160));
        wc_info = new info_widget(page_3);
        wc_info->setObjectName(QStringLiteral("wc_info"));
        wc_info->setGeometry(QRect(580, 10, 260, 160));
        livingroom_info = new info_widget(page_3);
        livingroom_info->setObjectName(QStringLiteral("livingroom_info"));
        livingroom_info->setGeometry(QRect(290, 10, 260, 160));
        kitchen_info = new info_widget(page_3);
        kitchen_info->setObjectName(QStringLiteral("kitchen_info"));
        kitchen_info->setGeometry(QRect(0, 10, 260, 160));
        bedroom2_info = new info_widget(page_3);
        bedroom2_info->setObjectName(QStringLiteral("bedroom2_info"));
        bedroom2_info->setGeometry(QRect(580, 220, 260, 160));
        stack_widget->addWidget(page_3);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 60, 171, 51));
        stack_widget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 30, 221, 71));
        stack_widget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        rec_button = new QPushButton(page_4);
        rec_button->setObjectName(QStringLiteral("rec_button"));
        rec_button->setGeometry(QRect(750, 10, 120, 80));
        take_photo_button = new QPushButton(page_4);
        take_photo_button->setObjectName(QStringLiteral("take_photo_button"));
        take_photo_button->setGeometry(QRect(750, 110, 120, 80));
        frame = new QFrame(page_4);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 0, 585, 480));
        frame->setStyleSheet(QStringLiteral("border-width:5px"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        video_widget = new QVideoWidget(frame);
        video_widget->setObjectName(QStringLiteral("video_widget"));
        video_widget->setGeometry(QRect(0, 0, 585, 480));
        video_widget->setStyleSheet(QStringLiteral(""));
        stack_widget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        label_2 = new QLabel(page_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 50, 151, 51));
        stack_widget->addWidget(page_5);

        horizontalLayout->addWidget(stack_widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stack_widget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        leave_button->setText(QApplication::translate("MainWindow", "Leave", 0));
        build_label->setText(QApplication::translate("MainWindow", "N/A", 0));
        time_label->setText(QApplication::translate("MainWindow", "N/A", 0));

        const bool __sortingEnabled = side_menu->isSortingEnabled();
        side_menu->setSortingEnabled(false);
        side_menu->setSortingEnabled(__sortingEnabled);

        label_3->setText(QApplication::translate("MainWindow", "Music", 0));
        label_4->setText(QApplication::translate("MainWindow", "Security", 0));
        rec_button->setText(QApplication::translate("MainWindow", "REC", 0));
        take_photo_button->setText(QApplication::translate("MainWindow", "Photo", 0));
        label_2->setText(QApplication::translate("MainWindow", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
