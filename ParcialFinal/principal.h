#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QDebug>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <math.h>
#include "simulacion.h"

using namespace std;

namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = nullptr);
    ~Principal();
    simulacion * simulation;

    /*variables implementadas para la verificacion*/
    double pi=3.14159265;

    //posiciones iniciales
    int xo;
    int yo;
    int xd;
    int yd;

    //datos del diaparo ofensivo
    double angulo1;
    int vo;
    int tvo;

    //datos del diaparo defensivo
    double angulo2;
    int vd;
    int tvd;

    //datos del diaparo de contraataque
    double angulo3;
    int vc;
    int tvc;

    int Disparo_Ofensivo(int yo_,int yd_,int xo_,int xd_);
    int Disparo_DfensivoAtt(int yo_,int yd_,int xo_,int xd_);
    int Disparo_Defensivo(int yo_,int yd_,int xo_,int xd_, int caso);
    int Disparo_ContraAtaque(int yo_,int yd_,int xo_,int xd_);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Principal *ui;
};

#endif // PRINCIPAL_H
