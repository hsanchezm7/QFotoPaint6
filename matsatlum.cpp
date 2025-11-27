#include "matsatlum.h"
#include "ui_matsatlum.h"
#include "imagenes.h"

MatSatLum::MatSatLum(int numfoto, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MatSatLum)
{
    ui->setupUi(this);
    nfoto = numfoto;
    activar_callback_fotos(false);
}

MatSatLum::~MatSatLum()
{
    delete ui;
    activar_callback_fotos(true);
}

void MatSatLum::on_horizontalSlider_valueChanged(int value)
{
    ver_matsatlum(nfoto, ui->dial->value(),
                  ui->horizontalSlider->value()/100.0,
                  ui->horizontalSlider_2->value()/100.0);
}

void MatSatLum::on_horizontalSlider_2_valueChanged(int value)
{
    ver_matsatlum(nfoto, ui->dial->value(),
                  ui->horizontalSlider->value()/100.0,
                  ui->horizontalSlider_2->value()/100.0);
}

void MatSatLum::on_dial_valueChanged(int value)
{
    ver_matsatlum(nfoto, ui->dial->value(),
                  ui->horizontalSlider->value()/100.0,
                  ui->horizontalSlider_2->value()/100.0);
}


void MatSatLum::on_MatSatLum_accepted()
{
    ver_matsatlum(nfoto, ui->dial->value(),
                  ui->horizontalSlider->value()/100.0,
                  ui->horizontalSlider_2->value()/100.0,
                  true);
}

void MatSatLum::on_MatSatLum_rejected()
{
    mostrar(nfoto);
}
