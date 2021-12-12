#ifndef TIMEDELEGATE_H
#define TIMEDELEGATE_H

#include <QDateTime>
#include <QStyledItemDelegate>

class timeDelegate : public QStyledItemDelegate {
  public:
    timeDelegate(QWidget* parent = 0) : QStyledItemDelegate(parent) {}

    QString displayText(const QVariant& value, const QLocale& locale) const {

        // 123
        return value.toDateTime().toString("hh:mm");
    }
};

#endif // TIMEDELEGATE_H
