#ifndef BALA_H
#define BALA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <math.h>

class bala:  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bala(float posx_,float posy_,int radio_,int v_,int ao_);
    float dt=0;
    float posx;
    float posy;
    int radio;
    int v;
    int a;
    int ancho;
    int alto;
    double pi=3.14159265;

    float NuevoEjeX(float x);
    float NuevoEjeY(float y);

    QTimer *TOfensivo;

public slots:
    void DisparoOfensivo();


};

#endif // BALA_H
