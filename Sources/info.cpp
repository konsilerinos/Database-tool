#include "info.h"
#include "ui_info.h"

Info::Info(QWidget* parent) : QWidget(parent), ui(new Ui::Info) {

    ui->setupUi(this);

    // exitButton, нажатие
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(onExitButtonClicked()));
}

Info::~Info() { delete ui; }

// exitButton, нажатие
void Info::onExitButtonClicked() {

    QWidget::close(); // Закрытие формы
}
