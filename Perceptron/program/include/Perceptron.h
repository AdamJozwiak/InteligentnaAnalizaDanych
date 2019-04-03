#ifndef ANALIZA_PERCEPTRON_H
#define ANALIZA_PERCEPTRON_H


#include <cstdlib>
#include <ctime>
class Perceptron{
public:
    int n;
    float c;
    float* wagi;
public:
    Perceptron(int n);
    float random();
    bool pozycja(float *wej);
    bool aktywacja(float suma);
    void trenuj(float *wej,bool odp);
    float* getWaga();
    float f(float x);
};
#endif //ANALIZA_PERCEPTRON_H
