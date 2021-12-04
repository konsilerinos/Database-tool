#ifndef GROUPINSERTFORM_H
#define GROUPINSERTFORM_H

#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QTableView>
#include <QWidget>

namespace Ui {
class GroupInsertForm;
}

class GroupInsertForm : public QWidget {
    Q_OBJECT

  public:
    explicit GroupInsertForm(QWidget* parent = nullptr);
    ~GroupInsertForm();

  private slots:

    void resirvedData(QSqlTableModel*, QSqlQueryModel*); // Приёмник моделей QSqlTableModel и QSqlQueryModel

    void onAddingButtonClicked(); // addingbutton, нажатие
    void onExitButtonClicked();   // exitButton, нажатие

    void onDepartmentBoxTextChanged();   // departmentBox, изменение значения
    void onCountSliderValueChanged();    // countSlider, изменение значения
    void onGroupNumberLineTextChanged(); // groupNumberLine, изменение текста

  private:
    Ui::GroupInsertForm* ui;

    QSqlTableModel* model;      // Модель, используется для отображения БД
    QSqlQueryModel* queryModel; // Модель, используется для выполнения запросов

    int errorCounter; // Счётчик ошибок

    void SetLinesEmptyValues();                     // Установить нулевые значения для текстовых полей
    QStringList GetDepartmentsFromDatabase();       // Получение списка кафедр из БД
    QStringList GetDepartmentsShortsFromDatabase(); // Получение сокращённых имён для кафедр из БД

    void Debug(QString message); // Сохранение отладочного сообщения в лог

    void DisableAddingButton(); // Блокировка-разблокировка кнопки добавления

    bool CheckCurrentValue(); // Проверка текущего показания полей на соответствие для вставки
    void AddGroupToModel();   // Добавление группы
};

#endif // GROUPINSERTFORM_H
