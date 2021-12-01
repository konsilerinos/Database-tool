#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    departmentInsertForm = new DepartmentInsertForm(); // Форма, используется для добавления кафедры
    auditoriumInsertForm = new AuditoriumInsertForm(); // Форма, используется для добавления аудитории
    groupInsertForm = new GroupInsertForm();           // Форма, используется для добавления группы
    teacherInsertForm = new TeacherInsertForm();       // Форма, используется для добавления преподавателя
    subjectInsertForm = new SubjectInsertForm();       // Форма, используется для добавления предмета
    lessonInsertForm = new LessonInsertForm();         // Форма, используется для добавления занятия

    requestsForm = new RequestsForm(); // Форма, используется для выбора запроса для отображения
    info = new Info();                 // Форма, используется для отображения информации о разработчике

    SetSignals(); // Определение сигналов и слотов

    SetTablesNames(); // Добавление названий таблиц в tablesNames

    OpenDatabase(); // Открытие БД

    queryModel = new QSqlQueryModel(this); // Модель, используется для выполнения запросов

    ui->tablesListWidget->setCurrentIndex(ui->tablesListWidget->model()->index(0, 0));
    ShowDatabaseTable(); // Вывод БД на экран

    // Установка режима "Только для чтения" для ячеек таблицы
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow() {

    delete departmentInsertForm; // Форма, используется для добавления кафедры
    delete auditoriumInsertForm; // Форма, используется для добавления аудитории
    delete groupInsertForm;      // Форма, используется для добавления группы
    delete teacherInsertForm;    // Форма, используется для добавления преподавателя
    delete subjectInsertForm;    // // Форма, используется для добавления предмета
    delete lessonInsertForm;     // Форма, используется для добавления занятия

    delete requestsForm; // Форма, используется для выбора запроса для отображения
    delete info;         // Форма, используется для отображения информации о разработчике

    delete model;      // Модель БД, необходима для её вывода на экран
    delete queryModel; // Модель, используется для выполнения запросов
    delete ui;
}

// Определение сигналов и слотов
void MainWindow::SetSignals() {

    connect(ui->addingButton, SIGNAL(clicked()), this, SLOT(onAddingButtonClicked()));     // addingButton, нажатие
    connect(ui->requestsButton, SIGNAL(clicked()), this, SLOT(onRequestsButtonClicked())); // requestsButton, нажатие
    connect(ui->infoButton, SIGNAL(clicked()), this, SLOT(onInfoButtonClicked()));         // infoButton, нажатие

    // tablesListWidget, изменение значения
    connect(ui->tablesListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onTablesListWidgetItemClicked()));

    // Отправка имени запроса из info в this
    connect(requestsForm, SIGNAL(SendRequestName(QString)), this, SLOT(recieveRequestName(QString)));

    // Отправка модели для выбора запроса
    connect(this, SIGNAL(SendDatabaseToRequestsForm(QSqlTableModel*)), requestsForm, SLOT(resirvedData(QSqlTableModel*)));

    // Отправка моделей для добавления кафедры
    connect(this, SIGNAL(SendDatabaseToDepartment(QSqlTableModel*, QSqlQueryModel*)), departmentInsertForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));

    // Отправка моделей для добавления аудитории
    connect(this, SIGNAL(SendDatabaseToAuditorium(QSqlTableModel*, QSqlQueryModel*)), auditoriumInsertForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));

    // Отправка моделей для добавления группы
    connect(this, SIGNAL(SendDatabaseToGroup(QSqlTableModel*, QSqlQueryModel*)), groupInsertForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));

    // Отправка моделей для добавления преподавателя
    connect(this, SIGNAL(SendDatabaseToTeacher(QSqlTableModel*, QSqlQueryModel*)), teacherInsertForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));

    // Отправка моделей для добавления предмета
    connect(this, SIGNAL(SendDatabaseToSubject(QSqlTableModel*, QSqlQueryModel*)), subjectInsertForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));

    // Отправка моделей для добавления занятия
    connect(this, SIGNAL(SendDatabaseToLesson(QSqlTableModel*, QSqlQueryModel*)), lessonInsertForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));
}

// addingButton, нажатие
void MainWindow::onAddingButtonClicked() {

    // Установка модели в исходное состояние
    model->setTable(ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text());
    model->select();

    // Открыть форму для добавления
    RunDepartmentForm(); // Кафедра
    RunAuditoriumForm(); // Аудитория
    RunGroupForm();      // Группы
    RunTeacherForm();    // Преподаватель
    RunSubjectForm();    // Предмет
    RunLessonForm();     // Занятие
}

