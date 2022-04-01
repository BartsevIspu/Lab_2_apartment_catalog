#ifndef DISTRICTDELEGATE_H
#define DISTRICTDELEGATE_H

#include "QtWidgets"

class DistrictDelegate: public QItemDelegate
{
    Q_OBJECT
public:
    DistrictDelegate(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

};

#endif // DISTRICTDELEGATE_H
