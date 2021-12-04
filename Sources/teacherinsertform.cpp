#include "teacherinsertform.h"
#include "ui_teacherinsertform.h"

TeacherInsertForm::TeacherInsertForm(QWidget* parent) : QWidget(parent), ui(new Ui::TeacherInsertForm) {

    ui->setupUi(this);

    connect(ui->lastNameLine, SIGNAL(textChanged(QString)), this, SLOT(onLastNameLineTextChanged()));     // lastNameLine, изменение значения
    connect(ui->nameLine, SIGNAL(textChanged(QString)), this, SLOT(onNameLineTextChanged()));             // nameLine, изменение текста
    connect(ui->patronymicLine, SIGNAL(textChanged(QString)), this, SLOT(onPatronymicLineTextChanged())); // patronymicLine, изменение текста

    connect(ui->departmentBox, SIGNAL(currentTextChanged(QString)), this, SLOT(onDepartmentBoxTextChanged())); // departmentBox, изменение значения
    connect(ui->countSlider, SIGNAL(valueChanged(int)), this, SLOT(onCountSliderValueChanged()));              // countSlider, изменение значения

    connect(ui->addingButton, SIGNAL(clicked()), this, SLOT(onAddingButtonClicked())); // addingButton, нажатие
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));     // exitButton, нажатие

    ui->countSlider->setRange(1, 50);                      // Установка границ
    ui->countSlider->setPageStep(1);                       // Установка шага
    ui->countSlider->setValue(25);                         // Установка значения по умолчанию
    ui->countSlider->setTickPosition(QSlider::TicksAbove); // Установка рисок

    ui->lastNameLine->setPlaceholderText("Стамескин");   // Сохранение подсказки в lastNameLine
    ui->nameLine->setPlaceholderText("Николай");         // Сохранение подсказки в nameLine
    ui->patronymicLine->setPlaceholderText("Сергеевич"); // Сохранение подсказки в patronymicLine

    this->setFocus(); // Установка фокуса на виджет

    ui->logText->setText("Debug(), TeacherInsertForm"); // Заголовок для лога
    ui->logText->setReadOnly(true);                     // Заблокировать редактирование
}

TeacherInsertForm::~TeacherInsertForm() { delete ui; }

// lastNameLine, изменение значения
void TeacherInsertForm::onLastNameLineTextChanged() {

    DisableAddingButton(); // Блокировка-разблокировка кнопки добавления
}

// nameLine, изменение текста
void TeacherInsertForm::onNameLineTextChanged() {

    DisableAddingButton(); // Блокировка-разблокировка кнопки добавления
}

// patronymicLine, изменение текста
void TeacherInsertForm::onPatronymicLineTextChanged() {

    DisableAddingButton(); // Блокировка-разблокировка кнопки добавления
}

// departmentBox, изменение зачения
void TeacherInsertForm::onDepartmentBoxTextChanged() {

    // Сохранение идентификатора кафедры в departmentIDLabel
    ui->departmentIDLabel->setText(QString::number(ui->departmentBox->currentIndex() + 1));
}

// countSlider, изменение значения
void TeacherInsertForm::onCountSliderValueChanged() {

    // Сохранение стажа работы в countLabel
    ui->countLabel->setText(QString::number(ui->countSlider->value()));
}

// addingButton, нажатие
void TeacherInsertForm::onAddingButtonClicked() {

    if (CheckCurrentValue()) {

        AddTeacherToModel();   // Добавлене записи
        SetLinesEmptyValues(); // Сохранение пустых строк в текстовые поля
    } else {

        SetLinesEmptyValues(); // Сохранение пустых строк в текстовые поля
    }
}

// exitButton, нажатие
void TeacherInsertForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}

// Приёмник моделей QSqlTableModel и QSqlQueryModel
void TeacherInsertForm::resirvedData(QSqlTableModel* resModel, QSqlQueryModel* resQueryModel) {

    model = resModel;           // Сохранение модели
    queryModel = resQueryModel; // Сохранение запросной модели

    while (model->canFetchMore()) {

        model->fetchMore();
    }

    errorCounter = 1;   // Зануление счётчика ошибок
    warningCounter = 1; // Зануление счётчика предупреждений

    QStringList postList = {"Ассистент", "Преподаватель", "Доцент", "Профессор"}; // Список должностей
    QStringList departmentList = GetDepartmentsFromDatabase();                    // Список кафедр

    ui->departmentBox->addItems(departmentList);             // Сохранение списка кафедр в departmentBox
    ui->departmentBox->setCurrentText(departmentList.at(0)); // Сохранение значения по умолчанию в departmentBox

    ui->postBox->addItems(postList);             // Сохранение списка должностей в postBox
    ui->postBox->setCurrentText(postList.at(0)); // Сохранение значения по умолчанию в postBox

    SetLinesEmptyValues(); // Сохранение пустых строк в поля ввода

    ui->IDLabel->setText(QString::number(model->rowCount() + 1));
}

