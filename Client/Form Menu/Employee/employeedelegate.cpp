#include "employeedelegate.h"
#include "qobject.h"

EmployeeDelegate::EmployeeDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void EmployeeDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(option.state & QStyle::State_MouseOver)
    {
        QRect   rect = option.rect;
        QLinearGradient gradient(0, 0, rect.width(), rect.height());

        gradient.setColorAt(0, Qt::white);
        gradient.setColorAt(0.5, Qt::blue);
        gradient.setColorAt(1, Qt::green);
        painter->setBrush(gradient);
        painter->setPen(QColor(QRgb(0xffffff)));
        painter->drawRect(rect);
    }
    QStyledItemDelegate::paint(painter, option, index);
}

QSize EmployeeDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &) const
{
    return QSize(option.rect.width(), 55);
}
