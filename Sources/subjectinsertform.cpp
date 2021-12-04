#include "subjectinsertform.h"
#include "ui_subjectinsertform.h"

SubjectInsertForm::SubjectInsertForm(QWidget* parent) : QWidget(parent), ui(new Ui::SubjectInsertForm) {

    ui->setupUi(this);

    connect(ui->nameLine, SIGNAL(textChanged(QString)), this, SLOT(onNameLineTextChanged()));       // nameLine, изменение значения
    connect(ui->shortNameLine, SIGNAL(textChanged(QString)), this, SLOT(onShortNameTextChanged())); // shortNameLine, изменение значения
    connect(ui->countSlider, SIGNAL(valueChanged(int)), this, SLOT(onCountSliderValueChanged()));   // countSlider, изменение значения

    connect(ui->addingButton, SIGNAL(clicked()), this, SLOT(onAddingButtonClicked())); // addingButton, нажатие
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));     // exitButton, нажатие

    ui->countSlider->setRange(8, 50);                      // Установка границ
    ui->countSlider->setPageStep(2);                       // Установка шага
    ui->countSlider->setValue(24);                         // Установка значения по умолчанию
    ui->countSlider->setTickPosition(QSlider::TicksAbove); // Установка рисок

    ui->nameLine->setPlaceholderText("Основы свапа ЗМЗ для любознательных"); // Сохранение подсказки в nameLine
    ui->shortNameLine->setPlaceholderText("Свап ЗМЗ, основы");               // сохранение подсказки в shortNameLine

    this->setFocus(); // Установка фокуса на виджет

    ui->logText->setText("Debug(), SubjectInsertForm"); // Заголовок для лога
    ui->logText->setReadOnly(true);                     // Заблокировать редактирование
}

SubjectInsertForm::~SubjectInsertForm() { delete ui; }

// Приёмник моделей QSqlTableModel и QSqlQueryModel
void SubjectInsertForm::resirvedData(QSqlTableModel* resModel, QSqlQueryModel* resQueryModel) {

    model = resModel;           // Сохранение модели
    queryModel = resQueryModel; // Сохранение запросной модели

    while (model->canFetchMore()) {

        model->fetchMore();
    }

    errorCounter = 1;      // Зануление счётчика ошибок
    SetLinesEmptyValues(); // Сохранение пустых строк в текстовые поля

    QString str = "SELECT [Идентификатор предмета] "
                  "FROM Предмет "
                  "WHERE [Идентификатор предмета] = ( "
                  "    SELECT MAX([Идентификатор предмета]) "
                  "    FROM Предмет "
                  ")";
    queryModel->setQuery(str);

    ui->IDLine->setText(QString::number(queryModel->index(0, 0).data().toInt() + 1)); // Установка текста в IDLine
}

// nameLine, изменение значения
void SubjectInsertForm::onNameLineTextChanged() {

    DisableAddingButton(); // Блокировка-разблокировка кнопки добавления
}

// shortNameLine, изменение значения
void SubjectInsertForm::onShortNameTextChanged() {

    DisableAddingButton(); // Блокировка-разблокировка кнопки добавления
}

// countSlider, изменение значения
void SubjectInsertForm::onCountSliderValueChanged() {

    ui->countLabel->setText(QString::number(ui->countSlider->value())); // Сохранение кол-ва часов в countLabel
}

// addingButton, нажатие
void SubjectInsertForm::onAddingButtonClicked() {

    if (CheckCurrentValue()) {

        AddSubjectToModel();   // Добавлене записи
        SetLinesEmptyValues(); // Сохранение пустых строк в текстовые поля
    } else {

        SetLinesEmptyValues(); // Сохранение пустых строк в текстовые поля
    }
}

// exitButton, нажатие
void SubjectInsertForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}

// Установить нулевые значения для текстовых полей
void SubjectInsertForm::SetLinesEmptyValues() {

    ui->nameLine->setText("");      // Сохранение пустой строки в nameLine
    ui->shortNameLine->setText(""); // Сохранение пустой строки в shortNameLine
}

// Сохранение отладочного сообщения в лог
void SubjectInsertForm::Debug(QString message) {

    ui->logText->setText(ui->logText->toPlainText() + "\n" + message); // Сохранение сообщения в лог
    ui->logText->moveCursor(QTextCursor::End);                         // Прокрутка блока текста с логом вниз
}

// Блокировка-разблокировка кнопки добавления
void SubjectInsertForm::DisableAddingButton() {

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

// Проверка текущего показания полей на соответствие для вставки
bool SubjectInsertForm::CheckCurrentValue() {

    if (CheckKeys())
        if (CheckNames())
            if (CheckShortNames())
                return true; // Проверки пройдены

    return false; // Проверки не пройдены
}

// Проверка ключевых полей на повторы
bool SubjectInsertForm::CheckKeys() {

    QString str = "SELECT * FROM Предмет WHERE [Идентификатор предмета] = %1";
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

// Проверка названий на повторы
bool SubjectInsertForm::CheckNames() {

    QString str = "SELECT * FROM Предмет WHERE [Название предмета] = '%1'";
    str = str.arg(ui->nameLine->text());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    if (queryModel->rowCount() != 0) {

        Debug("Запрос: " + str);
        Debug("Ошибка: предмет с таким названием уже существует");

        Debug("Счётчик ошибок: " + QString::number(errorCounter));
        errorCounter++;

        return false;
    }

    return true;
}

// Проверка сокращённых названий на повторы
bool SubjectInsertForm::CheckShortNames() {

    QString str = "SELECT * FROM Предмет WHERE [Короткое название предмета] = '%1'";
    str = str.arg(ui->shortNameLine->text());

    queryModel->setQuery(str); // Выполнение запроса, проверка ключевых полей

    if (queryModel->rowCount() != 0) {

        Debug("Запрос: " + str);
        Debug("Ошибка: предмет с таким сокращённым названием уже существует");

        Debug("Счётчик ошибок: " + QString::number(errorCounter));
        errorCounter++;

        return false;
    }

    return true;
}

// Добавление предмета
void SubjectInsertForm::AddSubjectToModel() {

    QString str = "INSERT INTO Предмет ([Идентификатор предмета], [Название предмета], [Короткое название предмета], [Количество часов]) "
                  "VALUES(%1, '%2', '%3', %4)";

    int ID = ui->IDLine->text().toInt();           // Идентификатор предмета
    QString name = ui->nameLine->text();           // Название предмета
    QString shortName = ui->shortNameLine->text(); // Сокращённое название предмета
    int count = ui->countLabel->text().toInt();    // Количество часов

    str = str.arg(ID).arg(name).arg(shortName).arg(count);

    queryModel->setQuery(str); // Выполнение запроса

    // Обновление идентификатора предмета в IDLine
    ui->IDLine->setText(QString::number(ui->IDLine->text().toInt() + 1));

    model->select();
}
