/*El programa recibe como parametros de entrada las alturas a las que se encuentran los caniones y la
 * distancia que los separa, a partir de esta informacion se calculan los datos necesarios en cada punto y
 * posteriormente se efectua la simulacion correspondiente

 * En la clase "principal" se efectuan todos los calculos matematicos necesarios para obtener los angulos,
 * velocidades y tiempos de vuelo de los diferentes disparos, eventualmente en la clase simulacion se crean
 * los objetos de la clase bala correspondientes a cada caso y el movimiento de las balas en la escena se realiza
 * desde dicha clase

 * En este caso al momento de simular le otorgue el valor de 1 metro a cada pixel con el objetivo de facilicitar
 * los procedimientos matematicos, la entrada de datos esta restringida por tanto al tamaño de la escena (1350x700)
 * por ello la entrada de datos esta limitada para las alturas en 500(metros) y separacion 1150(metros)*/

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


//En el primer caso solo se calcula un disparo ofensivo certero
void Principal::on_pushButton_clicked()
{
    yo = ui->yo1->value();
    xo=0;
    yd = ui->yd1->value();
    xd = ui->dist1->value();

    int dat=Disparo_Ofensivo(yo,yd,xo,xd);

    tvo=dat%1000;
    dat/=1000;
    angulo1=dat%1000;
    vo=dat/1000;

    if(dat!=0){
        this->hide();
        simulation =new simulacion(yo,yd,xd,angulo1,vo,tvo,1,0,0,0,0,0,0);
        simulation->show();
    }
}

//En el segundo caso solo se calcula un disparo "defensivo" que dañe al enemigo luego de que este dispare
//El disparo ofensivo previamente se calcula de manera aleatoria
void Principal::on_pushButton_2_clicked()
{
    yo = ui->yo1->value();
    xo = 0;
    yd = ui->yd1->value();
    xd = ui->dist1->value();
    tvo=1;

    int dat = Disparo_Ofensivo(yo,yd,xo,xd);

    tvo=dat%1000;    //se "descomprime" la informacion retornada por la funcion
    dat/=1000;
    angulo1=dat%1000;
    vo=dat/1000;

    int dat2 = Disparo_DfensivoAtt(yo,yd,xo,xd);
    tvd=dat2%1000;
    dat2/=1000;
    angulo2=dat2%1000;
    vd=dat2/1000;

    if(dat!=0){
        this->hide();
        simulation =new simulacion(yo,yd,xd,angulo1,vo,tvo,2,angulo2,vd,tvd,0,0,0); //se realiza la simulacion
        simulation->show();
    }

}

void Principal::on_pushButton_3_clicked()
{
    yo = ui->yo1->value();
    xo = 0;
    yd = ui->yd1->value();
    xd = ui->dist1->value();
    tvo=1;

    int dat = Disparo_Ofensivo(yo,yd,xo,xd);

    tvo=dat%1000;
    dat/=1000;
    angulo1=dat%1000;
    vo=dat/1000;

    int dat2 = Disparo_Defensivo(yo,yd,xo,xd,1);
    tvd=dat2%1000;
    dat2/=1000;
    angulo2=dat2%1000;
    vd=dat2/1000;

    if(dat!=0){
        this->hide();
        simulation =new simulacion(yo,yd,xd,angulo1,vo,tvo,3,angulo2,vd,tvd,0,0,0);
        simulation->show();
    }
}

void Principal::on_pushButton_4_clicked()
{
    yo = ui->yo1->value();
    xo = 0;
    yd = ui->yd1->value();
    xd = ui->dist1->value();
    tvo=1;

    int dat = Disparo_Ofensivo(yo,yd,xo,xd);

    tvo=dat%1000;
    dat/=1000;
    angulo1=dat%1000;
    vo=dat/1000;

    int dat2 = Disparo_Defensivo(yo,yd,xo,xd,2);
    tvd=dat2%1000;
    dat2/=1000;
    angulo2=dat2%1000;
    vd=dat2/1000;

    if(dat!=0){
        this->hide();
        simulation =new simulacion(yo,yd,xd,angulo1,vo,tvo,3,angulo2,vd,tvd,0,0,0);
        simulation->show();
    }
}

