#ifndef ZAD1_WARSTWA_H
#define ZAD1_WARSTWA_H

#include "Neuron.h"

class Warstwa {
private:
    vector<Neuron*> neurony;
public:
    void dodajNeuron(Neuron*);
    void usunNeuron(Neuron*);
};
#endif