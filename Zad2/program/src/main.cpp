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
        osX.push_back(x);
        osY.push_back(y);
        punkty.push_back(punkt);

    }


    //DODANIE PUNKTOW I NEURONOW W POCZATKOWYM POLOZENIU

    Plaszczyzna plaszczyzna(150,punkty);
    //cout<<plaszczyzna.alpha;
    main_plot.plot_xy(osX, osY);
    osX.clear();
    osY.clear();

    for(int i=0; i<plaszczyzna.getNeurony().size(); i++)
    {
        osX.push_back(plaszczyzna.getNeurony()[i].getX());
        osY.push_back(plaszczyzna.getNeurony()[i].getY());
    }

    main_plot.plot_xy(osX, osY);
    osX.clear();
    osY.clear();
    getchar();


    //NAUCZANIE NEURONOW WYBRANYM ALGORYTMEM

    for(int i=0;i<20;i++){
        plaszczyzna.algSrednich();
        plaszczyzna.lotto();
    }


    //RYSOWANIE NEURONOW W KONCOWYM POLOZENIU
    for(int i=0; i<plaszczyzna.getNeurony().size(); i++)
    {
        //cout<<plaszczyzna.getNeurony()[i].getX()<<endl;
        osX.push_back(plaszczyzna.getNeurony()[i].getX());
        osY.push_back(plaszczyzna.getNeurony()[i].getY());
    }

    plik.close();

    main_plot.plot_xy(osX, osY);
    getchar();


    return 0;
}