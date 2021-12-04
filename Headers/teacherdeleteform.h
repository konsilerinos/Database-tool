#ifndef TEACHERDELETEFORM_H
#define TEACHERDELETEFORM_H

#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QStringList>
#include <QWidget>

namespace Ui {
class TeacherDeleteForm;
}

class TeacherDeleteForm : public QWidget {
    Q_OBJECT

  public:
    explicit TeacherDeleteForm(QWidget* parent = nullptr);
    ~TeacherDeleteForm();

  private slots:
    void resirvedData(QSqlTableModel*, QSqlQueryModel*); // Приёмник моделей QSqlTableModel и QSqlQueryModel

    void onIDLineTextChanged(); // IDLine, изменение значения

    void onExitButtonClicked();   // exitButton, нажатие
    void onDeleteButtonClicked(); // deleteButton, нажатие

  private:
    Ui::TeacherDeleteForm* ui;  // Интерфейс пользователя
    QSqlTableModel* model;      // Модель, используется для отображения БД
    QSqlQueryModel* queryModel; // Модель, используется для выполнения запросов

    QStringList teachersIDList; // Список идентификаторов преподавателей

    int deleteCounter; // Счётчик удаления

    void DeleteTeacher(); // Удаление преподавателей

    bool CheckIDDigit(); // Проверка идентификатора на число
    bool CheckValue();   // Проверка на наличие преподавателя с таким табельным номером
    void SetName();      // Сохранение ФИО в текстовые поля

    void Debug(QString message); // Сохранение отладочного сообщения в лог
};

#endif // TEACHERDELETEFORM_H
