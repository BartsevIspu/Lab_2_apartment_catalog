#ifndef APARTMENTCATALOG_H
#define APARTMENTCATALOG_H

#include <QMainWindow>
#include "mymodel.h"
#include "QTableView"

QT_BEGIN_NAMESPACE
namespace Ui { class ApartmentCatalog; }
QT_END_NAMESPACE

class ApartmentCatalog : public QMainWindow
{
    Q_OBJECT

public:
    ApartmentCatalog(QWidget *parent = nullptr);
    ~ApartmentCatalog();

public slots:
    void addRow();
    void deleteRow();

private:
    Ui::ApartmentCatalog *ui;
    MyModel* myModel;
    QTableView* tableView;
};
#endif // APARTMENTCATALOG_H
