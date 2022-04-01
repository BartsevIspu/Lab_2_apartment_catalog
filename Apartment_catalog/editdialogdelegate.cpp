#include "editdialogdelegate.h"
#include "QtWidgets"
#include "editapdialog.h"

EditDialogDelegate::EditDialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;
}


bool EditDialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *mymodel,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditApDialog* editDialog = new EditApDialog(dparentWidget);

        QString id = mymodel->data(mymodel->index(index.row(),0,index)).toString();
        QString cityDistrict = mymodel->data(mymodel->index(index.row(),1,index)).toString();
        QString size = mymodel->data(mymodel->index(index.row(),2,index)).toString();
        QString roomNumber = mymodel->data(mymodel->index(index.row(),3,index)).toString();
        QString floor = mymodel->data(mymodel->index(index.row(),4,index)).toString();
        QString wallMaterial = mymodel->data(mymodel->index(index.row(),5,index)).toString();


        editDialog->setUpDialog(id, cityDistrict, size, roomNumber, floor, wallMaterial);

        if (editDialog->exec() == QDialog::Accepted)
        {
            mymodel->setData(mymodel->index(index.row(),0,index),editDialog->id());
            mymodel->setData(mymodel->index(index.row(),1,index),editDialog->cityDistrict());
            mymodel->setData(mymodel->index(index.row(),2,index),editDialog->size());
            mymodel->setData(mymodel->index(index.row(),3,index),editDialog->roomNumber());
            mymodel->setData(mymodel->index(index.row(),4,index),editDialog->floor());
            mymodel->setData(mymodel->index(index.row(),5,index),editDialog->wallMaterial());
        }

         editDialog->deleteLater();
    }
    return false;
}

QWidget *EditDialogDelegate::createEditor(QWidget* /* parent */,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    return nullptr;
}
