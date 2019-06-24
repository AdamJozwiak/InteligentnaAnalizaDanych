#include "WarstwaLin.h"
WarstwaLin::WarstwaLin(int lb_wejsc) {
    this->lb_wejsc=lb_wejsc;
    NeuronLin neuron(lb_wejsc);
    neurony.push_back(neuron);
    E=0;
}

double WarstwaLin::getY() {
    return y;
}

void WarstwaLin::obliczY(vector<double> wejscia) {
    this->wejscia = wejscia;
        y = neurony[0].propagacja(wejscia);
}

void WarstwaLin::obliczB(double odp, vector<double> wejscia) {
    double wynik;
    wynik=(getY()-odp) * neurony[0].pochodnaAktywacji(wejscia);
    neurony[0].setB(wynik);
}

void WarstwaLin::uczNeuron(vector<double> wejscia, double odp) {
    //cout<<"t"<<endl;
    obliczY(wejscia);
    //cout<<"t1"<<endl;
    obliczB(odp, wejscia);
    neurony[0].sumPoch(wejscia);
   // cout<<"t2"<<endl;
    E+=pow(getY() - odp, 2);
    //cout<<"t3"<<endl;
}

void WarstwaLin::zmienWagi(int N) {
    E/=2*N;
    neurony[0].dzielPoch(N);
    neurony[0].zmienWagi();
}

void WarstwaLin::zeruj() {
    neurony[0].zerPoch();
    E=0;
}

double WarstwaLin::getE() {
    return E;
}