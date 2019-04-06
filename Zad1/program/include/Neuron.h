#ifndef ZAD1_NEURON_H
#define ZAD1_NEURON_H

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include "Trener.h"

using namespace std;

class Neuron {
private:
    int lb_wag;
    double stala;
    double *wagi;
    int beta = 1;
    Trener trener;

public:
    Neuron(int lb_wag);

    double random();

    double propagacja(double *wagi);

    double wstecznaPropagacja();

    double aktywacja(double suma);

    double pochodnaAktywacji();

    void trenowanie(double *wej, bool odp);

    double blad();

};

#endif
