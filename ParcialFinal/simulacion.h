#ifndef SIMULACION_H
#define SIMULACION_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QDebug>
#include <QBrush>
#include "bala.h"

namespace Ui {
class simulacion;
}

class simulacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit simulacion(int yo_,int yd_,int xd_,int ao_,int vo_,int tvo_,int caso_,int ad_,int vd_,int tvd_,int ac_,int vc_,int tvc_, QWidget *parent = nullptr);
    ~simulacion();

    int caso;

    int yo;
    int xo=0;
    int yd;
    int xd;

    int ao;
    int vo;
    int tvo;

    int ad;
    int vd;
    int tvd;

    int ac;
    int vc;
    int tvc;

    float DefinnicionEjeY(float posy_);
    float DefinnicionEjeX(float posx_);

    void simulacion_1();
    void simulacion_2();
    void simulacion_3();
    void simulacion_4();

    bala *bo;
    bala *bd;
    bala *bc;

    QGraphicsScene * scene;
    QTimer *TDealy2s;
    QTimer *TDealy1s;

public slots:
    void Delay2s();
    void Delay1s();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::simulacion *ui;
};

#endif // SIMULACION_H
