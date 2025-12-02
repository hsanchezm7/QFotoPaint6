#include "perfilado.h"
#include "ui_perfilado.h"
#include "imagenes.h"

Perfilado::Perfilado(int numfoto, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Perfilado)
{
    ui->setupUi(this);
    nfoto = numfoto;
    activar_callback_fotos(false);
    perfilado(nfoto, ui->spinBox->value(), ui->spinBox_2->value(), false);
}

Perfilado::~Perfilado()
{
    activar_callback_fotos(true);
    delete ui;
}

void Perfilado::on_Perfilado_accepted()
{
    perfilado(nfoto, ui->spinBox->value(), ui->spinBox_2->value(), true);
}

void Perfilado::on_Perfilado_rejected()
{
    mostrar(nfoto);
}

void Perfilado::on_checkBox_stateChanged(int arg1)
{
    if (arg1)
        perfilado(nfoto, ui->spinBox->value(), ui->spinBox_2->value());
    else
        mostrar(nfoto);
}


void Perfilado::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    if (ui->checkBox->isChecked())
        perfilado(nfoto, ui->spinBox->value(), ui->spinBox_2->value());
}

void Perfilado::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}


void Perfilado::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    if (ui->checkBox->isChecked())
        perfilado(nfoto, ui->spinBox->value(), ui->spinBox_2->value());
}

void Perfilado::on_spinBox_2_valueChanged(int arg1)
{
    ui->horizontalSlider_2->setValue(arg1);
}
