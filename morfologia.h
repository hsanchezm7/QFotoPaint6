#ifndef MORFOLOGIA_H
#define MORFOLOGIA_H

#include <QDialog>

namespace Ui {
class Morfologia;
}

class Morfologia : public QDialog
{
    Q_OBJECT

public:
    explicit Morfologia(int numfoto, QWidget *parent = nullptr);
    ~Morfologia();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_spinBox_valueChanged(int arg1);

    void on_checkBox_stateChanged(int arg1);

    void on_Morfologia_accepted();

    void on_Morfologia_rejected();

private:
    Ui::Morfologia *ui;
    int nfoto;
};

#endif // MORFOLOGIA_H
