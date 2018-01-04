/********************************************************************************
** Form generated from reading UI file 'Blank_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLANK_WIDGET_H
#define UI_BLANK_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Blank_widget
{
public:

    void setupUi(QDialog *Blank_widget)
    {
        if (Blank_widget->objectName().isEmpty())
            Blank_widget->setObjectName(QStringLiteral("Blank_widget"));
        Blank_widget->resize(1024, 600);
        Blank_widget->setStyleSheet(QStringLiteral("background:black"));

        retranslateUi(Blank_widget);

        QMetaObject::connectSlotsByName(Blank_widget);
    } // setupUi

    void retranslateUi(QDialog *Blank_widget)
    {
        Blank_widget->setWindowTitle(QApplication::translate("Blank_widget", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Blank_widget: public Ui_Blank_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLANK_WIDGET_H
