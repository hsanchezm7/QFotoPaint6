#include "ajustelineal.h"
#include "ui_ajustelineal.h"
#include "imagenes.h"

AjusteLineal::AjusteLineal(int numfoto, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AjusteLineal)
{
    ui->setupUi(this);
    nfoto = numfoto;
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &AjusteLineal::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &AjusteLineal::reject);
    activar_callback_fotos(false);
    ajuste_lineal_hist(nfoto, 5, 5);
}

AjusteLineal::~AjusteLineal()
{
    activar_callback_fotos(true);
    delete ui;
}

void AjusteLineal::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    if (ui->checkBox->isChecked())
        ajuste_lineal_hist(nfoto, ui->spinBox->value(), ui->spinBox_2->value());
}


void AjusteLineal::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}


void AjusteLineal::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    if (ui->checkBox->isChecked())
        ajuste_lineal_hist(nfoto, ui->spinBox->value(), ui->spinBox_2->value());
}



void AjusteLineal::on_spinBox_2_valueChanged(int arg1)
{
    ui->horizontalSlider_2->setValue(arg1);
}


void AjusteLineal::on_checkBox_stateChanged(int arg1)
{
    if (arg1)
        ajuste_lineal_hist(nfoto, ui->spinBox->value(), ui->spinBox_2->value());
    else
        mostrar(nfoto);
}


void AjusteLineal::on_AjusteLineal_rejected()
{
    mostrar(nfoto);
}


void AjusteLineal::on_AjusteLineal_accepted()
{
    ajuste_lineal_hist(nfoto, ui->spinBox->value(), ui->spinBox_2->value(), true);
}

