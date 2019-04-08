#ifndef ZAD1_SIECNEURONOWA_H
#define ZAD1_SIECNEURONOWA_H

#include "Warstwa.h"

using namespace std;

class SiecNeuronowa {
protected:
    vector<Warstwa *> warstwy;
public:

    vector<Warstwa *> getWarstwy();

    virtual void liczB(int);

    void dodajWarstwe(int, int, bool);

    void uczSiec(double **zestaw, double **odp, int n);

    void firstB(double *odp);

    double *getY(double *wejscia);

    double E;
};

#endif
