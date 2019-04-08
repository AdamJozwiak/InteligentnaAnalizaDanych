#include "NeuronBezBiasu.h"

NeuronBezBiasu::NeuronBezBiasu(int lb_wag) : Neuron(lb_wag - 1) {}

double NeuronBezBiasu::pochodnaAktywacji(double *wejscia) {
    return aktywacja(suma(wejscia)) * (1 - aktywacja(suma(wejscia)));
}

double NeuronBezBiasu::suma(double *wejscia) {
    double suma = 0;
    for (int i = 0; i < lb_wag; i++) {
        suma += wejscia[i] * wagi[i];
    }
    return suma;
}

double NeuronBezBiasu::propagacja(double *wejscia) {
    return aktywacja(suma(wejscia));
}

void NeuronBezBiasu::sumPoch(double *wejscia) {
    for (int i = 0; i < lb_wag; i++) {
        pochodna[i] += b * wejscia[i];
    }
}