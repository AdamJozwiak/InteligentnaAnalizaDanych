
#ifndef ZAD3_NEURONLIN_H
#define ZAD3_NEURONLIN_H

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class NeuronLin{
private:
    int lb_wag;
    double alfa;
    double *wagi;
    double beta;
    double *deltaW;
    double b;
    double* pochodna;
public:
    NeuronLin(int n);
    double random();

    double aktywacja(double suma);

     double pochodnaAktywacji(vector<double> wejscia);

    double propagacja(vector<double> wejscia);

    double suma(vector<double> wejscia);

    void sumPoch(vector<double> wejscia);

    void zerPoch();

    void dzielPoch(int N);

    void zmienWagi(vector<double> wejscia, double odp);

    void setB(double b);

    double getB();

    double* getWagi();

};

#endif //ZAD3_NEURONLIN_H
