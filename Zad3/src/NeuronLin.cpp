#include "NeuronLin.h"

NeuronLin::NeuronLin(int n) {
    this->lb_wag = n + 1;
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
}

double NeuronLin::random() {
    return (double) (-100 + rand() % 100) / 100;
}

double NeuronLin::aktywacja(double suma) {
    return 1.0 / (1.0 + exp(-suma));
}

double NeuronLin::pochodnaAktywacji(vector<double> wejscia) {
    return aktywacja(suma(wejscia)) * (1 - aktywacja(suma(wejscia)));
}


double NeuronLin::suma(vector<double> wejscia) {
    double suma = 0;
    for (int i = 1; i < lb_wag; i++) {
        suma += wejscia[i - 1] * wagi[i];
    }
    suma += wagi[0];  ///bias
    return suma;
}

double NeuronLin::propagacja(vector<double> wejscia) {

    return aktywacja(suma(wejscia));
}

void NeuronLin::setB(double b) {
    this->b = b;
}

double NeuronLin::getB() {
    return b;
}

double *NeuronLin::getWagi() {
    return wagi;
}

void NeuronLin::zerPoch() {
    for (int i = 0; i < lb_wag; i++) {
        pochodna[i] = 0;

    }
}

void NeuronLin::sumPoch(vector<double> wejscia) {
    for (int i = 1; i < lb_wag; i++) {
        pochodna[i] += b * wejscia[i - 1];
    }
    pochodna[0] += b; ///bias
}

void NeuronLin::dzielPoch(int N) {
    for (int i = 0; i < lb_wag; ++i) {
        pochodna[i] /= N;
    }
}

void NeuronLin::zmienWagi() {
    for (int i = 0; i < lb_wag; i++) {
        deltaW[i] = -alfa * pochodna[i] + beta * deltaW[i];
        wagi[i] += deltaW[i];
    }
}