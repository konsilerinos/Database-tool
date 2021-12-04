/********************************************************************************
** Form generated from reading UI file 'teacherdeleteform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERDELETEFORM_H
#define UI_TEACHERDELETEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherDeleteForm
{
public:
    QLabel *headText;
    QPushButton *deleteButton;
    QPushButton *exitButton;
    QLabel *text2;
    QTextEdit *logText;
    QLabel *text3;
    QLabel *text1;
    QLabel *logHead;
    QTextEdit *surnameLine;
    QTextEdit *nameLine;
    QTextEdit *patronymicLine;
    QLabel *text4;
    QTextEdit *IDLine;

    void setupUi(QWidget *TeacherDeleteForm)
    {
        if (TeacherDeleteForm->objectName().isEmpty())
            TeacherDeleteForm->setObjectName(QString::fromUtf8("TeacherDeleteForm"));
        TeacherDeleteForm->resize(791, 451);
        TeacherDeleteForm->setMinimumSize(QSize(791, 451));
        TeacherDeleteForm->setMaximumSize(QSize(791, 451));
        TeacherDeleteForm->setStyleSheet(QString::fromUtf8("QWidget#TeacherDeleteForm {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        headText = new QLabel(TeacherDeleteForm);
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
        deleteButton = new QPushButton(TeacherDeleteForm);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(false);
        deleteButton->setGeometry(QRect(10, 390, 381, 51));
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
        exitButton = new QPushButton(TeacherDeleteForm);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(400, 390, 381, 51));
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
        text2 = new QLabel(TeacherDeleteForm);
        text2->setObjectName(QString::fromUtf8("text2"));
        text2->setGeometry(QRect(10, 110, 191, 41));
        QFont font2;
        font2.setPointSize(14);
        text2->setFont(font2);
        text2->setStyleSheet(QString::fromUtf8("QLabel#text2 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        logText = new QTextEdit(TeacherDeleteForm);
        logText->setObjectName(QString::fromUtf8("logText"));
        logText->setGeometry(QRect(10, 310, 771, 71));
        QFont font3;
        font3.setPointSize(10);
        logText->setFont(font3);
        logText->setStyleSheet(QString::fromUtf8("QTextEdit#logText {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text3 = new QLabel(TeacherDeleteForm);
        text3->setObjectName(QString::fromUtf8("text3"));
        text3->setGeometry(QRect(10, 160, 191, 41));
        text3->setFont(font2);
        text3->setStyleSheet(QString::fromUtf8("QLabel#text3 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        text1 = new QLabel(TeacherDeleteForm);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 60, 191, 41));
        text1->setFont(font2);
        text1->setStyleSheet(QString::fromUtf8("QLabel#text1 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        logHead = new QLabel(TeacherDeleteForm);
        logHead->setObjectName(QString::fromUtf8("logHead"));
        logHead->setGeometry(QRect(10, 260, 771, 41));
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
        surnameLine = new QTextEdit(TeacherDeleteForm);
        surnameLine->setObjectName(QString::fromUtf8("surnameLine"));
        surnameLine->setEnabled(false);
        surnameLine->setGeometry(QRect(210, 110, 571, 41));
        surnameLine->setFont(font2);
        surnameLine->setStyleSheet(QString::fromUtf8("QTextEdit#surnameLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        nameLine = new QTextEdit(TeacherDeleteForm);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));
        nameLine->setEnabled(false);
        nameLine->setGeometry(QRect(210, 160, 571, 41));
        nameLine->setFont(font2);
        nameLine->setStyleSheet(QString::fromUtf8("QTextEdit#nameLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        patronymicLine = new QTextEdit(TeacherDeleteForm);
        patronymicLine->setObjectName(QString::fromUtf8("patronymicLine"));
        patronymicLine->setEnabled(false);
        patronymicLine->setGeometry(QRect(210, 210, 571, 41));
        patronymicLine->setFont(font2);
        patronymicLine->setStyleSheet(QString::fromUtf8("QTextEdit#patronymicLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text4 = new QLabel(TeacherDeleteForm);
        text4->setObjectName(QString::fromUtf8("text4"));
        text4->setGeometry(QRect(10, 210, 191, 41));
        text4->setFont(font2);
        text4->setStyleSheet(QString::fromUtf8("QLabel#text4 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        IDLine = new QTextEdit(TeacherDeleteForm);
        IDLine->setObjectName(QString::fromUtf8("IDLine"));
        IDLine->setGeometry(QRect(210, 60, 571, 41));
        IDLine->setFont(font2);
        IDLine->setStyleSheet(QString::fromUtf8("QTextEdit#IDLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));

        retranslateUi(TeacherDeleteForm);

        QMetaObject::connectSlotsByName(TeacherDeleteForm);
    } // setupUi

    void retranslateUi(QWidget *TeacherDeleteForm)
    {
        TeacherDeleteForm->setWindowTitle(QApplication::translate("TeacherDeleteForm", "\320\237\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\214, \321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        headText->setText(QApplication::translate("TeacherDeleteForm", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        deleteButton->setText(QApplication::translate("TeacherDeleteForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        exitButton->setText(QApplication::translate("TeacherDeleteForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        text2->setText(QApplication::translate("TeacherDeleteForm", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        text3->setText(QApplication::translate("TeacherDeleteForm", "\320\230\320\274\321\217", nullptr));
        text1->setText(QApplication::translate("TeacherDeleteForm", "\320\242\320\260\320\261\320\265\320\273\321\214\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200", nullptr));
        logHead->setText(QApplication::translate("TeacherDeleteForm", "\320\233\320\276\320\263 \320\276\321\210\320\270\320\261\320\276\320\272 \320\270 \320\277\321\200\320\265\320\264\321\203\320\277\321\200\320\265\320\266\320\264\320\265\320\275\320\270\320\271", nullptr));
        text4->setText(QApplication::translate("TeacherDeleteForm", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherDeleteForm: public Ui_TeacherDeleteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERDELETEFORM_H
