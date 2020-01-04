/********************************************************************************
** Form generated from reading UI file 'Living_Room_win.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVING_ROOM_WIN_H
#define UI_LIVING_ROOM_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Living_Room_win
{
public:
    QPushButton *back_button;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *temp_icon_label;
    QLabel *temp_label;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *humi_icon_label;
    QLabel *humi_label;
    QFrame *room_buttons_frame;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *lights0_button;
    QPushButton *lights1_button;
    QPushButton *lights2_button;
    QPushButton *lights3_button;
    QPushButton *lights4_button;
    QPushButton *lights5_button;

    void setupUi(QDialog *Living_Room_win)
    {
        if (Living_Room_win->objectName().isEmpty())
            Living_Room_win->setObjectName(QString::fromUtf8("Living_Room_win"));
        Living_Room_win->resize(1024, 600);
        back_button = new QPushButton(Living_Room_win);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setGeometry(QRect(859, 10, 151, 101));
        layoutWidget = new QWidget(Living_Room_win);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 351, 141));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        temp_icon_label = new QLabel(layoutWidget);
        temp_icon_label->setObjectName(QString::fromUtf8("temp_icon_label"));
        temp_icon_label->setMaximumSize(QSize(119, 109));
        temp_icon_label->setPixmap(QPixmap(QString::fromUtf8(":/icons/temp.png")));
        temp_icon_label->setScaledContents(true);

        horizontalLayout_2->addWidget(temp_icon_label);

        temp_label = new QLabel(layoutWidget);
        temp_label->setObjectName(QString::fromUtf8("temp_label"));
        QFont font;
        font.setFamily(QString::fromUtf8("digitalk"));
        font.setPointSize(48);
        temp_label->setFont(font);

        horizontalLayout_2->addWidget(temp_label);

        layoutWidget1 = new QWidget(Living_Room_win);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 170, 351, 121));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        humi_icon_label = new QLabel(layoutWidget1);
        humi_icon_label->setObjectName(QString::fromUtf8("humi_icon_label"));
        humi_icon_label->setMaximumSize(QSize(109, 119));
        humi_icon_label->setPixmap(QPixmap(QString::fromUtf8(":/icons/humidity.png")));
        humi_icon_label->setScaledContents(true);
        humi_icon_label->setMargin(7);

        horizontalLayout_3->addWidget(humi_icon_label);

        humi_label = new QLabel(layoutWidget1);
        humi_label->setObjectName(QString::fromUtf8("humi_label"));
        humi_label->setFont(font);

        horizontalLayout_3->addWidget(humi_label);

        room_buttons_frame = new QFrame(Living_Room_win);
        room_buttons_frame->setObjectName(QString::fromUtf8("room_buttons_frame"));
        room_buttons_frame->setGeometry(QRect(430, 30, 351, 421));
        room_buttons_frame->setFrameShape(QFrame::StyledPanel);
        room_buttons_frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(room_buttons_frame);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(21, 21, 311, 381));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lights0_button = new QPushButton(widget);
        lights0_button->setObjectName(QString::fromUtf8("lights0_button"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lights0_button->sizePolicy().hasHeightForWidth());
        lights0_button->setSizePolicy(sizePolicy);
        lights0_button->setIconSize(QSize(64, 64));

        gridLayout->addWidget(lights0_button, 0, 0, 1, 1);

        lights1_button = new QPushButton(widget);
        lights1_button->setObjectName(QString::fromUtf8("lights1_button"));
        sizePolicy.setHeightForWidth(lights1_button->sizePolicy().hasHeightForWidth());
        lights1_button->setSizePolicy(sizePolicy);
        lights1_button->setIconSize(QSize(64, 64));

        gridLayout->addWidget(lights1_button, 0, 1, 1, 1);

        lights2_button = new QPushButton(widget);
        lights2_button->setObjectName(QString::fromUtf8("lights2_button"));
        sizePolicy.setHeightForWidth(lights2_button->sizePolicy().hasHeightForWidth());
        lights2_button->setSizePolicy(sizePolicy);
        lights2_button->setIconSize(QSize(64, 64));

        gridLayout->addWidget(lights2_button, 1, 0, 1, 1);

        lights3_button = new QPushButton(widget);
        lights3_button->setObjectName(QString::fromUtf8("lights3_button"));
        sizePolicy.setHeightForWidth(lights3_button->sizePolicy().hasHeightForWidth());
        lights3_button->setSizePolicy(sizePolicy);
        lights3_button->setIconSize(QSize(64, 64));

        gridLayout->addWidget(lights3_button, 1, 1, 1, 1);

        lights4_button = new QPushButton(widget);
        lights4_button->setObjectName(QString::fromUtf8("lights4_button"));
        sizePolicy.setHeightForWidth(lights4_button->sizePolicy().hasHeightForWidth());
        lights4_button->setSizePolicy(sizePolicy);
        lights4_button->setIconSize(QSize(64, 64));

        gridLayout->addWidget(lights4_button, 2, 0, 1, 1);

        lights5_button = new QPushButton(widget);
        lights5_button->setObjectName(QString::fromUtf8("lights5_button"));
        sizePolicy.setHeightForWidth(lights5_button->sizePolicy().hasHeightForWidth());
        lights5_button->setSizePolicy(sizePolicy);
        lights5_button->setIconSize(QSize(64, 64));

        gridLayout->addWidget(lights5_button, 2, 1, 1, 1);


        retranslateUi(Living_Room_win);

        QMetaObject::connectSlotsByName(Living_Room_win);
    } // setupUi

    void retranslateUi(QDialog *Living_Room_win)
    {
        Living_Room_win->setWindowTitle(QCoreApplication::translate("Living_Room_win", "Living_Room_win", nullptr));
        back_button->setText(QCoreApplication::translate("Living_Room_win", "Back", nullptr));
        temp_icon_label->setText(QString());
        temp_label->setText(QCoreApplication::translate("Living_Room_win", "N/A", nullptr));
        humi_icon_label->setText(QString());
        humi_label->setText(QCoreApplication::translate("Living_Room_win", "N/A", nullptr));
        lights0_button->setText(QString());
        lights1_button->setText(QString());
        lights2_button->setText(QString());
        lights3_button->setText(QString());
        lights4_button->setText(QString());
        lights5_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Living_Room_win: public Ui_Living_Room_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVING_ROOM_WIN_H
