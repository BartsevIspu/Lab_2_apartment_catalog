#ifndef EDITDIALOGDELEGATE_H
#define EDITDIALOGDELEGATE_H


#include "QtWidgets"

class EditDialogDelegate: public QStyledItemDelegate
{
    Q_OBJECT

public:
    EditDialogDelegate(QObject *parent = nullptr, QWidget* parentWidget = nullptr);

    bool editorEvent(QEvent *event, QAbstractItemModel *mymodel,
                     const QStyleOptionViewItem &option, const QModelIndex &index);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    private:
    QWidget* dparentWidget;
};

#endif // EDITDIALOGDELEGATE_H
