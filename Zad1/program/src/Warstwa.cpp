#include "Warstwa.h"

void Warstwa::dodajNeuron(Neuron* neuron) {
    neurony.push_back(neuron);
}

void Warstwa::usunNeuron(Neuron* neuron) {
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