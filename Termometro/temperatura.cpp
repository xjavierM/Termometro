#include "temperatura.h"
#include "ui_temperatura.h"
#include <QDebug>
#include <QMouseEvent>
Temperatura::Temperatura(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Temperatura)
{
    ui->setupUi(this);
    //Conexion de signal/slots
    connect(ui->dialCent,SIGNAL(valueChanged(int)),
            this,SLOT(cent2Fahr(int)));
    connect(ui->dialFahr,SIGNAL(valueChanged(int)),
            this,SLOT(fahr2Cent(int)));
    connect(ui->dialKelv,SIGNAL(valueChanged(int)),
            this,SLOT(kelv2Cent(int)));
    //Cambio de cursor
    connect(ui->dialCent, SIGNAL(sliderPressed()),
            this,SLOT(cambioCursor()));
    connect(ui->dialFahr, SIGNAL(sliderPressed()),
            this,SLOT(cambioCursor()));
    connect(ui->dialKelv, SIGNAL(sliderPressed()),
            this,SLOT(cambioCursor()));
    //Establecer valores
    ui->dialFahr->setValue(32);
    ui->dialKelv->setValue(273);
    ui->lblCent->setText("0\n°C");
    ui->lblFahr->setText("32\n°F");
    ui->lblKelvin->setText("273.15 \n°K");
}
Temperatura::~Temperatura()
{
    delete ui;
}
void Temperatura::cent2Fahr(int valor)
{
    if (ui->dialCent->hasFocus()){
        double f = valor * 9.0/5+32;
        double kelv =valor+273.15;
        QString fahr = QString::number(f);
        QString kelvin = QString::number(kelv);
        QString centi = QString::number(valor);
        ui->dialFahr->setValue(f);
        ui->dialKelv->setValue(kelv);
        ui->lblFahr->setText(fahr + "\n°F");
        ui->lblKelvin->setText(kelvin + "\n°K");
        ui->lblCent->setText(centi + "\n°C");
    }
}
void Temperatura::fahr2Cent(int valor)
{
    if (ui->dialFahr->hasFocus()){
        float c = (valor - 32)*5.0/9;
        float k = (valor - 32)*5.0/9+273.15;
        QString fahr = QString::number(valor);
        QString kelvin = QString::number(k);
        QString centi = QString::number(c);
        ui->dialCent->setValue(c);
        ui->dialKelv->setValue(k);
        ui->lblFahr->setText(fahr + "\n°F");
        ui->lblKelvin->setText(kelvin + "\n°K");
        ui->lblCent->setText(centi + "\n°C");
    }
}
void Temperatura::kelv2Cent(int valor)
{
    if (ui->dialKelv->hasFocus()){
        float c = (valor - 273.15);
        float f = (valor -273.15)*9/5.0+32;
        QString fahr = QString::number(f);
        QString kelvin = QString::number(valor);
        QString centi = QString::number(c);
        ui->dialFahr->setValue(f);
        ui->dialCent->setValue(c);
        ui->lblFahr->setText(fahr + "\n°F");
        ui->lblKelvin->setText(kelvin + "\n°K");
        ui->lblCent->setText(centi + "\n°C");
    }
}
void Temperatura::cambioCursor()
{
    if(ui->dialCent->hasFocus()){
        if(ui->dialCent->cursor() == Qt::OpenHandCursor){
            ui->dialCent->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialCent->setCursor(Qt::OpenHandCursor);
        }
    }else if (ui->dialFahr->hasFocus()){
        if(ui->dialFahr->cursor() == Qt::OpenHandCursor){
            ui->dialFahr->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialFahr->setCursor(Qt::OpenHandCursor);
        }
    }else if (ui->dialKelv->hasFocus()){
        if(ui->dialKelv->cursor() == Qt::OpenHandCursor){
            ui->dialKelv->setCursor(Qt::ClosedHandCursor);
        }else{
            ui->dialKelv->setCursor(Qt::OpenHandCursor);
        }
    }
}
