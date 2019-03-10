#include "Rysowanie.h"
//#define GNUPLOT_PATH "C:\\gnuplot\\bin"
#include "gnuplot_i.hpp"
#define GNUPLOT_PATH "D:\\gnuplocik\\gnuplot\\bin"

float Rysowanie::linia(float x) {
    return 1.5 * x;
}

void Rysowanie::losowaniePunktow(int n) {
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
    srand(time(NULL)*10);
    return (float) (rand()%10000)/100;
}

void Rysowanie::rysowanie(int n) {
    Gnuplot::set_GNUPlotPath( GNUPLOT_PATH );
    Gnuplot main_plot;
    main_plot.set_xlabel( "Os X" );
    main_plot.set_ylabel( "Os Y" );
    main_plot.set_grid();
    main_plot.set_style( "points" );
    main_plot.set_pointsize(10.0);


    //p->trenuj(trener[licznik]->getWej(), trener[licznik]->getOdp());
    //licznik = (licznik +1) % sizeof(trener);

    main_plot.plot_xy(osX,osY,"Test");
}
