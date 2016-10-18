/********************************************************************************
** Form generated from reading UI file 'Room_win.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOM_WIN_H
#define UI_ROOM_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Room_win
{
public:
    QPushButton *back_button;
    QPushButton *lights1_button;

    void setupUi(QDialog *Room_win)
    {
        if (Room_win->objectName().isEmpty())
            Room_win->setObjectName(QStringLiteral("Room_win"));
        Room_win->resize(1024, 600);
        back_button = new QPushButton(Room_win);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setGeometry(QRect(859, 10, 151, 101));
        lights1_button = new QPushButton(Room_win);
        lights1_button->setObjectName(QStringLiteral("lights1_button"));
        lights1_button->setGeometry(QRect(530, 10, 221, 161));

        retranslateUi(Room_win);

        QMetaObject::connectSlotsByName(Room_win);
    } // setupUi

    void retranslateUi(QDialog *Room_win)
    {
        Room_win->setWindowTitle(QApplication::translate("Room_win", "Room_win", 0));
        back_button->setText(QApplication::translate("Room_win", "Back", 0));
        lights1_button->setText(QApplication::translate("Room_win", "Lights 1", 0));
    } // retranslateUi

};

namespace Ui {
    class Room_win: public Ui_Room_win {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOM_WIN_H
