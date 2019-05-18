
#ifndef ZAD2_NEURON_H
#define ZAD2_NEURON_H

#include <ctime>
#include <cstdlib>

using namespace std;
class Neuron{

private:
    double x;
    double y;
    double aktywnosc;
public:
    Neuron();
    double getX();
    double getY();
    void setXY(double x, double y);
    void setY(double y);

};
#endif //ZAD2_NEURON_H
