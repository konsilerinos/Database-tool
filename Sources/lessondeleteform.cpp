#include "lessondeleteform.h"
#include "ui_lessondeleteform.h"

LessonDeleteForm::LessonDeleteForm(QWidget* parent) : QWidget(parent), ui(new Ui::LessonDeleteForm) {

    ui->setupUi(this);

    SetDays();   // Сохранение дней в dayBox
    SetMonths(); // Сохранение месяцев в monthBox
    SetYears();  // Сохранение годов в yearBox
    SetTimes();  // Сохранение времён в timeBox
    SetTypes();  // Сохранение типов в typeBox

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));     // exitButton, нажатие
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(onDeleteButtonClicked())); // deleteButton, нажатие

    ui->logText->setText("Debug(), SubjectDeleteForm"); // Заголовок для лога
    ui->logText->setReadOnly(true);                     // Заблокировать редактирование
}

LessonDeleteForm::~LessonDeleteForm() { delete ui; }

// Приёмник моделей QSqlTableModel и QSqlQueryModel
void LessonDeleteForm::resirvedData(QSqlTableModel* resModel, QSqlQueryModel* resQueryModel) {

    model = resModel;           // Сохранение модели
    queryModel = resQueryModel; // Сохранение запросной модели

    while (model->canFetchMore()) {

        model->fetchMore();
    }

    SaveID(); // Сохранение идентификаторв предметов в IDBox

    deleteCounter = 1; // Сброс счётчика удалений
}

// deleteButton, нажатие
void LessonDeleteForm::onDeleteButtonClicked() {

    Debug("Счётчик удаления: " + QString::number(deleteCounter));
    deleteCounter++;

    DeleteLesson(); // Удаление занятия

    model->select();
}

// exitButton, нажатите
void LessonDeleteForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}

// Сохранение дней в dayBox
void LessonDeleteForm::SetDays() {

    // Сохранение дней
    for (int i = 1; i <= 31; i++) {

        ui->dayBox->addItem(QString::number(i));
    }
    ui->dayBox->setCurrentText("1");
}

// Сохранение месяцев в monthBox
void LessonDeleteForm::SetMonths() {

    // Сохранение месяцев
    ui->monthBox->addItem("Январь");
    ui->monthBox->addItem("Февраль");
    ui->monthBox->addItem("Март");
    ui->monthBox->addItem("Апрель");
    ui->monthBox->addItem("Май");
    ui->monthBox->addItem("Июнь");
    ui->monthBox->addItem("Июль");
    ui->monthBox->addItem("Август");
    ui->monthBox->addItem("Сентябрь");
    ui->monthBox->addItem("Октябрь");
    ui->monthBox->addItem("Ноябрь");
    ui->monthBox->addItem("Декабрь");

    ui->monthBox->setCurrentText("Январь");
}

// Сохранение годов в yearBox
void LessonDeleteForm::SetYears() {

    // Сохранение годов
    for (int i = 2021; i <= 2050; i++) {

        ui->yearBox->addItem(QString::number(i));
    }
    ui->yearBox->setCurrentText("2021");
}

// Сохранение времён в timeBox
void LessonDeleteForm::SetTimes() {

    // Сохранение времени в timeBox
    ui->timeBox->addItem("9:00");
    ui->timeBox->addItem("10:40");
    ui->timeBox->addItem("12:20");
    ui->timeBox->addItem("14:30");
    ui->timeBox->addItem("16:10");
    ui->timeBox->addItem("18:20");
    ui->timeBox->addItem("20:00");

    // Установка времени по умолчанию
    ui->timeBox->setCurrentText("09:00");
}

// Сохранение типов в typeBox
void LessonDeleteForm::SetTypes() {

    // Сохранение типов в typeBox
    ui->typeBox->addItem("Лабораторная работа");
    ui->typeBox->addItem("Лекция");
    ui->typeBox->addItem("Семинар");

    // Установка типа по умолчанию
    ui->typeBox->setCurrentText("Лабораторная работа");
}

// Сохранение идентификаторв предметов в IDBox
void LessonDeleteForm::SaveID() {

    IDList.clear();     // Очистка IDList
    ui->IDBox->clear(); // Очистка IDBox

    QString str = "SELECT * FROM Предмет";

    queryModel->setQuery(str); // Выполнение запроса

    for (int i = 0; i < queryModel->rowCount(); i++) {

        IDList.append(queryModel->index(i, 0).data().toString());
    }

    ui->IDBox->addItems(IDList); // Сохранение идентификаторов предметов в IDBox
}

// Удаление занятия
void LessonDeleteForm::DeleteLesson() {

    // Выборка занятий
    QString str = "SELECT * FROM Занятие WHERE ([День проведения] = #%1#) AND ([Время проведения] = #%2#) AND "
                  "(Тип = '%3') AND ([Идентификатор предмета] = %4)";

    QString date = "%1/%2/%3"; // Дата проведения

    date = date.arg(ui->monthBox->currentIndex() + 1).arg(ui->dayBox->currentText().toInt()).arg(ui->yearBox->currentText().toInt());

    QString time = ui->timeBox->currentText() + ":00"; // Время проведения
    QString type = ui->typeBox->currentText();         // Тип
    int lessonID = ui->IDBox->currentText().toInt();   // Идентификатор предмета

    str = str.arg(date).arg(time).arg(type).arg(lessonID);

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    Debug("Удалено записей из таблицы \"Занятие\": " + QString::number(queryModel->rowCount()));

    // Удаление занятий
    str = "DELETE * FROM Занятие WHERE ([День проведения] = #%1#) AND ([Время проведения] = #%2#) AND "
          "(Тип = '%3') AND ([Идентификатор предмета] = %4)";

    date = "%1/%2/%3"; // Дата проведения

    date = date.arg(ui->monthBox->currentIndex() + 1).arg(ui->dayBox->currentText().toInt()).arg(ui->yearBox->currentText().toInt());

    time = ui->timeBox->currentText() + ":00";   // Время проведения
    type = ui->typeBox->currentText();           // Тип
    lessonID = ui->IDBox->currentText().toInt(); // Идентификатор предмета

    str = str.arg(date).arg(time).arg(type).arg(lessonID);

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    SaveID(); // Сохранение идентификаторв предметов в IDBox
}

// Сохранение отладочного сообщения в лог
void LessonDeleteForm::Debug(QString message) {

    ui->logText->setText(ui->logText->toPlainText() + "\n" + message); // Сохранение сообщения в лог
    ui->logText->moveCursor(QTextCursor::End);                         // Прокрутка блока текста с логом вниз
}
