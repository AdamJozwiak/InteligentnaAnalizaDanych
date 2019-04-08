#include <iostream>
#include "SiecNeuronowa.h"
#include <fstream>
#include "SiecBezBiasu.h"
#include "gnuplot_i.hpp"

#define GNUPLOT_PATH "C:\\gnuplot\\bin"

using namespace std;

int main() {
    srand(time(NULL));
    //ifstream fin;
    //fin.open("C:\\Users\\Michał\\Desktop\\dane.txt");
    Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);
    Gnuplot main_plot;
    main_plot.set_xlabel("Os X");
    main_plot.set_ylabel("Os Y");
    main_plot.set_grid();
    main_plot.set_style("lines");
    main_plot.set_xrange(0, 1);
    main_plot.set_yrange(0, 1);
    main_plot.set_pointsize(1.0);
    vector<double> osX;
    vector<double> osY;

    SiecNeuronowa *siecNeuronowa = new SiecNeuronowa;
    siecNeuronowa->dodajWarstwe(4, 4);
    siecNeuronowa->dodajWarstwe(3, 4);
    siecNeuronowa->dodajWarstwe(4, 3);
    double **zestaw = new double *[4];                 ///{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    for (int i = 0; i < 4; i++) {
        zestaw[i] = new double[4];
        for (int j = 0; j < 4; j++) {
            //fin>>zestaw[i][j];
            if (i == j) zestaw[i][j] = 1;
            else zestaw[i][j] = 0;
            cout << zestaw[i][j] << " ";

        }
        cout << endl;
    }
    //fin.close();

    for (int i = 0; i < 100000; i++) {
        siecNeuronowa->uczSiec(zestaw, zestaw, 4);
        osX.push_back((double) i / 10000);
        osY.push_back(siecNeuronowa->E);
        //cout<<siecNeuronowa.E<<endl;
    }
    main_plot.plot_xy(osX, osY, "Blad");
    getchar();

    for (int i = 0; i < 4; i++) {
        double *wypisz = siecNeuronowa->getY(zestaw[i]);
        for (int k = 0; k < 4; k++) {
            cout << wypisz[k] << " ";
        }
        cout << endl;
    }
    return 0;
}