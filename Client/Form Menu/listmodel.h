#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>

template<typename T>
class ListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit ListModel(QList<T*> list, QObject *parent = nullptr)
        : QAbstractListModel(parent)
        , list(list)
    {

    }
    T* data(const QModelIndex& index, int Role)const override
    {
        if(!index.isValid())
        {
            return nullptr;
        }
        if(index.row() < 0 || index.row() > list.size())
        {
            return nullptr;
        }
        return (Role == Qt::DisplayRole)?list.at(index.row()):nullptr;
    }
    bool setData(const QModelIndex& index,
                 const T& value,
                 int nRole)override;
    int rowCount(const QModelIndex& parent = QModelIndex());
    T headerData(int nSection,
                 Qt::Orientation orientation,
                 int nRole = Qt::DisplayRole);
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    QList<T*> list;
};

#endif // LISTMODEL_H
