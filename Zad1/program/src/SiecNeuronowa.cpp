#include "SiecNeuronowa.h"

void SiecNeuronowa::dodajNeuron(Neuron* neuron) {
    neurony.push_back(neuron);
}

void SiecNeuronowa::usunNeuron(Neuron* neuron) {
    vector<Neuron*>::iterator it;
    for(it = neurony.begin(); it != neurony.end(); it++)
    {
        if(*it == neuron)
        {
            it = neurony.erase(it);
            break;
        }
    }
}