#include "materialdelegate.h"
#include "QtWidgets"
#include "apartment.h"

MaterialDelegate::MaterialDelegate(QObject *parent): QItemDelegate(parent)
{

}


QWidget *MaterialDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QComboBox* cmb = new QComboBox(parent);
    QStringList mats = Apartment::GetMaterials();
    foreach  (QString mat, mats)
    {
        cmb->addItem(mat);
    }
    return cmb;
}

void MaterialDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    QComboBox *myeditor = static_cast<QComboBox*>(editor);

    QString value = myeditor->currentText();

    model->setData(index, value, Qt::EditRole);
}

void MaterialDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QComboBox *myeditor = qobject_cast<QComboBox *>(editor);
    const QString currentText =  index.data(Qt::DisplayRole).toString();
    const int cbIndex = myeditor->findText(currentText);
    if (cbIndex >= 0)
       myeditor->setCurrentIndex(cbIndex);
}
