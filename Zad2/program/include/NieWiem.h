#ifndef ZAD2_NIEWIEM_H
#define ZAD2_NIEWIEM_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include "gnuplot_i.hpp"
#include "Neuron.h"
#include "Punkt.h"



using namespace std;

class NieWiem {
private:
    vector<Punkt> punkty;
    vector<Neuron> neurony;
    double alpha;

public:
    NieWiem(int iloscNeur);
    double trojkat(vector<double, double> wierzcholki, int n);
    double okrag(vector<double, double> promien, int n);
    void prostokat(vector<Punkt> wierzcholki, int n);
    double theta(int j, int winIt);
    void lotto();
    int znajdzNajblizszy(int i);
    void algKohonen();
    vector<Punkt> getPunkty();
    void rysuj();
};

#endif
