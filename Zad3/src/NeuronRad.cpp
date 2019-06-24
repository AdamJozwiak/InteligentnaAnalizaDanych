#include "NeuronRad.h"

NeuronRad::NeuronRad(double x) {
    centrum=x;
    eta=0.03;
    //centrum[1]=y;
}

double NeuronRad::getOdleglosc(double punkt) {
    //return sqrt(pow(centrum[0] - punkt[0], 2) + pow(centrum[1] - punkt[1], 2));
    return sqrt(pow(centrum - punkt,2));
}

void NeuronRad::uczNeuron(double punkt) {
    centrum=centrum+eta*(punkt-centrum);
    //tutaj jakoś zmniejszyć współczynnik "eta"
}

void NeuronRad::setSigma(int P, vector<NeuronRad> posortowane){
     sigma=0;
    for(int i=1; i<P; i++){
        sigma+=pow(centrum - posortowane[i].getWsp(),2);
    }
    //cout<<"sigma"<<sigma/P<<endl;
    //sigma=sqrt(sigma/P);

}

double NeuronRad::getSigma() {
    return sigma;
}

void NeuronRad::setPom(double punkt) {
    this->pom=punkt;
}
double NeuronRad::getPom() {
    return pom;
}


double NeuronRad::getWsp(){
    return centrum;
}

double NeuronRad::getWyjscie(double x) {
    //cout<<"sigma: "<<getSigma()<<endl;
    return exp(-pow(getOdleglosc(x)/getSigma(),2));
}