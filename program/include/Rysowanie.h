#ifndef ANALIZA_RYSOWANIE_H
#define ANALIZA_RYSOWANIE_H

#include "Perceptron.h"
#include "Chodakowska.h"
#include <ctime>
#include <cstdlib>

using namespace std;

class Rysowanie {
private:
    Chodakowska *trener;
    float x;
    float y;
public:
    float linia(float x);
    void losowaniePunktow(int n);
    float random();
    void rysowanie(int n);
};
#endif
