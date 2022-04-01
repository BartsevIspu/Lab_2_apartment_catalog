#ifndef MATERIALDELEGATE_H
#define MATERIALDELEGATE_H

#include "QtWidgets"

class MaterialDelegate: public QItemDelegate
{
    Q_OBJECT
public:
    MaterialDelegate(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

};

#endif // MATERIALDELEGATE_H
