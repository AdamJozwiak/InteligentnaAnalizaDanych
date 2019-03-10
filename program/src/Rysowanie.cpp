#include "Rysowanie.h"
#define GNUPLOT_PATH "C:\\gnuplot\\bin"
#include "gnuplot_i.hpp"

float Rysowanie::linia(float x) {
    return (float) 1.5 * x;
}

void Rysowanie::losowaniePunktow(int n) {
    Chodakowska *trener[n];

    for(int i=0; i < n; i++)
    {
        float x = random();
        float y = random();
        bool odp = 1;
        if(y < linia(x))
        {
            odp = 0;
        }
        trener[i] = new Chodakowska (x, y, odp);
    }
}

float Rysowanie::random() {
    srand(time(NULL)*10);
    return (float) (rand()%100);
}

void Rysowanie::rysowanie(int n) {
    Gnuplot::set_GNUPlotPath( GNUPLOT_PATH );
    Gnuplot main_plot;
    main_plot.set_xlabel( "Os X" );
    main_plot.set_ylabel( "Os Y" );
    main_plot.set_grid();
    main_plot.set_style( "points" );
    main_plot.set_pointsize(10.0);

    Chodakowska *trener[n];
    Perceptron *p;
    int licznik=0;
    vector<float> osX;
    vector<float> osY;

    for(int i=0; i < n; i++)
    {
        float x = random();
        float y = random();
        bool odp = 1;
        if(y < linia(x))
        {
            odp = 0;
        }
        trener[i] = new Chodakowska (x, y, odp);

        osX.push_back(x);
        osY.push_back(y);
    }

    //p->trenuj(trener[licznik]->getWej(), trener[licznik]->getOdp());
    //licznik = (licznik +1) % sizeof(trener);

    main_plot.plot_xy(osX,osY,"Test");
}
