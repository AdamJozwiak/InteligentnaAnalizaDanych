#include "Perceptron.h"
Perceptron::Perceptron(int n) {
    wagi=new float[n];
    c=0.1;
    for(int i=0;i<n;i++)
    {
        wagi[i]=random();
    }

}
float Perceptron::random() {
    srand(time(NULL)*10);
    return (float)(-100+rand()%200)/100;

}

bool Perceptron::pozycja(float *wej) {
    float suma=0;
    for(int i=0;i<n;i++)
    {
        suma=suma+(wej[i]*wagi[i]);
    }
    return aktywacja(suma);
}

bool Perceptron::aktywacja(float suma) {
    if(suma>0) return 1;
    else return 0;
}

void Perceptron::trenuj(float *wej, bool odp) {
    int blad=odp-pozycja(wej);
    for(int i=0;i<n;i++)
    {
        wagi[i]+=blad*wej[i]*c;
    }
}

float* Perceptron::getWaga() {
    return wagi;
}