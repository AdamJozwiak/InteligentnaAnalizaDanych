#ifndef ZAD2_NIEWIEM_H
#define ZAD2_NIEWIEM_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include "Neuron.h"
#include "Punkt.h"



using namespace std;

class Plaszczyzna {
private:
    vector<Punkt> punkty;
    vector<Neuron> neurony;
    double alpha;

public:
    Plaszczyzna(int iloscNeur);
    Plaszczyzna(int iloscNeur, vector<Punkt> punkty);
    double trojkat(vector<double, double> wierzcholki, int n);
    double okrag(vector<double, double> promien, int n);
    void prostokat(vector<Punkt> wierzcholki, int n);
    double theta(int j, int winIt);
    void lotto();
    int znajdzNajblizszy(int i);
    void algKohonen();
    void sortNeur(int i);
    void algGazNeur();
    void algSrednich();
    vector<Punkt> getPunkty();
    vector<Neuron> getNeurony();
    void rysuj();
};

#endif
