#include "departmentinsertform.h"
#include "ui_departmentinsertform.h"

DepartmentInsertForm::DepartmentInsertForm(QWidget* parent) : QWidget(parent), ui(new Ui::DepartmentInsertForm) {

    ui->setupUi(this);

    // Определение сигналов и слотов
    SetSignals();

    // Установить свойства для countSlider
    SetSliderProperties();

    ui->nameLine->setPlaceholderText("Придумывания подсказок для QLineEdit"); // Сохранение подсказки в nameLine
    ui->shortNameLine->setPlaceholderText("ПДКЛЕ");                           // Сохранение подсказки в shortNameLine

    this->setFocus(); // Установка фокуса на виджет

    ui->logText->setText("Debug(), DepartmentInsertForm"); // Заголовок для лога
    ui->logText->setReadOnly(true);                        // Заблокировать редактирование
}

DepartmentInsertForm::~DepartmentInsertForm() { delete ui; }

// addingButton, нажатие. Отправка сигнала с dep
void DepartmentInsertForm::onAddingButtonClicked() {

    if (CheckCurrentValue()) {

        AddDepartmentToModel(); // Добавлене записи

        // Обновление IDLine
        ui->IDLine->setText(QString::number(ui->IDLine->text().toInt() + 1));

        SetLinesEmptyValues(); // Сохранение пустых строк в текстовые поля
    } else {

        SetLinesEmptyValues(); // Сохранение пустых строк в текстовые поля
    }
}

// exitButton, нажатие
void DepartmentInsertForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}

// countSlider, изменено значение
void DepartmentInsertForm::onCountSliderValueChanged() {

    ui->countLabel->setText(QString::number(ui->countSlider->value())); // Установка текста
}

// nameLine, изменение текста
void DepartmentInsertForm::onNameLineTextChanged() {

    DisableAddingButton(); // Блокировка-разблокировка кнопки добавления
}

// shortNameLine, изменение текста
void DepartmentInsertForm::onShortNameLineTextChanged() {

    DisableAddingButton(); // Блокировка-разблокировка кнопки добавления
}

// Революция!!!1!
void DepartmentInsertForm::resirvedData(QSqlTableModel* resModel, QSqlQueryModel* resQueryModel) {

    model = resModel;           // Сохранение модели
    queryModel = resQueryModel; // Сохранение запросной модели

    while (model->canFetchMore()) {

        model->fetchMore();
    }

    QString str = "SELECT [Идентификатор кафедры] "
                  "FROM Кафедра "
                  "WHERE [Идентификатор кафедры] = ( "
                  "    SELECT MAX([Идентификатор кафедры]) "
                  "    FROM Кафедра "
                  ")";
    queryModel->setQuery(str);

    ui->IDLine->setText(QString::number(queryModel->index(0, 0).data().toInt() + 1)); // Установка текста в IDLine

    errorCounter = 1;      // Зануление счётчика ошибок
    SetLinesEmptyValues(); // Сохранение пустых строк в текстовые поля
}

// Установить свойства для countSlider
void DepartmentInsertForm::SetSliderProperties() {

    ui->countSlider->setRange(10, 20);                     // Установка границ
    ui->countSlider->setPageStep(1);                       // Установка шага
    ui->countSlider->setValue(15);                         // Установка значения по умолчанию
    ui->countSlider->setTickPosition(QSlider::TicksAbove); // Установка рисок
}

// Установить нулевые значения для текстовых полей
void DepartmentInsertForm::SetLinesEmptyValues() {

    ui->nameLine->setText("");      // Сохранение пустой строки в поле nameLine
    ui->shortNameLine->setText(""); // Сохранение пустой строки в поле shortNameLine
}

// Определение сигналов и слотов
void DepartmentInsertForm::SetSignals() {

    connect(ui->addingButton, SIGNAL(clicked()), this, SLOT(onAddingButtonClicked()));                  // departmentAddingButton, нажатие
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));                      // exitButton, нажатие
    connect(ui->countSlider, SIGNAL(valueChanged(int)), this, SLOT(onCountSliderValueChanged()));       // countSlider, изменение положения ползунка
    connect(ui->nameLine, SIGNAL(textChanged(QString)), this, SLOT(onNameLineTextChanged()));           // nameLine, изменение текста
    connect(ui->shortNameLine, SIGNAL(textChanged(QString)), this, SLOT(onShortNameLineTextChanged())); // shortNameLine, изменение текста
}

// Сохранение отладочного сообщения в лог
void DepartmentInsertForm::Debug(QString message) {

    ui->logText->setText(ui->logText->toPlainText() + "\n" + message); // Сохранение сообщения в лог
    ui->logText->moveCursor(QTextCursor::End);                         // Прокрутка блока текста с логом вниз
}

// Блокировка-разблокировка кнопки добавления
void DepartmentInsertForm::DisableAddingButton() {

    if ((ui->nameLine->text() == "") || (ui->shortNameLine->text() == "")) {

        if (ui->addingButton->isEnabled() == true) {

            ui->addingButton->setDisabled(true); // Одно из полей пустое, блокировка addingButton
        }
    } else {

        if (ui->addingButton->isEnabled() == false) {

            ui->addingButton->setDisabled(false); // Пустые поля отсутствуют, разблокировка addingButton
        }
    }
}

// Проверка ключевых полей, названий кафедр
bool DepartmentInsertForm::CheckCurrentValue() {

    if (CheckKeys())
        if (CheckNames())
            if (CheckShortNames())
                return true; // Проверки пройдены

    return false; // Проверки не пройдены
}

// Проверка ключевых полей на повторение
bool DepartmentInsertForm::CheckKeys() {

    QString str = "SELECT * FROM Кафедра WHERE [Идентификатор кафедры] = %1";
    str = str.arg(ui->IDLine->text().toInt());

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

// Проверка названий кафедр на повторение
bool DepartmentInsertForm::CheckNames() {

    QString str = "SELECT *  FROM Кафедра  WHERE [Название кафедры] = '%1'";
    str = str.arg(ui->nameLine->text());

    queryModel->setQuery(str); // Выполнение запроса, проверка уникальности названия

    if (queryModel->rowCount() != 0) {

        Debug("Запрос: " + str);
        Debug("Ошибка: кафедра с таким названием уже существует");

        Debug("Счётчик ошибок: " + QString::number(errorCounter));
        errorCounter++;

        return false;
    }

    return true;
}

// Проверка сокращённых названий на повторение
bool DepartmentInsertForm::CheckShortNames() {

    QString str = "SELECT *  FROM Кафедра  WHERE [Сокращённое название] = '%1'";
    str = str.arg(ui->shortNameLine->text());

    queryModel->setQuery(str); // Выполнение запроса, проверка уникальности сокращённого названия

    if (queryModel->rowCount() != 0) {

        Debug("Запрос: " + str);
        Debug("Ошибка: кафедра с таким сокращённым названием уже существует");

        Debug("Счётчик ошибок: " + QString::number(errorCounter));
        errorCounter++;

        return false;
    }

    return true;
}

// Добавление кафедры
void DepartmentInsertForm::AddDepartmentToModel() {

    QString str = "INSERT INTO Кафедра ([Идентификатор кафедры], [Название кафедры], [Сокращённое название], [Количество ставок]) "
                  "VALUES(%1, '%2', '%3', %4)";
    str = str.arg(ui->IDLine->text().toInt()).arg(ui->nameLine->text()).arg(ui->shortNameLine->text()).arg(ui->countLabel->text().toInt());

    queryModel->setQuery(str); // Выполнение запроса

    model->select();
}
