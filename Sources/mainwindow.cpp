#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);

    departmentInsertForm = new DepartmentInsertForm(); // Форма, добавление кафедры
    auditoriumInsertForm = new AuditoriumInsertForm(); // Форма, добавление аудитории
    groupInsertForm = new GroupInsertForm();           // Форма, добавление группы
    teacherInsertForm = new TeacherInsertForm();       // Форма, добавление преподавателя
    subjectInsertForm = new SubjectInsertForm();       // Форма, добавление предмета
    lessonInsertForm = new LessonInsertForm();         // Форма, добавление занятия

    departmentDeleteForm = new DepartmentDeleteForm(); // Форма, удаление кафедры
    auditoriumDeleteForm = new AuditoriumDeleteForm(); // Форма, удаление аудитории
    groupDeleteForm = new GroupDeleteForm();           // Форма, удаление группы
    lessonDeleteForm = new LessonDeleteForm();         // Форма, удаление занятия
    subjectDeleteForm = new SubjectDeleteForm();       // Форма, удаление предмета
    teacherDeleteForm = new TeacherDeleteForm();       // Форма, удаление преподавателя

    changeInfoForm = new ChangeInfoForm(); // Форма, информация об изменении записей

    requestsForm = new RequestsForm(); // Форма, используется для выбора запроса для отображения
    info = new Info();                 // Форма, используется для отображения информации о разработчике

    SetSignals(); // Определение сигналов и слотов

    SetTablesNames(); // Добавление названий таблиц в tablesNames

    OpenDatabase(); // Открытие БД

    queryModel = new QSqlQueryModel(this); // Модель, используется для выполнения запросов

    ui->tablesListWidget->setCurrentIndex(ui->tablesListWidget->model()->index(0, 0));
    ShowDatabaseTable(); // Вывод БД на экран

    ui->infoButton->setText("Лицензия\nРазработчик"); // Сохранение надписи для infoButton

    // Установка режима "Только для чтения" для ячеек таблицы
    // ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow() {

    delete departmentInsertForm; // Форма, добавление кафедры
    delete auditoriumInsertForm; // Форма, добавление аудитории
    delete groupInsertForm;      // Форма, добавление группы
    delete teacherInsertForm;    // Форма, добавление преподавателя
    delete subjectInsertForm;    // Форма, добавление предмета
    delete lessonInsertForm;     // Форма, добавление занятия

    delete departmentDeleteForm; // Форма, удаление кафедры
    delete auditoriumDeleteForm; // Форма, удаление аудитории
    delete groupDeleteForm;      // Форма, удаление группы
    delete lessonDeleteForm;     // Форма, удаление занятия
    delete subjectDeleteForm;    // Форма, удаление предмета
    delete teacherDeleteForm;    // Форма, удаление преподавателя

    delete changeInfoForm; // Форма, информация об изменении записей

    delete requestsForm; // Форма, используется для выбора запроса для отображения
    delete info;         // Форма, используется для отображения информации о разработчике

    delete model;      // Модель БД, необходима для её вывода на экран
    delete queryModel; // Модель, используется для выполнения запросов
    delete ui;
}

