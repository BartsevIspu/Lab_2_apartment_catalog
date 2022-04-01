#ifndef APARTMENT_H
#define APARTMENT_H

#include "QString"
#include <QObject>

class Apartment: public QObject
{
    Q_OBJECT

public:
    Apartment(QString ID, QString CityDistrict, QString Size, QString RoomNumber, QString Floor, QString WallMaterial, QObject *parent = nullptr );
    virtual ~Apartment();

    void setID(QString ID);
    void setCityDistrict(QString CityDistrict);
    void setSize(QString Size);
    void setRoomNumber(QString RoomNumber);
    void setFloor(QString Floor);
    void setWallMaterial(QString WallMaterial);

    QString getID();
    QString getCityDistrict();
    QString getSize();
    QString getRoomNumber();
    QString getFloor();
    QString getWallMaterial();

    static QStringList GetRooms();
    static QStringList GetMaterials();
    static QStringList GetDistricts();

private:
    QString id;
    QString cityDistrict;
    QString size;
    QString roomNumber;
    QString floor;
    QString wallMaterial;
};

#endif // APARTMENT_H
