#ifndef GROUPDELETEFORM_H
#define GROUPDELETEFORM_H

#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QStringList>
#include <QWidget>

namespace Ui {
class GroupDeleteForm;
}

class GroupDeleteForm : public QWidget {
    Q_OBJECT

  public:
    explicit GroupDeleteForm(QWidget* parent = nullptr);
    ~GroupDeleteForm();

  private slots:
    void resirvedData(QSqlTableModel*, QSqlQueryModel*); // Приёмник моделей QSqlTableModel и QSqlQueryModel

    void onExitButtonClicked();   // exitButton, нажатие
    void onDeleteButtonClicked(); // deleteButton, нажатие

  private:
    Ui::GroupDeleteForm* ui; // Интерфейс пользователя

    QSqlTableModel* model;      // Модель, используется для отображения БД
    QSqlQueryModel* queryModel; // Модель, используется для выполнения запросов

    QStringList groupList; // Список групп

    int deleteCounter; // Счётчик удаления

    void SaveGroups(); // Сохранение групп и установка в groupBox

    void DeleteLessons(); // Удаление занятий
    void DeleteGroups();  // Удаление групп

    void Debug(QString message); // Сохранение отладочного сообщения в лог
};

#endif // GROUPDELETEFORM_H
