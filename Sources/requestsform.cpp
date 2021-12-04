#include "requestsform.h"
#include "ui_requestsform.h"

RequestsForm::RequestsForm(QWidget* parent) : QWidget(parent), ui(new Ui::RequestsForm) {

    ui->setupUi(this);

    // Сохранение названий запросов в requestsBox
    SetRequestsNames();

    // generateButton, нажатие
    connect(ui->generateButton, SIGNAL(clicked()), this, SLOT(onGenerateButtonClicked()));

    // exitButton, нажатие
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));

    // requestsBox, изменения значения
    connect(ui->requestsBox, SIGNAL(currentTextChanged(QString)), this, SLOT(onRequestsBoxTextChanged()));

    tableName = "1_аудитория_все_записи";
    requestName = "Запрос: аудитория, все записи";
    ui->sqlText->setText("SELECT *\nFROM Аудитория;");
}

RequestsForm::~RequestsForm() { delete ui; }

// Приёмник моделей QSqlTableModel и QSqlQueryModel
void RequestsForm::resirvedData(QSqlTableModel* resModel) {

    model = resModel; // Сохранение модели

    while (model->canFetchMore()) {

        model->fetchMore();
    }
}

// generateButton, нажатие
void RequestsForm::onGenerateButtonClicked() {

    // Связывание модели с таблицей
    model->setTable(tableName);

    model->select();

    // Генерирование сигнала с именем запроса
    emit SendRequestName(requestName);
}

// exitButton, нажатие
void RequestsForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}

