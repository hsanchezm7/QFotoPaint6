#ifndef COLORFALSO_H
#define COLORFALSO_H

#include <QDialog>

namespace Ui {
class ColorFalso;
}

class ColorFalso : public QDialog
{
    Q_OBJECT

public:
    explicit ColorFalso(int numfoto, QWidget *parent = nullptr);
    ~ColorFalso();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_ColorFalso_accepted();

    void on_ColorFalso_rejected();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::ColorFalso *ui;
    int nfoto;
};

#endif // COLORFALSO_H
