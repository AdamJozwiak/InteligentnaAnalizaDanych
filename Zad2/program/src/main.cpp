#include <iostream>
#include <ctime>
#include "NieWiem.h"
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




    NieWiem nieWiem(10);
    Punkt punkt1(3.0,4.0), punkt2(30.0,40.0);

    vector<Punkt> wektor;
    wektor.push_back(punkt1);
    wektor.push_back(punkt2);
    nieWiem.prostokat(wektor,200);
    for(int i=0;i<50;i++){
        nieWiem.algKohonen();
        nieWiem.lotto();
    }
    vector<double> osX;
    vector<double> osY;
    for(int i=0; i<nieWiem.getPunkty().size(); i++)
    {
        osX.push_back(nieWiem.getPunkty()[i].getX());
        osY.push_back(nieWiem.getPunkty()[i].getY());
    }

    main_plot.plot_xy(osX, osY);
    getchar();
    //nieWiem.rysuj();

    return 0;
}