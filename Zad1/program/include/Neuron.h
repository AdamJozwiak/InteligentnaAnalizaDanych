#ifndef ZAD1_NEURON_H
#define ZAD1_NEURON_H
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

class Neuron {
protected:
    int lb_wag;
    double alfa;
    double *wagi;
    double beta;
    double *deltaW;
    double b;
    double* pochodna;
public:

    Neuron(int lb_wag);

    double random();

    double aktywacja(double suma);

    virtual double pochodnaAktywacji(double* wejscia);

    virtual double propagacja(double *wejscia);

    virtual double suma(double *wejscia);

    virtual void sumPoch(double *wejscia);

    void zerPoch();

    void dzielPoch(int N);

    void zmienWagi();

    void setB(double b);

    double getB();

    double* getWagi();

};

#endif
