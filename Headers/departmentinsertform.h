#ifndef DEPARTMENTINSERTFORM_H
#define DEPARTMENTINSERTFORM_H

#include <QSqlQuery>
#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class DepartmentInsertForm;
}

class DepartmentInsertForm : public QWidget {
    Q_OBJECT

  public:
    explicit DepartmentInsertForm(QWidget* parent = nullptr);
    ~DepartmentInsertForm();

  private slots:
    void onAddingButtonClicked(); // departmentAddingButton, нажатие
    void onExitButtonClicked();   // exitButton, нажатие

    void onCountSliderValueChanged();  // countSlider, изменено значение
    void onNameLineTextChanged();      // nameLine, изменение текста
    void onShortNameLineTextChanged(); // shortNameLine, изменение текста

    void resirvedData(QSqlTableModel*, QSqlQueryModel*); // Приёмник моделей QSqlTableModel и QSqlQueryModel

  private:
    Ui::DepartmentInsertForm* ui; // Интерфейс пользователя
    QSqlTableModel* model;        // Модель, используется для отображения БД
    QSqlQueryModel* queryModel;   // Модель, используется для выполнения запросов

    int errorCounter; // Счётчик ошибок

    void SetSliderProperties(); // Установить свойства для countSlider
    void SetLinesEmptyValues(); // Установить нулевые значения для текстовых полей
    void SetSignals();          // Определение сигналов и слотов

    void Debug(QString message); // Сохранение отладочного сообщения в лог

    void DisableAddingButton(); // Блокировка-разблокировка кнопки добавления

    bool CheckCurrentValue();    // Проверка текущего показания полей на соответствие для вставки
    bool CheckKeys();            // Проверка ключевых полей на повторение
    bool CheckNames();           // Проверка названий кафедр на повторение
    bool CheckShortNames();      // Проверка сокращённых названий на повторение
    void AddDepartmentToModel(); // Добавление кафедры
};

#endif // DEPARTMENTINSERTFORM_H
