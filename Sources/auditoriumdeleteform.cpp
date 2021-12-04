#include "auditoriumdeleteform.h"
#include "ui_auditoriumdeleteform.h"
#include <QDebug>

AuditoriumDeleteForm::AuditoriumDeleteForm(QWidget* parent) : QWidget(parent), ui(new Ui::AuditoriumDeleteForm) {

    ui->setupUi(this);

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));     // exitButton, нажатие
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(onDeleteButtonClicked())); // deleteButton, нажатие

    ui->logText->setText("Debug(), AuditoriumDeleteForm"); // Заголовок для лога
    ui->logText->setReadOnly(true);                        // Заблокировать редактирование
}

AuditoriumDeleteForm::~AuditoriumDeleteForm() { delete ui; }

// Приёмник моделей QSqlTableModel и QSqlQueryModel
void AuditoriumDeleteForm::resirvedData(QSqlTableModel* resModel, QSqlQueryModel* resQueryModel) {

    model = resModel;           // Сохранение модели
    queryModel = resQueryModel; // Сохранение запросной модели

    while (model->canFetchMore()) {

        model->fetchMore();
    }

    SaveBodies();  // Сохранение всех номеров корпусов в bodyBox
    SaveFloors();  // Сохранение всех номеров этажей в floorBox
    SaveNumbers(); // Сохранение всех номеров аудиторий в numberBox

    deleteCounter = 1; // Сброс счётчика удалений
}

// exitButton, нажатие
void AuditoriumDeleteForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}

// deleteButton, нажатие
void AuditoriumDeleteForm::onDeleteButtonClicked() {

    Debug("Счётчик удаления: " + QString::number(deleteCounter));
    deleteCounter++;

    DeleteLessons();    // Удаление занятий
    DeleteAuditories(); // Удаление аудиторий

    model->select();
}

// Сохранение всех номеров корпусов в bodyBox
void AuditoriumDeleteForm::SaveBodies() {

    bodyList.clear();     // Очистка списка bodyList
    ui->bodyBox->clear(); // Очистка bodyBox

    while (model->canFetchMore())
        model->fetchMore();

    QString str = "SELECT DISTINCT Корпус FROM Аудитория";

    queryModel->setQuery(str); // Выполнение запроса

    for (int i = 0; i < queryModel->rowCount(); i++) {

        bodyList.append(queryModel->index(i, 0).data().toString());
    }

    ui->bodyBox->addItems(bodyList); // Сохранение номеров корпусов
}

// Сохранение всех номеров этажей в floorBox
void AuditoriumDeleteForm::SaveFloors() {

    floorList.clear();     // Очистка списка floorList
    ui->floorBox->clear(); // Очистка floorBox

    while (model->canFetchMore())
        model->fetchMore();

    QString str = "SELECT DISTINCT Этаж FROM Аудитория";

    queryModel->setQuery(str); // Выполнение запроса

    for (int i = 0; i < queryModel->rowCount(); i++) {

        floorList.append(queryModel->index(i, 0).data().toString());
    }

    ui->floorBox->addItems(floorList); // Сохранение номеров этажей
}

// Сохранение всех номеров кабинетов  в numberBox
void AuditoriumDeleteForm::SaveNumbers() {

    numberList.clear();     // Очистка списка numberList
    ui->numberBox->clear(); // Очистка numberBox

    while (model->canFetchMore())
        model->fetchMore();

    QString str = "SELECT DISTINCT Номер FROM Аудитория";

    queryModel->setQuery(str); // Выполнение запроса

    for (int i = 0; i < queryModel->rowCount(); i++) {

        numberList.append(queryModel->index(i, 0).data().toString());
    }

    ui->numberBox->addItems(numberList); // Сохранение номеров кабинетов
}

// Удаление занятий
void AuditoriumDeleteForm::DeleteLessons() {

    // Выборка занятий
    QString str = "SELECT * "
                  "FROM Занятие "
                  "WHERE ([Корпус аудитории] = %1) AND "
                  "([Этаж аудитории] = %2) AND "
                  "([Номер аудитории] = %3)";

    int body = ui->bodyBox->currentText().toInt();     // Корпус
    int floor = ui->floorBox->currentText().toInt();   // Этаж
    int number = ui->numberBox->currentText().toInt(); // Номер

    str = str.arg(body).arg(floor).arg(number);

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    Debug("Удалено записей из таблицы \"Занятие\": " + QString::number(queryModel->rowCount()));

    // Удаление занятий
    str = "DELETE * "
          "FROM Занятие "
          "WHERE ([Корпус аудитории] = %1) AND "
          "([Этаж аудитории] = %2) AND "
          "([Номер аудитории] = %3)";

    str = str.arg(body).arg(floor).arg(number);

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей
}

// Удаление аудиторий
void AuditoriumDeleteForm::DeleteAuditories() {

    // Выборка аудиторий
    QString str = "SELECT * "
                  "FROM Аудитория "
                  "WHERE (Корпус = %1) AND "
                  "(Этаж = %2) AND "
                  "(Номер = %3)";

    int body = ui->bodyBox->currentText().toInt();     // Корпус
    int floor = ui->floorBox->currentText().toInt();   // Этаж
    int number = ui->numberBox->currentText().toInt(); // Номер

    str = str.arg(body).arg(floor).arg(number);

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    Debug("Удалено записей из таблицы \"Аудитория\": " + QString::number(queryModel->rowCount()));

    // Удаление аудиторий
    str = "DELETE * "
          "FROM Аудитория "
          "WHERE (Корпус = %1) AND "
          "(Этаж = %2) AND "
          "(Номер = %3)";

    str = str.arg(body).arg(floor).arg(number);

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей
}

// Сохранение отладочного сообщения в лог
void AuditoriumDeleteForm::Debug(QString message) {

    ui->logText->setText(ui->logText->toPlainText() + "\n" + message); // Сохранение сообщения в лог
    ui->logText->moveCursor(QTextCursor::End);                         // Прокрутка блока текста с логом вниз
}
