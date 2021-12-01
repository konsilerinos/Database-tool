#ifndef REQUESTSFORM_H
#define REQUESTSFORM_H

#include <QSqlTableModel>
#include <QStringList>
#include <QWidget>

namespace Ui {
class RequestsForm;
}

class RequestsForm : public QWidget {
    Q_OBJECT

  public:
    explicit RequestsForm(QWidget* parent = nullptr);
    ~RequestsForm();

  signals:
    void SendModel();              // Отправка сигнала для отображения модели
    void SendRequestName(QString); // Отправка имени запроса

  private slots:
    void resirvedData(QSqlTableModel*); // Приёмник моделей QSqlTableModel и QSqlQueryModel
    void onGenerateButtonClicked();     // generateButton, нажатие
    void onExitButtonClicked();         // exitButton, нажатие
    void onRequestsBoxTextChanged();    // requestsBox, изменение значения

  private:
    Ui::RequestsForm* ui;

    QString tableName = "";   // Название таблицы
    QString requestText = ""; // Текст запроса
    QString requestName = ""; // Имя запроса

    QSqlTableModel* model; // Модель, используется для отображения БД

    void SetRequestsNames(); // Сохранение названий запросов в requestsBox
};

#endif // REQUESTSFORM_H