// requestsBox, изменение значения
void RequestsForm::onRequestsBoxTextChanged() {

    if (ui->requestsBox->currentText() == "1. Аудитория, все записи") {

        tableName = "1_аудитория_все_записи";
        requestName = "Запрос: аудитория, все записи";

        requestText = "SELECT *\n"
                      "FROM Аудитория;";
    } else if (ui->requestsBox->currentText() == "2. Аудитория, различные типы") {

        tableName = "2_аудитория_различные_типы";
        requestName = "Запрос: аудитория, различные типы";

        requestText = "SELECT DISTINCT [Тип аудитории]\n"
                      "FROM Аудитория;";
    } else if (ui->requestsBox->currentText() == "3. Группа, численность групп") {

        tableName = "3_группа_численность_групп";
        requestName = "Запрос: группа, численность групп";

        requestText = "SELECT [Номер группы], [Количество студентов]\n"
                      "FROM Группа;";
    } else if (ui->requestsBox->currentText() == "4. Кафедра, сокращённо") {

        tableName = "4_кафедра_сокращённо";
        requestName = "Запрос: кафедра, сокращённо";

        requestText = "SELECT [Название кафедры] AS Кафедра, [Сокращённое название] AS Сокращённо, [Количество ставок] AS Ставка\n"
                      "FROM Кафедра;";
    } else if (ui->requestsBox->currentText() == "5. Преподаватель, стаж работы от 14 до 17 лет") {

        tableName = "5_преподаватель_стаж_работ_от_14_до_17";
        requestName = "Запрос: преподаватель, стаж работ от 14 до 17 лет";

        requestText = "SELECT Фамилия, Имя, Отчество, Должность, [Стаж работы], [Идентификатор кафедры]\n"
                      "FROM Преподаватель\n"
                      "WHERE ([Стаж работы] >= 14) AND ([Стаж работы] <= 17)";
    } else if (ui->requestsBox->currentText() == "6. Занятие, с 5 по 7 мая") {

        tableName = "6_занятие_с_5_по_7_мая";
        requestName = "Запрос: занятие, с 5 по 7 мая";

        requestText = "SELECT [День проведения] AS день, [Время проведения] AS Время, Тип, [Идентификатор предмета] AS Идентификатор, [Номер группы] AS Группа\n"
                      "FROM Занятие\n"
                      "WHERE [День проведения] BETWEEN #05/05/2021# AND #05/07/2021#";
    } else if (ui->requestsBox->currentText() == "7. Занятие, в январе или декабре") {

        tableName = "7_занятие_в_январе_или_декабре";
        requestName = "Запрос: занятие, в январе или декабре";

        requestText = "SELECT [День проведения] AS день, [Время проведения] AS Время, Тип, [Идентификатор предмета] AS Идентификатор, [Номер группы] AS Группа\n"
                      "FROM Занятие\n"
                      "WHERE [День проведения] NOT BETWEEN #02/01/2021# AND #11/30/2021#";
    } else if (ui->requestsBox->currentText() == "8. Группа, определённые кафедры") {

        tableName = "8_группа_определённые_кафедры";
        requestName = "Запрос: группа, определённые кафедры";

        requestText = "SELECT [Номер группы] AS Группа, [Название кафедры] AS Кафедра, [Количество студентов] AS [Численность студентов]\n"
                      "FROM Группа\n"
                      "WHERE [Название кафедры] IN (4, 11, 13);";
    } else if (ui->requestsBox->currentText() == "9. Группа, без определённых групп") {

        tableName = "9_группа_без_определённых_групп";
        requestName = "Запрос: группа, без определённых групп";

        requestText = "SELECT [Номер группы] AS Группа, [Название кафедры] AS Кафедра, [Количество студентов] AS \"Численность студентов\"\n"
                      "FROM Группа\n"
                      "WHERE [Название кафедры] NOT IN (4, 11, 13)";
    } else if (ui->requestsBox->currentText() == "10. Преподаватель, условие на отчество") {

        tableName = "10_преподаватель_условие_на_отчество";
        requestName = "Запрос: преподаватель, условие на отчество";

        requestText = "SELECT Фамилия, Имя, Отчество, Должность, [Стаж работы], [Идентификатор кафедры]\n"
                      "FROM Преподаватель\n"
                      "WHERE Отчество LIKE \"*л?вич\"";
    } else if (ui->requestsBox->currentText() == "11. Группа, численность и ИД кафедры по возрастанию") {

        tableName = "11_группа_численность_и_ИД_кафедры_по_возрастанию";
        requestName = "Запрос: группа, численность и ИД кафедры по возрастанию";

        requestText = "SELECT [Номер группы] AS Группа, [Название кафедры] AS Кафедра, [Количество студентов] AS Численность, [Идентификатор кафедры]\n"
                      "FROM Группа\n"
                      "ORDER BY [Количество студентов], [Идентификатор кафедры] ASC";
    } else if (ui->requestsBox->currentText() == "12. Группа, численность по возрастанию, ИД кафедры по убыванию") {

        tableName = "12_группа_численность_по_возрастанию_ИД_кафедры_по_убыванию";
        requestName = "Запрос: группа, численность по возрастанию, ИД кафедры по убыванию";

        requestText = "SELECT [Номер группы] AS Группа, [Название кафедры] AS Кафедра, [Количество студентов] AS Численность, [Идентификатор кафедры]\n"
                      "FROM Группа\n"
                      "ORDER BY [Количество студентов] ASC, [Идентификатор кафедры] DESC";
    } else if (ui->requestsBox->currentText() == "13. Преподаватель, стаж работы, вычисляемый, по убыванию") {

        tableName = "13_преподаватель_стаж_работы_вычисляемый_по_убыванию";
        requestName = "Запрос: преподаватель, стаж работы, вычисляемый, по убыванию";

        requestText = "SELECT Фамилия, Имя, Отчество, Должность, [Стаж работы]+10 AS [Увеличенный стаж], [Идентификатор кафедры]\n"
                      "FROM Преподаватель\n"
                      "ORDER BY 5 DESC";
    } else if (ui->requestsBox->currentText() == "14. Преподаватели и кафедры, способ 1") {

        tableName = "14_преподаватели_и_кафедры_способ_1";
        requestName = "Запрос: преподаватели и кафедры, способ 1";

        requestText = "SELECT Кафедра.[Название кафедры] AS Кафедра, Кафедра.[Сокращённое название] AS Сокращённо, Фамилия, Имя, Отчество\n"
                      "FROM Кафедра, Преподаватель\n"
                      "WHERE Кафедра.[Идентификатор кафедры] = Преподаватель.[Идентификатор кафедры]";
    } else if (ui->requestsBox->currentText() == "15. Преподаватели и кафедры, способ 2") {

        tableName = "15_преподаватели_и_кафедры_способ_2";
        requestName = "Запрос: преподаватели и кафедры, способ 2";

        requestText = "SELECT Кафедра.[Название кафедры] AS Кафедра, Кафедра.[Сокращённое название] AS Сокращённо, Фамилия, Имя, Отчество\n"
                      "FROM Кафедра INNER JOIN Преподаватель\n"
                      "ON Кафедра.[Идентификатор кафедры] = Преподаватель.[Идентификатор кафедры]";
    } else if (ui->requestsBox->currentText() == "16. Общий стаж работы преподавателей с кафедры 8") {

        tableName = "16_общий_стаж_работы_преподавателей_с_кафедры_8";
        requestName = "";

        requestText = "SELECT SUM(Преподаватель.[Стаж работы]) AS [Общий стаж работы]\n"
                      "FROM Кафедра, Преподаватель\n"
                      "WHERE (Кафедра.[Идентификатор кафедры] = Преподаватель.[Идентификатор кафедры]) AND (Преподаватель.[Идентификатор кафедры] = 8)";
    } else if (ui->requestsBox->currentText() == "17. Общий стаж работы на кафедрах") {

        tableName = "17_общий_стаж_работы_на_кафедрах";
        requestName = "Запрос: общий стаж работы на кафедрах";

        requestText = "SELECT Кафедра.[Название кафедры] AS Кафедра, SUM(Преподаватель.[Стаж работы]) AS [Общий стаж работы]\n"
                      "FROM Кафедра, Преподаватель\n"
                      "WHERE Кафедра.[Идентификатор кафедры] = Преподаватель.[Идентификатор кафедры]\n"
                      "GROUP BY Кафедра.[Название кафедры]";
    } else if (ui->requestsBox->currentText() == "18. Средний стаж работы на кафедрах") {

        tableName = "18_средний_стаж_работы_на_кафедрах";
        requestName = "Запрос: средний стаж работы на кафедрах";

        requestText = "SELECT Кафедра.[Название кафедры] AS Кафедра, AVG(Преподаватель.[Стаж работы]) AS [Средний стаж работы]\n"
                      "FROM Кафедра, Преподаватель\n"
                      "WHERE Кафедра.[Идентификатор кафедры] = Преподаватель.[Идентификатор кафедры]\n"
                      "GROUP BY Кафедра.[Название кафедры]";
    } else if (ui->requestsBox->currentText() == "19. Определённый средний стаж для кафедр") {

        tableName = "19_определённый_средний_стаж_для_кафедр";
        requestName = "Запрос: определённый средний стаж для кафедр";

        requestText = "SELECT Кафедра.[Название кафедры] AS Кафедра, AVG(Преподаватель.[Стаж работы]) AS [Средний стаж работы]\n"
                      "FROM Кафедра, Преподаватель\n"
                      "WHERE Кафедра.[Идентификатор кафедры] = Преподаватель.[Идентификатор кафедры]\n"
                      "GROUP BY Кафедра.[Название кафедры]\n"
                      "HAVING AVG(Преподаватель.[Стаж работы]) > 17.4";
    } else if (ui->requestsBox->currentText() == "20. Аудитория, корпус-этаж-номер") {

        tableName = "20_аудитория_корпус_этаж_номер";
        requestName = "Запрос: аудитория, корпус-этаж-номер";

        requestText = "SELECT Корпус, Этаж, Номер FROM Аудитория\n"
                      "UNION SELECT [Корпус аудитории], [Этаж аудитории], [Номер аудитории] FROM Занятие;";
    } else if (ui->requestsBox->currentText() == "21. Группа, кафедра, идентификаторы кафедр") {

        tableName = "21_группа_кафедра_идентификаторы_кафедр";
        requestName = "Запрос: группа, кафедра, идентификаторы кафедр";

        requestText = "SELECT [Идентификатор кафедры] FROM Кафедра\n"
                      "UNION SELECT [Идентификатор кафедры] FROM Группа;";
    } else if (ui->requestsBox->currentText() == "22. Группа, занятие, номера групп") {

        tableName = "22_группа_занятие_номера_групп";
        requestName = "Запрос: группа, занятие, номера групп";

        requestText = "SELECT [Номер группы] FROM Группа\n"
                      "UNION SELECT [Номер группы] FROM Занятие;";
    } else if (ui->requestsBox->currentText() == "23. Кафедра, неминимальные ставки") {

        tableName = "23_кафедра_неминимальные_ставки";
        requestName = "Запрос: кафедра, минимальные ставки";

        requestText = "SELECT *\n"
                      "FROM Кафедра\n"
                      "WHERE [Количество ставок] <> (SELECT MIN([Количество ставок]) FROM Кафедра);";
    } else if (ui->requestsBox->currentText() == "24. Кафедра, чётные ставки") {

        tableName = "24_кафедра_чётные_ставки";
        requestName = "Запрос: кафедра, чётные ставки";

        requestText = "SELECT *\n"
                      "FROM Кафедра\n"
                      "WHERE [Количество ставок] IN (\n"
                      "    SELECT [Количество ставок]\n"
                      "    FROM Кафедра\n"
                      "    WHERE [Количество ставок] MOD 2 = 0\n"
                      ");";
    } else if (ui->requestsBox->currentText() == "25. Кафедра, существует группа") {

        tableName = "25_кафедра_существует_группа";
        requestName = "Запрос: кафедра, существует группа";

        requestText = "SELECT *\n"
                      "FROM Кафедра\n"
                      "WHERE EXISTS (\n"
                      "    SELECT [Идентификатор кафедры]\n"
                      "    FROM Группа\n"
                      "    WHERE Группа.[Идентификатор кафедры] = Кафедра.[Идентификатор кафедры]\n"
                      ");";
    } else if (ui->requestsBox->currentText() == "26. Кафедра, не существует группа") {

        tableName = "26_кафедра_не_существует_группа";
        requestName = "Запрос: кафедра, не существует группа";

        requestText = "SELECT *\n"
                      "FROM Кафедра\n"
                      "WHERE NOT EXISTS (\n"
                      "    SELECT [Идентификатор кафедры]\n"
                      "    FROM Группа\n"
                      "    WHERE Группа.[Идентификатор кафедры] = Кафедра.[Идентификатор кафедры]\n"
                      ");";
    }

    ui->sqlText->setText(requestText); // Сохранение текста запроса в sqlText
}

