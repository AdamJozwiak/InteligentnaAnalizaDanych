#ifndef ZAD1_NEURON_H
#define ZAD1_NEURON_H

#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class Neuron{
private:
    int lb_wag;
    double stala;
    double* wagi;
    int beta = 1;
public:
    Neuron(int lb_wag);
    double random();
    double sumowanie(double* wagi);
    double aktywacja(double suma);
    void trenowanie(double *wej, bool odp);
};

#endif
