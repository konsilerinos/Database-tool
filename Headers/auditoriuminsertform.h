#ifndef AUDITORIUMINSERTFORM_H
#define AUDITORIUMINSERTFORM_H

#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class AuditoriumInsertForm;
}

class AuditoriumInsertForm : public QWidget {
    Q_OBJECT

  public:
    explicit AuditoriumInsertForm(QWidget* parent = nullptr);
    ~AuditoriumInsertForm();

  private slots:

    void onTypeBoxTextChanged(); // typeBox, изменение текста
    void onBodyTextChanged();    // bodyLine, изменение текста
    void onFloorTextChanged();   // floorLine, изменение текста
    void onNumberTextChanged();  // numberLine, изменение текста

    void onAddingButtonClicked(); // addingbutton, нажатие
    void onExitButtonClicked();   // exitButton, нажатие

    void resirvedData(QSqlTableModel*, QSqlQueryModel*); // Приёмник моделей QSqlTableModel и QSqlQueryModel

  private:
    Ui::AuditoriumInsertForm* ui; // Интерфейс пользователя
    QSqlTableModel* model;        // Модель, используется для отображения БД
    QSqlQueryModel* queryModel;   // Модель, используется для выполнения запросов

    int errorCounter; // Счётчик ошибок

    void SetLinesEmptyValues(); // Установить нулевые значения для текстовых полей

    void Debug(QString message); // Сохранение отладочного сообщения в лог

    void DisableAddingButton(); // Блокировка-разблокировка кнопки добавления

    bool CheckCurrentValue();          // Проверка текущего показания полей на соответствие для вставки
    bool CheckBodyFloorNumberValues(); // Проверка значений полей bodyLine, floorLine и numberLine
    bool CheckBodyLine();              // Проверка bodyLine на число
    bool CheckFloorLine();             // Проверка floorLine на число
    bool CheckNumberLine();            // Проверка numberLine на число
    bool CheckKeys();                  // Проверка ключевых полей на повторение
    void AddAuditoriumToModel();       // Добавление аудитории
};

#endif // AUDITORIUMINSERTFORM_H
