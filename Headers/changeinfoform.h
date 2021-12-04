#ifndef CHANGEINFOFORM_H
#define CHANGEINFOFORM_H

#include <QWidget>

namespace Ui {
class ChangeInfoForm;
}

class ChangeInfoForm : public QWidget {
    Q_OBJECT

  public:
    explicit ChangeInfoForm(QWidget* parent = nullptr);
    ~ChangeInfoForm();

  private slots:
    void onExitButtonClicked(); // exitButton, нажатие

  private:
    Ui::ChangeInfoForm* ui;
};

#endif // CHANGEINFOFORM_H
