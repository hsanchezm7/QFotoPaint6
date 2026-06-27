#ifndef ECUALIZACIONHISTOGRAMA_H
#define ECUALIZACIONHISTOGRAMA_H

#include <QDialog>

namespace Ui {
class EcualizacionHistograma;
}

class EcualizacionHistograma : public QDialog
{
    Q_OBJECT

public:
    explicit EcualizacionHistograma(int numfoto, int modo, QWidget *parent = nullptr);
    ~EcualizacionHistograma();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_EcualizacionHistograma_accepted();

    void on_EcualizacionHistograma_rejected();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::EcualizacionHistograma *ui;
    int nfoto;
    int tipo; // 0: conjunta, 1: independiente
};

#endif // ECUALIZACIONHISTOGRAMA_H
