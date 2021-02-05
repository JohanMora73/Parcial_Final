#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    //srand(time(NULL));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_pushButton_clicked()
{
    yo = ui->yo1->value();
    xo=0;
    yd = ui->yd1->value();
    xd = ui->dist1->value();
    int dat=Disparo_Ofensivo(yo,yd,xo,xd);
    angulo1=dat%1000;
    vo=dat/1000;
    qDebug() <<"Retorno: "<<dat<<" angulo: "<<angulo1<<" velocidad: "<<vo;
    if(dat!=0){
        this->hide();
        simulation =new simulacion(yo,yd,xd,angulo1,vo);
        simulation->show();
    }
}

int Principal::Disparo_Ofensivo(int yo_,int yd_,int xo_,int xd_)
{

    //coordenadas iniciales(posicion de los caniones)
    int Yo=yo_;
    int Xo=xo_;
    int Yd=yd_;
    int Xd=xd_;
    double ao;

    qDebug() << " "<<yo<< " "<<xo<< " "<<yd<< " "<<xd;
    float vox,voy;
    float x, y;

    //ciclo para generar disparo ofencivo aleatorio

    bool resp=false;
    srand(time(NULL));
    for (int j=0;j<90;j++){
        int i = rand () % (90-0+1) + 0;
        ao=i*pi/180;
        //if(resp==true) break;
        for(int v = 0;v < 150; v+=2){
            vox=v*cos(ao);
            voy=v*sin(ao);
            //if(resp==true) break;
            for(int t=0;t<50;t++){
                x=Xo+vox*t;
                y=Yo+voy*t-0.5*9.8*t*t;
                if(y<0) break;
                //if(resp==true) break;
                if(sqrt(pow((x-Xd),2)+pow((y-Yd),2))<=0.05*Xd){
                    qDebug()<<"angulo de riezgo "<<i<<" y velocidad: "<<v<<"Tiempo de vuelo: "<<t;
                    QMessageBox::information(this,"Datos del disparo","Angulo: "+QString::number(i)+" Velocidad inicial: "+QString::number(v)+" Tiempo de vuelo: "+QString::number(t));
                    //return ;
                    resp=true;
                    return (v*1000)+i;
                }
            }
        }
        //qDebug () <<angulo1;

    }
    if(resp==false){
        QMessageBox::information(this,"Datos del disparo","No se encontró un disparo certero");
    }
    return 0;
}
