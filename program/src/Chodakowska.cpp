#include "Chodakowska.h"

Chodakowska::Chodakowska(float x,float y, bool odp) {
    wej=new float[3];
    wej[0]=x;
    wej[1]=y;
    wej[2]=1;
    this->odp=odp;
}
Chodakowska::Chodakowska(){};

float* Chodakowska::getWej() {
    return wej;
}

bool Chodakowska::getOdp() {
    return odp;
}

void Chodakowska::setWej(float x, float y) {
    wej=new float[3];
    wej[0]=x;
    wej[1]=y;
    wej[2]=1;
}

void Chodakowska::setOdp(bool odp) {
    this->odp=odp;
}