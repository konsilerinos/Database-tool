#ifndef SUBJECTDELETEFORM_H
#define SUBJECTDELETEFORM_H

#include <QSqlTableModel>
#include <QStringList>
#include <QWidget>

namespace Ui {
class SubjectDeleteForm;
}

class SubjectDeleteForm : public QWidget {
    Q_OBJECT

  public:
    explicit SubjectDeleteForm(QWidget* parent = nullptr);
    ~SubjectDeleteForm();

  private slots:
    void resirvedData(QSqlTableModel*, QSqlQueryModel*); // Приёмник моделей QSqlTableModel и QSqlQueryModel

    void onExitButtonClicked();   // exitButton, нажатие
    void onDeleteButtonClicked(); // deleteButton, нажатие

    void onIDBoxTextChanged();        // IDBox, изменение значения
    void onNameBoxTextChanged();      // nameBox, изменение значения
    void onShortNameBoxTextChanged(); // shortnameBox, изменение значения

  private:
    Ui::SubjectDeleteForm* ui;  // Интерфейс пользователя
    QSqlTableModel* model;      // Модель, используется для отображения БД
    QSqlQueryModel* queryModel; // Модель, используется для выполнения запросов

    QStringList IDList;         // Список идентификаторов предметов
    QStringList namesList;      // Список названий предметов
    QStringList shortNamesList; // Список сокращённых названий кафедр

    int deleteCounter; // Счётчик удаления

    void SaveID();         // Сохранение идентификаторов предметов
    void SaveNames();      // Сохранение названий предметов
    void SaveShortNames(); // Сохранение сокращённых названий предметов

    void DeleteLessons();  // Удаление занятий
    void DeleteSubjects(); // Удаление предметов

    void Debug(QString message); // Сохранение отладочного сообщения в лог
};

#endif // SUBJECTDELETEFORM_H