// Определение сигналов и слотов
void MainWindow::SetSignals() {

    connect(ui->addingButton, SIGNAL(clicked()), this, SLOT(onAddingButtonClicked()));     // addingButton, нажатие
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(onDeletingButtonClicked()));   // deleteButton, нажатие
    connect(ui->changeButton, SIGNAL(clicked()), this, SLOT(onChangeButtonClicked()));     // changeButton, нажатие
    connect(ui->requestsButton, SIGNAL(clicked()), this, SLOT(onRequestsButtonClicked())); // requestsButton, нажатие
    connect(ui->infoButton, SIGNAL(clicked()), this, SLOT(onInfoButtonClicked()));         // infoButton, нажатие

    // tablesListWidget, изменение значения
    connect(ui->tablesListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onTablesListWidgetItemClicked()));

    // Отправка имени запроса из info в this
    connect(requestsForm, SIGNAL(SendRequestName(QString)), this, SLOT(recieveRequestName(QString)));

    // Отправка модели для выбора запроса
    connect(this, SIGNAL(SendDatabaseToRequestsForm(QSqlTableModel*)), requestsForm, SLOT(resirvedData(QSqlTableModel*)));

    // Отправка моделей для добавления-удаления кафедры
    connect(this, SIGNAL(SendDepartmentDB(QSqlTableModel*, QSqlQueryModel*)), departmentInsertForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));
    connect(this, SIGNAL(SendDepartmentDB(QSqlTableModel*, QSqlQueryModel*)), departmentDeleteForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));

    // Отправка моделей для добавления-удаления аудитории
    connect(this, SIGNAL(SendAuditoriumDB(QSqlTableModel*, QSqlQueryModel*)), auditoriumInsertForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));
    connect(this, SIGNAL(SendAuditoriumDB(QSqlTableModel*, QSqlQueryModel*)), auditoriumDeleteForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));

    // Отправка моделей для добавления-удаления группы
    connect(this, SIGNAL(SendGroupDB(QSqlTableModel*, QSqlQueryModel*)), groupInsertForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));
    connect(this, SIGNAL(SendGroupDB(QSqlTableModel*, QSqlQueryModel*)), groupDeleteForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));

    // Отправка моделей для добавления-удаления преподавателя
    connect(this, SIGNAL(SendTeacherDB(QSqlTableModel*, QSqlQueryModel*)), teacherInsertForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));
    connect(this, SIGNAL(SendTeacherDB(QSqlTableModel*, QSqlQueryModel*)), teacherDeleteForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));

    // Отправка моделей для добавления-удаления предмета
    connect(this, SIGNAL(SendSubjectDB(QSqlTableModel*, QSqlQueryModel*)), subjectInsertForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));
    connect(this, SIGNAL(SendSubjectDB(QSqlTableModel*, QSqlQueryModel*)), subjectDeleteForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));

    // Отправка моделей для добавления-удаления занятия
    connect(this, SIGNAL(SendLessonDB(QSqlTableModel*, QSqlQueryModel*)), lessonInsertForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));
    connect(this, SIGNAL(SendLessonDB(QSqlTableModel*, QSqlQueryModel*)), lessonDeleteForm, SLOT(resirvedData(QSqlTableModel*, QSqlQueryModel*)));
}

// addingButton, нажатие
void MainWindow::onAddingButtonClicked() {

    // Установка модели в исходное состояние
    model->setTable(ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text());
    model->select();

    // Открыть форму для добавления
    RunDepartmentInsertForm(); // Кафедра
    RunAuditoriumInsertForm(); // Аудитория
    RunGroupInsertForm();      // Группы
    RunTeacherInsertForm();    // Преподаватель
    RunSubjectInsertForm();    // Предмет
    RunLessonInsertForm();     // Занятие
}

// deleteButton, нажатие
void MainWindow::onDeletingButtonClicked() {

    // Открыть форму для удаления
    RunDepartmentDeleteForm(); // Кафедра
    RunAuditoriumDeleteForm(); // Аудитория
    RunGroupDeleteForm();      // Группа
    RunLessonDeleteForm();     // Занятие
    RunSubjectDeleteForm();    // Предмет
    RunTeacherDeleteForm();    // Преподаватель
}

// changeButton, нажатие
void MainWindow::onChangeButtonClicked() {

    // Открыть форму в модальном режиме
    changeInfoForm->setWindowModality(Qt::ApplicationModal);

    // Открытие формы
    changeInfoForm->show();
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

    database = QSqlDatabase::addDatabase("QODBC"); // Драйвер
    // database.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=D:/DB1.mdb"); // Открытие БД
    database.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=DB1.mdb"); // Открытие БД

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

        QApplication::exit(); // Завершение работы
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

    while (model->canFetchMore()) {

        model->fetchMore();
    }

    // Вывод таблицы на экран
    ui->tableView->setModel(model);

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Занятие") {

        ui->tableView->setItemDelegateForColumn(0, new dateDelegate); // Установка делегата для отображения даты
        ui->tableView->setItemDelegateForColumn(1, new timeDelegate); // Установка делегата для отображения времени
    } else {

        ui->tableView->setItemDelegateForColumn(0, new valueDelegate); // Установка делегата по умолчанию
        ui->tableView->setItemDelegateForColumn(1, new valueDelegate); // Установка делегата по умолчанию
    }

    // Автоматическое выравнивание столбцов
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

