#include "Neuron.h"

Neuron::Neuron() {
    x=(double)(-10000+rand()%20000)/100;
    y=(double)(-10000+rand()%20000)/100;
}

double Neuron::getX() {
    return x;
}

double Neuron::getY() {
    return y;
}

void Neuron::setXY(double x, double y) {
    this->x=x;
    this->y=y;
}

void Neuron::setY(double y) {
    this->y=y;
}