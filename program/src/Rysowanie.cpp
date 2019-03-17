#include "Rysowanie.h"
#define GNUPLOT_PATH "C:\\gnuplot\\bin"
#include "gnuplot_i.hpp"
//#define GNUPLOT_PATH "D:\\gnuplocik\\gnuplot\\bin"

float Rysowanie::linia(float x) {
    return 1.5 * x;
}

void Rysowanie::losowaniePunktow(int n) {
    srand(time(NULL));
    trener=new Chodakowska[n];

    for(int i=0; i < n; i++)
    {
        float x = random();
        float y = random();
        bool odp;
        if(y < linia(x))
        {
            odp = 0;
        }
        else odp=1;
        trener[i].setWej(x,y);
        trener[i].setOdp(odp);
    }
}

float Rysowanie::random() {
    return (float) (rand()%10000)/100;
}

void Rysowanie::rysowanie(int n) {
    Gnuplot::set_GNUPlotPath( GNUPLOT_PATH );
    Gnuplot main_plot;
    main_plot.set_xlabel( "Os X" );
    main_plot.set_ylabel( "Os Y" );
    main_plot.set_grid();
    main_plot.set_style( "points" );
    main_plot.set_xrange(0, 1);
    main_plot.set_yrange(0, 1);
    main_plot.set_pointsize(1.0);
    losowaniePunktow(n);

    Perceptron p(3);

    vector<float> osX;
    vector<float> osY;

    for(int i = 0; i<n; i++)
    {
        osX.push_back(trener[i].getWej()[0]);
        osY.push_back(trener[i].getWej()[1]);
    }

    //main_plot.plot_xy(osX, osY, "Tyts");

    /*for(int i = 0; i < licznik; i++)
    {
        bool zgadywanie = p.pozycja(trener[i].getWej());
        if(zgadywanie == true)
        {

        }
    }*/

    vector<float> osX1;
    vector<float> osY1;

    osX1.push_back(0.0);
    osY1.push_back(p.f(0.0));
    osX1.push_back(1.0);
    osY1.push_back(p.f(1.0));

    main_plot.set_style("lines");

    for(int i = 0; i < n; i++)
    {
        //main_plot.plot_xy(osX1,osY1, "Linia");
        //cout<<"Wartosc X1: " << osX1[0] << " i Y1: " << osY1[0] << " ----------> Wartosc X2: " << osX1[1] << " i Y2: " << osY1[1] << endl;
        p.trenuj(trener[i].getWej(), trener[i].getOdp());
        //osY1.clear();
        osY1[0] = p.f(osX1[0]);
        osY1[1] = p.f(osX1[1]);
    }

    cin.get();
}
