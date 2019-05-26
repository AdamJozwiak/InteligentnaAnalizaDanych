#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "Plaszczyzna.h"
#include "gnuplot_i.hpp"
#define GNUPLOT_PATH "D:\\gnuplocik\\gnuplot\\bin"


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


    //WCZYTYWANIE Z PLIKU
    vector<Punkt> punkty;
    vector<double> osX;
    vector<double> osY;
    double x=0,y=0;
    ifstream plik;
    plik.open("D:\\Studia\\InteligentnaAnalizaDanych\\Zad2\\program\\src\\dane.txt");
    while(!plik.eof()){

        plik>>x;
        plik>>y;
        Punkt punkt(x,y);
        punkty.push_back(punkt);
        //osX.push_back(x);

        //osY.push_back(y);
    }
///////////////////////////////////////////////


    Plaszczyzna plaszczyzna(10,punkty);
    //Punkt punkt1(3.0,4.0), punkt2(30.0,40.0);

    vector<Punkt> wektor;

    /*wektor.push_back(punkt1);
    wektor.push_back(punkt2);
    plaszczyzna.prostokat(wektor,200);*/
    for(int i=0;i<20;i++){
        plaszczyzna.algSrednich();
        plaszczyzna.lotto();
    }

    /*for(int i=0; i<plaszczyzna.getPunkty().size(); i++)
    {
        osX.push_back(plaszczyzna.getPunkty()[i].getX());
        osY.push_back(plaszczyzna.getPunkty()[i].getY());
    }*/

    for(int i=0; i<plaszczyzna.getNeurony().size(); i++){
        for(int j=0; j<plaszczyzna.getNeurony()[i].getPkt().size(); j++){
            osX.push_back(plaszczyzna.getNeurony()[i].getPkt()[j].getX());
            osY.push_back(plaszczyzna.getNeurony()[i].getPkt()[j].getY());
        }
        if(plaszczyzna.getNeurony()[i].getPkt().size()!=0) {
            main_plot.plot_xy(osX, osY);
            osX.clear();
            osY.clear();
        }
    }


    for(int i=0; i<plaszczyzna.getNeurony().size(); i++)
    {
        osX.push_back(plaszczyzna.getNeurony()[i].getX());
        osY.push_back(plaszczyzna.getNeurony()[i].getY());
    }
    //plik.close();

    main_plot.plot_xy(osX, osY);
    getchar();
    //plaszczyzna.rysuj();


    return 0;
}