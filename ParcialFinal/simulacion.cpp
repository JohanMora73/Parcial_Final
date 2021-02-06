#include "simulacion.h"
#include "ui_simulacion.h"
#include "principal.h"

simulacion::simulacion(int yo_,int yd_,int xd_,int ao_,int vo_,int tvo_,int caso_,int ad_,int vd_,int tvd_,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::simulacion)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1350,690);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    caso=caso_;

    yo=yo_;
    yd=yd_;
    xd=xd_;
    ao=ao_;
    vo=vo_;
    tvo=tvo_;

    ad=ad_;
    vd=vd_;
    tvd=tvd_;

    //Ejes cartesianos y soportes
    scene->addLine(100,600,1350,600);
    scene->addLine(100,600,100,0);
    scene->addRect(50,625-yo,100,yo-25)->setBrush(Qt::green);
    scene->addRect(xd+50,625-yd,100,yd-25)->setBrush(Qt::green);
    //punto de referencia del canion defensivo y ofensivo
    scene->addEllipse(xd+75,575-yd,50,50)->setBrush(Qt::gray);
    scene->addEllipse(75,575-yo,50,50)->setBrush(Qt::gray);

    if (caso ==1) simulacion_1();
    if(caso==2){
        simulacion_2();
        TDealy2s = new QTimer();
        QObject::connect(TDealy2s,SIGNAL(timeout()),this,SLOT(Delay2s()));
        TDealy2s->start(20);
    }
    if(caso==3){
        simulacion_3();
        TDealy2s = new QTimer();
        QObject::connect(TDealy2s,SIGNAL(timeout()),this,SLOT(Delay2s()));
        TDealy2s->start(20);
    }
}

simulacion::~simulacion()
{
    delete ui;
}

void simulacion::simulacion_1()
{
    qDebug() <<"si";
    bo = new bala(xo,yo,0.05*xd,vo,ao,tvo);
    scene->addItem(bo);
}

void simulacion::simulacion_2()
{
    bo = new bala(xo,yo,0.05*xd,vo,ao,tvo);
    scene->addItem(bo);

    bd = new bala(xd,yd,0.025*xd,vd,ad,tvd);
    scene->addItem(bd);
}

void simulacion::simulacion_3()
{
    bo = new bala(xo,yo,0.05*xd,vo,ao,tvd);
    scene->addItem(bo);

    bd = new bala(xd,yd,0.025*xd,vd,ad,tvd-2);
    scene->addItem(bd);
}

void simulacion::Delay2s()
{
    if(bo->dt>=2){
        bd->TDefensivo->start(20);
        TDealy2s->stop();
    }
}

void simulacion::on_pushButton_clicked()
{
    this->hide();
    Principal *InterfazInicial= new Principal ();
    InterfazInicial->show();
    this->close();
}

void simulacion::on_pushButton_2_clicked()
{
    bo->TOfensivo->start(20);
}
