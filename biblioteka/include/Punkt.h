#ifndef ANALIZA_PUNKT_H
#define ANALIZA_PUNKT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;
class Punkt {
private:
    int x;
    int y;
public:
    Punkt(int, int);
    double randValue();
};

#endif