// Открыть форму добавления кафедры
void MainWindow::RunDepartmentInsertForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Кафедра") {

        emit SendDepartmentDB(model, queryModel);

        // Открыть форму в модальном режиме
        departmentInsertForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        departmentInsertForm->show();
    }
}

// Открыть форму добавления преподавателя
void MainWindow::RunTeacherInsertForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Преподаватель") {

        emit SendTeacherDB(model, queryModel);

        // Открыть форму в модальное режиме
        teacherInsertForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        teacherInsertForm->show();
    }
}

// Открыть форму для добавления аудитории
void MainWindow::RunAuditoriumInsertForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Аудитория") {

        emit SendAuditoriumDB(model, queryModel);

        // Открыть форму в модальном режиме
        auditoriumInsertForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        auditoriumInsertForm->show();
    }
}

// Открыть форму для добавления группы
void MainWindow::RunGroupInsertForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Группа") {

        emit SendGroupDB(model, queryModel);

        // Открыть форму в модальном режиме
        groupInsertForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        groupInsertForm->show();
    }
}

// Открыть форму для добавления предмета
void MainWindow::RunSubjectInsertForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Предмет") {

        emit SendSubjectDB(model, queryModel);

        // Открыть форму в модальном режиме
        subjectInsertForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        subjectInsertForm->show();
    }
}

// Открыть форму для добавления занятия
void MainWindow::RunLessonInsertForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Занятие") {

        emit SendLessonDB(model, queryModel);

        // Открыть форму в модальном режиме
        lessonInsertForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        lessonInsertForm->show();
    }
}

// Открыть форму для удаления кафедры
void MainWindow::RunDepartmentDeleteForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Кафедра") {

        emit SendDepartmentDB(model, queryModel);

        // Открыть форму в модальном режиме
        departmentDeleteForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        departmentDeleteForm->show();
    }
}

// Открыть форму для удаления преподавателя
void MainWindow::RunTeacherDeleteForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Преподаватель") {

        emit SendTeacherDB(model, queryModel);

        // Открыть форму в модальном режиме
        teacherDeleteForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        teacherDeleteForm->show();
    }
}

// Открыть форму для удаления аудитории
void MainWindow::RunAuditoriumDeleteForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Аудитория") {

        emit SendAuditoriumDB(model, queryModel);

        // Открыть форму в модальном режиме
        auditoriumDeleteForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        auditoriumDeleteForm->show();
    }
}

// Открыть форму для удаления группы
void MainWindow::RunGroupDeleteForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Группа") {

        emit SendGroupDB(model, queryModel);

        // Открыть форму в модальном режиме
        groupDeleteForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        groupDeleteForm->show();
    }
}

// Открыть форму для удаления предмета
void MainWindow::RunSubjectDeleteForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Предмет") {

        emit SendSubjectDB(model, queryModel);

        // Открыть форму в модальном режиме
        subjectDeleteForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        subjectDeleteForm->show();
    }
}

// Открыть форму для удаления занятия
void MainWindow::RunLessonDeleteForm() {

    if (ui->tablesListWidget->item(ui->tablesListWidget->currentRow())->text() == "Занятие") {

        emit SendLessonDB(model, queryModel);

        // Открыть форму в модальном режиме
        lessonDeleteForm->setWindowModality(Qt::ApplicationModal);

        // Открытие формы
        lessonDeleteForm->show();
    }
}
