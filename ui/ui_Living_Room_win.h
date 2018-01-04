/********************************************************************************
** Form generated from reading UI file 'Living_Room_win.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVING_ROOM_WIN_H
#define UI_LIVING_ROOM_WIN_H

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
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *lights0_button;
    QPushButton *lights1_button;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *lights2_button;
    QPushButton *lights3_button;

    void setupUi(QDialog *Living_Room_win)
    {
        if (Living_Room_win->objectName().isEmpty())
            Living_Room_win->setObjectName(QStringLiteral("Living_Room_win"));
        Living_Room_win->resize(1024, 600);
        back_button = new QPushButton(Living_Room_win);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setGeometry(QRect(859, 10, 151, 101));
        layoutWidget = new QWidget(Living_Room_win);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 351, 141));
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
        QFont font;
        font.setFamily(QStringLiteral("digitalk"));
        font.setPointSize(48);
        temp_label->setFont(font);

        horizontalLayout_2->addWidget(temp_label);

        layoutWidget1 = new QWidget(Living_Room_win);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 170, 351, 121));
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
        humi_label->setFont(font);

        horizontalLayout_3->addWidget(humi_label);

        room_buttons_frame = new QFrame(Living_Room_win);
        room_buttons_frame->setObjectName(QStringLiteral("room_buttons_frame"));
        room_buttons_frame->setGeometry(QRect(430, 50, 351, 351));
        room_buttons_frame->setFrameShape(QFrame::StyledPanel);
        room_buttons_frame->setFrameShadow(QFrame::Raised);
        layoutWidget2 = new QWidget(room_buttons_frame);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 20, 311, 141));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lights0_button = new QPushButton(layoutWidget2);
        lights0_button->setObjectName(QStringLiteral("lights0_button"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lights0_button->sizePolicy().hasHeightForWidth());
        lights0_button->setSizePolicy(sizePolicy);
        lights0_button->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(lights0_button);

        lights1_button = new QPushButton(layoutWidget2);
        lights1_button->setObjectName(QStringLiteral("lights1_button"));
        sizePolicy.setHeightForWidth(lights1_button->sizePolicy().hasHeightForWidth());
        lights1_button->setSizePolicy(sizePolicy);
        lights1_button->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(lights1_button);

        layoutWidget_2 = new QWidget(room_buttons_frame);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 180, 311, 141));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        lights2_button = new QPushButton(layoutWidget_2);
        lights2_button->setObjectName(QStringLiteral("lights2_button"));
        sizePolicy.setHeightForWidth(lights2_button->sizePolicy().hasHeightForWidth());
        lights2_button->setSizePolicy(sizePolicy);
        lights2_button->setIconSize(QSize(64, 64));

        horizontalLayout_4->addWidget(lights2_button);

        lights3_button = new QPushButton(layoutWidget_2);
        lights3_button->setObjectName(QStringLiteral("lights3_button"));
        sizePolicy.setHeightForWidth(lights3_button->sizePolicy().hasHeightForWidth());
        lights3_button->setSizePolicy(sizePolicy);
        lights3_button->setIconSize(QSize(64, 64));

        horizontalLayout_4->addWidget(lights3_button);


        retranslateUi(Living_Room_win);

        QMetaObject::connectSlotsByName(Living_Room_win);
    } // setupUi

    void retranslateUi(QDialog *Living_Room_win)
    {
        Living_Room_win->setWindowTitle(QApplication::translate("Living_Room_win", "Living_Room_win", Q_NULLPTR));
        back_button->setText(QApplication::translate("Living_Room_win", "Back", Q_NULLPTR));
        temp_icon_label->setText(QString());
        temp_label->setText(QApplication::translate("Living_Room_win", "N/A", Q_NULLPTR));
        humi_icon_label->setText(QString());
        humi_label->setText(QApplication::translate("Living_Room_win", "N/A", Q_NULLPTR));
        lights0_button->setText(QString());
        lights1_button->setText(QString());
        lights2_button->setText(QString());
        lights3_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Living_Room_win: public Ui_Living_Room_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVING_ROOM_WIN_H
