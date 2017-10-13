/********************************************************************************
** Form generated from reading UI file 'info_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
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
    QLabel *name_label;
    QLabel *status_label;
    QLabel *temp_label;
    QLabel *humidity_label;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *info_widget)
    {
        if (info_widget->objectName().isEmpty())
            info_widget->setObjectName(QStringLiteral("info_widget"));
        info_widget->resize(260, 160);
        name_label = new QLabel(info_widget);
        name_label->setObjectName(QStringLiteral("name_label"));
        name_label->setGeometry(QRect(20, 10, 201, 31));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        name_label->setFont(font);
        name_label->setStyleSheet(QStringLiteral("color: #282828;"));
        status_label = new QLabel(info_widget);
        status_label->setObjectName(QStringLiteral("status_label"));
        status_label->setGeometry(QRect(20, 38, 171, 21));
        status_label->setScaledContents(true);
        temp_label = new QLabel(info_widget);
        temp_label->setObjectName(QStringLiteral("temp_label"));
        temp_label->setGeometry(QRect(55, 68, 121, 33));
        QFont font1;
        font1.setFamily(QStringLiteral("DejaVu Sans"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        temp_label->setFont(font1);
        humidity_label = new QLabel(info_widget);
        humidity_label->setObjectName(QStringLiteral("humidity_label"));
        humidity_label->setGeometry(QRect(55, 112, 111, 33));
        humidity_label->setFont(font1);
        label = new QLabel(info_widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(11, 68, 37, 37));
        label->setMaximumSize(QSize(37, 40));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/temp.png")));
        label->setScaledContents(true);
        label->setMargin(0);
        label_2 = new QLabel(info_widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(11, 110, 37, 37));
        label_2->setMaximumSize(QSize(37, 40));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/humidity.png")));
        label_2->setScaledContents(true);
        label_2->setMargin(3);

        retranslateUi(info_widget);

        QMetaObject::connectSlotsByName(info_widget);
    } // setupUi

    void retranslateUi(QWidget *info_widget)
    {
        info_widget->setWindowTitle(QApplication::translate("info_widget", "info_widget", Q_NULLPTR));
        name_label->setText(QApplication::translate("info_widget", "N/A", Q_NULLPTR));
        status_label->setText(QString());
        temp_label->setText(QApplication::translate("info_widget", "N/A", Q_NULLPTR));
        humidity_label->setText(QApplication::translate("info_widget", "N/A", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class info_widget: public Ui_info_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_WIDGET_H
