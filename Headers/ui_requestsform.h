/********************************************************************************
** Form generated from reading UI file 'requestsform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQUESTSFORM_H
#define UI_REQUESTSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RequestsForm
{
public:
    QLabel *headText;
    QLabel *text7;
    QComboBox *requestsBox;
    QTextEdit *sqlText;
    QLabel *sqlHeadtext;
    QPushButton *exitButton;
    QPushButton *generateButton;

    void setupUi(QWidget *RequestsForm)
    {
        if (RequestsForm->objectName().isEmpty())
            RequestsForm->setObjectName(QString::fromUtf8("RequestsForm"));
        RequestsForm->resize(791, 351);
        RequestsForm->setMinimumSize(QSize(791, 351));
        RequestsForm->setMaximumSize(QSize(791, 351));
        RequestsForm->setStyleSheet(QString::fromUtf8("QWidget#RequestsForm {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        headText = new QLabel(RequestsForm);
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
        text7 = new QLabel(RequestsForm);
        text7->setObjectName(QString::fromUtf8("text7"));
        text7->setGeometry(QRect(10, 60, 161, 41));
        QFont font1;
        font1.setPointSize(14);
        text7->setFont(font1);
        text7->setStyleSheet(QString::fromUtf8("QLabel#text7 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        requestsBox = new QComboBox(RequestsForm);
        requestsBox->setObjectName(QString::fromUtf8("requestsBox"));
        requestsBox->setGeometry(QRect(180, 60, 601, 41));
        requestsBox->setFont(font1);
        requestsBox->setStyleSheet(QString::fromUtf8("QComboBox#requestsBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        sqlText = new QTextEdit(RequestsForm);
        sqlText->setObjectName(QString::fromUtf8("sqlText"));
        sqlText->setGeometry(QRect(10, 160, 771, 121));
        QFont font2;
        font2.setPointSize(10);
        sqlText->setFont(font2);
        sqlText->setStyleSheet(QString::fromUtf8("QTextEdit#sqlText {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        sqlHeadtext = new QLabel(RequestsForm);
        sqlHeadtext->setObjectName(QString::fromUtf8("sqlHeadtext"));
        sqlHeadtext->setGeometry(QRect(10, 110, 771, 41));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setWeight(50);
        sqlHeadtext->setFont(font3);
        sqlHeadtext->setStyleSheet(QString::fromUtf8("QLabel#sqlHeadtext {\n"
"\n"
"	background-color: #FFC300;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        sqlHeadtext->setAlignment(Qt::AlignCenter);
        exitButton = new QPushButton(RequestsForm);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(400, 290, 381, 51));
        QFont font4;
        font4.setPointSize(16);
        exitButton->setFont(font4);
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
        generateButton = new QPushButton(RequestsForm);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        generateButton->setEnabled(true);
        generateButton->setGeometry(QRect(10, 290, 381, 51));
        generateButton->setFont(font4);
        generateButton->setStyleSheet(QString::fromUtf8("QPushButton#generateButton {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #FFFFFF;\n"
"}\n"
"QPushButton#generateButton:hover {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
"QPushButton#generateButton:pressed {\n"
"\n"
"	background-color: #DB1921;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
""));

        retranslateUi(RequestsForm);

        QMetaObject::connectSlotsByName(RequestsForm);
    } // setupUi

    void retranslateUi(QWidget *RequestsForm)
    {
        RequestsForm->setWindowTitle(QApplication::translate("RequestsForm", "\320\227\320\260\320\277\321\200\320\276\321\201\321\213, \320\262\321\213\320\261\320\276\321\200", nullptr));
        headText->setText(QApplication::translate("RequestsForm", "\320\227\320\260\320\277\321\200\320\276\321\201\321\213", nullptr));
        text7->setText(QApplication::translate("RequestsForm", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\267\320\260\320\277\321\200\320\276\321\201", nullptr));
        sqlHeadtext->setText(QApplication::translate("RequestsForm", "\320\237\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\277\321\200\320\276\321\201\320\260 \320\275\320\260 \321\217\320\267\321\213\320\272\320\265 SQL", nullptr));
        exitButton->setText(QApplication::translate("RequestsForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        generateButton->setText(QApplication::translate("RequestsForm", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RequestsForm: public Ui_RequestsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUESTSFORM_H
