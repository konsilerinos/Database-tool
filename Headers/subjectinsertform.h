#ifndef SUBJECTINSERTFORM_H
#define SUBJECTINSERTFORM_H

#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QWidget>

namespace Ui {
class SubjectInsertForm;
}

class SubjectInsertForm : public QWidget {
    Q_OBJECT

  public:
    explicit SubjectInsertForm(QWidget* parent = nullptr);
    ~SubjectInsertForm();

  private slots:
    void resirvedData(QSqlTableModel*, QSqlQueryModel*); // Приёмник моделей QSqlTableModel и QSqlQueryModel

    void onNameLineTextChanged();     // nameLine, изменение значения
    void onShortNameTextChanged();    // shortNameLine, изменение значения
    void onCountSliderValueChanged(); // countSlider, изменение значения

    void onAddingButtonClicked(); // addingButton, нажатие
    void onExitButtonClicked();   // exitButton, нажатие

  private:
    Ui::SubjectInsertForm* ui;

    QSqlTableModel* model;      // Модель, используется для отображения БД
    QSqlQueryModel* queryModel; // Модель, используется для выполнения запросов

    int errorCounter; // Счётчик ошибок

    void SetLinesEmptyValues(); // Установить нулевые значения для текстовых полей

    void Debug(QString message); // Сохранение отладочного сообщения в лог

    void DisableAddingButton(); // Блокировка-разблокировка кнопки добавления

    bool CheckCurrentValue(); // Проверка текущего показания полей на соответствие для вставки
    bool CheckKeys();         // Проверка ключевых полей на повторы
    bool CheckNames();        // Проверка названий на повторы
    bool CheckShortNames();   // Проверка сокращённых названий на повторы
    void AddSubjectToModel(); // Добавление предмета
};

#endif // SUBJECTINSERTFORM_H
