#ifndef ZAD1_NEURONBEZBIASU_H
#define ZAD1_NEURONBEZBIASU_H

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>
#include "Neuron.h"

class NeuronBezBiasu : public Neuron {
public:

    NeuronBezBiasu(int lb_wag);

    double propagacja(double *wejscia);

    double pochodnaAktywacji(double *wejscia);

    double suma(double *wejscia);

    void sumPoch(double *wejscia);

};

#endif
