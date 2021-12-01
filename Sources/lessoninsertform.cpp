#include "lessoninsertform.h"
#include "ui_lessoninsertform.h"

LessonInsertForm::LessonInsertForm(QWidget* parent) : QWidget(parent), ui(new Ui::LessonInsertForm) {

    ui->setupUi(this);

    SetDays();   // Сохранение дней в dayBox
    SetMonths(); // Сохранение месяцев в monthBox
    SetYears();  // Сохранение годов в yearBox
    SetTimes();  // Сохранение времён в timeBox
    SetTypes();  // Сохранение типов в typeBox

    connect(ui->addingButton, SIGNAL(clicked()), this, SLOT(onAddingButtonClicked())); // addingButton, нажатие
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));     // exitButton, нажатие

    this->setFocus(); // Установка фокуса на виджет

    ui->logText->setText("Debug(), LessonInsertForm"); // Заголовок для лога
    ui->logText->setReadOnly(true);                    // Заблокировать редактирование
}

LessonInsertForm::~LessonInsertForm() { delete ui; }

// Приёмник моделей QSqlTableModel и QSqlQueryModel
void LessonInsertForm::resirvedData(QSqlTableModel* resModel, QSqlQueryModel* resQueryModel) {

    model = resModel;           // Сохранение модели
    queryModel = resQueryModel; // Сохранение запросной модели

    while (model->canFetchMore()) {

        model->fetchMore();
    }

    ui->bodyBox->addItems(GetAuditoriesBodies());    // Сохранение корпусов в bodyBox
    ui->floorBox->addItems(GetAuditoriesFloors());   // Сохранение этажей аудиторий в floorBox
    ui->numberBox->addItems(GetAuditoriesNumbers()); // Сохранение номеров в numberBox

    ui->groupBox->addItems(GetGroupsNames()); // Сохранение номеров групп в groupBox
    ui->IDBox->addItems(GetLessonsID());      // Сохранение идентификаторов предметов в IDBox

    errorCounter = 1;      // Зануление счётчика ошибок
    SetLinesEmptyValues(); // Сохранение пустых строк в текстовые поля
}

// addingButton, нажатие
void LessonInsertForm::onAddingButtonClicked() {

    if (CheckCurrentValue()) {

        AddLessonToModel();    // Добавлене записи
        SetLinesEmptyValues(); // Сохранение пустых строк в текстовые поля
    } else {

        SetLinesEmptyValues(); // Сохранение пустых строк в текстовые поля
    }
}

// exitButton, нажатите
void LessonInsertForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}

// Сохранение отладочного сообщения в лог
void LessonInsertForm::Debug(QString message) {

    ui->logText->setText(ui->logText->toPlainText() + "\n" + message); // Сохранение сообщения в лог
    ui->logText->moveCursor(QTextCursor::End);                         // Прокрутка блока текста с логом вниз
}

// Сохранение дней, месяцев и годов
void LessonInsertForm::SetDays() {

    // Сохранение дней
    for (int i = 1; i <= 31; i++) {

        ui->dayBox->addItem(QString::number(i));
    }
    ui->dayBox->setCurrentText("1");
}

