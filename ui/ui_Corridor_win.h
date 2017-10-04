/********************************************************************************
** Form generated from reading UI file 'Corridor_win.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CORRIDOR_WIN_H
#define UI_CORRIDOR_WIN_H

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

class Ui_Corridor_win
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
    QPushButton *lights2_button;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *lights0_button;
    QPushButton *lights1_button;

    void setupUi(QDialog *Corridor_win)
    {
        if (Corridor_win->objectName().isEmpty())
            Corridor_win->setObjectName(QStringLiteral("Corridor_win"));
        Corridor_win->resize(1024, 600);
        back_button = new QPushButton(Corridor_win);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setGeometry(QRect(859, 10, 151, 101));
        layoutWidget = new QWidget(Corridor_win);
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

        layoutWidget1 = new QWidget(Corridor_win);
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

        room_buttons_frame = new QFrame(Corridor_win);
        room_buttons_frame->setObjectName(QStringLiteral("room_buttons_frame"));
        room_buttons_frame->setGeometry(QRect(430, 50, 351, 441));
        room_buttons_frame->setFrameShape(QFrame::StyledPanel);
        room_buttons_frame->setFrameShadow(QFrame::Raised);
        lights2_button = new QPushButton(room_buttons_frame);
        lights2_button->setObjectName(QStringLiteral("lights2_button"));
        lights2_button->setGeometry(QRect(20, 170, 311, 251));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lights2_button->sizePolicy().hasHeightForWidth());
        lights2_button->setSizePolicy(sizePolicy);
        lights2_button->setIconSize(QSize(64, 64));
        layoutWidget2 = new QWidget(room_buttons_frame);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 20, 311, 131));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lights0_button = new QPushButton(layoutWidget2);
        lights0_button->setObjectName(QStringLiteral("lights0_button"));
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


        retranslateUi(Corridor_win);

        QMetaObject::connectSlotsByName(Corridor_win);
    } // setupUi

    void retranslateUi(QDialog *Corridor_win)
    {
        Corridor_win->setWindowTitle(QApplication::translate("Corridor_win", "Corridor_win", 0));
        back_button->setText(QApplication::translate("Corridor_win", "Back", 0));
        temp_icon_label->setText(QString());
        temp_label->setText(QApplication::translate("Corridor_win", "N/A", 0));
        humi_icon_label->setText(QString());
        humi_label->setText(QApplication::translate("Corridor_win", "N/A", 0));
        lights2_button->setText(QString());
        lights0_button->setText(QString());
        lights1_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Corridor_win: public Ui_Corridor_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CORRIDOR_WIN_H
