#ifndef ZAD2_NEURON_H
#define ZAD2_NEURON_H

#include "iostream"
#include "vector"
#include "cstdlib"
#include "cmath"

using namespace std;

class Neuron {
private:
    double **pozycja;
public:
    double trojkat(double punkty);
    double okrag(double promien);
};

#endif
