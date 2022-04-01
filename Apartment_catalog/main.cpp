#include "apartmentcatalog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ApartmentCatalog w;
    w.setFixedSize(480, 240);
    w.show();
    return a.exec();
}
