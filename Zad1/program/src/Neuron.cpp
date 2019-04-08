#include "Neuron.h"


Neuron::Neuron(int lb, bool akt) {
    this->lb_wag = lb + 1;
    wagi = new double[lb_wag];
    deltaW = new double[lb_wag];
    alfa = 0.4;
    beta = 0.4;
    pochodna = new double[lb_wag];
    for (int i = 0; i < lb_wag; i++) {
        wagi[i] = random();
        pochodna[i] = 0;
        deltaW[i] = 0;
    }
    //if(akt) f=this->aktywacja;
    this->akt=akt;
}

double Neuron::random() {
    return (double) (-100 + rand() % 100) / 100;
}

double Neuron::aktywacja(double suma) {

    if(akt)return 1.0 / (1.0 + exp(-suma));

    else return suma;
}


double Neuron::pochodnaAktywacji(double *wejscia) {
    return aktywacja(suma(wejscia)) * (1 - aktywacja(suma(wejscia)));
}

double Neuron::suma(double *wejscia) {
    double suma = 0;
    for (int i = 1; i < lb_wag; i++) {
        suma += wejscia[i - 1] * wagi[i];
    }
    suma += wagi[0];  ///bias
    return suma;
}

double Neuron::propagacja(double *wejscia) {

    return aktywacja(suma(wejscia));
}

void Neuron::setB(double b) {
    this->b = b;
}

double Neuron::getB() {
    return b;
}

double *Neuron::getWagi() {
    return wagi;
}

void Neuron::zerPoch() {
    for (int i = 0; i < lb_wag; i++) {
        pochodna[i] = 0;

    }
}

void Neuron::sumPoch(double *wejscia) {
    for (int i = 1; i < lb_wag; i++) {
        pochodna[i] += b * wejscia[i - 1];
    }
    pochodna[0] += b; ///bias
}

void Neuron::dzielPoch(int N) {
    for (int i = 0; i < lb_wag; ++i) {
        pochodna[i] /= N;
    }
}

void Neuron::zmienWagi() {
    for (int i = 0; i < lb_wag; i++) {
        deltaW[i] = -alfa * pochodna[i] + beta * deltaW[i];
        wagi[i] += deltaW[i];
    }
}

