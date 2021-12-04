#include "groupdeleteform.h"
#include "ui_groupdeleteform.h"
#include <QDebug>

GroupDeleteForm::GroupDeleteForm(QWidget* parent) : QWidget(parent), ui(new Ui::GroupDeleteForm) {

    ui->setupUi(this);

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));     // exitButton, нажатие
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(onDeleteButtonClicked())); // deleteButton, нажатие

    ui->logText->setText("Debug(), GroupDeleteForm"); // Заголовок для лога
    ui->logText->setReadOnly(true);                   // Заблокировать редактирование
}

GroupDeleteForm::~GroupDeleteForm() { delete ui; }

// Приёмник моделей QSqlTableModel и QSqlQueryModel
void GroupDeleteForm::resirvedData(QSqlTableModel* resModel, QSqlQueryModel* resQueryModel) {

    model = resModel;           // Сохранение модели
    queryModel = resQueryModel; // Сохранение запросной модели

    while (model->canFetchMore()) {

        model->fetchMore();
    }

    SaveGroups(); // Сохранение групп в groupList и установка в groupBox

    deleteCounter = 1; // Сброс счётчика удалений
}

// exitButton, нажатие
void GroupDeleteForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}

// deleteButton, нажатие
void GroupDeleteForm::onDeleteButtonClicked() {

    Debug("Счётчик удаления: " + QString::number(deleteCounter));
    deleteCounter++;

    DeleteLessons(); // Удаление занятий
    DeleteGroups();  // Удаление группы

    model->select();

    SaveGroups(); // Сохранение групп в groupList и установка в groupBox
}

// Сохранение групп в groupList и установка в groupBox
void GroupDeleteForm::SaveGroups() {

    groupList.clear();     // Очистка списка groupList
    ui->groupBox->clear(); // Очистка groupBox

    while (model->canFetchMore())
        model->fetchMore();

    QString str = "SELECT [Номер группы] FROM Группа";

    queryModel->setQuery(str); // Выполнение запроса

    for (int i = 0; i < queryModel->rowCount(); i++) {

        groupList.append(queryModel->index(i, 0).data().toString());
    }

    ui->groupBox->addItems(groupList); // Сохранение номеров групп
}

// Удаление занятий
void GroupDeleteForm::DeleteLessons() {

    // Выборка занятий
    QString str = "SELECT * FROM Занятие WHERE [Номер группы] = '%1'";
    str = str.arg(ui->groupBox->currentText());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    Debug("Удалено записей из таблицы \"Занятие\": " + QString::number(queryModel->rowCount()));

    // Удаление занятий
    str = "DELETE * FROM Занятие WHERE [Номер группы] = '%1'";
    str = str.arg(ui->groupBox->currentText());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей
}

// Удаление групп
void GroupDeleteForm::DeleteGroups() {

    // Выборка групп
    QString str = "SELECT * FROM Группа WHERE [Номер группы] = '%1'";
    str = str.arg(ui->groupBox->currentText());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    Debug("Удалено записей из таблицы \"Группа\": " + QString::number(queryModel->rowCount()));

    // Удаление групп
    str = "DELETE * FROM Группа WHERE [Номер группы] = '%1'";
    str = str.arg(ui->groupBox->currentText());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей
}

// Сохранение отладочного сообщения в лог
void GroupDeleteForm::Debug(QString message) {
    ui->logText->setText(ui->logText->toPlainText() + "\n" + message); // Сохранение сообщения в лог
    ui->logText->moveCursor(QTextCursor::End);                         // Прокрутка блока текста с логом вниз
}
