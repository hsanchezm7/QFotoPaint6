#ifndef CAPTURADEVIDEO_H
#define CAPTURADEVIDEO_H

#include <QDialog>
#include "imagenes.h"

using namespace std;

namespace Ui {
class CapturaDeVideo;
}

class CapturaDeVideo : public QDialog
{
    Q_OBJECT

public:
    explicit CapturaDeVideo(string nombre, QWidget *parent = nullptr);
    ~CapturaDeVideo();
    bool isOpen();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_CapturaDeVideo_accepted();

    void on_CapturaDeVideo_rejected();

private:
    Ui::CapturaDeVideo *ui;
    VideoCapture cap;
};

#endif // CAPTURADEVIDEO_H
