#include "capturadevideo.h"
#include "ui_capturadevideo.h"

CapturaDeVideo::CapturaDeVideo(string nombre, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CapturaDeVideo)
{
    ui->setupUi(this);
    if (cap.open(nombre)) {
        int nframes = cap.get(CAP_PROP_FRAME_COUNT);

        ui->horizontalSlider->setMaximum(nframes-1);
        ui->spinBox->setMaximum(nframes-1);
        ui->horizontalSlider->setTickInterval((nframes-1)/10);

        Mat frame;
        if (cap.read(frame))
            imshow("Frame del vídeo", frame);
    }
}

bool CapturaDeVideo::isOpen() {
    return cap.isOpened();
}

CapturaDeVideo::~CapturaDeVideo()
{
    delete ui;
}

void CapturaDeVideo::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    cap.set(CAP_PROP_POS_FRAMES, value);
    Mat frame;
    if (cap.read(frame))
        imshow("Frame del vídeo", frame);
}


void CapturaDeVideo::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}


void CapturaDeVideo::on_CapturaDeVideo_accepted()
{
    cap.set(CAP_PROP_POS_FRAMES, ui->spinBox->value());
    Mat frame;
    if (cap.read(frame))
        crear_nueva(primera_libre(), frame);

    destroyWindow("Frame del vídeo");
}

void CapturaDeVideo::on_CapturaDeVideo_rejected()
{
    destroyWindow("Frame del vídeo");
}

