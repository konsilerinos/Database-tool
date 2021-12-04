/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Info
{
public:
    QLabel *text1;
    QLabel *text2;
    QLabel *text3;
    QLabel *text4;
    QLabel *text5;
    QLabel *text6;
    QPushButton *exitButton;
    QLabel *Image;

    void setupUi(QWidget *Info)
    {
        if (Info->objectName().isEmpty())
            Info->setObjectName(QString::fromUtf8("Info"));
        Info->resize(851, 341);
        Info->setMinimumSize(QSize(851, 341));
        Info->setMaximumSize(QSize(851, 341));
        Info->setStyleSheet(QString::fromUtf8("QWidget#Info {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        text1 = new QLabel(Info);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 10, 341, 41));
        QFont font;
        font.setPointSize(22);
        text1->setFont(font);
        text1->setStyleSheet(QString::fromUtf8("QLabel#text1 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        text2 = new QLabel(Info);
        text2->setObjectName(QString::fromUtf8("text2"));
        text2->setGeometry(QRect(10, 50, 341, 41));
        QFont font1;
        font1.setPointSize(18);
        text2->setFont(font1);
        text2->setStyleSheet(QString::fromUtf8("QLabel#text2 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        text3 = new QLabel(Info);
        text3->setObjectName(QString::fromUtf8("text3"));
        text3->setGeometry(QRect(10, 100, 341, 41));
        text3->setFont(font);
        text3->setStyleSheet(QString::fromUtf8("QLabel#text3 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        text4 = new QLabel(Info);
        text4->setObjectName(QString::fromUtf8("text4"));
        text4->setGeometry(QRect(10, 140, 341, 41));
        text4->setFont(font1);
        text4->setStyleSheet(QString::fromUtf8("QLabel#text4 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        text5 = new QLabel(Info);
        text5->setObjectName(QString::fromUtf8("text5"));
        text5->setGeometry(QRect(10, 190, 341, 41));
        text5->setFont(font);
        text5->setStyleSheet(QString::fromUtf8("QLabel#text5 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        text6 = new QLabel(Info);
        text6->setObjectName(QString::fromUtf8("text6"));
        text6->setGeometry(QRect(10, 230, 341, 41));
        text6->setFont(font1);
        text6->setStyleSheet(QString::fromUtf8("QLabel#text6 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        exitButton = new QPushButton(Info);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(10, 280, 831, 51));
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
""));
        Image = new QLabel(Info);
        Image->setObjectName(QString::fromUtf8("Image"));
        Image->setGeometry(QRect(360, 10, 481, 261));
        Image->setStyleSheet(QString::fromUtf8("QLabel#Image {\n"
"\n"
"	background-color: #284B63;\n"
"	background-image: url(:/Images/Developer.png);\n"
"}"));

        retranslateUi(Info);

        QMetaObject::connectSlotsByName(Info);
    } // setupUi

    void retranslateUi(QWidget *Info)
    {
        Info->setWindowTitle(QApplication::translate("Info", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\321\207\320\270\320\272", nullptr));
        text1->setText(QApplication::translate("Info", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\321\207\320\270\320\272:", nullptr));
        text2->setText(QApplication::translate("Info", "\320\241\320\273\320\265\321\201\320\260\321\200\320\265\320\262 \320\235\320\270\320\272\320\276\320\273\320\260\320\271 \320\241\320\265\321\200\320\263\320\265\320\265\320\262\320\270\321\207", nullptr));
        text3->setText(QApplication::translate("Info", "GitHub", nullptr));
        text4->setText(QApplication::translate("Info", "konsilerinos", nullptr));
        text5->setText(QApplication::translate("Info", "\320\237\320\276\321\207\321\202\320\260:", nullptr));
        text6->setText(QApplication::translate("Info", "n_slesarev@mail.ru", nullptr));
        exitButton->setText(QApplication::translate("Info", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        Image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Info: public Ui_Info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