void Principal::on_pushButton_5_clicked()
{
    yo = ui->yo1->value();
    xo = 0;
    yd = ui->yd1->value();
    xd = ui->dist1->value();
    tvo=1;

    int dat = Disparo_Ofensivo(yo,yd,xo,xd);

    tvo=dat%1000;
    dat/=1000;
    angulo1=dat%1000;
    vo=dat/1000;

    int dat2 = Disparo_Defensivo(yo,yd,xo,xd,1);
    tvd=dat2%1000;
    dat2/=1000;
    angulo2=dat2%1000;
    vd=dat2/1000;

    int dat3 = Disparo_ContraAtaque(yo,yd,xo,xd);
    tvc=dat3%1000;
    dat3/=1000;
    angulo3=dat3%1000;
    vc=dat3/1000;
    if(dat!=0){
        this->hide();
        simulation =new simulacion(yo,yd,xd,angulo1,vo,tvo,4,angulo2,vd,tvd,angulo3,vc,tvc);
        simulation->show();
    }
}
/*funcion en la que se calcula un disparo ofensivo aleatorio certero*/
int Principal::Disparo_Ofensivo(int yo_,int yd_,int xo_,int xd_)
{

    //coordenadas iniciales(posicion de los caniones)
    int Yo=yo_;
    int Xo=xo_;
    int Yd=yd_;
    int Xd=xd_;
    double ao;

    float vox,voy;
    float x, y;

    //ciclo para generar disparo ofencivo aleatorio

    bool resp=false;
    srand(time(NULL));
    for (int j=0;j<90;j++){
        int i = rand () % (90-0+1) + 0;
        ao=i*pi/180;
        for(int v = 0;v < 150; v+=2){
            vox=v*cos(ao);
            voy=v*sin(ao);
            for(int t=12;t<50;t++){
                x=Xo+vox*t;
                y=Yo+voy*t-0.5*9.8*t*t;
                if(y<0) break;
                if(sqrt(pow((x-Xd),2)+pow((y-Yd),2))<=(0.05*Xd)+25){
                    QMessageBox::information(this,"Datos del disparo","Angulo: "+QString::number(i)+" Velocidad inicial: "+QString::number(v)+" Tiempo de vuelo: "+QString::number(t));

                    resp=true;
                    return (((v*1000)+i)*1000)+t;  //se retornan la velocidad inicial, angulo y tiempo de vuelo de manera "comprimida"(se hace lo mismo en las otras funciones)
                }
            }
        }
    }
    if(resp==false){
        QMessageBox::information(this,"Datos del disparo","No se encontró un disparo certero");
    }
    return 0;
}

//Se calcula un disparo defensivo que dañe al canion ofensivo luego de que este ataque
int Principal::Disparo_DfensivoAtt(int yo_, int yd_, int xo_, int xd_)
{
    //coordenadas iniciales(posicion de los caniones)
    int Yo=yo_;
    int Xo=xo_;
    int Yd=yd_;
    int Xd=xd_;
    double ad;

    float vdx,vdy;
    float x, y;

    //ciclo para generar disparo ofencivo aleatorio

    bool resp=false;
    srand(time(NULL));
    for (int j=0;j<90;j++){
        int i = rand () % (90-0+1) + 0;
        ad=i*pi/180;
        for(int v = 0;v < 150; v+=2){
            vdx=-v*cos(ad);
            vdy=v*sin(ad);
            for(int t=0;t<50;t++){
                x=Xd+vdx*t;
                y=Yd+vdy*t-0.5*9.8*t*t;
                if(y<0) break;
                if(sqrt(pow((x-Xo),2)+pow((y-Yo),2))<=(0.025*Xd)+25){
                    QMessageBox::information(this,"Datos del disparo","Angulo: "+QString::number(i)+" Velocidad inicial: "+QString::number(v)+" Tiempo de vuelo: "+QString::number(t));
                    resp=true;
                    return (((v*1000)+i)*1000)+t;
                }
            }
        }
    }
    if(resp==false){
        QMessageBox::information(this,"Datos del disparo","No se encontró un disparo certero");
    }
    return 0;
}

