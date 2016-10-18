/********************************************************************************
** Form generated from reading UI file 'info_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_WIDGET_H
#define UI_INFO_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_info_widget
{
public:
    QLabel *humidity_label;
    QLabel *temp_label;
    QLabel *name_label;

    void setupUi(QWidget *info_widget)
    {
        if (info_widget->objectName().isEmpty())
            info_widget->setObjectName(QStringLiteral("info_widget"));
        info_widget->resize(260, 160);
        humidity_label = new QLabel(info_widget);
        humidity_label->setObjectName(QStringLiteral("humidity_label"));
        humidity_label->setGeometry(QRect(20, 80, 121, 31));
        temp_label = new QLabel(info_widget);
        temp_label->setObjectName(QStringLiteral("temp_label"));
        temp_label->setGeometry(QRect(20, 40, 121, 31));
        name_label = new QLabel(info_widget);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(20, 10, 121, 31));

        retranslateUi(info_widget);

        QMetaObject::connectSlotsByName(info_widget);
    } // setupUi

    void retranslateUi(QWidget *info_widget)
    {
        info_widget->setWindowTitle(QApplication::translate("info_widget", "info_widget", 0));
        humidity_label->setText(QApplication::translate("info_widget", "N/A", 0));
        temp_label->setText(QApplication::translate("info_widget", "N/A", 0));
        name_label->setText(QApplication::translate("info_widget", "N/A", 0));
    } // retranslateUi

};

namespace Ui {
    class info_widget: public Ui_info_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_WIDGET_H