// Сохранение месяцев
void LessonInsertForm::SetMonths() {

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

// Сохранение годов
void LessonInsertForm::SetYears() {

    // Сохранение годов
    for (int i = 2021; i <= 2050; i++) {

        ui->yearBox->addItem(QString::number(i));
    }
    ui->yearBox->setCurrentText("2021");
}

// Сохранение времён в timeBox
void LessonInsertForm::SetTimes() {

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
void LessonInsertForm::SetTypes() {

    // Сохранение типов в typeBox
    ui->typeBox->addItem("Лабораторная работа");
    ui->typeBox->addItem("Лекция");
    ui->typeBox->addItem("Семинар");

    // Установка типа по умолчанию
    ui->typeBox->setCurrentText("Лабораторная работа");
}

// Установка значений по умолчанию
void LessonInsertForm::SetLinesEmptyValues() { ui->floorBox->setCurrentText(""); }

// Получить идентификаторы предметов из БД
QStringList LessonInsertForm::GetLessonsID() {

    QStringList strList; // Список корпусов
    QString str = "SELECT * FROM Предмет";

    queryModel->setQuery(str); // Выполнение запроса

    for (int i = 0; i < queryModel->rowCount(); i++) {

        strList.append(queryModel->index(i, 0).data().toString());
    }

    return strList;
}

// Получить названия групп из БД
QStringList LessonInsertForm::GetGroupsNames() {

    QStringList strList; // Список корпусов
    QString str = "SELECT [Номер группы] FROM Группа";

    queryModel->setQuery(str); // Выполнение запроса

    for (int i = 0; i < queryModel->rowCount(); i++) {

        strList.append(queryModel->index(i, 0).data().toString());
    }

    return strList;
}

// Получить корпуса аудиторий из БД
QStringList LessonInsertForm::GetAuditoriesBodies() {

    QStringList strList; // Список корпусов
    QString str = "SELECT DISTINCT Корпус FROM Аудитория";

    queryModel->setQuery(str); // Выполнение запроса

    for (int i = 0; i < queryModel->rowCount(); i++) {

        strList.append(queryModel->index(i, 0).data().toString());
    }

    return strList;
}

// Получить этажи аудиторий из БД
QStringList LessonInsertForm::GetAuditoriesFloors() {

    QStringList strList; // Список корпусов
    QString str = "SELECT DISTINCT Этаж FROM Аудитория";

    queryModel->setQuery(str); // Выполнение запроса

    for (int i = 0; i < queryModel->rowCount(); i++) {

        strList.append(queryModel->index(i, 0).data().toString());
    }

    return strList;
}

// Получить номера аудиторий из БД
QStringList LessonInsertForm::GetAuditoriesNumbers() {

    QStringList strList; // Список корпусов
    QString str = "SELECT DISTINCT Номер FROM Аудитория";

    queryModel->setQuery(str); // Выполнение запроса

    for (int i = 0; i < queryModel->rowCount(); i++) {

        strList.append(queryModel->index(i, 0).data().toString());
    }

    return strList;
}

// Проверка текущего показания полей на соответствие для вставки
bool LessonInsertForm::CheckCurrentValue() {

    if (CheckDate())
        if (CheckKeys())
            return true; // Проверки пройдены

    return false; // Проверки не пройдены
}

// Проверка даты
bool LessonInsertForm::CheckDate() {

    int year = ui->yearBox->currentText().toInt(); // Год
    int month = ui->monthBox->currentIndex() + 1;  // Месяц
    int day = ui->dayBox->currentText().toInt();   // День

    QDate date(year, month, day); // Сохранение даты

    if (!date.isValid()) {

        QString str = "'%1.%2.%3' (год-месяц-день)";
        str = str.arg(QString::number(year)).arg(QString::number(month)).arg(QString::number(day));

        Debug("Дата: " + str);
        Debug("Ошибка: некорректная дата");

        Debug("Счётчик ошибок: " + QString::number(errorCounter));
        errorCounter++;

        return false;
    }

    return true;
}

// Проверка ключевых полей на повторы
bool LessonInsertForm::CheckKeys() {

    QString str = "SELECT * FROM Занятие WHERE ([День проведения] = #%1#) AND ([Время проведения] = #%2#) AND "
                  "(Тип = '%3') AND ([Идентификатор предмета] = %4)";

    QString date = "%1/%2/%3"; // Дата проведения
    date = date.arg(ui->monthBox->currentIndex() + 1).arg(ui->dayBox->currentText().toInt()).arg(ui->yearBox->currentText().toInt());

    QString time = ui->timeBox->currentText() + ":00"; // Время проведения
    QString type = ui->typeBox->currentText();         // Тип
    int lessonID = ui->IDBox->currentText().toInt();   // Идентификатор предмета

    str = str.arg(date).arg(time).arg(type).arg(lessonID);

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    if (queryModel->rowCount() != 0) {

        Debug("Запрос: " + str);
        Debug("Ошибка: запись с такими ключевыми полями уже существует");

        Debug("Счётчик ошибок: " + QString::number(errorCounter));
        errorCounter++;

        return false;
    }

    return true;
}

// Добавление предмета
void LessonInsertForm::AddLessonToModel() {

    QString str = "INSERT INTO Занятие ([День проведения], [Время проведения], Тип, "
                  "[Идентификатор предмета], [Корпус аудитории], [Этаж аудитории], "
                  "[Номер аудитории], [Номер группы]) "
                  "VALUES(%1, %2, '%3', %4, %5, %6, %7, '%8')";

    int month = ui->monthBox->currentIndex() + 1;  // Месяц
    int day = ui->dayBox->currentText().toInt();   // День
    int year = ui->yearBox->currentText().toInt(); // Год

    QString date = "#%1/%2/%3#"; // Дата проведения
    date = date.arg(month).arg(day).arg(year);

    QString time = "#" + ui->timeBox->currentText() + ":00#"; // Время проведения
    QString type = ui->typeBox->currentText();                // Тип
    int lessonID = ui->IDBox->currentText().toInt();          // Идентификатор предмета

    int body = ui->bodyBox->currentText().toInt();     // Корпус аудитории
    int floor = ui->floorBox->currentText().toInt();   // Этаж аудитории
    int number = ui->numberBox->currentText().toInt(); // Номер аудитории

    QString groupNumber = ui->groupBox->currentText(); // Номер группы

    str = str.arg(date).arg(time).arg(type).arg(lessonID).arg(body).arg(floor).arg(number).arg(groupNumber);

    queryModel->setQuery(str); // Выполнение запроса

    model->select();
}