//Debido a que el punto 3 y 4 son relativamente similares se usa la misma funcion para hallar los datos de ambos
//Se calcula un disparo defensivo sertero a partir de uno ofensivo genterado con anterioridad
int Principal::Disparo_Defensivo(int yo_, int yd_, int xo_, int xd_, int caso_)
{
    //coordenadas iniciales(posicion de los caniones)
    int Yo=yo_;
    int Xo=xo_;
    int Yd=yd_;
    int Xd=xd_;
    int caso=caso_;
    double ad;

    //datos del disparo ofensivo
    double ao = angulo1*pi/180;
    float vox=vo*cos(ao);
    float voy=vo*sin(ao);

    float vdx,vdy;
    float _xd=Xd,_yd=Yd,_xo,_yo;

    bool resp=false;
    srand(time(NULL));

    for (int j=0;j<90;j++){
        int i = rand () % (90-0+1) + 0;
        ad=i*pi/180;
        for(int v = 0;v < 150; v+=2){
            vdx=v*cos(ad);
            vdy=v*sin(ad);
            for(int t=8;t<tvo;t++){
                _xo=Xo+vox*t;
                _yo=Yo+voy*t-0.5*9.8*t*t;
                _xd=Xd-vdx*(t-2);                       //t-2 para tener en cuenta el retraso
                _yd=Yd+vdy*(t-2)-0.5*9.8*(t-2)*(t-2);

                if(_yd<0) break;
                //no se verifica si el canion ofensivo se pueda daniar
                if (caso==1){
                    if(sqrt(pow((_xo-_xd),2)+pow((_yo-_yd),2))<=0.025*Xd && sqrt(pow((xo_-Xd),2)+pow((yo_-Yd),2))>=(0.05*Xd)+25){
                        QMessageBox::information(this,"Datos del disparo","angulo efectivo: "+QString::number(i)+" Velocidad inicial: "+QString::number(v)+" Tiempo de vuelo: "+QString::number(t));
                        resp=true;
                        return (((v*1000)+i)*1000)+t;
                    }
                }
                //Se verifica que ambos caniiones salgan intactos
                else if(caso==2){
                    if(sqrt(pow((_xo-_xd),2)+pow((_yo-_yd),2))<=0.025*Xd && sqrt(pow((xo_-Xd),2)+pow((yo_-Yd),2))>=(0.05*Xd)+25 && sqrt(pow((xd_-Xo),2)+pow((yd_-Yo),2))>=(0.025*Xd)+25){
                        QMessageBox::information(this,"Datos del disparo","angulo efectivo: "+QString::number(i)+" Velocidad inicial: "+QString::number(v)+" Tiempo de vuelo: "+QString::number(t));
                        resp=true;
                        return (((v*1000)+i)*1000)+t;
                    }
                }
            }

        }
    }
    if(resp==false){
        QMessageBox::information(this,"Datos del disparo","No se encontró un disparo certero"); //en el caso en que no se halle un disparo certero se hara saber al usuario
    }
    return 0;
}
//Se calcula un disparo de contraataque sertero a partir de uno defensivo genterado con anterioridad
int Principal::Disparo_ContraAtaque(int yo_, int yd_, int xo_, int xd_)
{
    //coordenadas iniciales(posicion de los caniones)
    int Yo=yo_;
    int Xo=xo_;
    int Yd=yd_;
    int Xd=xd_;
    double ac;

    //datos del disparo ofensivo
    double ad = angulo2*pi/180;
    float vdx=vd*cos(ad);
    float vdy=vd*sin(ad);

    float vcx,vcy;
    float _xc=Xo,_yc=Yo,_xd,_yd;

    bool resp=false;
    //srand(time(NULL));

    for (int j=0;j<90;j++){
        ac=j*pi/180;
        for(int v = 100;v < 300; v+=2){
            vcx=v*cos(ac);
            vcy=v*sin(ac);
            for(int t=2;t<(tvd-2);t++){
                _xd=Xd-vdx*t;
                _yd=Yd+vdy*t-0.5*9.8*t*t;
                _xc=Xo+vcx*(t-1);                       //t-1 para considerar el retraso de 1 segundo con respecto a la bala defensiva
                _yc=Yo+vcy*(t-1)-0.5*9.8*(t-1)*(t-1);
                if(_yc<0) break;
                if(sqrt(pow((_xc-_xd),2)+pow((_yc-_yd),2))<=0.005*Xd){
                    QMessageBox::information(this,"Datos del disparo","angulo efectivo: "+QString::number(j)+" Velocidad inicial: "+QString::number(v)+" Tiempo de vuelo: "+QString::number(t));
                    resp=true;
                    return (((v*1000)+j)*1000)+t;

                }
            }

        }
    }
    if(resp==false){
        QMessageBox::information(this,"Datos del disparo","No se encontró un disparo certero");
    }
    return 0;
}
