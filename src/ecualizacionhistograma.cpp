#include "ecualizacionhistograma.h"
#include "ui_ecualizacionhistograma.h"
#include "imagenes.h"

EcualizacionHistograma::EcualizacionHistograma(int numfoto, int modo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EcualizacionHistograma)
{
    ui->setupUi(this);
    nfoto = numfoto;
    tipo = modo;
    activar_callback_fotos(false);
    ecualizacion_hist(nfoto, 0);
}

EcualizacionHistograma::~EcualizacionHistograma()
{
    activar_callback_fotos(true);
    delete ui;
}

void EcualizacionHistograma::on_radioButton_clicked()
{
    tipo = 0;
    if (ui->checkBox->isChecked())
        ecualizacion_hist(nfoto, tipo);
}


void EcualizacionHistograma::on_radioButton_2_clicked()
{
    tipo = 1;
    if (ui->checkBox->isChecked())
        ecualizacion_hist(nfoto, tipo);
}


void EcualizacionHistograma::on_EcualizacionHistograma_accepted()
{
    ecualizacion_hist(nfoto, tipo, true);
}


void EcualizacionHistograma::on_EcualizacionHistograma_rejected()
{
    mostrar(nfoto);
}


void EcualizacionHistograma::on_checkBox_stateChanged(int arg1)
{
    if (arg1)
        ecualizacion_hist(nfoto, tipo);
    else
        mostrar(nfoto);
}

