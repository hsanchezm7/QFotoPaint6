#ifndef INFORMACIONMULTIMEDIA_H
#define INFORMACIONMULTIMEDIA_H

#include <QDialog>

using namespace std;

namespace Ui {
class InformacionMultimedia;
}

class InformacionMultimedia : public QDialog
{
    Q_OBJECT

public:
    explicit InformacionMultimedia(int numfoto, QWidget *parent = nullptr);
    ~InformacionMultimedia();

private:
    Ui::InformacionMultimedia *ui;
    int nfoto;

    void mostrarInfo();
    string cvTypeToString(int type);
};


#endif // INFORMACIONMULTIMEDIA_H
