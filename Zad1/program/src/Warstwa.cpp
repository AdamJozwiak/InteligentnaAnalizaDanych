#include "Warstwa.h"
#include "Neuron.h"

void Warstwa::stworzNeurony(int lb_neur, int lb_wejsc) {
    this->lb_wejsc = lb_wejsc;
    y = new double[lb_neur];
    for (int i = 0; i < lb_neur; i++) {
        Neuron *neuron = new Neuron(lb_wejsc);
        neurony.push_back(neuron);
    }
}

double *Warstwa::getWejscia() {
    return wejscia;
}

double *Warstwa::getY() {
    return y;
}

vector<Neuron *> Warstwa::getNeurony() {
    return neurony;
}

void Warstwa::obliczY(double *wejscia) {
    this->wejscia = wejscia;

    for (int i = 0; i < neurony.size(); i++) {
        y[i] = neurony[i]->propagacja(wejscia);
    }
}