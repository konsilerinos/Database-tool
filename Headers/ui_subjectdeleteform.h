/********************************************************************************
** Form generated from reading UI file 'subjectdeleteform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBJECTDELETEFORM_H
#define UI_SUBJECTDELETEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubjectDeleteForm
{
public:
    QLabel *headText;
    QPushButton *deleteButton;
    QPushButton *exitButton;
    QLabel *text2;
    QTextEdit *logText;
    QLabel *text3;
    QComboBox *nameBox;
    QComboBox *IDBox;
    QLabel *text1;
    QLabel *logHead;
    QComboBox *shortNameBox;

    void setupUi(QWidget *SubjectDeleteForm)
    {
        if (SubjectDeleteForm->objectName().isEmpty())
            SubjectDeleteForm->setObjectName(QString::fromUtf8("SubjectDeleteForm"));
        SubjectDeleteForm->resize(790, 401);
        SubjectDeleteForm->setStyleSheet(QString::fromUtf8("QWidget#SubjectDeleteForm {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        headText = new QLabel(SubjectDeleteForm);
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
        deleteButton = new QPushButton(SubjectDeleteForm);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(true);
        deleteButton->setGeometry(QRect(10, 340, 381, 51));
        QFont font1;
        font1.setPointSize(16);
        deleteButton->setFont(font1);
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton#deleteButton {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #FFFFFF;\n"
"}\n"
"QPushButton#deleteButton:hover {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
"QPushButton#deleteButton:pressed {\n"
"\n"
"	background-color: #DB1921;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
"QPushButton#deleteButton:disabled {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #4B7089;\n"
"	border: 5px solid #4B7089;\n"
"}"));
        exitButton = new QPushButton(SubjectDeleteForm);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(400, 340, 381, 51));
        exitButton->setMinimumSize(QSize(381, 51));
        exitButton->setMaximumSize(QSize(381, 51));
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
        text2 = new QLabel(SubjectDeleteForm);
        text2->setObjectName(QString::fromUtf8("text2"));
        text2->setGeometry(QRect(10, 110, 261, 41));
        QFont font2;
        font2.setPointSize(14);
        text2->setFont(font2);
        text2->setStyleSheet(QString::fromUtf8("QLabel#text2 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        logText = new QTextEdit(SubjectDeleteForm);
        logText->setObjectName(QString::fromUtf8("logText"));
        logText->setGeometry(QRect(10, 260, 771, 71));
        QFont font3;
        font3.setPointSize(10);
        logText->setFont(font3);
        logText->setStyleSheet(QString::fromUtf8("QTextEdit#logText {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text3 = new QLabel(SubjectDeleteForm);
        text3->setObjectName(QString::fromUtf8("text3"));
        text3->setGeometry(QRect(10, 160, 261, 41));
        text3->setFont(font2);
        text3->setStyleSheet(QString::fromUtf8("QLabel#text3 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        nameBox = new QComboBox(SubjectDeleteForm);
        nameBox->setObjectName(QString::fromUtf8("nameBox"));
        nameBox->setGeometry(QRect(280, 110, 501, 41));
        nameBox->setFont(font2);
        nameBox->setStyleSheet(QString::fromUtf8("QComboBox#nameBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        IDBox = new QComboBox(SubjectDeleteForm);
        IDBox->setObjectName(QString::fromUtf8("IDBox"));
        IDBox->setGeometry(QRect(280, 60, 501, 41));
        IDBox->setFont(font2);
        IDBox->setStyleSheet(QString::fromUtf8("QComboBox#IDBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text1 = new QLabel(SubjectDeleteForm);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 60, 261, 41));
        text1->setFont(font2);
        text1->setStyleSheet(QString::fromUtf8("QLabel#text1 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        logHead = new QLabel(SubjectDeleteForm);
        logHead->setObjectName(QString::fromUtf8("logHead"));
        logHead->setGeometry(QRect(10, 210, 771, 41));
        QFont font4;
        font4.setPointSize(16);
        font4.setBold(false);
        font4.setWeight(50);
        logHead->setFont(font4);
        logHead->setStyleSheet(QString::fromUtf8("QLabel#logHead {\n"
"\n"
"	background-color: #FFC300;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        logHead->setAlignment(Qt::AlignCenter);
        shortNameBox = new QComboBox(SubjectDeleteForm);
        shortNameBox->setObjectName(QString::fromUtf8("shortNameBox"));
        shortNameBox->setGeometry(QRect(280, 160, 501, 41));
        shortNameBox->setFont(font2);
        shortNameBox->setStyleSheet(QString::fromUtf8("QComboBox#shortNameBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));

        retranslateUi(SubjectDeleteForm);

        QMetaObject::connectSlotsByName(SubjectDeleteForm);
    } // setupUi

    void retranslateUi(QWidget *SubjectDeleteForm)
    {
        SubjectDeleteForm->setWindowTitle(QApplication::translate("SubjectDeleteForm", "\320\237\321\200\320\265\320\264\320\274\320\265\321\202, \321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        headText->setText(QApplication::translate("SubjectDeleteForm", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\320\260", nullptr));
        deleteButton->setText(QApplication::translate("SubjectDeleteForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        exitButton->setText(QApplication::translate("SubjectDeleteForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        text2->setText(QApplication::translate("SubjectDeleteForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        text3->setText(QApplication::translate("SubjectDeleteForm", "\320\241\320\276\320\272\321\200\320\260\321\211\321\221\320\275\320\275\320\276\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        text1->setText(QApplication::translate("SubjectDeleteForm", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\202\320\276\321\200 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\320\260", nullptr));
        logHead->setText(QApplication::translate("SubjectDeleteForm", "\320\233\320\276\320\263 \320\276\321\210\320\270\320\261\320\276\320\272 \320\270 \320\277\321\200\320\265\320\264\321\203\320\277\321\200\320\265\320\266\320\264\320\265\320\275\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubjectDeleteForm: public Ui_SubjectDeleteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBJECTDELETEFORM_H
