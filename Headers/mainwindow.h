#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "auditoriumdeleteform.h"
#include "auditoriuminsertform.h"
#include "changeinfoform.h"
#include "departmentdeleteform.h"
#include "departmentinsertform.h"
#include "groupdeleteform.h"
#include "groupinsertform.h"
#include "info.h"
#include "lessondeleteform.h"
#include "lessoninsertform.h"
#include "requestsform.h"
#include "subjectdeleteform.h"
#include "subjectinsertform.h"
#include "teacherdeleteform.h"
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
    void onDeletingButtonClicked();       // deleteButton, нажатие
    void onChangeButtonClicked();         // changeButton, нажатие
    void onTablesListWidgetItemClicked(); // tablesListWidget, изменение значения
    void onRequestsButtonClicked();       // requestsButton, нажатие
    void onInfoButtonClicked();           // infoButton, нажатие

    void recieveRequestName(QString); // Приёмник имени запроса

  signals:

    void SendDepartmentDB(QSqlTableModel*, QSqlQueryModel*); // Отправка моделей для добавления кафедры
    void SendAuditoriumDB(QSqlTableModel*, QSqlQueryModel*); // Отправка моделей для добавления аудитории
    void SendGroupDB(QSqlTableModel*, QSqlQueryModel*);      // Отправка моделей для добавления группы
    void SendTeacherDB(QSqlTableModel*, QSqlQueryModel*);    // Отправка моделей для добавления преподавателя
    void SendSubjectDB(QSqlTableModel*, QSqlQueryModel*);    // Отправка моделей для добавления предмета
    void SendLessonDB(QSqlTableModel*, QSqlQueryModel*);     // Отправка моделей для добавления занятия

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
    AuditoriumDeleteForm* auditoriumDeleteForm; // Форма, используется для удаления аудитории
    GroupDeleteForm* groupDeleteForm;           // Форма, используется для удаления группы
    SubjectDeleteForm* subjectDeleteForm;       // Форма, используется для удаления предмета
    LessonDeleteForm* lessonDeleteForm;         // Форма, используется для удаления занятия
    TeacherDeleteForm* teacherDeleteForm;       // Форма, используется для удаления преподавателя

    ChangeInfoForm* changeInfoForm; // Форма, информация об изменении записей

    Info* info; // Форма, используется для отображения информации о разработчике

    RequestsForm* requestsForm; // Форма, используется для выбора запроса для отображения

    void SetSignals(); // Определение сигналов и слотов

    void SetTablesNames(); // Сохранение названий таблиц в tablesListWidget

    void OpenDatabase();      // Открыть БД
    void ShowDatabaseTable(); // Отобразить БД, таблица

    void RunDepartmentInsertForm(); // Открыть форму для добавления кафедры
    void RunTeacherInsertForm();    // Открыть форму для добавления преподавателя
    void RunAuditoriumInsertForm(); // Открыть форму для добавления аудитории
    void RunGroupInsertForm();      // Открыть форму для добавления группы
    void RunSubjectInsertForm();    // Открыть форму для добавления предмета
    void RunLessonInsertForm();     // Открыть форму для добавления занятия

    void RunDepartmentDeleteForm(); // Открыть форму для удаления кафедры
    void RunTeacherDeleteForm();    // Открыть форму для удаления преподавателя
    void RunAuditoriumDeleteForm(); // Открыть форму для удаления аудитории
    void RunGroupDeleteForm();      // Открыть форму для удаления группы
    void RunSubjectDeleteForm();    // Открыть форму для удаления предмета
    void RunLessonDeleteForm();     // Открыть форму для удаления занятия
};
#endif // MAINWINDOW_H
