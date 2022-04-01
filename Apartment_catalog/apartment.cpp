#include "apartment.h"
#include <QTableWidget>

Apartment::Apartment(QString ID, QString CityDistrict, QString Size, QString RoomNumber, QString Floor,
                 QString WallMaterial, QObject *parent): QObject(parent)
{
    id = ID;
    cityDistrict = CityDistrict;
    size = Size;
    roomNumber = RoomNumber;
    floor = Floor;
    wallMaterial = WallMaterial;
}

void Apartment::setID(QString value)
{
    id = value;
}
void Apartment::setCityDistrict(QString value)
{
    cityDistrict = value;
}
void Apartment::setSize(QString value)
{
    size = value;
}
void Apartment::setRoomNumber(QString value)
{
    roomNumber = value;
}
void Apartment::setFloor(QString value)
{
    floor = value;
}
void Apartment::setWallMaterial(QString value)
{
    wallMaterial = value;
}

QString Apartment::getID()
{
    return id;
}
QString Apartment::getCityDistrict()
{
    return cityDistrict;
}
QString Apartment::getSize()
{
    return size;
}
QString Apartment::getRoomNumber()
{
    return roomNumber;
}
QString Apartment::getFloor()
{
    return floor;
}
QString Apartment::getWallMaterial()
{
    return wallMaterial;
}

QStringList Apartment::GetDistricts()
{
    QStringList value;
    value.append("Ленинский");
    value.append("Фрунзенский");
    value.append("Октябрьский");
    value.append("Советский");
    return value;
}

QStringList Apartment::GetRooms()
{
    QStringList value;
    value.append("1");
    value.append("2");
    value.append("3");
    value.append("4");
    return value;
}

QStringList Apartment::GetMaterials()
{
    QStringList value;
    value.append("Белый кирпич");
    value.append("Красный кирпич");
    value.append("Древесина");
    value.append("Гипсокартон");
    value.append("Газобетон");
    return value;
}

Apartment::~Apartment()
{
}
