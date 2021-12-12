#ifndef VALUEDELEGATE_H
#define VALUEDELEGATE_H

#include <QStyledItemDelegate>
#include <QWidget>

class valueDelegate : public QStyledItemDelegate {
  public:
    valueDelegate(QWidget* parent = 0) : QStyledItemDelegate(parent) {}

    QString displayText(const QVariant& value, const QLocale& locale) const {

        // 123
        return value.toString();
    }
};

#endif // VALUEDELEGATE_H
