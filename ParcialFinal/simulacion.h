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
    explicit simulacion(int yo_,int yd_,int xd_,int ao_,int vo_,QWidget *parent = nullptr);
    ~simulacion();

    int yo;
    int xo=0;
    int yd;
    int xd;
    int ao;
    int vo;

    float DefinnicionEjeY(float posy_);
    float DefinnicionEjeX(float posx_);
    void simulacion_1();

    bala *bo;

    QGraphicsScene * scene;

public slots:
    //void simulacion_1();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::simulacion *ui;
};

#endif // SIMULACION_H
