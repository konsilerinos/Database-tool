#ifndef AUDITORIUMDELETEFORM_H
#define AUDITORIUMDELETEFORM_H

#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QStringList>
#include <QWidget>

namespace Ui {
class AuditoriumDeleteForm;
}

class AuditoriumDeleteForm : public QWidget {
    Q_OBJECT

  public:
    explicit AuditoriumDeleteForm(QWidget* parent = nullptr);
    ~AuditoriumDeleteForm();

  private slots:
    void resirvedData(QSqlTableModel*, QSqlQueryModel*); // Приёмник моделей QSqlTableModel и QSqlQueryModel

    void onExitButtonClicked();   // exitButton, нажатие
    void onDeleteButtonClicked(); // deleteButton, нажатие

  private:
    Ui::AuditoriumDeleteForm* ui; // Интерфейс пользователя
    QSqlTableModel* model;        // Модель, используется для отображения БД
    QSqlQueryModel* queryModel;   // Модель, используется для выполнения запросов

    int deleteCounter; // Счётчик удаления

    QStringList bodyList;   // Список номеров корпусов
    QStringList floorList;  // Список номеров этажей
    QStringList numberList; // Список номеров комнат

    void SaveBodies();  // Сохранение всех номеров корпусов в bodyBox
    void SaveFloors();  // Сохранение всех номеров этажей в floorBox
    void SaveNumbers(); // Сохранение всех номеров кабинетов в numberBox

    void DeleteLessons();    // Удаление занятий
    void DeleteAuditories(); // Удаление аудиторий

    void Debug(QString message); // Сохранение отладочного сообщения в лог
};

#endif // AUDITORIUMDELETEFORM_H
