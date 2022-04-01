#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    Apartment* ap1 = new Apartment("0", "Фрунзенский", "30", "3", "9", "Газобетон", this);
    Apartment* ap2 = new Apartment("1","Ленинский","34", "3", "2", "Кирпич красный", this);
    Apartment* ap3 = new Apartment("2","Октябрьский","48", "4", "5", "Гипсокартон", this);
    addApartment(ap1);
    addApartment(ap2);
    addApartment(ap3);
}

int MyModel::rowCount(const QModelIndex &) const
{
   return apartments.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 6;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString value = "";
        Apartment* apartment = apartments.at(index.row());

        switch(index.column())
        {
        case 0: value = apartment->getID(); break;
        case 1: value = apartment->getCityDistrict(); break;
        case 2: value = apartment->getSize(); break;
        case 3: value = apartment->getRoomNumber(); break;
        case 4: value = apartment->getFloor(); break;
        case 5: value = apartment->getWallMaterial(); break;
        default: value = ""; break;
        }

        return value;
    }
    return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Район города");
            case 2:
                return QString("Площадь (м2)");
            case 3:
                return QString("Кол-во комнат");
            case 4:
                return QString("Этаж");
            case 5:
                return QString("Материал стен");
            }
        }
    }
    return QVariant();
}

bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (role == Qt::EditRole || role == Qt::DecorationRole)
    {
        Apartment* apartment = apartments.at(index.row());
        switch(index.column())
        {
        case 0: apartment->setID(value.toString()); break;
        case 1: apartment->setCityDistrict(value.toString()); break;
        case 2: apartment->setSize(value.toString()); break;
        case 3: apartment->setRoomNumber(value.toString()); break;
        case 4: apartment->setFloor(value.toString()); break;
        case 5: apartment->setWallMaterial(value.toString()); break;
        }
    }
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void MyModel::addApartment(Apartment *ap)
{
    beginInsertRows(QModelIndex(), apartments.size(), apartments.size());
    apartments.append(ap);
    endInsertRows();
}

void MyModel::deleteApartment(int row)
{
    beginRemoveRows(QModelIndex(), row, row);
    apartments.removeAt(row);
    endRemoveRows();
}
