#ifndef ZAD3_NEURONRAD_H
#define ZAD3_NEURONRAD_H

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
class NeuronRad{
private:
double centrum;
double eta;
double sigma;
double eta2; //Jeśli robimy zmodyfikowanym WTA
double pom;
public:
    NeuronRad(double x);
    double getOdleglosc(double punkt);
    void uczNeuron(double punkt);
    void setSigma(int P, vector<NeuronRad> posortowane);
    double getSigma();
    void setPom(double punkt);
    double getPom();
    double getWsp();
    double getWyjscie(double x);

};

#endif //ZAD3_NEURONRAD_H
