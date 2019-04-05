#ifndef ZAD1_SIECNEURONOWA_H
#define ZAD1_SIECNEURONOWA_H

#include <vector>
#include "Neuron.h"

using namespace std;

class SiecNeuronowa {
private:
    vector<Neuron*> neurony;
public:
    void dodajNeuron(Neuron*);
    void usunNeuron(Neuron*);
};

#endif
