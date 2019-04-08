#include <iostream>
#include "SiecNeuronowa.h"
#include <fstream>
#include "gnuplot_i.hpp"

//#define GNUPLOT_PATH "C:\\gnuplot\\bin"
#define GNUPLOT_PATH "D:\\gnuplocik\\gnuplot\\bin"


using namespace std;

int main() {
    srand(time(NULL));
    ifstream fin;
    fin.open("D:\\Studia\\InteligentnaAnalizaDanych\\train1.txt");
    Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);
    Gnuplot main_plot;
    main_plot.set_xlabel("Os X");
    main_plot.set_ylabel("Os Y");
    main_plot.set_grid();
    main_plot.set_style("points");
    main_plot.set_xrange(0, 1);
    main_plot.set_yrange(0, 1);
    main_plot.set_pointsize(1.0);
    vector<double> osX;
    vector<double> osY;

    SiecNeuronowa *siecNeuronowa = new SiecNeuronowa;
    siecNeuronowa->dodajWarstwe(1, 1, true);
    siecNeuronowa->dodajWarstwe(15, 1, true);
    siecNeuronowa->dodajWarstwe(1, 15, false);
    vector<double> x;
    vector<double> y;
    if (fin.good()) {

        while(!fin.eof()) {
            double x2;

            fin >> x2;
            x.push_back(x2);
            fin >> x2;
            y.push_back(x2);
            //if (i == j) zestaw[i][j] = 1;
            //else zestaw[i][j] = 0;
            //cout << zestaw[i][j] << " ";

        }
    }
    else cout<<"zle xd";

    double** zestaw = new double *[x.size()];
    double** odp = new double *[y.size()];
    for(int i=0; i<x.size(); i++)
    {
        zestaw[i]=new double [1];
        odp[i]=new double [1];

        zestaw[i][0]=x[i];
        odp[i][0]=y[i];

    }

    fin.close();

    main_plot.plot_xy(x, y, "Prawdziwa");

    for (int i = 0; i < 100000; i++) {
        siecNeuronowa->uczSiec(zestaw, odp, x.size());
        //osX.push_back((double) i / 10000);
        //osY.push_back(siecNeuronowa->E);
        //cout<<siecNeuronowa.E<<endl;
    }

    y.clear();

    for (int i = 0; i < x.size(); i++) {
        y.push_back(siecNeuronowa->getY(zestaw[i])[0]);
    }

    main_plot.plot_xy(x, y, "Nauczona");
    getchar();

    /*for (int i = 0; i < 4; i++) {
        double *wypisz = siecNeuronowa->getY(zestaw[i]);
        for (int k = 0; k < 4; k++) {
            cout << wypisz[k] << " ";
        }
        cout << endl;
    }*/
    return 0;
}