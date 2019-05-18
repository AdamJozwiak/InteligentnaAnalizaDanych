#ifndef ZAD2_NEURON_H
#define ZAD2_NEURON_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

class Neuron {
private:
    vector<double,double> punkty;
public:
    double trojkat(vector<double, double> wierzcholki, int n);
    double okrag(vector<double, double> promien, int n);
    double prostokat(vector<double[2]> wierzcholki, int n);
};

#endif
