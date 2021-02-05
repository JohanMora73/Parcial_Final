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
    double angulo1;
    double angulo2;
    double angulo3;
    int xo;
    int yo;
    int vo;
    int xd;
    int yd;


    int Disparo_Ofensivo(int yo_,int yd_,int xo_,int xd_);


private slots:
    void on_pushButton_clicked();

private:
    Ui::Principal *ui;
};

#endif // PRINCIPAL_H
