#ifndef ZAD1_NEURON_H
#define ZAD1_NEURON_H

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include "Trener.h"
#include <iostream>

using namespace std;

class Neuron {
private:
    int lb_wag;
    double alfa;
    double *wagi;

    double beta;



    //Trener trener;

public:
    double *deltaW;
    double b;
    double* pochodna;
    Neuron(int lb_wag);

    double random();

    double propagacja(double *wejscia);


    double aktywacja(double suma);

    double pochodnaAktywacji(double* wejscia);

    void setB(double b);
    double getB();

    double suma(double *wejscia);
    double* getWagi();

    void zerPoch();

    void sumPoch(double *wejscia);

    void dzielPoch(int N);

    void zmienWagi();

};

#endif
