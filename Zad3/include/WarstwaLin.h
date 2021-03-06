#ifndef ZAD3_WARSTWALIN_H
#define ZAD3_WARSTWALIN_H

#include <vector>
#include <cmath>
#include "NeuronLin.h"
using namespace std;
class WarstwaLin{
private:

    vector<double> wejscia;
    double y;
    int lb_wejsc;
    double E;
public:
    vector<NeuronLin> neurony;
    WarstwaLin(int lb_wejsc);
    double getY(vector<double> wejscia);
    void obliczY(vector<double> wejscia);
    void uczNeuron(vector<double> wejscia, double odp);
    void obliczB(double odp, vector<double> wejscia);
    void zmienWagi(int N);
    void zeruj();
    double getE();

};

#endif //ZAD3_WARSTWALIN_H
