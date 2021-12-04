/********************************************************************************
** Form generated from reading UI file 'subjectinsertform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBJECTINSERTFORM_H
#define UI_SUBJECTINSERTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubjectInsertForm
{
public:
    QLabel *headText;
    QLineEdit *IDLine;
    QLabel *text1;
    QLabel *text2;
    QLineEdit *nameLine;
    QLabel *text3;
    QLineEdit *shortNameLine;
    QLabel *countLabel;
    QSlider *countSlider;
    QLabel *text4;
    QTextEdit *logText;
    QLabel *logHead;
    QPushButton *addingButton;
    QPushButton *exitButton;

    void setupUi(QWidget *SubjectInsertForm)
    {
        if (SubjectInsertForm->objectName().isEmpty())
            SubjectInsertForm->setObjectName(QString::fromUtf8("SubjectInsertForm"));
        SubjectInsertForm->resize(791, 451);
        SubjectInsertForm->setMinimumSize(QSize(791, 451));
        SubjectInsertForm->setMaximumSize(QSize(791, 451));
        SubjectInsertForm->setStyleSheet(QString::fromUtf8("QWidget#SubjectInsertForm {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        headText = new QLabel(SubjectInsertForm);
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
        IDLine = new QLineEdit(SubjectInsertForm);
        IDLine->setObjectName(QString::fromUtf8("IDLine"));
        IDLine->setEnabled(false);
        IDLine->setGeometry(QRect(280, 60, 501, 41));
        QFont font1;
        font1.setPointSize(14);
        IDLine->setFont(font1);
        IDLine->setStyleSheet(QString::fromUtf8("QLineEdit#IDLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        IDLine->setAlignment(Qt::AlignCenter);
        text1 = new QLabel(SubjectInsertForm);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 60, 261, 41));
        text1->setFont(font1);
        text1->setStyleSheet(QString::fromUtf8("QLabel#text1 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        text2 = new QLabel(SubjectInsertForm);
        text2->setObjectName(QString::fromUtf8("text2"));
        text2->setGeometry(QRect(10, 110, 261, 41));
        text2->setFont(font1);
        text2->setStyleSheet(QString::fromUtf8("QLabel#text2 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        nameLine = new QLineEdit(SubjectInsertForm);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));
        nameLine->setEnabled(true);
        nameLine->setGeometry(QRect(280, 110, 501, 41));
        nameLine->setFont(font1);
        nameLine->setStyleSheet(QString::fromUtf8("QLineEdit#nameLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        nameLine->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        text3 = new QLabel(SubjectInsertForm);
        text3->setObjectName(QString::fromUtf8("text3"));
        text3->setGeometry(QRect(10, 160, 261, 41));
        text3->setFont(font1);
        text3->setStyleSheet(QString::fromUtf8("QLabel#text3 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        shortNameLine = new QLineEdit(SubjectInsertForm);
        shortNameLine->setObjectName(QString::fromUtf8("shortNameLine"));
        shortNameLine->setEnabled(true);
        shortNameLine->setGeometry(QRect(280, 160, 501, 41));
        shortNameLine->setFont(font1);
        shortNameLine->setStyleSheet(QString::fromUtf8("QLineEdit#shortNameLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        shortNameLine->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        countLabel = new QLabel(SubjectInsertForm);
        countLabel->setObjectName(QString::fromUtf8("countLabel"));
        countLabel->setGeometry(QRect(700, 210, 81, 41));
        countLabel->setFont(font1);
        countLabel->setStyleSheet(QString::fromUtf8("QLabel#countLabel {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        countLabel->setAlignment(Qt::AlignCenter);
        countSlider = new QSlider(SubjectInsertForm);
        countSlider->setObjectName(QString::fromUtf8("countSlider"));
        countSlider->setGeometry(QRect(279, 211, 411, 41));
        countSlider->setStyleSheet(QString::fromUtf8("QSlider#countSlider::handle:horizontal {\n"
"background: #FFFFFF;\n"
"}\n"
"\n"
"QSlider#countSlider::handle:horizontal:hover {\n"
"background: #FFC300;\n"
"}\n"
"\n"
"QSlider#countSlider::handle:horizontal:pressed {\n"
"background: #3976A0;\n"
"}"));
        countSlider->setOrientation(Qt::Horizontal);
        text4 = new QLabel(SubjectInsertForm);
        text4->setObjectName(QString::fromUtf8("text4"));
        text4->setGeometry(QRect(10, 210, 261, 41));
        text4->setFont(font1);
        text4->setStyleSheet(QString::fromUtf8("QLabel#text4 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        logText = new QTextEdit(SubjectInsertForm);
        logText->setObjectName(QString::fromUtf8("logText"));
        logText->setGeometry(QRect(10, 310, 771, 71));
        QFont font2;
        font2.setPointSize(10);
        logText->setFont(font2);
        logText->setStyleSheet(QString::fromUtf8("QTextEdit#logText {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        logHead = new QLabel(SubjectInsertForm);
        logHead->setObjectName(QString::fromUtf8("logHead"));
        logHead->setGeometry(QRect(10, 260, 771, 41));
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
        addingButton = new QPushButton(SubjectInsertForm);
        addingButton->setObjectName(QString::fromUtf8("addingButton"));
        addingButton->setEnabled(false);
        addingButton->setGeometry(QRect(10, 390, 381, 51));
        QFont font4;
        font4.setPointSize(16);
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
"QPushButton#addingButton:disabled {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #4B7089;\n"
"	border: 5px solid #4B7089;\n"
"}"));
        exitButton = new QPushButton(SubjectInsertForm);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(400, 390, 381, 51));
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

        retranslateUi(SubjectInsertForm);

        QMetaObject::connectSlotsByName(SubjectInsertForm);
    } // setupUi

    void retranslateUi(QWidget *SubjectInsertForm)
    {
        SubjectInsertForm->setWindowTitle(QApplication::translate("SubjectInsertForm", "\320\237\321\200\320\265\320\264\320\274\320\265\321\202, \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        headText->setText(QApplication::translate("SubjectInsertForm", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\320\260", nullptr));
        text1->setText(QApplication::translate("SubjectInsertForm", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\206\320\270\320\276\320\275\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200*", nullptr));
        text2->setText(QApplication::translate("SubjectInsertForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\320\260", nullptr));
        text3->setText(QApplication::translate("SubjectInsertForm", "\320\241\320\276\320\272\321\200\320\260\321\211\321\221\320\275\320\275\320\276\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        countLabel->setText(QApplication::translate("SubjectInsertForm", "10", nullptr));
        text4->setText(QApplication::translate("SubjectInsertForm", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\207\320\260\321\201\320\276\320\262", nullptr));
        logHead->setText(QApplication::translate("SubjectInsertForm", "\320\233\320\276\320\263 \320\276\321\210\320\270\320\261\320\276\320\272 \320\270 \320\277\321\200\320\265\320\264\321\203\320\277\321\200\320\265\320\266\320\264\320\265\320\275\320\270\320\271", nullptr));
        addingButton->setText(QApplication::translate("SubjectInsertForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        exitButton->setText(QApplication::translate("SubjectInsertForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubjectInsertForm: public Ui_SubjectInsertForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBJECTINSERTFORM_H
