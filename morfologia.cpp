#include "morfologia.h"
#include "ui_morfologia.h"
#include "imagenes.h"

Morfologia::Morfologia(int numfoto, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Morfologia)
{
    ui->setupUi(this);
    nfoto = numfoto;
    activar_callback_fotos(false);
    morfologia(nfoto, OP_EROSION, 3);
}

Morfologia::~Morfologia()
{
    activar_callback_fotos(true);
    delete ui;
}

void Morfologia::on_comboBox_currentIndexChanged(int index)
{
    if (ui->checkBox->isChecked()) {
        op_morfologia modo = (op_morfologia)index;
        morfologia(nfoto, modo, ui->spinBox->value(), false);
    }
}

void Morfologia::on_spinBox_valueChanged(int arg1)
{
    if (ui->checkBox->isChecked()) {
        op_morfologia modo = (op_morfologia)ui->comboBox->currentIndex();
        morfologia(nfoto, modo, arg1, false);
    }
}

void Morfologia::on_checkBox_stateChanged(int arg1)
{
    if (arg1) {
        op_morfologia modo = (op_morfologia)ui->comboBox->currentIndex();
        morfologia(nfoto, modo, ui->spinBox->value(), false);
    } else {
        mostrar(nfoto);
    }
}

void Morfologia::on_Morfologia_accepted()
{
    op_morfologia modo = (op_morfologia)ui->comboBox->currentIndex();
    morfologia(nfoto, modo, ui->spinBox->value(), true);
}

void Morfologia::on_Morfologia_rejected()
{
    mostrar(nfoto); // Restaurar original
}
