#ifndef DEPARTMENTDELETEFORM_H
#define DEPARTMENTDELETEFORM_H

#include <QWidget>

namespace Ui {
class DepartmentDeleteForm;
}

class DepartmentDeleteForm : public QWidget
{
    Q_OBJECT

public:
    explicit DepartmentDeleteForm(QWidget *parent = nullptr);
    ~DepartmentDeleteForm();

private:
    Ui::DepartmentDeleteForm *ui;
};

#endif // DEPARTMENTDELETEFORM_H
