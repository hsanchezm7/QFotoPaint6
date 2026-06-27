#include "perspectiva.h"
#include "ui_perspectiva.h"
#include "imagenes.h"

int npers_orig, npers_dest;
Point2f ppers_orig[4], ppers_dest[4];
int pers_corresp[MAX_VENTANAS];

void pers_callback (int evento, int x, int y, int flags, void *pt)
{
    int num= (long long) pt;
    if (flags == EVENT_FLAG_LBUTTON) {
        int imin= 0;
        int distmin= 500;
        for (int i = 0; i < 4; i++) {
            int distact;
            if (num==0)
                distact= abs(x-ppers_orig[i].x)+
                          abs(y-ppers_orig[i].y);
            else
                distact= abs(x-ppers_dest[i].x)+
                          abs(y-ppers_dest[i].y);
            if (distact < distmin) {
                distmin= distact;
                imin= i;
            }
        }
        if (distmin < 500) {
            if (num==0)
                ppers_orig[imin]= Point2f(x,y);
            else
                ppers_dest[imin]= Point2f(x,y);
            ver_perspectiva(npers_orig, npers_dest, ppers_orig, ppers_dest);
        }
    }
}

Perspectiva::Perspectiva(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Perspectiva)
{
    ui->setupUi(this);
    for (int i= 0, pos= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada) {
            ui->listWidget->addItem(QString::fromStdString(foto[i].nombre));
            ui->listWidget_2->addItem(QString::fromStdString(foto[i].nombre));
            pers_corresp[pos++]= i;
        }
    }
    npers_orig = foto_activa();
    npers_dest = pers_corresp[0];

    // puntos de imagen origen
    int w = foto[npers_orig].img.cols;
    int h = foto[npers_orig].img.rows;

    ppers_orig[0]= Point2f(0,0);
    ppers_orig[1]= Point2f(w,0);
    ppers_orig[2]= Point2f(w,h);
    ppers_orig[3]= Point2f(0,h);

    // puntos de imagen destino
    w = foto[npers_dest].img.cols;
    h = foto[npers_dest].img.rows;

    ppers_dest[0]= Point2f(w*0.4,0);
    ppers_dest[1]= Point2f(w*0.6,0);
    ppers_dest[2]= Point2f(w,h);
    ppers_dest[3]= Point2f(0,h);

    ver_perspectiva(npers_orig, npers_dest, ppers_orig, ppers_dest);
    setMouseCallback("Origen", pers_callback, 0);
    setMouseCallback("Destino", pers_callback, (void*)1);

}

Perspectiva::~Perspectiva()
{
    delete ui;
}

void Perspectiva::on_Perspectiva_accepted()
{
    ver_perspectiva(npers_orig, npers_dest, ppers_orig, ppers_dest, true);
    destroyWindow("Origen");
    destroyWindow("Destino");
    mostrar(npers_dest);
}

void Perspectiva::on_Perspectiva_rejected()
{
    destroyWindow("Origen");
    destroyWindow("Destino");
}

void Perspectiva::on_listWidget_currentRowChanged(int currentRow)
{
    int npers_orig_old = npers_orig;
    npers_orig = pers_corresp[currentRow];

    double px = double(foto[npers_orig].img.cols)/foto[npers_orig_old].img.cols;
    double py = double(foto[npers_orig].img.rows)/foto[npers_orig_old].img.rows;

    for (int i = 0; i<4; i++) {
        ppers_orig[i].x *= px;
        ppers_orig[i].y *= py;
    }

    ver_perspectiva(npers_orig, npers_dest, ppers_orig, ppers_dest);
}

void Perspectiva::on_listWidget_2_currentRowChanged(int currentRow)
{
    int npers_dest_old = npers_dest;
    npers_dest = pers_corresp[currentRow];

    double px = double(foto[npers_dest].img.cols)/foto[npers_dest_old].img.cols;
    double py = double(foto[npers_dest].img.rows)/foto[npers_dest_old].img.rows;

    for (int i = 0; i<4; i++) {
        ppers_dest[i].x *= px;
        ppers_dest[i].y *= py;
    }

    ver_perspectiva(npers_orig, npers_dest, ppers_orig, ppers_dest);
}

