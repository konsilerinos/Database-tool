/********************************************************************************
** Form generated from reading UI file 'lessondeleteform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LESSONDELETEFORM_H
#define UI_LESSONDELETEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LessonDeleteForm
{
public:
    QComboBox *dayBox;
    QComboBox *typeBox;
    QTextEdit *logText;
    QLabel *headText;
    QComboBox *IDBox;
    QPushButton *exitButton;
    QLabel *logHead;
    QLabel *text1;
    QComboBox *yearBox;
    QLabel *text2;
    QComboBox *monthBox;
    QComboBox *timeBox;
    QPushButton *deleteButton;

    void setupUi(QWidget *LessonDeleteForm)
    {
        if (LessonDeleteForm->objectName().isEmpty())
            LessonDeleteForm->setObjectName(QString::fromUtf8("LessonDeleteForm"));
        LessonDeleteForm->resize(791, 351);
        LessonDeleteForm->setMinimumSize(QSize(791, 351));
        LessonDeleteForm->setMaximumSize(QSize(791, 351));
        LessonDeleteForm->setStyleSheet(QString::fromUtf8("QWidget#LessonDeleteForm {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        dayBox = new QComboBox(LessonDeleteForm);
        dayBox->setObjectName(QString::fromUtf8("dayBox"));
        dayBox->setGeometry(QRect(190, 60, 121, 41));
        QFont font;
        font.setPointSize(14);
        dayBox->setFont(font);
        dayBox->setStyleSheet(QString::fromUtf8("QComboBox#dayBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        typeBox = new QComboBox(LessonDeleteForm);
        typeBox->setObjectName(QString::fromUtf8("typeBox"));
        typeBox->setGeometry(QRect(190, 110, 471, 41));
        typeBox->setFont(font);
        typeBox->setStyleSheet(QString::fromUtf8("QComboBox#typeBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        logText = new QTextEdit(LessonDeleteForm);
        logText->setObjectName(QString::fromUtf8("logText"));
        logText->setGeometry(QRect(10, 210, 771, 71));
        QFont font1;
        font1.setPointSize(10);
        logText->setFont(font1);
        logText->setStyleSheet(QString::fromUtf8("QTextEdit#logText {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        headText = new QLabel(LessonDeleteForm);
        headText->setObjectName(QString::fromUtf8("headText"));
        headText->setGeometry(QRect(10, 10, 771, 41));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        headText->setFont(font2);
        headText->setStyleSheet(QString::fromUtf8("QLabel#headText {\n"
"\n"
"	background-color: #FFC300;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        headText->setAlignment(Qt::AlignCenter);
        IDBox = new QComboBox(LessonDeleteForm);
        IDBox->setObjectName(QString::fromUtf8("IDBox"));
        IDBox->setGeometry(QRect(670, 110, 111, 41));
        IDBox->setFont(font);
        IDBox->setStyleSheet(QString::fromUtf8("QComboBox#IDBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        exitButton = new QPushButton(LessonDeleteForm);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(400, 290, 381, 51));
        QFont font3;
        font3.setPointSize(16);
        exitButton->setFont(font3);
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
        logHead = new QLabel(LessonDeleteForm);
        logHead->setObjectName(QString::fromUtf8("logHead"));
        logHead->setGeometry(QRect(10, 160, 771, 41));
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
        text1 = new QLabel(LessonDeleteForm);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 60, 171, 41));
        text1->setFont(font);
        text1->setStyleSheet(QString::fromUtf8("QLabel#text1 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        yearBox = new QComboBox(LessonDeleteForm);
        yearBox->setObjectName(QString::fromUtf8("yearBox"));
        yearBox->setGeometry(QRect(520, 60, 141, 41));
        yearBox->setFont(font);
        yearBox->setStyleSheet(QString::fromUtf8("QComboBox#yearBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text2 = new QLabel(LessonDeleteForm);
        text2->setObjectName(QString::fromUtf8("text2"));
        text2->setGeometry(QRect(10, 110, 171, 41));
        text2->setFont(font);
        text2->setStyleSheet(QString::fromUtf8("QLabel#text2 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        monthBox = new QComboBox(LessonDeleteForm);
        monthBox->setObjectName(QString::fromUtf8("monthBox"));
        monthBox->setGeometry(QRect(320, 60, 191, 41));
        monthBox->setFont(font);
        monthBox->setStyleSheet(QString::fromUtf8("QComboBox#monthBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        timeBox = new QComboBox(LessonDeleteForm);
        timeBox->setObjectName(QString::fromUtf8("timeBox"));
        timeBox->setGeometry(QRect(670, 60, 111, 41));
        timeBox->setFont(font);
        timeBox->setStyleSheet(QString::fromUtf8("QComboBox#timeBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        deleteButton = new QPushButton(LessonDeleteForm);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(true);
        deleteButton->setGeometry(QRect(10, 290, 381, 51));
        deleteButton->setFont(font3);
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
""));

        retranslateUi(LessonDeleteForm);

        QMetaObject::connectSlotsByName(LessonDeleteForm);
    } // setupUi

    void retranslateUi(QWidget *LessonDeleteForm)
    {
        LessonDeleteForm->setWindowTitle(QApplication::translate("LessonDeleteForm", "\320\227\320\260\320\275\321\217\321\202\320\270\320\265, \321\203\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        headText->setText(QApplication::translate("LessonDeleteForm", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \320\267\320\260\320\275\321\217\321\202\320\270\321\217", nullptr));
        exitButton->setText(QApplication::translate("LessonDeleteForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        logHead->setText(QApplication::translate("LessonDeleteForm", "\320\233\320\276\320\263 \320\276\321\210\320\270\320\261\320\276\320\272 \320\270 \320\277\321\200\320\265\320\264\321\203\320\277\321\200\320\265\320\266\320\264\320\265\320\275\320\270\320\271", nullptr));
        text1->setText(QApplication::translate("LessonDeleteForm", "\320\224\320\265\320\275\321\214 / \320\262\321\200\320\265\320\274\321\217", nullptr));
        text2->setText(QApplication::translate("LessonDeleteForm", "\320\242\320\270\320\277 / \320\230\320\224", nullptr));
        deleteButton->setText(QApplication::translate("LessonDeleteForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LessonDeleteForm: public Ui_LessonDeleteForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LESSONDELETEFORM_H
