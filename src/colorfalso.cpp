#include "colorfalso.h"
#include "ui_colorfalso.h"
#include "imagenes.h"

ColorFalso::ColorFalso(int numfoto, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ColorFalso)
{
    ui->setupUi(this);
    nfoto = numfoto;
    activar_callback_fotos(false);
    aplicar_mapa_color(nfoto, 0);
}

ColorFalso::~ColorFalso()
{
    activar_callback_fotos(true);
    delete ui;
}

void ColorFalso::on_comboBox_currentIndexChanged(int index)
{
    if (ui->checkBox->isChecked())
        aplicar_mapa_color(nfoto, index, false);
}


void ColorFalso::on_ColorFalso_accepted()
{
    aplicar_mapa_color(nfoto, ui->comboBox->currentIndex(), true);
}


void ColorFalso::on_ColorFalso_rejected()
{
    mostrar(nfoto);
}


void ColorFalso::on_checkBox_stateChanged(int arg1)
{
    if (arg1)
        aplicar_mapa_color(nfoto, ui->comboBox->currentIndex(), false);
    else
        mostrar(nfoto);
}
