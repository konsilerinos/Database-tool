#ifndef DATEDELEGATE_H
#define DATEDELEGATE_H

#include <QDateTime>
#include <QStyledItemDelegate>

class dateDelegate : public QStyledItemDelegate {
  public:
    dateDelegate(QWidget* parent = 0) : QStyledItemDelegate(parent) {}

    QString displayText(const QVariant& value, const QLocale& locale) const {

        // 123
        return value.toDateTime().toString("dd.MM.yyyy");
    }
};

#endif // DATEDELEGATE_H
