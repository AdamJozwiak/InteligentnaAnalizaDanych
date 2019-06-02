
#ifndef ZAD2_NEURON_H
#define ZAD2_NEURON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Punkt.h"

using namespace std;
class Neuron{

private:
    double x;
    double y;
    int zmeczenie;
    vector<Punkt> punktyNeur;
public:
    Neuron();
    double getX();
    double getY();
    void setXY(double x, double y);
    void setY(double y);
    void addPkt(Punkt punkt);
    void clear();
    void usrednij();
    void zmecz();
    void odpocznij();
    int getZmeczenie();
    vector<Punkt> getPkt();

};
#endif //ZAD2_NEURON_H
