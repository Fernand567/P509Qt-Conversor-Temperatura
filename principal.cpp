#include "principal.h"
#include "ui_principal.h"

#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{

    ui->setupUi(this);
    // Conectar el dial de cent a fahr
    connect(ui->inCent, SIGNAL(valueChanged(int)),this,SLOT(cent2fahr(int)));
    // Conectar el dial de fahr a cent
    connect(ui->inFar, SIGNAL(valueChanged(int)),this,SLOT(fahr2cent(int)));
    // Conectar el dial de kelv a cent
    connect(ui->inKelv,SIGNAL(valueChanged(int)),this,SLOT(kelv2cent(int)));
    // Conectar el dial de cent a kelv
    connect(ui->inCent,SIGNAL(valueChanged(int)),this,SLOT(cent2kelv(int)));
    // Conectar el dial de kelv a fahr
    connect(ui->inKelv,SIGNAL(valueChanged(int)),this,SLOT(kelv2fahr(int)));
    // Conectar el dial de fahr a kelv
    connect(ui->inFar,SIGNAL(valueChanged(int)),this,SLOT(fahr2kelv(int)));

}

Principal::~Principal()
{
    delete ui;
}

void Principal::cent2fahr(int i)
{
    if (ui->inCent->hasFocus()){
        float f = (i*9.0/5)+32;
        ui->inFar->setValue(f);
    }
}

void Principal::fahr2cent(int i)
{
    if (ui->inFar->hasFocus()){
        int c = (i-32)*5.0/9;
        ui->inCent->setValue(c);
    }
}

void Principal::cent2kelv(int i)
{
    if(ui->inCent->hasFocus()){
        int c=(i+273);
        ui->inKelv->setValue(c);
    }
}

void Principal::kelv2cent(int i)
{
    if(ui->inKelv->hasFocus()){
        int k=(i-273);
        ui->inCent->setValue(k);
    }
}

void Principal::fahr2kelv(int i)
{
    if(ui->inFar->hasFocus()){
        int f=(i-32)*5/9+273;
        ui->inKelv->setValue(f);
    }
}

void Principal::kelv2fahr(int i)
{
    if(ui->inKelv->hasFocus()){
        int k=(i-273)*9/5+32;
        ui->inFar->setValue(k);
    }
}
