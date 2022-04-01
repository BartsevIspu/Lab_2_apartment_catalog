#ifndef EDITAPDIALOG_H
#define EDITAPDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "apartment.h"


class EditApDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit *editIDLine;
    QComboBox *editDistrictComboBox;
    QLineEdit *editSize;
    QComboBox *editRoomComboBox;
    QLineEdit *editFloor;
    QComboBox *editMaterialComboBox;

public:
    EditApDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString cityDistrict() const;
    QString size() const;
    QString roomNumber() const;
    QString floor() const;
    QString wallMaterial() const;

    void setUpDialog(QString id, QString cityDistrict, QString size, QString roomNumber,
                     QString floor, QString wallMaterial);
};

#endif // EDITAPDIALOG_H
