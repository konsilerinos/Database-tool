#ifndef LESSONDELETEFORM_H
#define LESSONDELETEFORM_H

#include <QDate>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QStringList>
#include <QWidget>

namespace Ui {
class LessonDeleteForm;
}

class LessonDeleteForm : public QWidget {
    Q_OBJECT

  public:
    explicit LessonDeleteForm(QWidget* parent = nullptr);
    ~LessonDeleteForm();

  private slots:
    void resirvedData(QSqlTableModel*, QSqlQueryModel*); // Приёмник моделей QSqlTableModel и QSqlQueryModel

    void onDeleteButtonClicked(); // deleteButton, нажатие
    void onExitButtonClicked();   // exitButton, нажатите

  private:
    Ui::LessonDeleteForm* ui; // Интерфейс пользователя

    QSqlTableModel* model;      // Модель, используется для отображения БД
    QSqlQueryModel* queryModel; // Модель, используется для выполнения запросов

    QStringList IDList; // Список идентификаторов предметов

    int deleteCounter; // Счётчик удаления

    void SetDays();   // Сохранение дней в dayBox
    void SetMonths(); // Сохранение месяцев в monthBox
    void SetYears();  // Сохранение годов в yearBox
    void SetTimes();  // Сохранение времён в timeBox
    void SetTypes();  // Сохранение типов в typeBox
    void SaveID();    // Сохранение идентификаторв предметов в IDBox

    void DeleteLesson(); // Удаление занятия

    void Debug(QString message); // Сохранение отладочного сообщения в лог
};

#endif // LESSONDELETEFORM_H
