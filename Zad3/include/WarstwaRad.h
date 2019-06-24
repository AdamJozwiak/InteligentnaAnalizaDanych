#ifndef ZAD3_WARSTWARAD_H
#define ZAD3_WARSTWARAD_H

#include "NeuronRad.h"
#include "klasaSortNeur.h"
#include <algorithm>
#include <functional>
using namespace std;

class WarstwaRad{
private:
    vector<NeuronRad> neurony;
    int P; //ilosc sasiadow branych przy obliczaniiu sigmy
public:
    WarstwaRad(int n, vector<double> x);
    int znajdzNajblizszy(double punkt);
    void uczNeurony(vector<double> punkt);
    vector<NeuronRad> sortujNeurony();
    void obliczSigmy();
    vector<double> getY(double x);
};

#endif //ZAD3_WARSTWARAD_H
