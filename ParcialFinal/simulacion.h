#ifndef SIMULACION_H
#define SIMULACION_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QDebug>
#include "bala.h"

namespace Ui {
class simulacion;
}

class simulacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit simulacion(int yo_,int yd_,int xd_,int ao_,int vo_,int tvo_,int caso_,int ad_,int vd_,int tvd_, QWidget *parent = nullptr);
    ~simulacion();

    int caso;

    int yo;
    int xo=0;
    int tvo;
    int yd;
    int xd;
    int ao;
    int vo;

    int ad;
    int vd;
    int tvd;

    float DefinnicionEjeY(float posy_);
    float DefinnicionEjeX(float posx_);

    void simulacion_1();
    void simulacion_2();
    void simulacion_3();

    bala *bo;
    bala *bd;

    QGraphicsScene * scene;
    QTimer *TDealy2s;

public slots:
    void Delay2s();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::simulacion *ui;
};

#endif // SIMULACION_H
