#ifndef ROOMDELEGATE_H
#define ROOMDELEGATE_H

#include "QtWidgets"

class RoomDelegate: public QItemDelegate
{
    Q_OBJECT
public:
    RoomDelegate(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

};

#endif // ROOMDELEGATE_H
