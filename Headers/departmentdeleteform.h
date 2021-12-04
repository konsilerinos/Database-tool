#ifndef DEPARTMENTDELETEFORM_H
#define DEPARTMENTDELETEFORM_H

#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QStringList>
#include <QWidget>

namespace Ui {
class DepartmentDeleteForm;
}

class DepartmentDeleteForm : public QWidget {
    Q_OBJECT

  public:
    explicit DepartmentDeleteForm(QWidget* parent = nullptr);
    ~DepartmentDeleteForm();

  private slots:
    void resirvedData(QSqlTableModel*, QSqlQueryModel*); // Приёмник моделей QSqlTableModel и QSqlQueryModel

    void onExitButtonClicked();   // exitButton, нажатие
    void onDeleteButtonClicked(); // deleteButton, нажатие

    void onIDBoxValueChanged();    // IDBox, изменение значения
    void onNameBoxValueChanged();  // nameBox, изменение значения
    void onShortNamesBoxChanged(); // shortNamesBox, изменение значения

  private:
    Ui::DepartmentDeleteForm* ui; // Интерфейс пользователя
    QSqlTableModel* model;        // Модель, используется для отображения БД
    QSqlQueryModel* queryModel;   // Модель, используется для выполнения запросов

    int deleteCounter; // Счётчик удаления

    QStringList IDList;         // Идентификаторы кафедр, список
    QStringList namesList;      // Названия кафедр, список
    QStringList shortNamesList; // Сокращённые названия, список

    void SaveID();         // Сохранение идентификаторов кафедр в IDBox
    void SaveNames();      // Сохранение названий кафедр в nameBox
    void SaveShortNames(); // Сохранение сокращённых названий кафедр в shortNameBox

    void DeleteLessons();     // Удаление занятий
    void DeleteGroups();      // Удаление групп
    void DeleteTeachers();    // Удаление преподавателей
    void DeleteDepartments(); // Удаление кафедры

    void Debug(QString message); // Сохранение отладочного сообщения в лог
};

#endif // DEPARTMENTDELETEFORM_H
