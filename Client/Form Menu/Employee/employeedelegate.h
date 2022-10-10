#ifndef EMPLOYEEDELEGATE_H
#define EMPLOYEEDELEGATE_H

#include <QtWidgets>

class EmployeeDelegate : public QStyledItemDelegate
{
public:
    explicit EmployeeDelegate(QObject *parent = nullptr);

    virtual void paint(
               QPainter*            painter,
               const QStyleOptionViewItem&  option,
               const QModelIndex&           index
               )const override;
    virtual QSize sizeHint(
                   const QStyleOptionViewItem& option,
                   const QModelIndex&
                   )const override;

};

#endif // EMPLOYEEDELEGATE_H
