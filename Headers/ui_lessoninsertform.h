/********************************************************************************
** Form generated from reading UI file 'lessoninsertform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LESSONINSERTFORM_H
#define UI_LESSONINSERTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LessonInsertForm
{
public:
    QLabel *headText;
    QComboBox *dayBox;
    QLabel *text1;
    QComboBox *yearBox;
    QComboBox *monthBox;
    QLabel *text2;
    QComboBox *timeBox;
    QComboBox *typeBox;
    QLabel *text3;
    QComboBox *floorBox;
    QComboBox *bodyBox;
    QComboBox *numberBox;
    QComboBox *groupBox;
    QLabel *text4;
    QLabel *logHead;
    QTextEdit *logText;
    QPushButton *exitButton;
    QPushButton *addingButton;
    QComboBox *IDBox;

    void setupUi(QWidget *LessonInsertForm)
    {
        if (LessonInsertForm->objectName().isEmpty())
            LessonInsertForm->setObjectName(QString::fromUtf8("LessonInsertForm"));
        LessonInsertForm->resize(791, 451);
        LessonInsertForm->setMinimumSize(QSize(791, 451));
        LessonInsertForm->setMaximumSize(QSize(791, 451));
        LessonInsertForm->setStyleSheet(QString::fromUtf8("QWidget#LessonInsertForm {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        headText = new QLabel(LessonInsertForm);
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
        dayBox = new QComboBox(LessonInsertForm);
        dayBox->setObjectName(QString::fromUtf8("dayBox"));
        dayBox->setGeometry(QRect(190, 60, 121, 41));
        QFont font1;
        font1.setPointSize(14);
        dayBox->setFont(font1);
        dayBox->setStyleSheet(QString::fromUtf8("QComboBox#dayBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text1 = new QLabel(LessonInsertForm);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 60, 171, 41));
        text1->setFont(font1);
        text1->setStyleSheet(QString::fromUtf8("QLabel#text1 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        yearBox = new QComboBox(LessonInsertForm);
        yearBox->setObjectName(QString::fromUtf8("yearBox"));
        yearBox->setGeometry(QRect(520, 60, 141, 41));
        yearBox->setFont(font1);
        yearBox->setStyleSheet(QString::fromUtf8("QComboBox#yearBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        monthBox = new QComboBox(LessonInsertForm);
        monthBox->setObjectName(QString::fromUtf8("monthBox"));
        monthBox->setGeometry(QRect(320, 60, 191, 41));
        monthBox->setFont(font1);
        monthBox->setStyleSheet(QString::fromUtf8("QComboBox#monthBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text2 = new QLabel(LessonInsertForm);
        text2->setObjectName(QString::fromUtf8("text2"));
        text2->setGeometry(QRect(10, 110, 171, 41));
        text2->setFont(font1);
        text2->setStyleSheet(QString::fromUtf8("QLabel#text2 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        timeBox = new QComboBox(LessonInsertForm);
        timeBox->setObjectName(QString::fromUtf8("timeBox"));
        timeBox->setGeometry(QRect(670, 60, 111, 41));
        timeBox->setFont(font1);
        timeBox->setStyleSheet(QString::fromUtf8("QComboBox#timeBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        typeBox = new QComboBox(LessonInsertForm);
        typeBox->setObjectName(QString::fromUtf8("typeBox"));
        typeBox->setGeometry(QRect(190, 110, 471, 41));
        typeBox->setFont(font1);
        typeBox->setStyleSheet(QString::fromUtf8("QComboBox#typeBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text3 = new QLabel(LessonInsertForm);
        text3->setObjectName(QString::fromUtf8("text3"));
        text3->setGeometry(QRect(10, 160, 171, 41));
        text3->setFont(font1);
        text3->setStyleSheet(QString::fromUtf8("QLabel#text3 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        floorBox = new QComboBox(LessonInsertForm);
        floorBox->setObjectName(QString::fromUtf8("floorBox"));
        floorBox->setGeometry(QRect(390, 160, 191, 41));
        floorBox->setFont(font1);
        floorBox->setStyleSheet(QString::fromUtf8("QComboBox#floorBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        bodyBox = new QComboBox(LessonInsertForm);
        bodyBox->setObjectName(QString::fromUtf8("bodyBox"));
        bodyBox->setGeometry(QRect(190, 160, 191, 41));
        bodyBox->setFont(font1);
        bodyBox->setStyleSheet(QString::fromUtf8("QComboBox#bodyBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        numberBox = new QComboBox(LessonInsertForm);
        numberBox->setObjectName(QString::fromUtf8("numberBox"));
        numberBox->setGeometry(QRect(590, 160, 191, 41));
        numberBox->setFont(font1);
        numberBox->setStyleSheet(QString::fromUtf8("QComboBox#numberBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        groupBox = new QComboBox(LessonInsertForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(190, 210, 591, 41));
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("QComboBox#groupBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text4 = new QLabel(LessonInsertForm);
        text4->setObjectName(QString::fromUtf8("text4"));
        text4->setGeometry(QRect(10, 210, 171, 41));
        text4->setFont(font1);
        text4->setStyleSheet(QString::fromUtf8("QLabel#text4 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        logHead = new QLabel(LessonInsertForm);
        logHead->setObjectName(QString::fromUtf8("logHead"));
        logHead->setGeometry(QRect(10, 260, 771, 41));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setWeight(50);
        logHead->setFont(font2);
        logHead->setStyleSheet(QString::fromUtf8("QLabel#logHead {\n"
"\n"
"	background-color: #FFC300;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        logHead->setAlignment(Qt::AlignCenter);
        logText = new QTextEdit(LessonInsertForm);
        logText->setObjectName(QString::fromUtf8("logText"));
        logText->setGeometry(QRect(10, 310, 771, 71));
        QFont font3;
        font3.setPointSize(10);
        logText->setFont(font3);
        logText->setStyleSheet(QString::fromUtf8("QTextEdit#logText {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        exitButton = new QPushButton(LessonInsertForm);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(400, 390, 381, 51));
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
        addingButton = new QPushButton(LessonInsertForm);
        addingButton->setObjectName(QString::fromUtf8("addingButton"));
        addingButton->setEnabled(true);
        addingButton->setGeometry(QRect(10, 390, 381, 51));
        addingButton->setFont(font4);
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
""));
        IDBox = new QComboBox(LessonInsertForm);
        IDBox->setObjectName(QString::fromUtf8("IDBox"));
        IDBox->setGeometry(QRect(670, 110, 111, 41));
        IDBox->setFont(font1);
        IDBox->setStyleSheet(QString::fromUtf8("QComboBox#IDBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));

        retranslateUi(LessonInsertForm);

        QMetaObject::connectSlotsByName(LessonInsertForm);
    } // setupUi

    void retranslateUi(QWidget *LessonInsertForm)
    {
        LessonInsertForm->setWindowTitle(QApplication::translate("LessonInsertForm", "\320\227\320\260\320\275\321\217\321\202\320\270\320\265, \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        headText->setText(QApplication::translate("LessonInsertForm", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \320\267\320\260\320\275\321\217\321\202\320\270\321\217", nullptr));
        text1->setText(QApplication::translate("LessonInsertForm", "\320\224\320\265\320\275\321\214 / \320\262\321\200\320\265\320\274\321\217", nullptr));
        text2->setText(QApplication::translate("LessonInsertForm", "\320\242\320\270\320\277 / \320\230\320\224", nullptr));
        text3->setText(QApplication::translate("LessonInsertForm", "\320\220\321\203\320\264\320\270\321\202\320\276\321\200\320\270\321\217 (\320\272-\321\215-\320\275)", nullptr));
        text4->setText(QApplication::translate("LessonInsertForm", "\320\235\320\276\320\274\320\265\321\200 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        logHead->setText(QApplication::translate("LessonInsertForm", "\320\233\320\276\320\263 \320\276\321\210\320\270\320\261\320\276\320\272 \320\270 \320\277\321\200\320\265\320\264\321\203\320\277\321\200\320\265\320\266\320\264\320\265\320\275\320\270\320\271", nullptr));
        exitButton->setText(QApplication::translate("LessonInsertForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        addingButton->setText(QApplication::translate("LessonInsertForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LessonInsertForm: public Ui_LessonInsertForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LESSONINSERTFORM_H
