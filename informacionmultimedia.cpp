#include "informacionmultimedia.h"
#include "ui_informacionmultimedia.h"

#include "imagenes.h"

InformacionMultimedia::InformacionMultimedia(int numfoto, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InformacionMultimedia)
{
    ui->setupUi(this);
    nfoto= numfoto;

    mostrarInfo();
}

InformacionMultimedia::~InformacionMultimedia()
{
    delete ui;
}

void InformacionMultimedia::mostrarInfo() {
    ui->treeWidget->clear();

    for (size_t i = 0; i < MAX_VENTANAS; ++i) {
        Mat img = foto[i].img;

        if (img.empty())
            continue;

        // elemento raíz
        QTreeWidgetItem *root = new QTreeWidgetItem(ui->treeWidget);
        QString nombreNodo = QString("%1")
                                 .arg(foto[i].nombre);

        QFont font = root->font(0);
        font.setBold(true);
        root->setFont(0, font);
        root->setText(0, nombreNodo);

         // dimensiones (ancho x alto)
        QString dimensiones = QString("%1 x %2 píxeles")
                                  .arg(img.cols)
                                  .arg(img.rows);
        QTreeWidgetItem *itemDimensiones = new QTreeWidgetItem(root);
        itemDimensiones->setText(0, "Resolución (ancho x alto): " + dimensiones);
        // total de píxeles
        QString totalPixeles = QString("Total de píxeles: %1").arg(img.total());
        QTreeWidgetItem *itemTotal = new QTreeWidgetItem(root);
        itemTotal->setText(0, totalPixeles);
        // relación de aspecto
        int w = img.cols;
        int h = img.rows;
        double ratio = (double) w / h;
        double delta = 0.01;
        QString textoRatio;

        if (abs(ratio - (16.0/9.0)) < delta) {
            textoRatio = "16:9 (Panorámico)";
        } else if (abs(ratio - (4.0/3.0)) < delta) {
            textoRatio = "4:3 (Estándar TV)";
        } else if (abs(ratio - 1.0) < delta) {
            textoRatio = "1:1 (Cuadrado)";
        } else if (abs(ratio - (3.0/2.0)) < delta) {
            textoRatio = "3:2 (Fotografía Clásica/DSLR)";
        } else if (abs(ratio - (21.0/9.0)) < delta) {
            textoRatio = "21:9 (Ultra Panorámico)";
        } else if (abs(ratio - (16.0/10.0)) < delta) {
            textoRatio = "16:10";
        } else {
            textoRatio = QString("%1").arg(ratio, 0, 'f', 2);
        }

        QTreeWidgetItem *itemAspecto = new QTreeWidgetItem(root);
        itemAspecto->setText(0, "Relación de Aspecto: " + textoRatio);

        // tamaño en memoria
        double bytes = (double)img.total() * img.elemSize();
        QString memoria;

        if (bytes >= pow(1024, 2))
            memoria = QString::number(bytes / pow(1024, 2), 'f', 2) + " MB";
        else memoria = QString::number(bytes / 1024.0, 'f', 2) + " KB";

        QTreeWidgetItem *itemMemoria = new QTreeWidgetItem(root);
        itemMemoria->setText(0, "Tamaño (en memoria): " + memoria);

        // canales de color
        QTreeWidgetItem *itemCanales = new QTreeWidgetItem(root);
        itemCanales->setText(0, QString("Canales de color: %1").arg(img.channels()));

        // tipo CV
        QString tipoMatriz = QString::fromStdString(cvTypeToString(img.type()));
        QTreeWidgetItem *itemTipo = new QTreeWidgetItem(root);
        itemTipo->setText(0, "Tipo de matriz (profundidad/canales): " + tipoMatriz);

        // tamaño de elemento
        QTreeWidgetItem *itemElemSize = new QTreeWidgetItem(root);
        itemElemSize->setText(0, QString("Bytes por Píxel: %1").arg(img.elemSize()));
    }

    ui->treeWidget->expandAll();
}

string InformacionMultimedia::cvTypeToString(int type) {
    string r;

    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);

    switch ( depth ) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "UNKNOWN"; break;
    }
    r += "C" + to_string(chans);
    return r;
}
