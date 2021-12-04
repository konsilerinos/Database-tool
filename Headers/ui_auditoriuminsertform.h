/********************************************************************************
** Form generated from reading UI file 'auditoriuminsertform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDITORIUMINSERTFORM_H
#define UI_AUDITORIUMINSERTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuditoriumInsertForm
{
public:
    QLabel *headText;
    QLineEdit *bodyLine;
    QLabel *text1;
    QLabel *text2;
    QComboBox *typeBox;
    QLabel *typeLabel;
    QLineEdit *floorLine;
    QLineEdit *numberLine;
    QPushButton *exitButton;
    QPushButton *addingButton;
    QLabel *logHead;
    QTextEdit *logText;

    void setupUi(QWidget *AuditoriumInsertForm)
    {
        if (AuditoriumInsertForm->objectName().isEmpty())
            AuditoriumInsertForm->setObjectName(QString::fromUtf8("AuditoriumInsertForm"));
        AuditoriumInsertForm->resize(791, 351);
        AuditoriumInsertForm->setMinimumSize(QSize(791, 351));
        AuditoriumInsertForm->setMaximumSize(QSize(791, 351));
        AuditoriumInsertForm->setStyleSheet(QString::fromUtf8("QWidget#AuditoriumInsertForm {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        headText = new QLabel(AuditoriumInsertForm);
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
        bodyLine = new QLineEdit(AuditoriumInsertForm);
        bodyLine->setObjectName(QString::fromUtf8("bodyLine"));
        bodyLine->setEnabled(true);
        bodyLine->setGeometry(QRect(280, 60, 161, 41));
        QFont font1;
        font1.setPointSize(14);
        bodyLine->setFont(font1);
        bodyLine->setStyleSheet(QString::fromUtf8("QLineEdit#bodyLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        bodyLine->setAlignment(Qt::AlignCenter);
        text1 = new QLabel(AuditoriumInsertForm);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 60, 261, 41));
        text1->setFont(font1);
        text1->setStyleSheet(QString::fromUtf8("QLabel#text1 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        text2 = new QLabel(AuditoriumInsertForm);
        text2->setObjectName(QString::fromUtf8("text2"));
        text2->setGeometry(QRect(10, 110, 261, 41));
        text2->setFont(font1);
        text2->setStyleSheet(QString::fromUtf8("QLabel#text2 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        typeBox = new QComboBox(AuditoriumInsertForm);
        typeBox->setObjectName(QString::fromUtf8("typeBox"));
        typeBox->setGeometry(QRect(280, 110, 411, 41));
        typeBox->setFont(font1);
        typeBox->setStyleSheet(QString::fromUtf8("QComboBox#typeBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        typeLabel = new QLabel(AuditoriumInsertForm);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        typeLabel->setGeometry(QRect(700, 110, 81, 41));
        typeLabel->setFont(font1);
        typeLabel->setStyleSheet(QString::fromUtf8("QLabel#typeLabel {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        typeLabel->setAlignment(Qt::AlignCenter);
        floorLine = new QLineEdit(AuditoriumInsertForm);
        floorLine->setObjectName(QString::fromUtf8("floorLine"));
        floorLine->setEnabled(true);
        floorLine->setGeometry(QRect(450, 60, 161, 41));
        floorLine->setFont(font1);
        floorLine->setStyleSheet(QString::fromUtf8("QLineEdit#floorLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        floorLine->setAlignment(Qt::AlignCenter);
        numberLine = new QLineEdit(AuditoriumInsertForm);
        numberLine->setObjectName(QString::fromUtf8("numberLine"));
        numberLine->setEnabled(true);
        numberLine->setGeometry(QRect(620, 60, 161, 41));
        numberLine->setFont(font1);
        numberLine->setStyleSheet(QString::fromUtf8("QLineEdit#numberLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        numberLine->setAlignment(Qt::AlignCenter);
        exitButton = new QPushButton(AuditoriumInsertForm);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(400, 290, 381, 51));
        exitButton->setMinimumSize(QSize(381, 51));
        exitButton->setMaximumSize(QSize(381, 51));
        QFont font2;
        font2.setPointSize(16);
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
        addingButton = new QPushButton(AuditoriumInsertForm);
        addingButton->setObjectName(QString::fromUtf8("addingButton"));
        addingButton->setEnabled(false);
        addingButton->setGeometry(QRect(10, 290, 381, 51));
        addingButton->setFont(font2);
        addingButton->setStyleSheet(QString::fromUtf8("QPushButton#addingButton {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #FFFFFF;\n"
"}\n"
"QPushButton#addingButton:hover {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
"QPushButton#addingButton:pressed {\n"
"\n"
"	background-color: #DB1921;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
"QPushButton#addingButton:disabled {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #4B7089;\n"
"	border: 5px solid #4B7089;\n"
"}"));
        logHead = new QLabel(AuditoriumInsertForm);
        logHead->setObjectName(QString::fromUtf8("logHead"));
        logHead->setGeometry(QRect(10, 160, 771, 41));
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
        logText = new QTextEdit(AuditoriumInsertForm);
        logText->setObjectName(QString::fromUtf8("logText"));
        logText->setGeometry(QRect(10, 210, 771, 71));
        QFont font4;
        font4.setPointSize(10);
        logText->setFont(font4);
        logText->setStyleSheet(QString::fromUtf8("QTextEdit#logText {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));

        retranslateUi(AuditoriumInsertForm);

        QMetaObject::connectSlotsByName(AuditoriumInsertForm);
    } // setupUi

    void retranslateUi(QWidget *AuditoriumInsertForm)
    {
        AuditoriumInsertForm->setWindowTitle(QApplication::translate("AuditoriumInsertForm", "\320\220\321\203\320\264\320\270\321\202\320\276\321\200\320\270\321\217, \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        headText->setText(QApplication::translate("AuditoriumInsertForm", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\271 \320\260\321\203\320\264\320\270\321\202\320\276\321\200\320\270\320\270", nullptr));
        text1->setText(QApplication::translate("AuditoriumInsertForm", "\320\232\320\276\321\200\320\277\321\203\321\201, \321\215\321\202\320\260\320\266, \320\275\320\276\320\274\320\265\321\200", nullptr));
        text2->setText(QApplication::translate("AuditoriumInsertForm", "\320\242\320\270\320\277, \320\262\320\274\320\265\321\201\321\202\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        typeLabel->setText(QApplication::translate("AuditoriumInsertForm", "5", nullptr));
        exitButton->setText(QApplication::translate("AuditoriumInsertForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        addingButton->setText(QApplication::translate("AuditoriumInsertForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        logHead->setText(QApplication::translate("AuditoriumInsertForm", "\320\233\320\276\320\263 \320\276\321\210\320\270\320\261\320\276\320\272 \320\270 \320\277\321\200\320\265\320\264\321\203\320\277\321\200\320\265\320\266\320\264\320\265\320\275\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuditoriumInsertForm: public Ui_AuditoriumInsertForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDITORIUMINSERTFORM_H
