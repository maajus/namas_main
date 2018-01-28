/********************************************************************************
** Form generated from reading UI file 'Bath_Room_win.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATH_ROOM_WIN_H
#define UI_BATH_ROOM_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bath_Room_win
{
public:
    QPushButton *back_button;
    QFrame *room_buttons_frame;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *lights0_button;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QPushButton *lights1_button;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QPushButton *lights2_button;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QPushButton *lights3_button;
    QFrame *room_temp_frame;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *temp_icon_label;
    QLabel *temp_label;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *humi_icon_label;
    QLabel *humi_label;

    void setupUi(QDialog *Bath_Room_win)
    {
        if (Bath_Room_win->objectName().isEmpty())
            Bath_Room_win->setObjectName(QStringLiteral("Bath_Room_win"));
        Bath_Room_win->resize(1024, 530);
        back_button = new QPushButton(Bath_Room_win);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setGeometry(QRect(864, 20, 140, 101));
        room_buttons_frame = new QFrame(Bath_Room_win);
        room_buttons_frame->setObjectName(QStringLiteral("room_buttons_frame"));
        room_buttons_frame->setGeometry(QRect(440, 20, 401, 321));
        room_buttons_frame->setFrameShape(QFrame::StyledPanel);
        room_buttons_frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(room_buttons_frame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(26, 14, 351, 291));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lights0_button = new QPushButton(widget);
        lights0_button->setObjectName(QStringLiteral("lights0_button"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lights0_button->sizePolicy().hasHeightForWidth());
        lights0_button->setSizePolicy(sizePolicy);
        lights0_button->setIconSize(QSize(128, 128));

        horizontalLayout->addWidget(lights0_button);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_4->addWidget(label_2);

        lights1_button = new QPushButton(widget);
        lights1_button->setObjectName(QStringLiteral("lights1_button"));
        sizePolicy.setHeightForWidth(lights1_button->sizePolicy().hasHeightForWidth());
        lights1_button->setSizePolicy(sizePolicy);
        lights1_button->setIconSize(QSize(128, 128));

        horizontalLayout_4->addWidget(lights1_button);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_5->addWidget(label_3);

        lights2_button = new QPushButton(widget);
        lights2_button->setObjectName(QStringLiteral("lights2_button"));
        sizePolicy.setHeightForWidth(lights2_button->sizePolicy().hasHeightForWidth());
        lights2_button->setSizePolicy(sizePolicy);
        lights2_button->setIconSize(QSize(128, 128));

        horizontalLayout_5->addWidget(lights2_button);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_6->addWidget(label_4);

        lights3_button = new QPushButton(widget);
        lights3_button->setObjectName(QStringLiteral("lights3_button"));
        sizePolicy.setHeightForWidth(lights3_button->sizePolicy().hasHeightForWidth());
        lights3_button->setSizePolicy(sizePolicy);
        lights3_button->setIconSize(QSize(128, 128));

        horizontalLayout_6->addWidget(lights3_button);


        verticalLayout->addLayout(horizontalLayout_6);

        room_temp_frame = new QFrame(Bath_Room_win);
        room_temp_frame->setObjectName(QStringLiteral("room_temp_frame"));
        room_temp_frame->setGeometry(QRect(18, 20, 401, 321));
        room_temp_frame->setFrameShape(QFrame::StyledPanel);
        room_temp_frame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(room_temp_frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(26, 20, 351, 141));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        temp_icon_label = new QLabel(layoutWidget);
        temp_icon_label->setObjectName(QStringLiteral("temp_icon_label"));
        temp_icon_label->setMaximumSize(QSize(119, 109));
        temp_icon_label->setPixmap(QPixmap(QString::fromUtf8(":/icons/temp.png")));
        temp_icon_label->setScaledContents(true);

        horizontalLayout_2->addWidget(temp_icon_label);

        temp_label = new QLabel(layoutWidget);
        temp_label->setObjectName(QStringLiteral("temp_label"));
        QFont font1;
        font1.setFamily(QStringLiteral("digitalk"));
        font1.setPointSize(48);
        temp_label->setFont(font1);

        horizontalLayout_2->addWidget(temp_label);

        layoutWidget1 = new QWidget(room_temp_frame);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(26, 170, 351, 121));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        humi_icon_label = new QLabel(layoutWidget1);
        humi_icon_label->setObjectName(QStringLiteral("humi_icon_label"));
        humi_icon_label->setMaximumSize(QSize(109, 119));
        humi_icon_label->setPixmap(QPixmap(QString::fromUtf8(":/icons/humidity.png")));
        humi_icon_label->setScaledContents(true);
        humi_icon_label->setMargin(7);

        horizontalLayout_3->addWidget(humi_icon_label);

        humi_label = new QLabel(layoutWidget1);
        humi_label->setObjectName(QStringLiteral("humi_label"));
        humi_label->setFont(font1);

        horizontalLayout_3->addWidget(humi_label);


        retranslateUi(Bath_Room_win);

        QMetaObject::connectSlotsByName(Bath_Room_win);
    } // setupUi

    void retranslateUi(QDialog *Bath_Room_win)
    {
        Bath_Room_win->setWindowTitle(QApplication::translate("Bath_Room_win", "Bath_Room_win", 0));
        back_button->setText(QApplication::translate("Bath_Room_win", "Back", 0));
        label->setText(QApplication::translate("Bath_Room_win", "\305\240viesos", 0));
        lights0_button->setText(QString());
        label_2->setText(QApplication::translate("Bath_Room_win", "LED", 0));
        lights1_button->setText(QString());
        label_3->setText(QApplication::translate("Bath_Room_win", "Ventiliatorius", 0));
        lights2_button->setText(QString());
        label_4->setText(QApplication::translate("Bath_Room_win", "Veidrodis", 0));
        lights3_button->setText(QString());
        temp_icon_label->setText(QString());
        temp_label->setText(QApplication::translate("Bath_Room_win", "N/A", 0));
        humi_icon_label->setText(QString());
        humi_label->setText(QApplication::translate("Bath_Room_win", "N/A", 0));
    } // retranslateUi

};

namespace Ui {
    class Bath_Room_win: public Ui_Bath_Room_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATH_ROOM_WIN_H
