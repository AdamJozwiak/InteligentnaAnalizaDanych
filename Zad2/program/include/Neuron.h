
#ifndef ZAD2_NEURON_H
#define ZAD2_NEURON_H

#include <ctime>
#include <cstdlib>
#include <vector>
#include "Punkt.h"

using namespace std;
class Neuron{

private:
    double x;
    double y;
    double aktywnosc;
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
    vector<Punkt> getPkt();

};
#endif //ZAD2_NEURON_H
