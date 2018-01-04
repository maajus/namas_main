/********************************************************************************
** Form generated from reading UI file 'Work_Room_win.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORK_ROOM_WIN_H
#define UI_WORK_ROOM_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Work_Room_win
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
    QPushButton *lights0_button;

    void setupUi(QDialog *Work_Room_win)
    {
        if (Work_Room_win->objectName().isEmpty())
            Work_Room_win->setObjectName(QStringLiteral("Work_Room_win"));
        Work_Room_win->resize(1024, 600);
        back_button = new QPushButton(Work_Room_win);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setGeometry(QRect(859, 10, 151, 101));
        layoutWidget = new QWidget(Work_Room_win);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 170, 351, 141));
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

        layoutWidget1 = new QWidget(Work_Room_win);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 50, 351, 121));
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

        lights0_button = new QPushButton(Work_Room_win);
        lights0_button->setObjectName(QStringLiteral("lights0_button"));
        lights0_button->setGeometry(QRect(500, 50, 191, 241));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lights0_button->sizePolicy().hasHeightForWidth());
        lights0_button->setSizePolicy(sizePolicy);
        lights0_button->setIconSize(QSize(64, 64));

        retranslateUi(Work_Room_win);

        QMetaObject::connectSlotsByName(Work_Room_win);
    } // setupUi

    void retranslateUi(QDialog *Work_Room_win)
    {
        Work_Room_win->setWindowTitle(QApplication::translate("Work_Room_win", "Work_Room_win", Q_NULLPTR));
        back_button->setText(QApplication::translate("Work_Room_win", "Back", Q_NULLPTR));
        temp_icon_label->setText(QString());
        temp_label->setText(QApplication::translate("Work_Room_win", "N/A", Q_NULLPTR));
        humi_icon_label->setText(QString());
        humi_label->setText(QApplication::translate("Work_Room_win", "N/A", Q_NULLPTR));
        lights0_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Work_Room_win: public Ui_Work_Room_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORK_ROOM_WIN_H
