/********************************************************************************
** Form generated from reading UI file 'changeinfoform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEINFOFORM_H
#define UI_CHANGEINFOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeInfoForm
{
public:
    QLabel *headText;
    QLabel *text1;
    QPushButton *exitButton;

    void setupUi(QWidget *ChangeInfoForm)
    {
        if (ChangeInfoForm->objectName().isEmpty())
            ChangeInfoForm->setObjectName(QString::fromUtf8("ChangeInfoForm"));
        ChangeInfoForm->resize(791, 331);
        ChangeInfoForm->setMinimumSize(QSize(791, 331));
        ChangeInfoForm->setMaximumSize(QSize(791, 331));
        ChangeInfoForm->setStyleSheet(QString::fromUtf8("QWidget#ChangeInfoForm {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        headText = new QLabel(ChangeInfoForm);
        headText->setObjectName(QString::fromUtf8("headText"));
        headText->setGeometry(QRect(10, 10, 771, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        headText->setFont(font);
        headText->setStyleSheet(QString::fromUtf8("QLabel#headText {\n"
"\n"
"	background-color: #FFC300;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        headText->setAlignment(Qt::AlignCenter);
        text1 = new QLabel(ChangeInfoForm);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 60, 771, 201));
        QFont font1;
        font1.setPointSize(16);
        text1->setFont(font1);
        text1->setStyleSheet(QString::fromUtf8("QLabel#text1 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text1->setAlignment(Qt::AlignCenter);
        exitButton = new QPushButton(ChangeInfoForm);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(10, 270, 771, 51));
        exitButton->setMinimumSize(QSize(381, 51));
        exitButton->setMaximumSize(QSize(99999, 51));
        exitButton->setFont(font1);
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton#exitButton {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #FFFFFF;\n"
"}\n"
"QPushButton#exitButton:hover {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
"QPushButton#exitButton:pressed {\n"
"\n"
"	background-color: #DB1921;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
"QPushButton#exitButton:disabled {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #4B7089;\n"
"	border: 5px solid #4B7089;\n"
"}"));

        retranslateUi(ChangeInfoForm);

        QMetaObject::connectSlotsByName(ChangeInfoForm);
    } // setupUi

    void retranslateUi(QWidget *ChangeInfoForm)
    {
        ChangeInfoForm->setWindowTitle(QApplication::translate("ChangeInfoForm", "\320\240\320\260\320\264\320\265\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        headText->setText(QApplication::translate("ChangeInfoForm", "\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200\320\270\320\262\320\260\320\275\320\270\320\265 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        text1->setText(QApplication::translate("ChangeInfoForm", "\320\230\320\267\320\274\320\265\320\275\321\217\320\271 \321\217\321\207\320\265\320\271\320\272\320\270 \321\202\320\260\320\261\320\273\320\270\321\206\321\213, \321\201 \320\275\320\270\321\205 \321\201\320\275\321\217\321\202\320\260 \320\261\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\272\320\260", nullptr));
        exitButton->setText(QApplication::translate("ChangeInfoForm", "\320\220\320\263\320\260, \320\277\320\276\320\275\321\217\321\202\320\275\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeInfoForm: public Ui_ChangeInfoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINFOFORM_H
