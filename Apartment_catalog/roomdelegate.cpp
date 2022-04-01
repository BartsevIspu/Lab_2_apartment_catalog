#include "roomdelegate.h"
#include "QtWidgets"
#include "apartment.h"

RoomDelegate::RoomDelegate(QObject *parent): QItemDelegate(parent)
{

}


QWidget *RoomDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QComboBox* cmb = new QComboBox(parent);
    QStringList rooms = Apartment::GetRooms();
    foreach  (QString room, rooms)
    {
        cmb->addItem(room);
    }
    return cmb;
}

void RoomDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    QComboBox *myeditor = static_cast<QComboBox*>(editor);

    QString value = myeditor->currentText();

    model->setData(index, value, Qt::EditRole);
}

void RoomDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QComboBox *myeditor = qobject_cast<QComboBox *>(editor);
    const QString currentText =  index.data(Qt::DisplayRole).toString();
    const int cbIndex = myeditor->findText(currentText);
    if (cbIndex >= 0)
       myeditor->setCurrentIndex(cbIndex);
}
