#include <iostream>
#include "gnuplot_i.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Perceptron.h"
#include "Rysowanie.h"
//#define GNUPLOT_PATH "C:\\gnuplot\\bin"
//#define GNUPLOT_PATH "D:\\gnuplocik\\gnuplot\\bin"
using namespace std;

double randValue() {
    srand(time(NULL) * 1250);
    return (double)rand() / RAND_MAX * 100;
}

int main() {
    /*Gnuplot::set_GNUPlotPath( GNUPLOT_PATH );
    Gnuplot main_plot;
    main_plot.set_xlabel( "Os X" );
    main_plot.set_ylabel( "Os Y" );
    main_plot.set_grid();

    main_plot.set_style( "points" );
    main_plot.set_pointsize(10.0);

    vector<double> osX;
    vector<double> osY;

    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            osX.push_back(i);
            osY.push_back(randValue());
        }
    }
   // main_plot.plot_xy(osX,osY,"Test");
   Perceptron perceptron(3);
    bool a=0;
    bool b=1;
    int c=a-b;
    cout<<c;
    //cout<<perceptron.random();
    //getchar();*/

    Rysowanie rysunek;
    rysunek.rysowanie(100);
}