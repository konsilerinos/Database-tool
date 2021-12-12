/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *addingButton;
    QListWidget *tablesListWidget;
    QLabel *headText;
    QLabel *tableHead;
    QPushButton *deleteButton;
    QPushButton *changeButton;
    QLabel *toolsHead;
    QLabel *tablesHead;
    QLabel *requestsHead;
    QPushButton *infoButton;
    QPushButton *requestsButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1321, 721);
        MainWindow->setMinimumSize(QSize(1321, 721));
        MainWindow->setMaximumSize(QSize(1321, 721));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow#MainWindow {\n"
"\n"
"	background-color: #284B63;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(180, 110, 1131, 601));
        tableView->setMaximumSize(QSize(99999, 16777215));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"	selection-background-color: #185680;\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"\n"
"    background: #284B63;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"\n"
"    background-color: #284B63;\n"
"    color: white;\n"
"	border: 1px solid #1A3344;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QHeaderView::section:checked {\n"
"\n"
"    background-color: #DB1921;\n"
"    color: #FFFFFF;\n"
"    font-weight: bold;\n"
"}\n"
""));
        addingButton = new QPushButton(centralwidget);
        addingButton->setObjectName(QString::fromUtf8("addingButton"));
        addingButton->setGeometry(QRect(10, 430, 161, 41));
        QFont font;
        font.setPointSize(12);
        addingButton->setFont(font);
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
        tablesListWidget = new QListWidget(centralwidget);
        tablesListWidget->setObjectName(QString::fromUtf8("tablesListWidget"));
        tablesListWidget->setGeometry(QRect(10, 110, 161, 161));
        tablesListWidget->setFont(font);
        tablesListWidget->setStyleSheet(QString::fromUtf8("QListWidget#tablesListWidget {\n"
"\n"
"	border: 5px solid #1A3344;\n"
"}\n"
"\n"
"QListWidget::item {\n"
"\n"
"	background-color: #FFFFFF;\n"
"}\n"
"\n"
"QListWidget::item::hover {\n"
"\n"
"	background-color: #185680;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"QListView::item:selected {\n"
"\n"
"	background-color: #284B63;\n"
"    color: #FFFFFF;\n"
"}"));
        headText = new QLabel(centralwidget);
        headText->setObjectName(QString::fromUtf8("headText"));
        headText->setGeometry(QRect(10, 10, 1301, 41));
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
        tableHead = new QLabel(centralwidget);
        tableHead->setObjectName(QString::fromUtf8("tableHead"));
        tableHead->setGeometry(QRect(180, 60, 1131, 41));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setWeight(50);
        tableHead->setFont(font2);
        tableHead->setStyleSheet(QString::fromUtf8("QLabel#tableHead {\n"
"\n"
"	background-color: #FFC300;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        tableHead->setAlignment(Qt::AlignCenter);
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(10, 530, 161, 41));
        deleteButton->setFont(font);
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
        changeButton = new QPushButton(centralwidget);
        changeButton->setObjectName(QString::fromUtf8("changeButton"));
        changeButton->setGeometry(QRect(10, 480, 161, 41));
        changeButton->setFont(font);
        changeButton->setStyleSheet(QString::fromUtf8("QPushButton#changeButton {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #FFFFFF;\n"
"}\n"
"QPushButton#changeButton:hover {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
"QPushButton#changeButton:pressed {\n"
"\n"
"	background-color: #DB1921;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
""));
        toolsHead = new QLabel(centralwidget);
        toolsHead->setObjectName(QString::fromUtf8("toolsHead"));
        toolsHead->setGeometry(QRect(10, 380, 161, 41));
        QFont font3;
        font3.setPointSize(16);
        toolsHead->setFont(font3);
        toolsHead->setStyleSheet(QString::fromUtf8("QLabel#toolsHead {\n"
"\n"
"	background-color: #FFC300;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        toolsHead->setAlignment(Qt::AlignCenter);
        tablesHead = new QLabel(centralwidget);
        tablesHead->setObjectName(QString::fromUtf8("tablesHead"));
        tablesHead->setGeometry(QRect(10, 60, 161, 41));
        tablesHead->setFont(font3);
        tablesHead->setStyleSheet(QString::fromUtf8("QLabel#tablesHead {\n"
"\n"
"	background-color: #FFC300;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        tablesHead->setAlignment(Qt::AlignCenter);
        requestsHead = new QLabel(centralwidget);
        requestsHead->setObjectName(QString::fromUtf8("requestsHead"));
        requestsHead->setGeometry(QRect(10, 280, 161, 41));
        requestsHead->setFont(font3);
        requestsHead->setStyleSheet(QString::fromUtf8("QLabel#requestsHead {\n"
"\n"
"	background-color: #FFC300;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}"));
        requestsHead->setAlignment(Qt::AlignCenter);
        infoButton = new QPushButton(centralwidget);
        infoButton->setObjectName(QString::fromUtf8("infoButton"));
        infoButton->setGeometry(QRect(10, 580, 161, 131));
        infoButton->setFont(font);
        infoButton->setStyleSheet(QString::fromUtf8("QPushButton#infoButton {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #FFFFFF;\n"
"}\n"
"QPushButton#infoButton:hover {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
"QPushButton#infoButton:pressed {\n"
"\n"
"	background-color: #DB1921;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
""));
        requestsButton = new QPushButton(centralwidget);
        requestsButton->setObjectName(QString::fromUtf8("requestsButton"));
        requestsButton->setGeometry(QRect(10, 330, 161, 41));
        requestsButton->setFont(font);
        requestsButton->setStyleSheet(QString::fromUtf8("QPushButton#requestsButton {\n"
"\n"
"	background-color: #284B63;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #FFFFFF;\n"
"}\n"
"QPushButton#requestsButton:hover {\n"
"\n"
"	background-color: #FFFFFF;\n"
"	color: #1A3344;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
"QPushButton#requestsButton:pressed {\n"
"\n"
"	background-color: #DB1921;\n"
"	color: #FFFFFF;\n"
"	border: 5px solid #1A3344;\n"
"}\n"
""));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\221\320\260\320\267\320\260 \320\264\320\260\320\275\320\275\321\213\321\205, \320\270\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\320\270", nullptr));
        addingButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        headText->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \320\261\320\260\320\267\320\276\320\271 \320\264\320\260\320\275\320\275\321\213\321\205, \320\270\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\320\270", nullptr));
        tableHead->setText(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260: \320\260\321\203\320\264\320\270\321\202\320\276\321\200\320\270\321\217", nullptr));
        deleteButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        changeButton->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        toolsHead->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\270", nullptr));
        tablesHead->setText(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\321\213", nullptr));
        requestsHead->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\200\320\276\321\201\321\213", nullptr));
        infoButton->setText(QString());
        requestsButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
