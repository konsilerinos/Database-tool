#ifndef TEACHERINSERTFORM_H
#define TEACHERINSERTFORM_H

#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class TeacherInsertForm;
}

class TeacherInsertForm : public QWidget {
    Q_OBJECT

  public:
    explicit TeacherInsertForm(QWidget* parent = nullptr);
    ~TeacherInsertForm();

  private slots:
    void onLastNameLineTextChanged();   // lastNameLine, изменение значения
    void onNameLineTextChanged();       // nameLine, изменение текста
    void onPatronymicLineTextChanged(); // patronymicLine, изменение текста
    void onDepartmentBoxTextChanged();  // departmentBox, изменение зачения
    void onCountSliderValueChanged();   // countSlider, изменение значения

    void onAddingButtonClicked(); // addingButton, нажатие
    void onExitButtonClicked();   // exitButton, нажатие

    void resirvedData(QSqlTableModel*, QSqlQueryModel*); // Приёмник моделей QSqlTableModel и QSqlQueryModel

  private:
    Ui::TeacherInsertForm* ui;

    QSqlTableModel* model;      // Модель, используется для отображения БД
    QSqlQueryModel* queryModel; // Модель, используется для выполнения запросов

    int errorCounter;   // Счётчик ошибок
    int warningCounter; // Счётчик предупреждений

    void SetLinesEmptyValues();               // Установить нулевые значения для текстовых полей
    QStringList GetDepartmentsFromDatabase(); // Получение списка кафедр из БД

    void Debug(QString message); // Сохранение отладочного сообщения в лог

    void DisableAddingButton(); // Блокировка-разблокировка кнопки добавления

    bool CheckCurrentValue(); // Проверка текущего показания полей на соответствие для вставки
    bool CheckKeys();         // Проверка ключевых полей на повторы
    bool CheckFIO();          // Проверка ФИО на повторы
    void AddTeacherToModel(); // Добавление преподавателя
};

#endif // TEACHERINSERTFORM_H
