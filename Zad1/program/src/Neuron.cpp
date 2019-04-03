#include "Neuron.h"

Neuron::Neuron(int lb_wag) {
    wagi = new double [lb_wag];
    stala = 0.1;
    for(int i = 0; i < lb_wag; i++)
    {
        wagi[i] = random();
    }
}

double Neuron::random() {
    srand(time(NULL));
    return (double) (-100+rand()%200)/100;
}

double Neuron::sumowanie(double *wejscie) {
    double suma = 0;

    for(int i = 0; i < lb_wag; i++)
    {
        suma += wejscie[i] * wagi[i];
    }

    return suma;
}

double Neuron::aktywacja(double suma) {
    return 1/(1+exp(-beta*suma));
}

