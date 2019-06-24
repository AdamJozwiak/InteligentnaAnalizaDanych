#include <iostream>
#include <ctime>
#include <fstream>
#include "WarstwaRad.h"
#include "WarstwaLin.h"
#include "gnuplot_i.hpp"
#define GNUPLOT_PATH "D:\\gnuplocik\\gnuplot\\bin"

using namespace std;

vector<double> randomC(vector<double> x, int N){
    vector<double> wylosowane;
    int j;
    for(int i=0; i<N; i++){
        j=rand()%x.size();
        wylosowane.push_back(x[j]);
     }
     return wylosowane;

}

int main() {
    srand(time(NULL));
    Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);
    Gnuplot main_plot;
    main_plot.set_xlabel("Iteracje");
    main_plot.set_ylabel("Blad");
    main_plot.set_grid();
    main_plot.set_style("points");
    main_plot.set_xrange(-100, 100);
    main_plot.set_yrange(-100, 100);
    main_plot.set_pointsize(1.0);

    vector<double> osX, bladX;
    vector<double> osY, bladY;

    double x,y;
    ifstream plik;
    plik.open("D:\\Studia\\InteligentnaAnalizaDanych\\Zad3\\src\\dane.txt");
    while(!plik.eof()){

        plik>>x;
        plik>>y;
        osX.push_back(x);
        osY.push_back(y);
    }
    /*main_plot.plot_xy(osX, osY);
    osX.clear();
    osY.clear();
    getchar();*/

    WarstwaRad warstwaRad(30,randomC(osX,30));
    WarstwaLin warstwaLin(30);

    for(int i=0; i<100; i++){
       // cout<<warstwaRad.getY(osX[1])[1]<<endl;
        warstwaRad.uczNeurony(osX);

    }


    vector<double> wyjsciaRad;
    for(int i=0; i<10000; i++){
        //cout<<i<<endl;
        warstwaLin.zeruj();

        for(int j=0; j<osY.size(); j++) {
            wyjsciaRad = warstwaRad.getY(osX[j]);

            //cout<<"wielkosc wyjsciaRad: "<<wyjsciaRad.size()<<endl;
            warstwaLin.uczNeuron(wyjsciaRad,osY[j]);
            //cout<<"p2"<<endl;
        }
        //cout<<"p"<<endl;
        warstwaLin.zmienWagi(osX.size());
        //cout<<"blad: "<<warstwaLin.getE()<<endl;
        //bladX.push_back((double) i/1000);
        //bladY.push_back(warstwaLin.getE());
    }
    cout<<"koniec nauki";
    //main_plot.plot_xy(bladX, bladY);
    //getchar();

    plik.close();
    osX.clear();
    osY.clear();
    plik.open("D:\\Studia\\InteligentnaAnalizaDanych\\Zad3\\src\\dane2.txt");
    while(!plik.eof()){

        plik>>x;
        plik>>y;
        osX.push_back(x);
        osY.push_back(y);
    }
    main_plot.plot_xy(osX, osY);
    osY.clear();

    for(int i=0; i<osX.size(); i++){
        warstwaLin.obliczY(warstwaRad.getY(osX[i]));
        //cout<<"Y: "<<warstwaLin.getY()<<endl;
        osY.push_back(warstwaLin.getY());
    }


    main_plot.plot_xy(osX, osY);
    osX.clear();
    osY.clear();
    getchar();
    plik.close();

    return 0;
}