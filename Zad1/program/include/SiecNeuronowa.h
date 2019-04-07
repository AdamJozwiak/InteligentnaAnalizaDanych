#ifndef ZAD1_SIECNEURONOWA_H
#define ZAD1_SIECNEURONOWA_H

#include "Warstwa.h"

using namespace std;

class SiecNeuronowa {
private:
    vector<Warstwa> warstwy;


public:
    double E;
    //SiecNeuronowa();
    void dodajWarstwe(int, int);
    void usunWarstwe(Warstwa);
    vector<Warstwa>& getWarstwy();
    void uczSiec(double** zestaw, double** odp, int n);
    double* oblicz(double *wejscia);
//    double E(double* y, double* odp);
    void liczB(int);
    void firstB(double *odp);
    double* getY(double *wejscia);
};

#endif
