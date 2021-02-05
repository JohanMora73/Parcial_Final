#include "simulacion.h"
#include "ui_simulacion.h"
#include "principal.h"

simulacion::simulacion(int yo_,int yd_,int xd_,int ao_,int vo_,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::simulacion)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1350,690);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    yo=yo_;
    yd=yd_;
    xd=xd_;
    ao=ao_;
    vo=vo_;
    simulacion_1();
    //QLine *line = new QLine();
    //scene->addItem(line);
    //(x1,y1,x2,y2);
    scene->addLine(100,600,1350,600);
    scene->addLine(100,600,100,0);
    scene->addRect(50,610-yo,100,yo-10)->setBrush(Qt::gray);
    scene->addRect(xd-50,610-yd,100,yd-10)->setBrush(Qt::gray);

}

simulacion::~simulacion()
{
    delete ui;
}

float simulacion::DefinnicionEjeY(float posy_)
{
    return 600+10-posy_;
}

float simulacion::DefinnicionEjeX(float posx_)
{
    return 100-10+posx_;
}

void simulacion::simulacion_1()
{
    qDebug() <<"si";
    bo = new bala(xo,yo,10,vo,ao);
    scene->addItem(bo);

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
    bo->TOfensivo->start(100);
}
