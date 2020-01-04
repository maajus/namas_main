/********************************************************************************
** Form generated from reading UI file 'info_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_WIDGET_H
#define UI_INFO_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_info_widget
{
public:
    QLabel *name_label;
    QLabel *status_label;
    QLabel *temp_label;
    QLabel *humidity_label;
    QLabel *label;
    QLabel *label_2;
    QLabel *bulb_label;

    void setupUi(QWidget *info_widget)
    {
        if (info_widget->objectName().isEmpty())
            info_widget->setObjectName(QString::fromUtf8("info_widget"));
        info_widget->resize(260, 160);
        name_label = new QLabel(info_widget);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setGeometry(QRect(20, 10, 201, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        name_label->setFont(font);
        name_label->setStyleSheet(QString::fromUtf8("color: #282828;"));
        status_label = new QLabel(info_widget);
        status_label->setObjectName(QString::fromUtf8("status_label"));
        status_label->setGeometry(QRect(20, 39, 171, 17));
        QFont font1;
        font1.setPointSize(7);
        status_label->setFont(font1);
        status_label->setScaledContents(true);
        temp_label = new QLabel(info_widget);
        temp_label->setObjectName(QString::fromUtf8("temp_label"));
        temp_label->setGeometry(QRect(55, 58, 121, 33));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        temp_label->setFont(font2);
        humidity_label = new QLabel(info_widget);
        humidity_label->setObjectName(QString::fromUtf8("humidity_label"));
        humidity_label->setGeometry(QRect(55, 102, 111, 33));
        humidity_label->setFont(font2);
        label = new QLabel(info_widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(11, 58, 37, 37));
        label->setMaximumSize(QSize(37, 40));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/temp.png")));
        label->setScaledContents(true);
        label->setMargin(0);
        label_2 = new QLabel(info_widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(11, 100, 37, 37));
        label_2->setMaximumSize(QSize(37, 40));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/humidity.png")));
        label_2->setScaledContents(true);
        label_2->setMargin(3);
        bulb_label = new QLabel(info_widget);
        bulb_label->setObjectName(QString::fromUtf8("bulb_label"));
        bulb_label->setGeometry(QRect(182, 64, 37, 61));
        bulb_label->setPixmap(QPixmap(QString::fromUtf8(":/icons/bulb_off.png")));
        bulb_label->setScaledContents(true);
        bulb_label->setMargin(0);

        retranslateUi(info_widget);

        QMetaObject::connectSlotsByName(info_widget);
    } // setupUi

    void retranslateUi(QWidget *info_widget)
    {
        info_widget->setWindowTitle(QCoreApplication::translate("info_widget", "info_widget", nullptr));
        name_label->setText(QCoreApplication::translate("info_widget", "N/A", nullptr));
        status_label->setText(QString());
        temp_label->setText(QCoreApplication::translate("info_widget", "N/A", nullptr));
        humidity_label->setText(QCoreApplication::translate("info_widget", "N/A", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        bulb_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class info_widget: public Ui_info_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_WIDGET_H
