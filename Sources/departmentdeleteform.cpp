#include "departmentdeleteform.h"
#include "ui_departmentdeleteform.h"
#include <QDebug>

DepartmentDeleteForm::DepartmentDeleteForm(QWidget* parent) : QWidget(parent), ui(new Ui::DepartmentDeleteForm) {

    ui->setupUi(this);

    connect(ui->IDBox, SIGNAL(currentTextChanged(QString)), this, SLOT(onIDBoxValueChanged()));           // IDBox, изменение значения
    connect(ui->nameBox, SIGNAL(currentTextChanged(QString)), this, SLOT(onNameBoxValueChanged()));       // nameBox, изменение значения
    connect(ui->shortNameBox, SIGNAL(currentTextChanged(QString)), this, SLOT(onShortNamesBoxChanged())); // shortNamesBox, изменение значения

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));     // exitButton, нажатие
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(onDeleteButtonClicked())); // deleteButton, нажатие

    ui->logText->setText("Debug(), DepartmentDeleteForm"); // Заголовок для лога
    ui->logText->setReadOnly(true);                        // Заблокировать редактирование
}

DepartmentDeleteForm::~DepartmentDeleteForm() { delete ui; }

// Приёмник моделей QSqlTableModel и QSqlQueryModel
void DepartmentDeleteForm::resirvedData(QSqlTableModel* resModel, QSqlQueryModel* resQueryModel) {

    model = resModel;           // Сохранение модели
    queryModel = resQueryModel; // Сохранение запросной модели

    while (model->canFetchMore()) {

        model->fetchMore();
    }

    SaveID();         // Сохранение идентификаторов кафедр в IDBox
    SaveNames();      // Сохранение названий кафедр в nameBox
    SaveShortNames(); // Сохранение сокращённых названий кафедр в shortNameBox

    deleteCounter = 1; // Сброс счётчика удалений
}

// exitButton, нажатие
void DepartmentDeleteForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}

// deleteButton, нажатие
void DepartmentDeleteForm::onDeleteButtonClicked() {

    Debug("Счётчик удаления: " + QString::number(deleteCounter));
    deleteCounter++;

    DeleteLessons();     // Удаление занятий
    DeleteGroups();      // Удаление групп
    DeleteTeachers();    // Удаление преподавателей
    DeleteDepartments(); // Удаление кафедры

    // Обновление полей
    ui->IDBox->removeItem(ui->IDBox->currentIndex());
    ui->nameBox->removeItem(ui->nameBox->currentIndex());
    ui->shortNameBox->removeItem(ui->shortNameBox->currentIndex());

    model->select();
}

// IDBox, изменение значения
void DepartmentDeleteForm::onIDBoxValueChanged() {

    ui->nameBox->setCurrentIndex(ui->IDBox->currentIndex());      // Изменение значения для nameBox
    ui->shortNameBox->setCurrentIndex(ui->IDBox->currentIndex()); // Изменение значеиня для shortNameBox
}

// nameBox, изменение значения
void DepartmentDeleteForm::onNameBoxValueChanged() {

    ui->IDBox->setCurrentIndex(ui->nameBox->currentIndex());        // Изменение значения для IDBox
    ui->shortNameBox->setCurrentIndex(ui->nameBox->currentIndex()); // Изменение значения для shortNameBox
}

// shortNamesBox, изменение значения
void DepartmentDeleteForm::onShortNamesBoxChanged() {

    ui->IDBox->setCurrentIndex(ui->shortNameBox->currentIndex());   // Изменение значения для IDBox
    ui->nameBox->setCurrentIndex(ui->shortNameBox->currentIndex()); // Изменение значения для nameBox
}

// Сохранение идентификаторов кафедр в IDBox
void DepartmentDeleteForm::SaveID() {

    IDList.clear(); // Очистка списка IDList

    while (model->canFetchMore())
        model->fetchMore();

    for (int i = 0; i < model->rowCount(); i++) {

        IDList.append(model->index(i, 0).data().toString());
    }

    ui->IDBox->addItems(IDList); // Сохранение идентификаторов кафедр
}

// Сохранение названий кафедр в nameBox
void DepartmentDeleteForm::SaveNames() {

    namesList.clear(); // Очистка списка namesList

    while (model->canFetchMore())
        model->fetchMore();

    for (int i = 0; i < model->rowCount(); i++) {

        namesList.append(model->index(i, 1).data().toString());
    }

    ui->nameBox->addItems(namesList); // Сохранение названий кафедр
}

// Сохранение сокращённых названий кафедр в shortNameBox
void DepartmentDeleteForm::SaveShortNames() {

    shortNamesList.clear(); // Очистка списка shortNamesList

    while (model->canFetchMore())
        model->fetchMore();

    for (int i = 0; i < model->rowCount(); i++) {

        shortNamesList.append(model->index(i, 2).data().toString());
    }

    ui->shortNameBox->addItems(shortNamesList); // Сохранение сокращённых названий
}

// Удаление занятий
void DepartmentDeleteForm::DeleteLessons() {

    // Выборка занятий
    QString str = "SELECT * FROM Занятие WHERE [Номер группы] LIKE '%1'";
    str = str.arg(ui->shortNameBox->currentText() + "%");

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    Debug("Удалено записей из таблицы \"Занятие\": " + QString::number(queryModel->rowCount()));

    // Удаление занятий
    str = "DELETE * FROM Занятие WHERE [Номер группы] LIKE '%1'";
    str = str.arg(ui->shortNameBox->currentText() + "%");

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей
}

// Удаление групп
void DepartmentDeleteForm::DeleteGroups() {

    // Выборка групп
    QString str = "SELECT * FROM Группа WHERE [Номер группы] LIKE '%1'";
    str = str.arg(ui->shortNameBox->currentText() + "%");

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    Debug("Удалено записей из таблицы \"Занятие\": " + QString::number(queryModel->rowCount()));

    // Удаление групп
    str = "SELECT * FROM Группа WHERE [Номер группы] LIKE '%1'";
    str = str.arg(ui->shortNameBox->currentText() + "%");

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей
}

// Удаление преподавателей
void DepartmentDeleteForm::DeleteTeachers() {

    // Выборка преподавателей
    QString str = "SELECT * FROM Преподаватель WHERE [Идентификатор кафедры] = %1";
    str = str.arg(ui->IDBox->currentText().toInt());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    Debug("Удалено записей из таблицы \"Преподаватель\": " + QString::number(queryModel->rowCount()));

    // Удаление преподавателей
    str = "DELETE * FROM Преподаватель WHERE [Идентификатор кафедры] = %1";
    str = str.arg(ui->IDBox->currentText().toInt());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей
}

// Удаление кафедры
void DepartmentDeleteForm::DeleteDepartments() {

    // Выборка кафедры
    QString str = "SELECT * FROM Кафедра WHERE [Идентификатор кафедры] = %1";
    str = str.arg(ui->IDBox->currentText().toInt());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    Debug("Удалено записей из таблицы \"Кафедра\": " + QString::number(queryModel->rowCount()));

    // Удаление кафедры
    str = "DELETE * FROM Кафедра WHERE [Идентификатор кафедры] = %1";
    str = str.arg(ui->IDBox->currentText().toInt());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей
}

// Сохранение отладочного сообщения в лог
void DepartmentDeleteForm::Debug(QString message) {

    ui->logText->setText(ui->logText->toPlainText() + "\n" + message); // Сохранение сообщения в лог
    ui->logText->moveCursor(QTextCursor::End);                         // Прокрутка блока текста с логом вниз
}
