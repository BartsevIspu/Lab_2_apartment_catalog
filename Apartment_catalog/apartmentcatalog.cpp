#include "apartmentcatalog.h"
#include "ui_apartmentcatalog.h"
#include "districtdelegate.h"
#include "editapdialog.h"
#include "editdialogdelegate.h"
#include "roomdelegate.h"
#include "materialdelegate.h"
#include "linedelegate.h"
#include "mymodel.h"
#include <QGridLayout>
#include <QPushButton>

ApartmentCatalog::ApartmentCatalog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ApartmentCatalog)
{
    ui->setupUi(this);

    tableView = new QTableView();
    myModel = new MyModel(this);

    tableView->setModel(myModel);
    tableView->viewport()->setAttribute(Qt::WA_Hover);
    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    EditDialogDelegate* editDialogDelegate = new EditDialogDelegate(nullptr,this);
    tableView->setItemDelegateForColumn(0, editDialogDelegate);

    LineDelegate* lineDelegate = new LineDelegate();
    tableView->setItemDelegateForColumn(2, lineDelegate);
    tableView->setItemDelegateForColumn(4, lineDelegate);

    DistrictDelegate* districtDelegate = new DistrictDelegate();
    tableView->setItemDelegateForColumn(1, districtDelegate);

    RoomDelegate* roomDelegate = new RoomDelegate();
    tableView->setItemDelegateForColumn(3, roomDelegate);

    MaterialDelegate* materialDelegate = new MaterialDelegate();
    tableView->setItemDelegateForColumn(5, materialDelegate);

    QGridLayout* layout= new QGridLayout();
    layout->addWidget(tableView, 1, 1, 1, 2);

    QPushButton* addApartmentButton = new QPushButton("Add row");
    QPushButton* deleteApartmentButton = new QPushButton("Delete row");

    layout->addWidget(addApartmentButton, 2, 1);
    layout->addWidget(deleteApartmentButton, 2, 2);

    QObject::connect(addApartmentButton,SIGNAL(clicked(bool)),this,SLOT(addRow()));
    QObject::connect(deleteApartmentButton,SIGNAL(clicked(bool)),this,SLOT(deleteRow()));

    QWidget* wdg=new QWidget();
    wdg->setLayout(layout);
    this->setWindowTitle("ApartmentCatalog");
    this->setCentralWidget(wdg);
}

ApartmentCatalog::~ApartmentCatalog()
{
    delete ui;
}

void ApartmentCatalog::addRow()
{
    EditApDialog* addDialog = new EditApDialog(this);
    if (addDialog->exec() == QDialog::Accepted)
    {
        Apartment* ap = new Apartment(addDialog->id(),addDialog->cityDistrict(),addDialog->size(),
                           addDialog->roomNumber(), addDialog->floor(), addDialog->wallMaterial(), this);
        myModel->addApartment(ap);
    }

    addDialog->deleteLater();
}

void ApartmentCatalog::deleteRow()
{
    QModelIndex selList = tableView->currentIndex();
    if (selList.isValid())
        myModel->deleteApartment(selList.row());
}

