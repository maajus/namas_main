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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
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
    QListWidget *listWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *page_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_39;
    QWidget *widget2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_11;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *pushButton_14;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QPushButton *pushButton_17;
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
        time_label->setGeometry(QRect(690, 10, 301, 71));
        QFont font;
        font.setFamily(QStringLiteral("digitalk"));
        font.setPointSize(48);
        font.setBold(false);
        font.setWeight(50);
        time_label->setFont(font);
        time_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 90, 991, 481));
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
        listWidget = new QListWidget(page);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 691, 401));
        widget = new QWidget(page);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 413, 521, 61));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_4);

        widget1 = new QWidget(page);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(720, 20, 131, 381));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(widget1);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget1);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(widget1);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_7);

        stack_widget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 10, 361, 61));
        QFont font3;
        font3.setFamily(QStringLiteral("DejaVu Sans"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        lineEdit->setFont(font3);
        pushButton_39 = new QPushButton(page_2);
        pushButton_39->setObjectName(QStringLiteral("pushButton_39"));
        pushButton_39->setGeometry(QRect(670, 30, 141, 121));
        widget2 = new QWidget(page_2);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(101, 77, 351, 381));
        gridLayout = new QGridLayout(widget2);
        gridLayout->setSpacing(10);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_8 = new QPushButton(widget2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_8, 0, 0, 1, 1);

        pushButton_9 = new QPushButton(widget2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_9, 0, 1, 1, 1);

        pushButton_10 = new QPushButton(widget2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        sizePolicy.setHeightForWidth(pushButton_10->sizePolicy().hasHeightForWidth());
        pushButton_10->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_10, 0, 2, 1, 1);

        pushButton_12 = new QPushButton(widget2);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        sizePolicy.setHeightForWidth(pushButton_12->sizePolicy().hasHeightForWidth());
        pushButton_12->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_12, 1, 0, 1, 1);

        pushButton_13 = new QPushButton(widget2);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        sizePolicy.setHeightForWidth(pushButton_13->sizePolicy().hasHeightForWidth());
        pushButton_13->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_13, 1, 1, 1, 1);

        pushButton_11 = new QPushButton(widget2);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        sizePolicy.setHeightForWidth(pushButton_11->sizePolicy().hasHeightForWidth());
        pushButton_11->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_11, 1, 2, 1, 1);

        pushButton_15 = new QPushButton(widget2);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        sizePolicy.setHeightForWidth(pushButton_15->sizePolicy().hasHeightForWidth());
        pushButton_15->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_15, 2, 0, 1, 1);

        pushButton_16 = new QPushButton(widget2);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        sizePolicy.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_16, 2, 1, 1, 1);

        pushButton_14 = new QPushButton(widget2);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        sizePolicy.setHeightForWidth(pushButton_14->sizePolicy().hasHeightForWidth());
        pushButton_14->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_14, 2, 2, 1, 1);

        pushButton_18 = new QPushButton(widget2);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        sizePolicy.setHeightForWidth(pushButton_18->sizePolicy().hasHeightForWidth());
        pushButton_18->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_18, 3, 0, 1, 1);

        pushButton_19 = new QPushButton(widget2);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        sizePolicy.setHeightForWidth(pushButton_19->sizePolicy().hasHeightForWidth());
        pushButton_19->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_19, 3, 1, 1, 1);

        pushButton_17 = new QPushButton(widget2);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        sizePolicy.setHeightForWidth(pushButton_17->sizePolicy().hasHeightForWidth());
        pushButton_17->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_17, 3, 2, 1, 1);

        stack_widget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        rec_button = new QPushButton(page_4);
        rec_button->setObjectName(QStringLiteral("rec_button"));
        rec_button->setGeometry(QRect(730, 10, 120, 80));
        take_photo_button = new QPushButton(page_4);
        take_photo_button->setObjectName(QStringLiteral("take_photo_button"));
        take_photo_button->setGeometry(QRect(730, 110, 120, 80));
        frame = new QFrame(page_4);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 0, 585, 480));
        frame->setStyleSheet(QStringLiteral("border:1px solid #435F70;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        video_widget = new QVideoWidget(frame);
        video_widget->setObjectName(QStringLiteral("video_widget"));
        video_widget->setGeometry(QRect(5, 5, 575, 470));
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

        pushButton->setText(QApplication::translate("MainWindow", "Play", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Stop", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "<", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", ">", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Radio", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Mp3", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Youtube", 0));
        lineEdit->setInputMask(QString());
        pushButton_39->setText(QApplication::translate("MainWindow", "Arm system", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "1", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "2", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "3", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "4", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "5", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "6", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "7", 0));
        pushButton_16->setText(QApplication::translate("MainWindow", "8", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "9", 0));
        pushButton_18->setText(QApplication::translate("MainWindow", "#", 0));
        pushButton_19->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton_17->setText(QApplication::translate("MainWindow", "Del", 0));
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