// Установить нулевые значения для текстовых полей
void TeacherInsertForm::SetLinesEmptyValues() {

    ui->lastNameLine->setText("");   // Сохранение пустой строки в lastNameLine
    ui->nameLine->setText("");       // Сохранение пустой строки в nameLine
    ui->patronymicLine->setText(""); // Сохранение пустой строки в patronymicLine
}

// Получение списка кафедр из БД
QStringList TeacherInsertForm::GetDepartmentsFromDatabase() {

    QStringList strList; // Список кафедр

    // Открытие таблицы "Кафедра"
    model->setTable("Кафедра");
    model->select();

    while (model->canFetchMore())
        model->fetchMore();

    for (int i = 0; i < model->rowCount(); i++) {

        strList.append(model->index(i, 1).data().toString());
    }

    // Открытие таблицы "Группа"
    model->setTable("Преподаватель");
    model->select();

    return strList;
}

// Сохранение отладочного сообщения в лог
void TeacherInsertForm::Debug(QString message) {

    ui->logText->setText(ui->logText->toPlainText() + "\n" + message); // Сохранение сообщения в лог
    ui->logText->moveCursor(QTextCursor::End);                         // Прокрутка блока текста с логом вниз
}

// Блокировка-разблокировка кнопки добавления
void TeacherInsertForm::DisableAddingButton() {

    if ((ui->lastNameLine->text() == "") || (ui->nameLine->text() == "") || (ui->patronymicLine->text() == "")) {

        if (ui->addingButton->isEnabled() == true) {

            ui->addingButton->setDisabled(true); // Одно из полей пустое, блокировка addingButton
        }
    } else {

        if (ui->addingButton->isEnabled() == false) {

            ui->addingButton->setDisabled(false); // Пустые поля отсутствуют, разблокировка addingButton
        }
    }
}

// Проверка текущего показания полей на соответствие для вставки
bool TeacherInsertForm::CheckCurrentValue() {

    if (CheckKeys())
        if (CheckFIO())
            return true; // Проверки пройдены

    return false; // Проверки не пройдены
}

// Проверка ключевых полей на повторы
bool TeacherInsertForm::CheckKeys() {

    QString str = "SELECT * FROM Преподаватель WHERE [Табельный номер] = %1";
    str = str.arg(ui->IDLabel->text().toInt());

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

// Проверка ФИО на повторы
bool TeacherInsertForm::CheckFIO() {

    QString str = "SELECT * FROM Преподаватель WHERE (Фамилия = '%1') AND (Имя = '%2') AND (Отчество = '%3')";
    str = str.arg(ui->lastNameLine->text()).arg(ui->nameLine->text()).arg(ui->patronymicLine->text());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    if (queryModel->rowCount() != 0) {

        Debug("Запрос: " + str);
        Debug("Предупреждение: преподаватель с таким ФИО уже существует");

        Debug("Счётчик предупреждений: " + QString::number(warningCounter));
        warningCounter++;
    }

    return true;
}

// Добавление преподавателя
void TeacherInsertForm::AddTeacherToModel() {

    QString str = "INSERT INTO Преподаватель ([Табельный номер], Фамилия, Имя, Отчество, Должность, [Стаж работы], [Идентификатор кафедры]) "
                  "VALUES(%1, '%2', '%3', '%4', '%5', %6, %7)";

    int teacherID = ui->IDLabel->text().toInt();              // Табельный номер
    QString lastName = ui->lastNameLine->text();              // Фамилия
    QString name = ui->nameLine->text();                      // Имя
    QString patronymic = ui->patronymicLine->text();          // Отчество
    QString post = ui->postBox->currentText();                // Должность
    int count = ui->countLabel->text().toInt();               // Стаж работы
    int departmentID = ui->departmentIDLabel->text().toInt(); // Идентификатор кафедры

    str = str.arg(teacherID).arg(lastName).arg(name).arg(patronymic).arg(post).arg(count).arg(departmentID);

    queryModel->setQuery(str); // Выполнение запроса

    ui->IDLabel->setText(QString::number(ui->IDLabel->text().toInt() + 1)); // Обновление табельного номера для IDLabel

    model->select();
}
