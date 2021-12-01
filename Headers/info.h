#ifndef INFO_H
#define INFO_H

#include <QWidget>

namespace Ui {
class Info;
}

class Info : public QWidget {
    Q_OBJECT

  public:
    explicit Info(QWidget* parent = nullptr);
    ~Info();

  private slots:
    void onExitButtonClicked(); // exitButton, нажатие

  private:
    Ui::Info* ui;
};

#endif // INFO_H
