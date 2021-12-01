#ifndef LESSONINSERTFORM_H
#define LESSONINSERTFORM_H

#include <QDate>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class LessonInsertForm;
}

class LessonInsertForm : public QWidget {
    Q_OBJECT

  public:
    explicit LessonInsertForm(QWidget* parent = nullptr);
    ~LessonInsertForm();

  private slots:
    void resirvedData(QSqlTableModel*, QSqlQueryModel*); // Приёмник моделей QSqlTableModel и QSqlQueryModel

    void onAddingButtonClicked(); // addingButton, нажатие
    void onExitButtonClicked();   // exitButton, нажатите

  private:
    Ui::LessonInsertForm* ui;

    QSqlTableModel* model;      // Модель, используется для отображения БД
    QSqlQueryModel* queryModel; // Модель, используется для выполнения запросов

    int errorCounter; // Счётчик ошибок

    void Debug(QString message); // Сохранение отладочного сообщения в лог

    void SetDays();   // Сохранение дней в dayBox
    void SetMonths(); // Сохранение месяцев в monthBox
    void SetYears();  // Сохранение годов в yearBox
    void SetTimes();  // Сохранение времён в timeBox
    void SetTypes();  // Сохранение типов в typeBox

    void SetLinesEmptyValues(); // Установка значений по умолчанию

    QStringList GetAuditoriesBodies();  // Получить корпуса аудиторий из БД
    QStringList GetAuditoriesFloors();  // Получить этажи аудиторий из БД
    QStringList GetAuditoriesNumbers(); // Получить номера аудиторий из БД
    QStringList GetLessonsID();         // Получить идентификаторы предметов из БД
    QStringList GetGroupsNames();       // Получить названия групп из БД

    bool CheckCurrentValue(); // Проверка текущего показания полей на соответствие для вставки
    bool CheckDate();         // Проверка даты
    bool CheckKeys();         // Проверка ключевых полей на повторы
    void AddLessonToModel();  // Добавление предмета
};

#endif // LESSONINSERTFORM_H
