/********************************************************************************
** Form generated from reading UI file 'teacherinsertform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERINSERTFORM_H
#define UI_TEACHERINSERTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherInsertForm
{
public:
    QLabel *headText;
    QLineEdit *IDLabel;
    QLabel *text1;
    QLineEdit *lastNameLine;
    QLabel *text2;
    QLineEdit *nameLine;
    QLabel *text3;
    QLabel *text4;
    QLineEdit *patronymicLine;
    QComboBox *postBox;
    QLabel *text5;
    QSlider *countSlider;
    QLabel *text6;
    QLabel *countLabel;
    QComboBox *departmentBox;
    QLabel *text7;
    QTextEdit *logText;
    QLabel *logHead;
    QPushButton *addingButton;
    QPushButton *exitButton;
    QLabel *departmentIDLabel;

    void setupUi(QWidget *TeacherInsertForm)
    {
        if (TeacherInsertForm->objectName().isEmpty())
            TeacherInsertForm->setObjectName(QString::fromUtf8("TeacherInsertForm"));
        TeacherInsertForm->resize(791, 601);
        TeacherInsertForm->setMinimumSize(QSize(791, 601));
        TeacherInsertForm->setMaximumSize(QSize(791, 601));
        TeacherInsertForm->setStyleSheet(QString::fromUtf8("QWidget#TeacherInsertForm {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        headText = new QLabel(TeacherInsertForm);
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
        IDLabel = new QLineEdit(TeacherInsertForm);
        IDLabel->setObjectName(QString::fromUtf8("IDLabel"));
        IDLabel->setEnabled(false);
        IDLabel->setGeometry(QRect(210, 60, 571, 41));
        QFont font1;
        font1.setPointSize(14);
        IDLabel->setFont(font1);
        IDLabel->setStyleSheet(QString::fromUtf8("QLineEdit#IDLabel {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        IDLabel->setAlignment(Qt::AlignCenter);
        text1 = new QLabel(TeacherInsertForm);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 60, 191, 41));
        text1->setFont(font1);
        text1->setStyleSheet(QString::fromUtf8("QLabel#text1 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        lastNameLine = new QLineEdit(TeacherInsertForm);
        lastNameLine->setObjectName(QString::fromUtf8("lastNameLine"));
        lastNameLine->setGeometry(QRect(210, 110, 571, 41));
        lastNameLine->setFont(font1);
        lastNameLine->setStyleSheet(QString::fromUtf8("QLineEdit#lastNameLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text2 = new QLabel(TeacherInsertForm);
        text2->setObjectName(QString::fromUtf8("text2"));
        text2->setGeometry(QRect(10, 110, 191, 41));
        text2->setFont(font1);
        text2->setStyleSheet(QString::fromUtf8("QLabel#text2 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        nameLine = new QLineEdit(TeacherInsertForm);
        nameLine->setObjectName(QString::fromUtf8("nameLine"));
        nameLine->setGeometry(QRect(210, 160, 571, 41));
        nameLine->setFont(font1);
        nameLine->setStyleSheet(QString::fromUtf8("QLineEdit#nameLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text3 = new QLabel(TeacherInsertForm);
        text3->setObjectName(QString::fromUtf8("text3"));
        text3->setGeometry(QRect(10, 160, 191, 41));
        text3->setFont(font1);
        text3->setStyleSheet(QString::fromUtf8("QLabel#text3 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        text4 = new QLabel(TeacherInsertForm);
        text4->setObjectName(QString::fromUtf8("text4"));
        text4->setGeometry(QRect(10, 210, 191, 41));
        text4->setFont(font1);
        text4->setStyleSheet(QString::fromUtf8("QLabel#text4 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        patronymicLine = new QLineEdit(TeacherInsertForm);
        patronymicLine->setObjectName(QString::fromUtf8("patronymicLine"));
        patronymicLine->setGeometry(QRect(210, 210, 571, 41));
        patronymicLine->setFont(font1);
        patronymicLine->setStyleSheet(QString::fromUtf8("QLineEdit#patronymicLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        postBox = new QComboBox(TeacherInsertForm);
        postBox->setObjectName(QString::fromUtf8("postBox"));
        postBox->setGeometry(QRect(210, 360, 571, 41));
        postBox->setFont(font1);
        postBox->setStyleSheet(QString::fromUtf8("QComboBox#postBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text5 = new QLabel(TeacherInsertForm);
        text5->setObjectName(QString::fromUtf8("text5"));
        text5->setGeometry(QRect(10, 360, 191, 41));
        text5->setFont(font1);
        text5->setStyleSheet(QString::fromUtf8("QLabel#text5 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        countSlider = new QSlider(TeacherInsertForm);
        countSlider->setObjectName(QString::fromUtf8("countSlider"));
        countSlider->setGeometry(QRect(210, 310, 481, 41));
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
        text6 = new QLabel(TeacherInsertForm);
        text6->setObjectName(QString::fromUtf8("text6"));
        text6->setGeometry(QRect(10, 310, 191, 41));
        text6->setFont(font1);
        text6->setStyleSheet(QString::fromUtf8("QLabel#text6 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        countLabel = new QLabel(TeacherInsertForm);
        countLabel->setObjectName(QString::fromUtf8("countLabel"));
        countLabel->setGeometry(QRect(700, 310, 81, 41));
        countLabel->setFont(font1);
        countLabel->setStyleSheet(QString::fromUtf8("QLabel#countLabel {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        countLabel->setAlignment(Qt::AlignCenter);
        departmentBox = new QComboBox(TeacherInsertForm);
        departmentBox->setObjectName(QString::fromUtf8("departmentBox"));
        departmentBox->setGeometry(QRect(210, 260, 481, 41));
        departmentBox->setFont(font1);
        departmentBox->setStyleSheet(QString::fromUtf8("QComboBox#departmentBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        text7 = new QLabel(TeacherInsertForm);
        text7->setObjectName(QString::fromUtf8("text7"));
        text7->setGeometry(QRect(10, 260, 191, 41));
        text7->setFont(font1);
        text7->setStyleSheet(QString::fromUtf8("QLabel#text7 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        logText = new QTextEdit(TeacherInsertForm);
        logText->setObjectName(QString::fromUtf8("logText"));
        logText->setGeometry(QRect(10, 460, 771, 71));
        QFont font2;
        font2.setPointSize(10);
        logText->setFont(font2);
        logText->setStyleSheet(QString::fromUtf8("QTextEdit#logText {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        logHead = new QLabel(TeacherInsertForm);
        logHead->setObjectName(QString::fromUtf8("logHead"));
        logHead->setGeometry(QRect(10, 410, 771, 41));
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
        addingButton = new QPushButton(TeacherInsertForm);
        addingButton->setObjectName(QString::fromUtf8("addingButton"));
        addingButton->setEnabled(false);
        addingButton->setGeometry(QRect(10, 540, 381, 51));
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
        exitButton = new QPushButton(TeacherInsertForm);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(400, 540, 381, 51));
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
"QPushButton#exitButton:disabled {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #4B7089;\n"
"	border: 5px solid #4B7089;\n"
"}"));
        departmentIDLabel = new QLabel(TeacherInsertForm);
        departmentIDLabel->setObjectName(QString::fromUtf8("departmentIDLabel"));
        departmentIDLabel->setGeometry(QRect(700, 260, 81, 41));
        departmentIDLabel->setFont(font1);
        departmentIDLabel->setStyleSheet(QString::fromUtf8("QLabel#departmentIDLabel {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        departmentIDLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(TeacherInsertForm);

        QMetaObject::connectSlotsByName(TeacherInsertForm);
    } // setupUi

    void retranslateUi(QWidget *TeacherInsertForm)
    {
        TeacherInsertForm->setWindowTitle(QApplication::translate("TeacherInsertForm", "\320\237\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\214, \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        headText->setText(QApplication::translate("TeacherInsertForm", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        text1->setText(QApplication::translate("TeacherInsertForm", "\320\242\320\260\320\261\320\265\320\273\321\214\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200*", nullptr));
        text2->setText(QApplication::translate("TeacherInsertForm", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        text3->setText(QApplication::translate("TeacherInsertForm", "\320\230\320\274\321\217", nullptr));
        text4->setText(QApplication::translate("TeacherInsertForm", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        text5->setText(QApplication::translate("TeacherInsertForm", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        text6->setText(QApplication::translate("TeacherInsertForm", "\320\241\321\202\320\260\320\266 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
        countLabel->setText(QApplication::translate("TeacherInsertForm", "10", nullptr));
        text7->setText(QApplication::translate("TeacherInsertForm", "\320\232\320\260\321\204\320\265\320\264\321\200\320\260", nullptr));
        logHead->setText(QApplication::translate("TeacherInsertForm", "\320\233\320\276\320\263 \320\276\321\210\320\270\320\261\320\276\320\272 \320\270 \320\277\321\200\320\265\320\264\321\203\320\277\321\200\320\265\320\266\320\264\320\265\320\275\320\270\320\271", nullptr));
        addingButton->setText(QApplication::translate("TeacherInsertForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        exitButton->setText(QApplication::translate("TeacherInsertForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        departmentIDLabel->setText(QApplication::translate("TeacherInsertForm", "10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherInsertForm: public Ui_TeacherInsertForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERINSERTFORM_H
