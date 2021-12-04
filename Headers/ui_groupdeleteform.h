/********************************************************************************
** Form generated from reading UI file 'groupdeleteform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPDELETEFORM_H
#define UI_GROUPDELETEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupDeleteForm
{
public:
    QLabel *headText;
    QPushButton *deleteButton;
    QPushButton *exitButton;
    QTextEdit *logText;
    QComboBox *groupBox;
    QLabel *text1;
    QLabel *logHead;

    void setupUi(QWidget *GroupDeleteForm)
    {
        if (GroupDeleteForm->objectName().isEmpty())
            GroupDeleteForm->setObjectName(QString::fromUtf8("GroupDeleteForm"));
        GroupDeleteForm->resize(791, 301);
        GroupDeleteForm->setMinimumSize(QSize(791, 301));
        GroupDeleteForm->setMaximumSize(QSize(791, 301));
        GroupDeleteForm->setStyleSheet(QString::fromUtf8("QWidget#GroupDeleteForm {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        headText = new QLabel(GroupDeleteForm);
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
        deleteButton = new QPushButton(GroupDeleteForm);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(true);
        deleteButton->setGeometry(QRect(10, 240, 381, 51));
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
        exitButton = new QPushButton(GroupDeleteForm);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(400, 240, 381, 51));
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
        logText = new QTextEdit(GroupDeleteForm);
        logText->setObjectName(QString::fromUtf8("logText"));
        logText->setGeometry(QRect(10, 160, 771, 71));
        QFont font2;
        font2.setPointSize(10);
        logText->setFont(font2);
        logText->setStyleSheet(QString::fromUtf8("QTextEdit#logText {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        groupBox = new QComboBox(GroupDeleteForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(160, 60, 621, 41));
        QFont font3;
        font3.setPointSize(14);
        groupBox->setFont(font3);
        groupBox->setStyleSheet(QString::fromUtf8("QComboBox#groupBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text1 = new QLabel(GroupDeleteForm);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 60, 141, 41));
        text1->setFont(font3);
        text1->setStyleSheet(QString::fromUtf8("QLabel#text1 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        logHead = new QLabel(GroupDeleteForm);
        logHead->setObjectName(QString::fromUtf8("logHead"));
        logHead->setGeometry(QRect(10, 110, 771, 41));
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

        retranslateUi(GroupDeleteForm);

        QMetaObject::connectSlotsByName(GroupDeleteForm);
    } // setupUi

    void retranslateUi(QWidget *GroupDeleteForm)
    {
        GroupDeleteForm->setWindowTitle(QApplication::translate("GroupDeleteForm", "\320\223\321\200\321\203\320\277\320\277\320\260, \321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        headText->setText(QApplication::translate("GroupDeleteForm", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        deleteButton->setText(QApplication::translate("GroupDeleteForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        exitButton->setText(QApplication::translate("GroupDeleteForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        text1->setText(QApplication::translate("GroupDeleteForm", "\320\235\320\276\320\274\320\265\321\200 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        logHead->setText(QApplication::translate("GroupDeleteForm", "\320\233\320\276\320\263 \320\276\321\210\320\270\320\261\320\276\320\272 \320\270 \320\277\321\200\320\265\320\264\321\203\320\277\321\200\320\265\320\266\320\264\320\265\320\275\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupDeleteForm: public Ui_GroupDeleteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPDELETEFORM_H
