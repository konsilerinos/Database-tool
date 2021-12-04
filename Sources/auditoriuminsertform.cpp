#include "auditoriuminsertform.h"
#include "ui_auditoriuminsertform.h"

AuditoriumInsertForm::AuditoriumInsertForm(QWidget* parent) : QWidget(parent), ui(new Ui::AuditoriumInsertForm) {

    ui->setupUi(this);

    // Сохранение типов в typeBox
    ui->typeBox->addItem("Лабораторная");
    ui->typeBox->addItem("Лекционный зал");
    ui->typeBox->addItem("Семинарская");

    ui->typeBox->setCurrentText("Лекционный зал"); // Сохранение значения по умолчанию в typeBox
    ui->typeLabel->setText("150");                 // Сохранение значения по умолчанию в typeLabel

    connect(ui->typeBox, SIGNAL(currentTextChanged(QString)), this, SLOT(onTypeBoxTextChanged())); // typeBox, изменение значения

    connect(ui->bodyLine, SIGNAL(textChanged(QString)), this, SLOT(onBodyTextChanged()));     // bodyLine, изменение значения
    connect(ui->floorLine, SIGNAL(textChanged(QString)), this, SLOT(onFloorTextChanged()));   // floorLine, изменение текста
    connect(ui->numberLine, SIGNAL(textChanged(QString)), this, SLOT(onNumberTextChanged())); // numberLine, изменение текста

    connect(ui->addingButton, SIGNAL(clicked()), this, SLOT(onAddingButtonClicked())); // addingButton, нажатие
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));     // exitButton, нажатие

    ui->bodyLine->setPlaceholderText("1");   // Сохранение подсказки в bodyLine
    ui->floorLine->setPlaceholderText("2");  // Сохранение подсказки в floorLine
    ui->numberLine->setPlaceholderText("3"); // Сохранение подсказки в numberLine

    this->setFocus(); // Установка фокуса на виджет

    ui->logText->setText("Debug(), AuditoriumInsertForm"); // Заголовок для лога
    ui->logText->setReadOnly(true);                        // Заблокировать редактирование
}

AuditoriumInsertForm::~AuditoriumInsertForm() { delete ui; }

// typeBox, изменение текста
void AuditoriumInsertForm::onTypeBoxTextChanged() {

    if (ui->typeBox->currentText() == "Лабораторная") {

        ui->typeLabel->setText("30");
    } else if (ui->typeBox->currentText() == "Семинарская") {

        ui->typeLabel->setText("35");
    } else if (ui->typeBox->currentText() == "Лекционный зал") {

        ui->typeLabel->setText("150");
    }
}

// bodyLine, изменение текста
void AuditoriumInsertForm::onBodyTextChanged() {

    DisableAddingButton(); // Блокировка-разблокировка кнопки добавления
}

// floorLine, изменение текста
void AuditoriumInsertForm::onFloorTextChanged() {

    DisableAddingButton(); // Блокировка-разблокировка кнопки добавления
}

// numberLine, изменение текста
void AuditoriumInsertForm::onNumberTextChanged() {

    DisableAddingButton(); // Блокировка-разблокировка кнопки добавления
}

// addingbutton, нажатие
void AuditoriumInsertForm::onAddingButtonClicked() {

    if (CheckCurrentValue()) {

        AddAuditoriumToModel(); // Добавлене записи

        // Очистка полей ввода
        SetLinesEmptyValues();

    } else {

        // Очистка полей ввода
        SetLinesEmptyValues();
    }
}

// exitButton, нажатие
void AuditoriumInsertForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}

// Приёмник моделей QSqlTableModel и QSqlQueryModel
void AuditoriumInsertForm::resirvedData(QSqlTableModel* resModel, QSqlQueryModel* resQueryModel) {

    model = resModel;           // Сохранение модели
    queryModel = resQueryModel; // Сохранение запросной модели

    while (model->canFetchMore()) {

        model->fetchMore();
    }

    SetLinesEmptyValues(); // Сохранение пустых строк в поля ввода

    errorCounter = 1; // Зануление счётчика ошибок
}

// Установить нулевые значения для текстовых полей
void AuditoriumInsertForm::SetLinesEmptyValues() {

    ui->bodyLine->setText("");   // Сохранение пустой строки в поле bodyLine
    ui->floorLine->setText("");  // Сохранение пустой строки в поле floorLine
    ui->numberLine->setText(""); // Сохранение пустой строки в поле numberLine
}

// Сохранение отладочного сообщения в лог
void AuditoriumInsertForm::Debug(QString message) {

    ui->logText->setText(ui->logText->toPlainText() + "\n" + message); // Сохранение сообщения в лог
    ui->logText->moveCursor(QTextCursor::End);                         // Прокрутка блока текста с логом вниз
}

