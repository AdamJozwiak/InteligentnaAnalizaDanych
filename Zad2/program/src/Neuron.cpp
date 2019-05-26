#include "Neuron.h"

Neuron::Neuron() {
    //do {
        x = (double) (-1000 + rand() % 2500) / 100;
        y = (double) (-1500 + rand() % 2500) / 100;
        zmeczenie=0;
    //}while (x < 3.0 || y < 4.0 || x > 30.0 ||
           //y>40.0 );
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

void Neuron::addPkt(Punkt punkt) {
    punktyNeur.push_back(punkt);
}

void Neuron::clear() {
    punktyNeur.clear();
}

vector<Punkt> Neuron::getPkt() {
    return punktyNeur;
}

void Neuron::usrednij() {
    double sredniaX=0, sredniaY=0;
    for(int i=0; i<punktyNeur.size(); i++){
        sredniaX+=punktyNeur[i].getX();
        sredniaY+=punktyNeur[i].getY();
    }
    sredniaX/=punktyNeur.size();
    sredniaY/=punktyNeur.size();
    x=sredniaX;
    y=sredniaY;
}

void Neuron::zmecz() {
    zmeczenie=5;
}

void Neuron::odpocznij() {
    zmeczenie--;
}

int Neuron::getZmeczenie() {
    return zmeczenie;
}