// Сохранение названий запросов в requestsBox
void RequestsForm::SetRequestsNames() {

    // Таблицы
    QStringList strList;
    strList.append("1. Аудитория, все записи");
    strList.append("2. Аудитория, различные типы");
    strList.append("3. Группа, численность групп");
    strList.append("4. Кафедра, сокращённо");
    strList.append("5. Преподаватель, стаж работы от 14 до 17 лет");
    strList.append("6. Занятие, с 5 по 7 мая");
    strList.append("7. Занятие, в январе или декабре");
    strList.append("8. Группа, определённые кафедры");
    strList.append("9. Группа, без определённых групп");
    strList.append("10. Преподаватель, условие на отчество");
    strList.append("11. Группа, численность и ИД кафедры по возрастанию");
    strList.append("12. Группа, численность по возрастанию, ИД кафедры по убыванию");
    strList.append("13. Преподаватель, стаж работы, вычисляемый, по убыванию");
    strList.append("14. Преподаватели и кафедры, способ 1");
    strList.append("15. Преподаватели и кафедры, способ 2");
    strList.append("16. Общий стаж работы преподавателей с кафедры 8");
    strList.append("17. Общий стаж работы на кафедрах");
    strList.append("18. Средний стаж работы на кафедрах");
    strList.append("19. Определённый средний стаж для кафедр");
    strList.append("20. Аудитория, корпус-этаж-номер");
    strList.append("21. Группа, кафедра, идентификаторы кафедр");
    strList.append("22. Группа, занятие, номера групп");
    strList.append("23. Кафедра, неминимальные ставки");
    strList.append("24. Кафедра, чётные ставки");
    strList.append("25. Кафедра, существует группа");
    strList.append("26. Кафедра, не существует группа");

    // Сохранение названий таблиц в requestsBox
    ui->requestsBox->addItems(strList);
}
