#include "bala.h"

bala::bala(float posx_, float posy_,int radio_, int v_,int ao_)
{
    setPixmap(QPixmap(":/recursos/imagenes/bala.png"));
    setScale(0.1);

    posx=posx_;
    posy=posy_;
    v=v_;
    a=ao_;
    radio=radio_;
    ancho=2*radio;
    alto=2*radio;
    setPos(NuevoEjeX(posx),NuevoEjeY(posy));

    TOfensivo=new QTimer();
    connect(TOfensivo,SIGNAL(timeout()),this,SLOT(DisparoOfensivo()));
    //TOfensivo->start(100);

}

float bala::NuevoEjeX(float x)
{
    return 100-10+x;
}

float bala::NuevoEjeY(float y)
{
    return 600-10-y;
}

void bala::DisparoOfensivo()
{
    float vx, vy;
    float x, y;
    float angulo;

    angulo=a*pi/180;
    qDebug() << "velocidad: "<<v<<"angulo: "<<a;
    vx=v*cos(angulo);
    vy=v*sin(angulo);

    x=posx+vx*dt;
    y=posy+vy*dt-0.5*9.8*dt*dt;

    setPos(NuevoEjeX(x),NuevoEjeY(y));
    //setPos(NuevoEjeX(x),y);

    dt+=0.2;

}
