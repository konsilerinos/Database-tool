/********************************************************************************
** Form generated from reading UI file 'groupinsertform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPINSERTFORM_H
#define UI_GROUPINSERTFORM_H

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

class Ui_GroupInsertForm
{
public:
    QLabel *headText;
    QLineEdit *groupNumberLine;
    QLabel *text1;
    QLabel *text2;
    QComboBox *departmentBox;
    QLabel *departmentIDLabel;
    QLabel *text3;
    QSlider *countSlider;
    QLabel *countLabel;
    QPushButton *exitButton;
    QPushButton *addingButton;
    QTextEdit *logText;
    QLabel *logHead;
    QLabel *shortNameLabel;

    void setupUi(QWidget *GroupInsertForm)
    {
        if (GroupInsertForm->objectName().isEmpty())
            GroupInsertForm->setObjectName(QString::fromUtf8("GroupInsertForm"));
        GroupInsertForm->resize(791, 401);
        GroupInsertForm->setMinimumSize(QSize(791, 401));
        GroupInsertForm->setMaximumSize(QSize(791, 401));
        GroupInsertForm->setStyleSheet(QString::fromUtf8("QWidget#GroupInsertForm {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        headText = new QLabel(GroupInsertForm);
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
        groupNumberLine = new QLineEdit(GroupInsertForm);
        groupNumberLine->setObjectName(QString::fromUtf8("groupNumberLine"));
        groupNumberLine->setEnabled(true);
        groupNumberLine->setGeometry(QRect(210, 60, 481, 41));
        QFont font1;
        font1.setPointSize(14);
        groupNumberLine->setFont(font1);
        groupNumberLine->setStyleSheet(QString::fromUtf8("QLineEdit#groupNumberLine {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        groupNumberLine->setAlignment(Qt::AlignCenter);
        text1 = new QLabel(GroupInsertForm);
        text1->setObjectName(QString::fromUtf8("text1"));
        text1->setGeometry(QRect(10, 60, 191, 41));
        text1->setFont(font1);
        text1->setStyleSheet(QString::fromUtf8("QLabel#text1 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        text2 = new QLabel(GroupInsertForm);
        text2->setObjectName(QString::fromUtf8("text2"));
        text2->setGeometry(QRect(10, 110, 191, 41));
        text2->setFont(font1);
        text2->setStyleSheet(QString::fromUtf8("QLabel#text2 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        departmentBox = new QComboBox(GroupInsertForm);
        departmentBox->setObjectName(QString::fromUtf8("departmentBox"));
        departmentBox->setGeometry(QRect(210, 110, 481, 41));
        departmentBox->setFont(font1);
        departmentBox->setStyleSheet(QString::fromUtf8("QComboBox#departmentBox {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        departmentIDLabel = new QLabel(GroupInsertForm);
        departmentIDLabel->setObjectName(QString::fromUtf8("departmentIDLabel"));
        departmentIDLabel->setGeometry(QRect(700, 110, 81, 41));
        departmentIDLabel->setFont(font1);
        departmentIDLabel->setStyleSheet(QString::fromUtf8("QLabel#departmentIDLabel {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        departmentIDLabel->setAlignment(Qt::AlignCenter);
        text3 = new QLabel(GroupInsertForm);
        text3->setObjectName(QString::fromUtf8("text3"));
        text3->setGeometry(QRect(10, 160, 191, 41));
        text3->setFont(font1);
        text3->setStyleSheet(QString::fromUtf8("QLabel#text3 {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"}"));
        countSlider = new QSlider(GroupInsertForm);
        countSlider->setObjectName(QString::fromUtf8("countSlider"));
        countSlider->setGeometry(QRect(210, 160, 481, 41));
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
        countLabel = new QLabel(GroupInsertForm);
        countLabel->setObjectName(QString::fromUtf8("countLabel"));
        countLabel->setGeometry(QRect(700, 160, 81, 41));
        countLabel->setFont(font1);
        countLabel->setStyleSheet(QString::fromUtf8("QLabel#countLabel {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        countLabel->setAlignment(Qt::AlignCenter);
        exitButton = new QPushButton(GroupInsertForm);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(400, 340, 381, 51));
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
        addingButton = new QPushButton(GroupInsertForm);
        addingButton->setObjectName(QString::fromUtf8("addingButton"));
        addingButton->setEnabled(false);
        addingButton->setGeometry(QRect(10, 340, 381, 51));
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
        logText = new QTextEdit(GroupInsertForm);
        logText->setObjectName(QString::fromUtf8("logText"));
        logText->setGeometry(QRect(10, 260, 771, 71));
        QFont font3;
        font3.setPointSize(10);
        logText->setFont(font3);
        logText->setStyleSheet(QString::fromUtf8("QTextEdit#logText {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}"));
        logHead = new QLabel(GroupInsertForm);
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
        shortNameLabel = new QLabel(GroupInsertForm);
        shortNameLabel->setObjectName(QString::fromUtf8("shortNameLabel"));
        shortNameLabel->setGeometry(QRect(700, 60, 81, 41));
        shortNameLabel->setFont(font1);
        shortNameLabel->setStyleSheet(QString::fromUtf8("QLabel#shortNameLabel {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        shortNameLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(GroupInsertForm);

        QMetaObject::connectSlotsByName(GroupInsertForm);
    } // setupUi

    void retranslateUi(QWidget *GroupInsertForm)
    {
        GroupInsertForm->setWindowTitle(QApplication::translate("GroupInsertForm", "\320\223\321\200\321\203\320\277\320\277\320\260, \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        headText->setText(QApplication::translate("GroupInsertForm", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\271 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        groupNumberLine->setText(QString());
        text1->setText(QApplication::translate("GroupInsertForm", "\320\235\320\276\320\274\320\265\321\200 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        text2->setText(QApplication::translate("GroupInsertForm", "\320\232\320\260\321\204\320\265\320\264\321\200\320\260", nullptr));
        departmentIDLabel->setText(QApplication::translate("GroupInsertForm", "10", nullptr));
        text3->setText(QApplication::translate("GroupInsertForm", "\320\247\320\270\321\201\320\273\320\265\320\275\320\275\320\276\321\201\321\202\321\214", nullptr));
        countLabel->setText(QApplication::translate("GroupInsertForm", "10", nullptr));
        exitButton->setText(QApplication::translate("GroupInsertForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        addingButton->setText(QApplication::translate("GroupInsertForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        logHead->setText(QApplication::translate("GroupInsertForm", "\320\233\320\276\320\263 \320\276\321\210\320\270\320\261\320\276\320\272 \320\270 \320\277\321\200\320\265\320\264\321\203\320\277\321\200\320\265\320\266\320\264\320\265\320\275\320\270\320\271", nullptr));
        shortNameLabel->setText(QApplication::translate("GroupInsertForm", "10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupInsertForm: public Ui_GroupInsertForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPINSERTFORM_H
