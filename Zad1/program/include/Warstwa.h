#ifndef ZAD1_WARSTWA_H
#define ZAD1_WARSTWA_H

#include "Neuron.h"

class Warstwa {
private:
    vector<Neuron> neurony;
    double* wejscia;
    double* y;
    int lb_wejsc;
public:
    Warstwa(int lb_neur, int lb_wejsc);
    void dodajNeuron(Neuron);
    void usunNeuron(Neuron);
    vector<Neuron>& getNeurony();
    void obliczY(double* wejscia);
    double* getY();
    double lbNeur();
    double* getWejscia();


};
#endif