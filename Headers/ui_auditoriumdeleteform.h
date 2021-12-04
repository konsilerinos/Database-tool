/********************************************************************************
** Form generated from reading UI file 'auditoriumdeleteform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDITORIUMDELETEFORM_H
#define UI_AUDITORIUMDELETEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuditoriumDeleteForm
{
public:
    QComboBox *bodyBox;
    QLabel *text1;
    QLabel *headText;
    QPushButton *deleteButton;
    QLabel *logHead;
    QTextEdit *logText;
    QPushButton *exitButton;
    QComboBox *floorBox;
    QComboBox *numberBox;

    void setupUi(QWidget *AuditoriumDeleteForm)
    {
        if (AuditoriumDeleteForm->objectName().isEmpty())
            AuditoriumDeleteForm->setObjectName(QString::fromUtf8("AuditoriumDeleteForm"));
        AuditoriumDeleteForm->resize(791, 301);
        AuditoriumDeleteForm->setMinimumSize(QSize(791, 301));
        AuditoriumDeleteForm->setMaximumSize(QSize(791, 301));
        AuditoriumDeleteForm->setStyleSheet(QString::fromUtf8("QWidget#AuditoriumDeleteForm {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        bodyBox = new QComboBox(AuditoriumDeleteForm);
        bodyBox->setObjectName(QString::fromUtf8("bodyBox"));
        bodyBox->setGeometry(QRect(220, 60, 181, 41));
        QFont font;
        font.setPointSize(14);
        bodyBox->setFont(font);
        bodyBox->setStyleSheet(QString::fromUtf8("QComboBox#bodyBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text1 = new QLabel(AuditoriumDeleteForm);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 60, 201, 41));
        text1->setFont(font);
        text1->setStyleSheet(QString::fromUtf8("QLabel#text1 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        headText = new QLabel(AuditoriumDeleteForm);
        headText->setObjectName(QString::fromUtf8("headText"));
        headText->setGeometry(QRect(10, 10, 771, 41));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        headText->setFont(font1);
        headText->setStyleSheet(QString::fromUtf8("QLabel#headText {\n"
"\n"
"	background-color: #FFC300;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        headText->setAlignment(Qt::AlignCenter);
        deleteButton = new QPushButton(AuditoriumDeleteForm);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(true);
        deleteButton->setGeometry(QRect(10, 240, 381, 51));
        QFont font2;
        font2.setPointSize(16);
        deleteButton->setFont(font2);
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
        logHead = new QLabel(AuditoriumDeleteForm);
        logHead->setObjectName(QString::fromUtf8("logHead"));
        logHead->setGeometry(QRect(10, 110, 771, 41));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setWeight(50);
        logHead->setFont(font3);
        logHead->setStyleSheet(QString::fromUtf8("QLabel#logHead {\n"
"\n"
"	background-color: #FFC300;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        logHead->setAlignment(Qt::AlignCenter);
        logText = new QTextEdit(AuditoriumDeleteForm);
        logText->setObjectName(QString::fromUtf8("logText"));
        logText->setGeometry(QRect(10, 160, 771, 71));
        QFont font4;
        font4.setPointSize(10);
        logText->setFont(font4);
        logText->setStyleSheet(QString::fromUtf8("QTextEdit#logText {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        exitButton = new QPushButton(AuditoriumDeleteForm);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(400, 240, 381, 51));
        exitButton->setMinimumSize(QSize(381, 51));
        exitButton->setMaximumSize(QSize(381, 51));
        exitButton->setFont(font2);
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
        floorBox = new QComboBox(AuditoriumDeleteForm);
        floorBox->setObjectName(QString::fromUtf8("floorBox"));
        floorBox->setEnabled(true);
        floorBox->setGeometry(QRect(410, 60, 181, 41));
        floorBox->setFont(font);
        floorBox->setStyleSheet(QString::fromUtf8("QComboBox#floorBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        numberBox = new QComboBox(AuditoriumDeleteForm);
        numberBox->setObjectName(QString::fromUtf8("numberBox"));
        numberBox->setEnabled(true);
        numberBox->setGeometry(QRect(600, 60, 181, 41));
        numberBox->setFont(font);
        numberBox->setStyleSheet(QString::fromUtf8("QComboBox#numberBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));

        retranslateUi(AuditoriumDeleteForm);

        QMetaObject::connectSlotsByName(AuditoriumDeleteForm);
    } // setupUi

    void retranslateUi(QWidget *AuditoriumDeleteForm)
    {
        AuditoriumDeleteForm->setWindowTitle(QApplication::translate("AuditoriumDeleteForm", "\320\220\321\203\320\264\320\270\321\202\320\276\321\200\320\270\321\217, \321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        text1->setText(QApplication::translate("AuditoriumDeleteForm", "\320\232\320\276\321\200\320\277\321\203\321\201 - \321\215\321\202\320\260\320\266 - \320\275\320\276\320\274\320\265\321\200", nullptr));
        headText->setText(QApplication::translate("AuditoriumDeleteForm", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\260\321\203\320\264\320\270\321\202\320\276\321\200\320\270\320\270", nullptr));
        deleteButton->setText(QApplication::translate("AuditoriumDeleteForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        logHead->setText(QApplication::translate("AuditoriumDeleteForm", "\320\233\320\276\320\263 \320\276\321\210\320\270\320\261\320\276\320\272 \320\270 \320\277\321\200\320\265\320\264\321\203\320\277\321\200\320\265\320\266\320\264\320\265\320\275\320\270\320\271", nullptr));
        exitButton->setText(QApplication::translate("AuditoriumDeleteForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuditoriumDeleteForm: public Ui_AuditoriumDeleteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDITORIUMDELETEFORM_H
