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
