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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *lights0_button;
    QPushButton *lights1_button;
    QPushButton *lights2_button;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *temp_label;
    QLabel *humi_label;

    void setupUi(QDialog *Bath_Room_win)
    {
        if (Bath_Room_win->objectName().isEmpty())
            Bath_Room_win->setObjectName(QStringLiteral("Bath_Room_win"));
        Bath_Room_win->resize(1024, 600);
        back_button = new QPushButton(Bath_Room_win);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setGeometry(QRect(859, 10, 151, 101));
        layoutWidget = new QWidget(Bath_Room_win);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(400, 40, 426, 130));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lights0_button = new QPushButton(layoutWidget);
        lights0_button->setObjectName(QStringLiteral("lights0_button"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lights0_button->sizePolicy().hasHeightForWidth());
        lights0_button->setSizePolicy(sizePolicy);
        lights0_button->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(lights0_button);

        lights1_button = new QPushButton(layoutWidget);
        lights1_button->setObjectName(QStringLiteral("lights1_button"));
        sizePolicy.setHeightForWidth(lights1_button->sizePolicy().hasHeightForWidth());
        lights1_button->setSizePolicy(sizePolicy);
        lights1_button->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(lights1_button);

        lights2_button = new QPushButton(layoutWidget);
        lights2_button->setObjectName(QStringLiteral("lights2_button"));
        sizePolicy.setHeightForWidth(lights2_button->sizePolicy().hasHeightForWidth());
        lights2_button->setSizePolicy(sizePolicy);
        lights2_button->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(lights2_button);

        layoutWidget1 = new QWidget(Bath_Room_win);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(190, 40, 171, 251));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        temp_label = new QLabel(layoutWidget1);
        temp_label->setObjectName(QStringLiteral("temp_label"));
        QFont font;
        font.setFamily(QStringLiteral("digitalk"));
        font.setPointSize(48);
        temp_label->setFont(font);

        verticalLayout->addWidget(temp_label);

        humi_label = new QLabel(layoutWidget1);
        humi_label->setObjectName(QStringLiteral("humi_label"));
        humi_label->setFont(font);

        verticalLayout->addWidget(humi_label);


        retranslateUi(Bath_Room_win);

        QMetaObject::connectSlotsByName(Bath_Room_win);
    } // setupUi

    void retranslateUi(QDialog *Bath_Room_win)
    {
        Bath_Room_win->setWindowTitle(QApplication::translate("Bath_Room_win", "Bath_Room_win", 0));
        back_button->setText(QApplication::translate("Bath_Room_win", "Back", 0));
        lights0_button->setText(QString());
        lights1_button->setText(QString());
        lights2_button->setText(QString());
        temp_label->setText(QApplication::translate("Bath_Room_win", "N/A", 0));
        humi_label->setText(QApplication::translate("Bath_Room_win", "N/A", 0));
    } // retranslateUi

};

namespace Ui {
    class Bath_Room_win: public Ui_Bath_Room_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATH_ROOM_WIN_H
