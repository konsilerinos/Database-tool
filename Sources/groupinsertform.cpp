#include "groupinsertform.h"
#include "ui_groupinsertform.h"

GroupInsertForm::GroupInsertForm(QWidget* parent) : QWidget(parent), ui(new Ui::GroupInsertForm) {

    ui->setupUi(this);

    connect(ui->departmentBox, SIGNAL(currentTextChanged(QString)), this, SLOT(onDepartmentBoxTextChanged())); // departmentBox, изменение значения
    connect(ui->countSlider, SIGNAL(valueChanged(int)), this, SLOT(onCountSliderValueChanged()));              // countSlider, изменение значения

    connect(ui->groupNumberLine, SIGNAL(textChanged(QString)), this, SLOT(onGroupNumberLineTextChanged())); // groupNumberLine, изменение текста

    connect(ui->addingButton, SIGNAL(clicked()), this, SLOT(onAddingButtonClicked())); // addingButton, нажатие
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));     // exitButton, нажатие

    ui->countSlider->setRange(15, 35);                     // Установка границ
    ui->countSlider->setPageStep(1);                       // Установка шага
    ui->countSlider->setValue(20);                         // Установка значения по умолчанию
    ui->countSlider->setTickPosition(QSlider::TicksAbove); // Установка рисок

    ui->groupNumberLine->setPlaceholderText("АБВГД-7"); // Сохранение подсказки в groupNumberLine

    this->setFocus(); // Установка фокуса на виджет

    ui->logText->setText("Debug(), GroupInsertForm"); // Заголовок для лога
    ui->logText->setReadOnly(true);                   // Заблокировать редактирование
}

GroupInsertForm::~GroupInsertForm() { delete ui; }

// Приёмник моделей QSqlTableModel и QSqlQueryModel
void GroupInsertForm::resirvedData(QSqlTableModel* resModel, QSqlQueryModel* resQueryModel) {

    model = resModel;           // Сохранение модели
    queryModel = resQueryModel; // Сохранение запросной модели

    while (model->canFetchMore()) {

        model->fetchMore();
    }

    errorCounter = 1; // Зануление счётчика ошибок

    // Установка списка кафедр в departmentBox
    ui->departmentBox->addItems(GetDepartmentsFromDatabase());

    SetLinesEmptyValues(); // Сохранение пустых строк в поля ввода

    emit ui->departmentBox->currentIndexChanged("");
}

// addingbutton, нажатие
void GroupInsertForm::onAddingButtonClicked() {

    if (CheckCurrentValue()) {

        AddGroupToModel();     // Добавлене записи
        SetLinesEmptyValues(); // Сохранение пустых строк в текстовые поля
    } else {

        SetLinesEmptyValues(); // Сохранение пустых строк в текстовые поля
    }
}

// exitButton, нажатие
void GroupInsertForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}

// departmentBox, изменение значения
void GroupInsertForm::onDepartmentBoxTextChanged() {

    // Сохранение идентификатора в departmentIDLabel
    ui->departmentIDLabel->setText(QString::number(ui->departmentBox->currentIndex() + 1));

    // Сохранение сокращённых названий для кафедр
    QStringList shortNames = GetDepartmentsShortsFromDatabase();
    ui->shortNameLabel->setText(shortNames[ui->departmentBox->currentIndex()]);
}

// countSlider, изменение значения
void GroupInsertForm::onCountSliderValueChanged() {

    // Сохранение численности в countLabel
    ui->countLabel->setText(QString::number(ui->countSlider->value()));
}

// groupNumberLine, изменение текста
void GroupInsertForm::onGroupNumberLineTextChanged() {

    DisableAddingButton(); // Блокировка-разблокировка кнопки добавления
}

// Установить нулевые значения для текстовых полей
void GroupInsertForm::SetLinesEmptyValues() {

    ui->groupNumberLine->setText(""); // Сохранение пустой строки в groupNumberLine
}

// Получение списка кафедр из БД
QStringList GroupInsertForm::GetDepartmentsFromDatabase() {

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
    model->setTable("Группа");
    model->select();

    return strList;
}

// Получение сокращённых имён для кафедр из БД
QStringList GroupInsertForm::GetDepartmentsShortsFromDatabase() {

    QStringList strList; // Список кафедр

    // Открытие таблицы "Кафедра"
    model->setTable("Кафедра");
    model->select();

    while (model->canFetchMore())
        model->fetchMore();

    for (int i = 0; i < model->rowCount(); i++) {

        strList.append(model->index(i, 2).data().toString());
    }

    // Открытие таблицы "Группа"
    model->setTable("Группа");
    model->select();

    return strList;
}

// Сохранение отладочного сообщения в лог
void GroupInsertForm::Debug(QString message) {

    ui->logText->setText(ui->logText->toPlainText() + "\n" + message); // Сохранение сообщения в лог
    ui->logText->moveCursor(QTextCursor::End);                         // Прокрутка блока текста с логом вниз
}

// Блокировка-разблокировка кнопки добавления
void GroupInsertForm::DisableAddingButton() {

    if (ui->groupNumberLine->text() == "") {

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
bool GroupInsertForm::CheckCurrentValue() {

    QString str = "SELECT * FROM Группа WHERE [Номер группы] = '%1'";
    str = str.arg(ui->groupNumberLine->text());

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
void GroupInsertForm::AddGroupToModel() {

    QString str = "INSERT INTO Группа ([Номер группы], [Название кафедры], [Количество студентов], [Идентификатор кафедры]) "
                  "VALUES('%1', %2, %3, %4)";

    QString groupNumber = ui->groupNumberLine->text();          // Номер группы
    int departmentName = ui->departmentBox->currentIndex() + 1; // Название кафедры
    int studentsCount = ui->countLabel->text().toInt();         // Количество студентов

    str = str.arg(groupNumber).arg(departmentName).arg(studentsCount).arg(departmentName);

    queryModel->setQuery(str); // Выполнение запроса

    model->select();
}