// Блокировка-разблокировка кнопки добавления
void AuditoriumInsertForm::DisableAddingButton() {

    if ((ui->bodyLine->text() == "") || (ui->floorLine->text() == "") || (ui->numberLine->text() == "")) {

        if (ui->addingButton->isEnabled() == true) {

            ui->addingButton->setDisabled(true); // Одно из полей пустое, блокировка addingButton
        }
    } else {

        if (ui->addingButton->isEnabled() == false) {

            ui->addingButton->setDisabled(false); // Пустые поля отсутствуют, разблокировка addingButton
        }
    }
}

// Проверка ключевых полей
bool AuditoriumInsertForm::CheckCurrentValue() {

    if (CheckBodyFloorNumberValues())
        if (CheckKeys())
            return true; // Проверки проейдены

    return false; // Проверки не пройдены
}

// Проверка значений полей bodyLine, floorLine и numberLine
bool AuditoriumInsertForm::CheckBodyFloorNumberValues() {

    if (CheckBodyLine())
        if (CheckFloorLine())
            if (CheckNumberLine())
                return true; // Проверки пройдены

    return false; // Проверки не пройдены
}

// Проверка bodyLine на число
bool AuditoriumInsertForm::CheckBodyLine() {

    bool bodyFlag = ui->bodyLine->text().toInt(&bodyFlag, 10);

    if (!bodyFlag) {

        Debug("bodyLine->text() = '" + ui->bodyLine->text() + "'");
        Debug("Ошибка: невозможно преобразовать в целое число");

        Debug("Счётчик ошибок: " + QString::number(errorCounter));
        errorCounter++;

        return false;
    } else {

        if (ui->bodyLine->text().toInt() <= 0) {

            Debug("bodyLine->text().toInt() = '" + ui->bodyLine->text() + "'");
            Debug("Ошибка: число не является натуральным");

            Debug("Счётчик ошибок: " + QString::number(errorCounter));
            errorCounter++;

            return false;
        }
    }

    return true;
}

// Проверка floorLine на число
bool AuditoriumInsertForm::CheckFloorLine() {

    bool floorFlag = ui->floorLine->text().toInt(&floorFlag, 10);

    if (!floorFlag) {

        Debug("floorLine->text() = '" + ui->floorLine->text() + "'");
        Debug("Ошибка: невозможно преобразовать в целое число");

        Debug("Счётчик ошибок: " + QString::number(errorCounter));
        errorCounter++;

        return false;
    } else {

        if (ui->floorLine->text().toInt() <= 0) {

            Debug("floorLine->text().toInt() = '" + ui->floorLine->text() + "'");
            Debug("Ошибка: число не является натуральным");

            Debug("Счётчик ошибок: " + QString::number(errorCounter));
            errorCounter++;

            return false;
        }
    }

    return true;
}

// Проверка numberLine на число
bool AuditoriumInsertForm::CheckNumberLine() {

    bool numberFlag = ui->numberLine->text().toInt(&numberFlag, 10);

    if (!numberFlag) {

        Debug("numberLine->text() = '" + ui->numberLine->text() + "'");
        Debug("Ошибка: невозможно преобразовать в целое число");

        Debug("Счётчик ошибок: " + QString::number(errorCounter));
        errorCounter++;

        return false;
    } else {

        if (ui->numberLine->text().toInt() <= 0) {

            Debug("numberLine->text().toInt() = '" + ui->numberLine->text() + "'");
            Debug("Ошибка: число не является натуральным");

            Debug("Счётчик ошибок: " + QString::number(errorCounter));
            errorCounter++;

            return false;
        }
    }

    return true;
}

// Проверка ключевых полей на повторение
bool AuditoriumInsertForm::CheckKeys() {

    QString str = "SELECT * FROM Аудитория WHERE ([Корпус] = %1) AND ([Этаж] = %2) AND ([Номер] = %3)";
    str = str.arg(ui->bodyLine->text().toInt()).arg(ui->floorLine->text().toInt()).arg(ui->numberLine->text().toInt());

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

// Добавление аудитории
void AuditoriumInsertForm::AddAuditoriumToModel() {

    QString str = "INSERT INTO Аудитория (Корпус, Этаж, Номер, [Тип аудитории], Вместимость) "
                  "VALUES(%1, %2, %3, '%4', %5)";

    int body = ui->bodyLine->text().toInt();      // Корпус
    int floor = ui->floorLine->text().toInt();    // Этаж
    int number = ui->numberLine->text().toInt();  // Номер
    int capacity = ui->typeLabel->text().toInt(); // Вместимость аудитории

    str = str.arg(body).arg(floor).arg(number).arg(ui->typeBox->currentText()).arg(capacity);

    queryModel->setQuery(str); // Выполнение запроса

    model->select();
}
