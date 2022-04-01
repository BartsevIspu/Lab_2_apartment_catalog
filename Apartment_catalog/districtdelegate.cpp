#include "districtdelegate.h"
#include "QtWidgets"
#include "apartment.h"

DistrictDelegate::DistrictDelegate(QObject *parent): QItemDelegate(parent)
{

}


QWidget *DistrictDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QComboBox* cmb = new QComboBox(parent);
    QStringList districts = Apartment::GetDistricts();
    foreach  (QString district, districts)
    {
        cmb->addItem(district);
    }
    return cmb;
}

void DistrictDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    QComboBox *myeditor = static_cast<QComboBox*>(editor);

    QString value = myeditor->currentText();

    model->setData(index, value, Qt::EditRole);
}

void DistrictDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QComboBox *myeditor = qobject_cast<QComboBox *>(editor);
    const QString currentText =  index.data(Qt::DisplayRole).toString();
    const int cbIndex = myeditor->findText(currentText);
    if (cbIndex >= 0)
       myeditor->setCurrentIndex(cbIndex);
}
