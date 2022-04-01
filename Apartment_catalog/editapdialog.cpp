#include "editapdialog.h"
#include "apartment.h"

EditApDialog::EditApDialog(QWidget* pwgt): QDialog(pwgt)
{
    editIDLine = new QLineEdit();
    editDistrictComboBox = new QComboBox();
    editSize = new QLineEdit();
    editRoomComboBox = new QComboBox();
    editFloor = new QLineEdit();
    editMaterialComboBox = new QComboBox();

    QStringList districts = Apartment::GetDistricts();
    foreach  (QString district, districts)
    {
        editDistrictComboBox->addItem(district);
    }

    QStringList rooms = Apartment::GetRooms();
    foreach  (QString room, rooms)
    {
        editRoomComboBox->addItem(room);
    }

    QStringList mats = Apartment::GetMaterials();
    foreach  (QString mat, mats)
    {
        editMaterialComboBox->addItem(mat);
    }

    QGridLayout* layout = new QGridLayout;

    layout->addWidget(new QLabel("id"),1,1);
    layout->addWidget(editIDLine,1,2);

    layout->addWidget(new QLabel("Район города"),2,1);
    layout->addWidget(editDistrictComboBox,2,2);

    layout->addWidget(new QLabel("Площадь (м2)"),3,1);
    layout->addWidget(editSize,3,2);

    layout->addWidget(new QLabel("Кол-во комнат"),4,1);
    layout->addWidget(editRoomComboBox,4,2);

    layout->addWidget(new QLabel("Этаж"),5,1);
    layout->addWidget(editFloor,5,2);

    layout->addWidget(new QLabel("Материал стен"),6,1);
    layout->addWidget(editMaterialComboBox,6,2);

    QPushButton* buttonOk = new QPushButton("&ОК");

    layout->addWidget(buttonOk,7,1,1,2);

    QObject::connect(buttonOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(layout);
    this->setWindowTitle("Добавление/редактура");

    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditApDialog::id() const
{
    return editIDLine->text();
}
QString EditApDialog::cityDistrict() const
{
    return editDistrictComboBox->currentText();
}
QString EditApDialog::size() const
{
    return editSize->text();
}
QString EditApDialog::roomNumber() const
{
    return editRoomComboBox->currentText();
}
QString EditApDialog::floor() const
{
    return editFloor->text();
}
QString EditApDialog::wallMaterial() const
{
    return editMaterialComboBox->currentText();
}

void EditApDialog::setUpDialog(QString id, QString cityDistrict, QString size, QString roomNumber,
                                QString floor, QString wallMaterial)
{
    editIDLine->setText(id);
    int ind = editDistrictComboBox->findText(cityDistrict);
    if (ind>=0)
    {
        editDistrictComboBox->setCurrentIndex(ind);
    }
    editSize->setText(size);
    int ind1 = editRoomComboBox->findText(roomNumber);
    if (ind1>=0)
    {
        editRoomComboBox->setCurrentIndex(ind1);
    }
    editFloor->setText(floor);
    int ind2 = editMaterialComboBox->findText(wallMaterial);
    if (ind2>=0)
    {
        editMaterialComboBox->setCurrentIndex(ind2);
    }
}
