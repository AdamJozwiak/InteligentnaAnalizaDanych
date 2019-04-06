#include "Neuron.h"

Neuron::Neuron(int lb_wag) {
    wagi = new double[lb_wag];
    stala = 0.1;
    for (int i = 0; i < lb_wag; i++) {
        wagi[i] = random();
    }
}

double Neuron::random() {
    srand(time(NULL));
    return (double) (-100 + rand() % 200) / 100;
}

double Neuron::aktywacja(double suma) {
    return 1.0 / (1.0 + exp(-1.0 * beta * suma));
}

double Neuron::pochodnaAktywacji() {
    return beta * propagacja(trener.getWejscie()) * (1 - propagacja(trener.getWejscie()));
}

double Neuron::propagacja(double *wejscie) {
    double suma = 0;
    for (int i = 0; i < lb_wag; i++) {
        suma += wejscie[i] * wagi[i];
    }
    return aktywacja(suma);
}

double Neuron::wstecznaPropagacja() {
    double suma = 0;
}

double Neuron::blad() {
}