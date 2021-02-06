#include "bala.h"
//#include "principal.h"

//extern Principal *InterfazInicial;

bala::bala(float posx_, float posy_,int radio_, int v_,int a_,int tv_)
{
    setPixmap(QPixmap(":/recursos/imagenes/bala.png"));
    setScale(0.1);

    tv=tv_;
    Trastro=tv/10;
    t=Trastro;
    posx=posx_;
    posy=posy_;
    v=v_;
    a=a_;
    radio=radio_;
    ancho=2*radio;
    alto=2*radio;
    setPos(NuevoEjeX(posx),NuevoEjeY(posy));
    //aux=aux_;

    TOfensivo=new QTimer();
    connect(TOfensivo,SIGNAL(timeout()),this,SLOT(DisparoOfensivo()));

    TDefensivo=new QTimer();
    connect(TDefensivo,SIGNAL(timeout()),this,SLOT(DisparoDefensivo()));
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

float bala::NuevoEjeXext(float x, float radio_)
{
    return 100-radio_+x;
}

float bala::NuevoEjeYext(float y, float radio_)
{
    return 600-radio_-y;
}

void bala::DisparoOfensivo()
{
    float vx, vy;
    float x, y;
    float angulo;

    angulo=a*pi/180;
    //qDebug() << "velocidad: "<<v<<"angulo: "<<a;
    vx=v*cos(angulo);
    vy=v*sin(angulo);

    x=posx+vx*dt;
    y=posy+vy*dt-0.5*9.8*dt*dt;

    setPos(NuevoEjeX(x),NuevoEjeY(y));
    //setPos(NuevoEjeX(x),y);
    if(dt>=tv){
        TOfensivo->stop();
    }
    if(dt>=t){
        qDebug() <<"Asies, trastro && t "<<Trastro<<t;
        t+=Trastro;
        scene()->addEllipse(NuevoEjeXext(x,radio),NuevoEjeYext(y,radio),2*radio,2*radio);
    }
    dt+=0.05;

    //qDebug () <<"dt: "<<dt<< "tv: "<<tv;

}

void bala::DisparoDefensivo()
{
    float vx, vy;
    float x, y;
    float angulo;

    angulo=a*pi/180;
    //qDebug() << "velocidad: "<<v<<"angulo: "<<a;
    vx=-v*cos(angulo);
    vy=v*sin(angulo);

    x=posx+vx*dt;
    y=posy+vy*dt-0.5*9.8*dt*dt;

    setPos(NuevoEjeX(x),NuevoEjeY(y));
    //setPos(NuevoEjeX(x),y);
    if(dt>=tv){
        TDefensivo->stop();
    }
    if(dt>=t){
        qDebug() <<"Asies, trastro && t "<<Trastro<<t;
        t+=Trastro;
        scene()->addEllipse(NuevoEjeXext(x,radio),NuevoEjeYext(y,radio),2*radio,2*radio);
    }
    dt+=0.05;
}
