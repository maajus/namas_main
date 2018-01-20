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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVideoWidget"
#include "include/info_widget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *side_menu;
    QStackedWidget *stack_widget;
    QWidget *page_3;
    info_widget *bedroom_info;
    info_widget *wc_info;
    info_widget *corridor_info;
    info_widget *livingroom_info;
    info_widget *workroom_info;
    QWidget *page;
    QListWidget *listWidget;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *page_2;
    QPushButton *alarm_button;
    QLabel *arm_alarm_label;
    QWidget *keypad_widget;
    QLineEdit *alarm_code_lineedit;
    QWidget *layoutWidget3;
    QGridLayout *keypad_layout;
    QPushButton *key_1;
    QPushButton *key_2;
    QPushButton *key_3;
    QPushButton *key_4;
    QPushButton *key_5;
    QPushButton *key_6;
    QPushButton *key_7;
    QPushButton *key_8;
    QPushButton *key_9;
    QPushButton *hash_key;
    QPushButton *key_0;
    QPushButton *del_key;
    QWidget *page_4;
    QPushButton *rec_button;
    QPushButton *take_photo_button;
    QFrame *frame;
    QVideoWidget *video_widget;
    QWidget *page_5;
    QLabel *label_2;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *date_label;
    QLabel *time_label;
    QLabel *pir1_label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 600);
        MainWindow->setMinimumSize(QSize(1024, 600));
        MainWindow->setMaximumSize(QSize(1024, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 90, 991, 481));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        side_menu = new QListWidget(layoutWidget);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/home1.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font;
        font.setPointSize(16);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(side_menu);
        __qlistwidgetitem->setFont(font);
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
        QFont font1;
        font1.setPointSize(12);
        side_menu->setFont(font1);
        side_menu->setSpacing(5);

        horizontalLayout->addWidget(side_menu);

        stack_widget = new QStackedWidget(layoutWidget);
        stack_widget->setObjectName(QStringLiteral("stack_widget"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        bedroom_info = new info_widget(page_3);
        bedroom_info->setObjectName(QStringLiteral("bedroom_info"));
        bedroom_info->setGeometry(QRect(0, 220, 260, 160));
        wc_info = new info_widget(page_3);
        wc_info->setObjectName(QStringLiteral("wc_info"));
        wc_info->setGeometry(QRect(580, 10, 260, 160));
        corridor_info = new info_widget(page_3);
        corridor_info->setObjectName(QStringLiteral("corridor_info"));
        corridor_info->setGeometry(QRect(290, 10, 260, 160));
        livingroom_info = new info_widget(page_3);
        livingroom_info->setObjectName(QStringLiteral("livingroom_info"));
        livingroom_info->setGeometry(QRect(0, 10, 260, 160));
        workroom_info = new info_widget(page_3);
        workroom_info->setObjectName(QStringLiteral("workroom_info"));
        workroom_info->setGeometry(QRect(290, 220, 260, 160));
        stack_widget->addWidget(page_3);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        listWidget = new QListWidget(page);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 691, 401));
        layoutWidget1 = new QWidget(page);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 413, 521, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(layoutWidget1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton_4);

        layoutWidget2 = new QWidget(page);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(720, 20, 131, 381));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(layoutWidget2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(layoutWidget2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(layoutWidget2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_7);

        stack_widget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        alarm_button = new QPushButton(page_2);
        alarm_button->setObjectName(QStringLiteral("alarm_button"));
        alarm_button->setGeometry(QRect(600, 130, 231, 211));
        arm_alarm_label = new QLabel(page_2);
        arm_alarm_label->setObjectName(QStringLiteral("arm_alarm_label"));
        arm_alarm_label->setGeometry(QRect(600, 345, 231, 31));
        QFont font2;
        font2.setPointSize(14);
        arm_alarm_label->setFont(font2);
        arm_alarm_label->setAlignment(Qt::AlignCenter);
        keypad_widget = new QWidget(page_2);
        keypad_widget->setObjectName(QStringLiteral("keypad_widget"));
        keypad_widget->setGeometry(QRect(30, 10, 541, 471));
        alarm_code_lineedit = new QLineEdit(keypad_widget);
        alarm_code_lineedit->setObjectName(QStringLiteral("alarm_code_lineedit"));
        alarm_code_lineedit->setGeometry(QRect(40, 0, 481, 61));
        QFont font3;
        font3.setFamily(QStringLiteral("DejaVu Sans"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        alarm_code_lineedit->setFont(font3);
        layoutWidget3 = new QWidget(keypad_widget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(51, 67, 471, 391));
        keypad_layout = new QGridLayout(layoutWidget3);
        keypad_layout->setSpacing(10);
        keypad_layout->setObjectName(QStringLiteral("keypad_layout"));
        keypad_layout->setContentsMargins(0, 0, 0, 0);
        key_1 = new QPushButton(layoutWidget3);
        key_1->setObjectName(QStringLiteral("key_1"));
        sizePolicy.setHeightForWidth(key_1->sizePolicy().hasHeightForWidth());
        key_1->setSizePolicy(sizePolicy);

        keypad_layout->addWidget(key_1, 0, 0, 1, 1);

        key_2 = new QPushButton(layoutWidget3);
        key_2->setObjectName(QStringLiteral("key_2"));
        sizePolicy.setHeightForWidth(key_2->sizePolicy().hasHeightForWidth());
        key_2->setSizePolicy(sizePolicy);

        keypad_layout->addWidget(key_2, 0, 1, 1, 1);

        key_3 = new QPushButton(layoutWidget3);
        key_3->setObjectName(QStringLiteral("key_3"));
        sizePolicy.setHeightForWidth(key_3->sizePolicy().hasHeightForWidth());
        key_3->setSizePolicy(sizePolicy);

        keypad_layout->addWidget(key_3, 0, 2, 1, 1);

        key_4 = new QPushButton(layoutWidget3);
        key_4->setObjectName(QStringLiteral("key_4"));
        sizePolicy.setHeightForWidth(key_4->sizePolicy().hasHeightForWidth());
        key_4->setSizePolicy(sizePolicy);

        keypad_layout->addWidget(key_4, 1, 0, 1, 1);

        key_5 = new QPushButton(layoutWidget3);
        key_5->setObjectName(QStringLiteral("key_5"));
        sizePolicy.setHeightForWidth(key_5->sizePolicy().hasHeightForWidth());
        key_5->setSizePolicy(sizePolicy);

        keypad_layout->addWidget(key_5, 1, 1, 1, 1);

        key_6 = new QPushButton(layoutWidget3);
        key_6->setObjectName(QStringLiteral("key_6"));
        sizePolicy.setHeightForWidth(key_6->sizePolicy().hasHeightForWidth());
        key_6->setSizePolicy(sizePolicy);

        keypad_layout->addWidget(key_6, 1, 2, 1, 1);

        key_7 = new QPushButton(layoutWidget3);
        key_7->setObjectName(QStringLiteral("key_7"));
        sizePolicy.setHeightForWidth(key_7->sizePolicy().hasHeightForWidth());
        key_7->setSizePolicy(sizePolicy);

        keypad_layout->addWidget(key_7, 2, 0, 1, 1);

        key_8 = new QPushButton(layoutWidget3);
        key_8->setObjectName(QStringLiteral("key_8"));
        sizePolicy.setHeightForWidth(key_8->sizePolicy().hasHeightForWidth());
        key_8->setSizePolicy(sizePolicy);

        keypad_layout->addWidget(key_8, 2, 1, 1, 1);

        key_9 = new QPushButton(layoutWidget3);
        key_9->setObjectName(QStringLiteral("key_9"));
        sizePolicy.setHeightForWidth(key_9->sizePolicy().hasHeightForWidth());
        key_9->setSizePolicy(sizePolicy);

        keypad_layout->addWidget(key_9, 2, 2, 1, 1);

        hash_key = new QPushButton(layoutWidget3);
        hash_key->setObjectName(QStringLiteral("hash_key"));
        sizePolicy.setHeightForWidth(hash_key->sizePolicy().hasHeightForWidth());
        hash_key->setSizePolicy(sizePolicy);

        keypad_layout->addWidget(hash_key, 3, 0, 1, 1);

        key_0 = new QPushButton(layoutWidget3);
        key_0->setObjectName(QStringLiteral("key_0"));
        sizePolicy.setHeightForWidth(key_0->sizePolicy().hasHeightForWidth());
        key_0->setSizePolicy(sizePolicy);

        keypad_layout->addWidget(key_0, 3, 1, 1, 1);

        del_key = new QPushButton(layoutWidget3);
        del_key->setObjectName(QStringLiteral("del_key"));
        sizePolicy.setHeightForWidth(del_key->sizePolicy().hasHeightForWidth());
        del_key->setSizePolicy(sizePolicy);

        keypad_layout->addWidget(del_key, 3, 2, 1, 1);

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

        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(538, 0, 441, 98));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        date_label = new QLabel(layoutWidget4);
        date_label->setObjectName(QStringLiteral("date_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(date_label->sizePolicy().hasHeightForWidth());
        date_label->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamily(QStringLiteral("digitalk"));
        font4.setPointSize(48);
        font4.setBold(false);
        font4.setWeight(50);
        date_label->setFont(font4);
        date_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(date_label);

        time_label = new QLabel(layoutWidget4);
        time_label->setObjectName(QStringLiteral("time_label"));
        sizePolicy1.setHeightForWidth(time_label->sizePolicy().hasHeightForWidth());
        time_label->setSizePolicy(sizePolicy1);
        time_label->setFont(font4);
        time_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(time_label);

        pir1_label = new QLabel(centralwidget);
        pir1_label->setObjectName(QStringLiteral("pir1_label"));
        pir1_label->setGeometry(QRect(10, 10, 21, 21));
        pir1_label->setPixmap(QPixmap(QString::fromUtf8(":/icons/green-circle.png")));
        pir1_label->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stack_widget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));

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
        alarm_button->setText(QString());
        arm_alarm_label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        alarm_code_lineedit->setInputMask(QApplication::translate("MainWindow", "99999", 0));
        key_1->setText(QApplication::translate("MainWindow", "1", 0));
        key_2->setText(QApplication::translate("MainWindow", "2", 0));
        key_3->setText(QApplication::translate("MainWindow", "3", 0));
        key_4->setText(QApplication::translate("MainWindow", "4", 0));
        key_5->setText(QApplication::translate("MainWindow", "5", 0));
        key_6->setText(QApplication::translate("MainWindow", "6", 0));
        key_7->setText(QApplication::translate("MainWindow", "7", 0));
        key_8->setText(QApplication::translate("MainWindow", "8", 0));
        key_9->setText(QApplication::translate("MainWindow", "9", 0));
        hash_key->setText(QApplication::translate("MainWindow", "#", 0));
        key_0->setText(QApplication::translate("MainWindow", "0", 0));
        del_key->setText(QApplication::translate("MainWindow", "Del", 0));
        rec_button->setText(QApplication::translate("MainWindow", "REC", 0));
        take_photo_button->setText(QApplication::translate("MainWindow", "Photo", 0));
        label_2->setText(QApplication::translate("MainWindow", "Settings", 0));
        date_label->setText(QApplication::translate("MainWindow", "N/A", 0));
        time_label->setText(QApplication::translate("MainWindow", "N/A", 0));
        pir1_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
