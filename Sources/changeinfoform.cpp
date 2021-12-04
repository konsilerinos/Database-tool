#include "changeinfoform.h"
#include "ui_changeinfoform.h"

ChangeInfoForm::ChangeInfoForm(QWidget* parent) : QWidget(parent), ui(new Ui::ChangeInfoForm) {

    ui->setupUi(this);

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked())); // exitButton, нажатие
}

ChangeInfoForm::~ChangeInfoForm() { delete ui; }

// exitButton, нажатие
void ChangeInfoForm::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}
