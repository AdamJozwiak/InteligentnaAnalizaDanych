#ifndef INTELIGENTNAANALIZADANYCH_RYSOWANIE_H
#define INTELIGENTNAANALIZADANYCH_RYSOWANIE_H

#include "Chodakowska.h"
#include <ctime>
#include <cstdlib>
#include "Perceptron.h"

using namespace std;

class Rysowanie {
private:
    float x;
    float y;
public:
    float linia(float x);
    void losowaniePunktow(int n);
    float random();
    void rysowanie(int n);
};
#endif //INTELIGENTNAANALIZADANYCH_RYSOWANIE_H
