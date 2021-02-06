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
    bala(float posx_,float posy_,int radio_,int v_,int ao_,int tvo);
    float dt=0;
    float posx;
    float posy;
    float Trastro,t;
    int radio;
    float tv;
    int v;
    int a;
    int ancho;
    int alto;
    double pi=3.14159265;
    //int aux;

    float NuevoEjeX(float x);
    float NuevoEjeY(float y);
    float NuevoEjeXext(float x, float radio_);
    float NuevoEjeYext(float y, float radio_);

    QTimer *TOfensivo;
    QTimer *TDefensivo;

public slots:
    void DisparoOfensivo();
    void DisparoDefensivo();


};

#endif // BALA_H
