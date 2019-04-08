#ifndef ZAD1_WARSTWA_H
#define ZAD1_WARSTWA_H

#include "Neuron.h"

class Warstwa {
protected:
    vector<Neuron *> neurony;
    double *wejscia;
    double *y;
    int lb_wejsc;
public:
    vector<Neuron *> getNeurony();

    virtual void stworzNeurony(int lb_neur, int lb_wejsc, bool akt);

    void obliczY(double *wejscia);

    double *getY();

    double *getWejscia();


};

#endif