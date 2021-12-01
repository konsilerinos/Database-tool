#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "auditoriuminsertform.h"
#include "departmentdeleteform.h"
#include "departmentinsertform.h"
#include "groupinsertform.h"
#include "info.h"
#include "lessoninsertform.h"
#include "requestsform.h"
#include "subjectinsertform.h"
#include "teacherinsertform.h"
#include <QDateTime>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

  private slots:
    void onAddingButtonClicked();         // addingButton, нажатие
    void onTablesListWidgetItemClicked(); // tablesListWidget, изменение значения
    void onRequestsButtonClicked();       // requestsButton, нажатие
    void onInfoButtonClicked();           // infoButton, нажатие

    void recieveRequestName(QString); // Приёмник имени запроса

  signals:

    void SendDatabaseToDepartment(QSqlTableModel*, QSqlQueryModel*); // Отправка моделей для добавления кафедры
    void SendDatabaseToAuditorium(QSqlTableModel*, QSqlQueryModel*); // Отправка моделей для добавления аудитории
    void SendDatabaseToGroup(QSqlTableModel*, QSqlQueryModel*);      // Отправка моделей для добавления группы
    void SendDatabaseToTeacher(QSqlTableModel*, QSqlQueryModel*);    // Отправка моделей для добавления преподавателя
    void SendDatabaseToSubject(QSqlTableModel*, QSqlQueryModel*);    // Отправка моделей для добавления предмета
    void SendDatabaseToLesson(QSqlTableModel*, QSqlQueryModel*);     // Отправка моделей для добавления занятия

    void SendDatabaseToRequestsForm(QSqlTableModel*); // Отправка модели для выбора запроса

  private:
    Ui::MainWindow* ui;

    QSqlDatabase database;           // БД
    QSqlTableModel* model = nullptr; // Модель, используется для отображения БД
    QSqlQueryModel* queryModel;      // Модель, используется для выполнения запросов

    DepartmentInsertForm* departmentInsertForm; // Форма, используется для добавления кафедры
    AuditoriumInsertForm* auditoriumInsertForm; // Форма, используется для добавления аудитории
    GroupInsertForm* groupInsertForm;           // Форма, используется для добавления группы
    TeacherInsertForm* teacherInsertForm;       // Форма, используется для добавления преподавателя
    SubjectInsertForm* subjectInsertForm;       // Форма, используется для добавления предмета
    LessonInsertForm* lessonInsertForm;         // Форма, используется для добавления занятия

    DepartmentDeleteForm* departmentDeleteForm; // Форма, используется для удаления кафедры

    Info* info; // Форма, используется для отображения информации о разработчике

    RequestsForm* requestsForm; // Форма, используется для выбора запроса для отображения

    void SetSignals(); // Определение сигналов и слотов

    void SetTablesNames(); // Сохранение названий таблиц в tablesListWidget

    void OpenDatabase();      // Открыть БД
    void ShowDatabaseTable(); // Отобразить БД, таблица

    void RunDepartmentForm(); // Открыть форму для добавления кафедры
    void RunTeacherForm();    // Открыть форму для добавления преподавателя
    void RunAuditoriumForm(); // Открыть форму для добавления аудитории
    void RunGroupForm();      // Открыть форму для добавления группы
    void RunSubjectForm();    // Открыть форму для добавления предмета
    void RunLessonForm();     // Открыть форму для добавления занятия
};
#endif // MAINWINDOW_H
