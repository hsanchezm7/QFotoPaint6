#include "bajorrelieve.h"
#include "ui_bajorrelieve.h"
#include "imagenes.h"


Bajorrelieve::Bajorrelieve(int numfoto, int numres, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Bajorrelieve)
{
    ui->setupUi(this);
    activar_callback_fotos(false);
    nfoto = numfoto;
    nres = numres;
    ntextura = 0;
    ver_bajorrelieve(nfoto, nres, ui->dial->value(),
                     ui->horizontalSlider->value()/100.0,
                     ui->spinBox->value(), ntextura);
}

Bajorrelieve::~Bajorrelieve()
{
    activar_callback_fotos(true);
    delete ui;
}

void Bajorrelieve::on_horizontalSlider_valueChanged(int value)
{
    ver_bajorrelieve(nfoto, nres, ui->dial->value(),
                     ui->horizontalSlider->value()/100.0,
                     ui->spinBox->value(), ntextura);
}


void Bajorrelieve::on_dial_valueChanged(int value)
{
    ver_bajorrelieve(nfoto, nres, ui->dial->value(),
                     ui->horizontalSlider->value()/100.0,
                     ui->spinBox->value(), ntextura);
}


void Bajorrelieve::on_spinBox_valueChanged(int arg1)
{
    ver_bajorrelieve(nfoto, nres, ui->dial->value(),
                     ui->horizontalSlider->value()/100.0,
                     ui->spinBox->value(), ntextura);
}


void Bajorrelieve::on_radioButton_clicked()
{
    ntextura = 0;
    ver_bajorrelieve(nfoto, nres, ui->dial->value(),
                     ui->horizontalSlider->value()/100.0,
                     ui->spinBox->value(), ntextura);
}


void Bajorrelieve::on_radioButton_2_clicked()
{
    ntextura = 1;
    ver_bajorrelieve(nfoto, nres, ui->dial->value(),
                     ui->horizontalSlider->value()/100.0,
                     ui->spinBox->value(), ntextura);
}


void Bajorrelieve::on_radioButton_3_clicked()
{
    ntextura = 2;
    ver_bajorrelieve(nfoto, nres, ui->dial->value(),
                     ui->horizontalSlider->value()/100.0,
                     ui->spinBox->value(), ntextura);
}


void Bajorrelieve::on_radioButton_4_clicked()
{
    ntextura = 3;
    ver_bajorrelieve(nfoto, nres, ui->dial->value(),
                     ui->horizontalSlider->value()/100.0,
                     ui->spinBox->value(), ntextura);
}


void Bajorrelieve::on_Bajorrelieve_accepted()
{
    ver_bajorrelieve(nfoto, nres, ui->dial->value(),
                     ui->horizontalSlider->value()/100.0,
                     ui->spinBox->value(), ntextura, true);

    destroyWindow("Efecto de bajorrelieve");
}


void Bajorrelieve::on_Bajorrelieve_rejected()
{
    destroyWindow("Efecto de bajorrelieve");
}

