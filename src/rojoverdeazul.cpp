#include "rojoverdeazul.h"
#include "ui_rojoverdeazul.h"
#include "imagenes.h"

RojoVerdeAzul::RojoVerdeAzul(int numfoto, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RojoVerdeAzul)
{
    ui->setupUi(this);
    nfoto = numfoto;
    activar_callback_fotos(false);
    ver_rojoverdeazul(nfoto, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0);
}

RojoVerdeAzul::~RojoVerdeAzul()
{
    delete ui;
    activar_callback_fotos(true);
}

void RojoVerdeAzul::on_doubleSpinBox_valueChanged(double arg1)
{
    ui->horizontalSlider->setValue((int)(arg1 * 100));
}

void RojoVerdeAzul::on_horizontalSlider_valueChanged(int value)
{
    ui->doubleSpinBox->setValue(value / 100.0);
    if (ui->checkBox->isChecked()) {
        ver_rojoverdeazul(nfoto,
                          ui->doubleSpinBox->value(),   ui->spinBox->value(),
                          ui->doubleSpinBox_2->value(), ui->spinBox_2->value(),
                          ui->doubleSpinBox_3->value(), ui->spinBox_3->value(),
                          false);
    }
}

void RojoVerdeAzul::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider_2->setValue(arg1);
}

void RojoVerdeAzul::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    if (ui->checkBox->isChecked()) {
        ver_rojoverdeazul(nfoto,
                          ui->doubleSpinBox->value(),   ui->spinBox->value(),
                          ui->doubleSpinBox_2->value(), ui->spinBox_2->value(),
                          ui->doubleSpinBox_3->value(), ui->spinBox_3->value(),
                          false);
    }
}

void RojoVerdeAzul::on_doubleSpinBox_2_valueChanged(double arg1)
{
    ui->horizontalSlider_3->setValue((int)(arg1 * 100));
}

void RojoVerdeAzul::on_horizontalSlider_3_valueChanged(int value)
{
    ui->doubleSpinBox_2->setValue(value / 100.0);
    if (ui->checkBox->isChecked()) {
        ver_rojoverdeazul(nfoto,
                          ui->doubleSpinBox->value(),   ui->spinBox->value(),
                          ui->doubleSpinBox_2->value(), ui->spinBox_2->value(),
                          ui->doubleSpinBox_3->value(), ui->spinBox_3->value(),
                          false);
    }
}

void RojoVerdeAzul::on_spinBox_2_valueChanged(int arg1)
{
    ui->horizontalSlider_4->setValue(arg1);
}

void RojoVerdeAzul::on_horizontalSlider_4_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    if (ui->checkBox->isChecked()) {
        ver_rojoverdeazul(nfoto,
                          ui->doubleSpinBox->value(),   ui->spinBox->value(),
                          ui->doubleSpinBox_2->value(), ui->spinBox_2->value(),
                          ui->doubleSpinBox_3->value(), ui->spinBox_3->value(),
                          false);
    }
}

void RojoVerdeAzul::on_doubleSpinBox_3_valueChanged(double arg1)
{
    ui->horizontalSlider_5->setValue((int)(arg1 * 100));
}

void RojoVerdeAzul::on_horizontalSlider_5_valueChanged(int value)
{
    ui->doubleSpinBox_3->setValue(value / 100.0);
    if (ui->checkBox->isChecked()) {
        ver_rojoverdeazul(nfoto,
                          ui->doubleSpinBox->value(),   ui->spinBox->value(),
                          ui->doubleSpinBox_2->value(), ui->spinBox_2->value(),
                          ui->doubleSpinBox_3->value(), ui->spinBox_3->value(),
                          false);
    }
}

void RojoVerdeAzul::on_spinBox_3_valueChanged(int arg1)
{
    ui->horizontalSlider_6->setValue(arg1);
}

void RojoVerdeAzul::on_horizontalSlider_6_valueChanged(int value)
{
    ui->spinBox_3->setValue(value);
    if (ui->checkBox->isChecked()) {
        ver_rojoverdeazul(nfoto,
                          ui->doubleSpinBox->value(),   ui->spinBox->value(),
                          ui->doubleSpinBox_2->value(), ui->spinBox_2->value(),
                          ui->doubleSpinBox_3->value(), ui->spinBox_3->value(),
                          false);
    }
}

void RojoVerdeAzul::on_checkBox_stateChanged(int arg1)
{
    if (arg1) {
        ver_rojoverdeazul(nfoto,
                          ui->doubleSpinBox->value(),   ui->spinBox->value(),
                          ui->doubleSpinBox_2->value(), ui->spinBox_2->value(),
                          ui->doubleSpinBox_3->value(), ui->spinBox_3->value(),
                          false);
    } else {
        mostrar(nfoto);
    }
}

void RojoVerdeAzul::on_RojoVerdeAzul_accepted()
{
    ver_rojoverdeazul(nfoto,
                      ui->doubleSpinBox->value(),   ui->spinBox->value(),
                      ui->doubleSpinBox_2->value(), ui->spinBox_2->value(),
                      ui->doubleSpinBox_3->value(), ui->spinBox_3->value(),
                      true);
}


void RojoVerdeAzul::on_RojoVerdeAzul_rejected()
{
    mostrar(nfoto);
}

