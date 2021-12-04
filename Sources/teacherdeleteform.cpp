#include "teacherdeleteform.h"
#include "ui_teacherdeleteform.h"
#include <QDebug>

TeacherDeleteForm::TeacherDeleteForm(QWidget* parent) : QWidget(parent), ui(new Ui::TeacherDeleteForm) {

    ui->setupUi(this);

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));     // exitButton, нажатие
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(onDeleteButtonClicked())); // deleteButton, нажатие

    connect(ui->IDLine, SIGNAL(textChanged()), this, SLOT(onIDLineTextChanged())); // IDLine, изменение текста

    // Установка подсказок в текстовые поля
    ui->surnameLine->setPlaceholderText("Ошибка");
    ui->nameLine->setPlaceholderText("Либо вы ввели не число");
    ui->patronymicLine->setPlaceholderText("Либо такого преподавателя нет");

    ui->logText->setText("Debug(), TeacherDeleteForm"); // Заголовок для лога
    ui->logText->setReadOnly(true);                     // Заблокировать редактирование
}

TeacherDeleteForm::~TeacherDeleteForm() { delete ui; }

// Приёмник моделей QSqlTableModel и QSqlQueryModel
void TeacherDeleteForm::resirvedData(QSqlTableModel* resModel, QSqlQueryModel* resQueryModel) {

    model = resModel;           // Сохранение модели
    queryModel = resQueryModel; // Сохранение запросной модели

    while (model->canFetchMore()) {

        model->fetchMore();
    }

    deleteCounter = 1; // Сброс счётчика удалений
}

// IDLine, изменение значения
void TeacherDeleteForm::onIDLineTextChanged() {

    // Проверка на число
    if (CheckIDDigit())
        if (CheckValue()) {

            ui->deleteButton->setDisabled(false); // Снятие блокировки с deleteButton
            SetName();                            // Сохранение ФИО в текстовые поля
            return;
        }

    ui->deleteButton->setDisabled(true); // Установка блокировки на deleteButton

    // Очистка текстовых полей
    ui->surnameLine->setText("");
    ui->nameLine->setText("");
    ui->patronymicLine->setText("");
}

// exitButton, нажатие
void TeacherDeleteForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}

// deleteButton, нажатие
void TeacherDeleteForm::onDeleteButtonClicked() {

    Debug("Счётчик удаления: " + QString::number(deleteCounter));
    deleteCounter++;

    DeleteTeacher(); // Удаление преподавателя

    model->select();

    ui->IDLine->setText("");
}

// Удаление преподавателей
void TeacherDeleteForm::DeleteTeacher() {

    // Выборка преподавателя
    QString str = "SELECT * FROM Преподаватель WHERE [Табельный номер] = %1";
    str = str.arg(ui->IDLine->toPlainText().toInt());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    Debug("Удалено записей из таблицы \"Преподаватель\": " + QString::number(queryModel->rowCount()));

    // Удаление преподавателя
    str = "DELETE * FROM Преподаватель WHERE [Табельный номер] = %1";
    str = str.arg(ui->IDLine->toPlainText().toInt());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей
}

// Проверка идентификатора на число
bool TeacherDeleteForm::CheckIDDigit() {

    bool digitFlag = false;
    int digit = ui->IDLine->toPlainText().toInt(&digitFlag, 10);

    return digitFlag;
}

// Проверка на наличие преподавателя с таким табельным номером
bool TeacherDeleteForm::CheckValue() {

    QString str = "SELECT * FROM Преподаватель WHERE [Табельный номер] = %1";
    str = str.arg(ui->IDLine->toPlainText().toInt());

    queryModel->setQuery(str); // Выполнение запроса

    if (queryModel->rowCount() == 0) {

        return false;
    }

    return true;
}

// Сохранение ФИО в текстовые поля
void TeacherDeleteForm::SetName() {

    QString str = "SELECT * FROM Преподаватель WHERE [Табельный номер] = %1";
    str = str.arg(ui->IDLine->toPlainText().toInt());

    // Сохранение ФИО в текстовые поля
    ui->surnameLine->setText(queryModel->index(0, 1).data().toString());
    ui->nameLine->setText(queryModel->index(0, 2).data().toString());
    ui->patronymicLine->setText(queryModel->index(0, 3).data().toString());
}

// Сохранение отладочного сообщения в лог
void TeacherDeleteForm::Debug(QString message) {

    ui->logText->setText(ui->logText->toPlainText() + "\n" + message); // Сохранение сообщения в лог
    ui->logText->moveCursor(QTextCursor::End);                         // Прокрутка блока текста с логом вниз
}
