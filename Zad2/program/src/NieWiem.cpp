#include "NieWiem.h"

double Neuron::prostokat(vector<double[2]> wierzcholki, int n)  {
    double xy[2];
    do {
        xy[0] = (double) (-100000 + rand() % 200000) / 100;
        xy[1] = (double) (-100000 + rand() % 200000) / 100;
    }   while(xy[0]<wierzcholki[0][0] || xy[1]<wierzcholki[0][1] || xy[0]>wierzcholki[1][0] || xy[1]>wierzcholki[1][1]);
    wierzcholki.push_back(xy);
}

