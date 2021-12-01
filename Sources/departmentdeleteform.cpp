#include "departmentdeleteform.h"
#include "ui_departmentdeleteform.h"

DepartmentDeleteForm::DepartmentDeleteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepartmentDeleteForm)
{
    ui->setupUi(this);
}

DepartmentDeleteForm::~DepartmentDeleteForm()
{
    delete ui;
}