// tablesListWidget, изменение значения
void MainWindow::onTablesListWidgetItemClicked() {

    // Обновление заголовка
    ui->tableHead->setText("Таблица: " + ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text());

    ShowDatabaseTable(); // Вывод БД на экран, таблицы
}

// requestsButton, нажатие
void MainWindow::onRequestsButtonClicked() {

    // Отправка модели для выбора запроса
    emit SendDatabaseToRequestsForm(model);

    // Открыть форму в модальном режиме
    requestsForm->setWindowModality(Qt::ApplicationModal);

    // Открытие формы
    requestsForm->show();
}

// infoButton, нажатие
void MainWindow::onInfoButtonClicked() {

    // Открыть форму в модальном режиме
    info->setWindowModality(Qt::ApplicationModal);

    // Открытие формы
    info->show();
}

// Приёмник имени запроса
void MainWindow::recieveRequestName(QString requestName) {

    ui->tableHead->setText(requestName); // Сохранение имени запроса в tableHead
}

// Сохранение названий таблиц в tablesListWidget
void MainWindow::SetTablesNames() {

    // Таблицы
    QStringList strList;
    strList.append("Аудитория");
    strList.append("Группа");
    strList.append("Занятие");
    strList.append("Кафедра");
    strList.append("Предмет");
    strList.append("Преподаватель");

    // Сохранение названий таблиц в tablesListWidget
    ui->tablesListWidget->addItems(strList);
}

// Открыть БД
void MainWindow::OpenDatabase() {

    database = QSqlDatabase::addDatabase("QODBC");                                                       // Драйвер
    database.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=D:/DB1.mdb"); // Открытие БД

    // Проверка БД на открытие
    if (!database.open()) {

        // БД не открыта, блокировка элементов управления
        ui->tablesListWidget->setDisabled(true);
        ui->requestsButton->setDisabled(true);
        ui->addingButton->setDisabled(true);
        ui->changeButton->setDisabled(true);
        ui->deleteButton->setDisabled(true);

        // Установка сообщения об ошибке в заголовок
        ui->tableHead->setText("Ошибка: база данных не найдена");
    }

    // Модель БД, необходима для её вывода на экран
    model = new QSqlTableModel(this, database);
}

// Отобразить БД, таблица
void MainWindow::ShowDatabaseTable() {

    // Модель не приняла БД
    if (model == nullptr) {

        return;
    }

    // Связывание модели с таблицей
    model->setTable(ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text());

    model->select();

    // Вывод таблицы на экран
    ui->tableView->setModel(model);

    // Автоматическое выравнивание столбцов
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

// Открыть форму добавления кафедры
void MainWindow::RunDepartmentForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Кафедра") {

        emit SendDatabaseToDepartment(model, queryModel);

        // Открыть форму в модальном режиме
        departmentInsertForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        departmentInsertForm->show();
    }
}

// Открыть форму добавления преподавателя
void MainWindow::RunTeacherForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Преподаватель") {

        emit SendDatabaseToTeacher(model, queryModel);

        // Открыть форму в модальное режиме
        teacherInsertForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        teacherInsertForm->show();
    }
}

// Открыть форму для добавления аудитории
void MainWindow::RunAuditoriumForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Аудитория") {

        emit SendDatabaseToAuditorium(model, queryModel);

        // Открыть форму в модальном режиме
        auditoriumInsertForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        auditoriumInsertForm->show();
    }
}

// Открыть форму для добавления группы
void MainWindow::RunGroupForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Группа") {

        emit SendDatabaseToGroup(model, queryModel);

        // Открыть форму в модальном режиме
        groupInsertForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        groupInsertForm->show();
    }
}

// Открыть форму для добавления предмета
void MainWindow::RunSubjectForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Предмет") {

        emit SendDatabaseToSubject(model, queryModel);

        // Открыть форму в модальном режиме
        subjectInsertForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        subjectInsertForm->show();
    }
}

// Открыть форму для добавления занятия
void MainWindow::RunLessonForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Занятие") {

        emit SendDatabaseToLesson(model, queryModel);

        // Открыть форму в модальном режиме
        lessonInsertForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        lessonInsertForm->show();
    }
}
