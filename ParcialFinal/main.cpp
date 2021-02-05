#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    /*Para la simulacion se tomara cada pixel de la pantalla como 1 metro, por tannto la separacion maxima será 1km
    y la altura maxima para los caniones será 600m*/
    QApplication a(argc, argv);
    MainWindow w;
    return a.exec();
}
