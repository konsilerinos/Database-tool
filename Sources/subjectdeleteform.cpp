#include "subjectdeleteform.h"
#include "ui_subjectdeleteform.h"

SubjectDeleteForm::SubjectDeleteForm(QWidget* parent) : QWidget(parent), ui(new Ui::SubjectDeleteForm) {

    ui->setupUi(this); // 123

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));     // exitButton, нажатие
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(onDeleteButtonClicked())); // deleteButton, нажатие

    connect(ui->IDBox, SIGNAL(currentTextChanged(QString)), this, SLOT(onIDBoxTextChanged()));               // IDBox, изменение значения
    connect(ui->nameBox, SIGNAL(currentTextChanged(QString)), this, SLOT(onNameBoxTextChanged()));           // nameBox, изменение значения
    connect(ui->shortNameBox, SIGNAL(currentTextChanged(QString)), this, SLOT(onShortNameBoxTextChanged())); // shortNameBox, изменение значения

    ui->logText->setText("Debug(), SubjectDeleteForm"); // Заголовок для лога
    ui->logText->setReadOnly(true);                     // Заблокировать редактирование
}

SubjectDeleteForm::~SubjectDeleteForm() { delete ui; }

// Приёмник моделей QSqlTableModel и QSqlQueryModel
void SubjectDeleteForm::resirvedData(QSqlTableModel* resModel, QSqlQueryModel* resQueryModel) {

    model = resModel;           // Сохранение модели
    queryModel = resQueryModel; // Сохранение запросной модели

    while (model->canFetchMore()) {

        model->fetchMore();
    }

    SaveID();         // Сохранение идентификаторов предметов
    SaveNames();      // Сохранение названий предметов
    SaveShortNames(); // Сохранение сокращённых названий предметов

    deleteCounter = 1; // Сброс счётчика удалений
}

// exitButton, нажатие
void SubjectDeleteForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}

// deleteButton, нажатие
void SubjectDeleteForm::onDeleteButtonClicked() {

    Debug("Счётчик удаления: " + QString::number(deleteCounter));
    deleteCounter++;

    DeleteLessons();  // Удаление занятий
    DeleteSubjects(); // Удаление предметов

    model->select();

    SaveID();         // Сохранение идентификаторов предметов
    SaveNames();      // Сохранение названий предметов
    SaveShortNames(); // Сохранение сокращённых названий предметов
}

// IDBox, изменение значения
void SubjectDeleteForm::onIDBoxTextChanged() {

    ui->nameBox->setCurrentIndex(ui->IDBox->currentIndex());      // Изменение значения для nameBox
    ui->shortNameBox->setCurrentIndex(ui->IDBox->currentIndex()); // Изменение значения для shortNameBox
}

// nameBox, изменение значения
void SubjectDeleteForm::onNameBoxTextChanged() {

    ui->IDBox->setCurrentIndex(ui->nameBox->currentIndex());        // Изменение значения для IDBox
    ui->shortNameBox->setCurrentIndex(ui->nameBox->currentIndex()); // Изменение значения для shortNameBox
}

// shortnameBox, изменение значения
void SubjectDeleteForm::onShortNameBoxTextChanged() {

    ui->IDBox->setCurrentIndex(ui->shortNameBox->currentIndex());   // Изменение значения для IDBox
    ui->nameBox->setCurrentIndex(ui->shortNameBox->currentIndex()); // Изменение значения для nameBox
}

// Сохранение идентификаторов предметов
void SubjectDeleteForm::SaveID() {

    IDList.clear();     // Очистка списка IDList
    ui->IDBox->clear(); // Очистка IDBox

    while (model->canFetchMore())
        model->fetchMore();

    QString str = "SELECT [Идентификатор предмета] FROM Предмет";

    queryModel->setQuery(str); // Выполнение запроса

    for (int i = 0; i < queryModel->rowCount(); i++) {

        IDList.append(queryModel->index(i, 0).data().toString());
    }

    ui->IDBox->addItems(IDList); // Сохранение идентификаторов предметов
}

// Сохранение названий предметов
void SubjectDeleteForm::SaveNames() {

    namesList.clear();    // Очистка списка namesList
    ui->nameBox->clear(); // Очистка nameBox

    while (model->canFetchMore())
        model->fetchMore();

    QString str = "SELECT [Название предмета] FROM Предмет";

    queryModel->setQuery(str); // Выполнение запроса

    for (int i = 0; i < queryModel->rowCount(); i++) {

        namesList.append(queryModel->index(i, 0).data().toString());
    }

    ui->nameBox->addItems(namesList); // Сохранение названий предметов
}

// Сохранение сокращённых названий предметов
void SubjectDeleteForm::SaveShortNames() {

    shortNamesList.clear();    // Очистка списка shortNamesList
    ui->shortNameBox->clear(); // Очистка nameBox

    while (model->canFetchMore())
        model->fetchMore();

    QString str = "SELECT [Короткое название предмета] FROM Предмет";

    queryModel->setQuery(str); // Выполнение запроса

    for (int i = 0; i < queryModel->rowCount(); i++) {

        shortNamesList.append(queryModel->index(i, 0).data().toString());
    }

    ui->shortNameBox->addItems(shortNamesList); // Сохранение сокращённых названий предметов
}

// Удаление занятий
void SubjectDeleteForm::DeleteLessons() {

    // Выборка занятий
    QString str = "SELECT * FROM Занятие WHERE [Идентификатор предмета] = %1";
    str = str.arg(ui->IDBox->currentText().toInt());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    Debug("Удалено записей из таблицы \"Занятие\": " + QString::number(queryModel->rowCount()));

    // Удаление занятий
    str = "DELETE * FROM Занятие WHERE [Идентификатор предмета] = %1";
    str = str.arg(ui->IDBox->currentText().toInt());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей
}

// Удаление предметов
void SubjectDeleteForm::DeleteSubjects() {

    // Выборка предметов
    QString str = "SELECT * FROM Предмет WHERE [Идентификатор предмета] = %1";
    str = str.arg(ui->IDBox->currentText().toInt());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    Debug("Удалено записей из таблицы \"Предмет\": " + QString::number(queryModel->rowCount()));

    // Удаление предметов
    str = "DELETE * FROM Предмет WHERE [Идентификатор предмета] = %1";
    str = str.arg(ui->IDBox->currentText().toInt());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей
}

// Сохранение отладочного сообщения в лог
void SubjectDeleteForm::Debug(QString message) {

    ui->logText->setText(ui->logText->toPlainText() + "\n" + message); // Сохранение сообщения в лог
    ui->logText->moveCursor(QTextCursor::End);                         // Прокрутка блока текста с логом вниз
}
