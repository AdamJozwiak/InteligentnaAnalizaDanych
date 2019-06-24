#include "WarstwaRad.h"

WarstwaRad::WarstwaRad(int n, vector<double> x) {
    for(int i=0; i<n; i++){
        NeuronRad neuronRad(x[i]);
        neurony.push_back(neuronRad);
    }
    P=10;
}

int WarstwaRad::znajdzNajblizszy(double punkt) {
    int najblizszy=0;
    for(int i=1; i<neurony.size(); i++){
        if(neurony[najblizszy].getOdleglosc(punkt) > neurony[i].getOdleglosc(punkt)) {
            najblizszy=i;
        }
    }
    return najblizszy;
}


vector<NeuronRad> WarstwaRad::sortujNeurony() {
    vector<NeuronRad> posortowane=neurony;
    sort(posortowane.begin(),posortowane.end(), klasaSortNeur());
    return posortowane;
}


void WarstwaRad::obliczSigmy() {

    vector<NeuronRad> wektorPom;
    for(int i=0; i<neurony.size(); i++){
        for(int j=0; j<neurony.size(); j++){
            neurony[j].setPom(neurony[j].getOdleglosc(neurony[i].getWsp()));
        }
        neurony[i].setSigma(P,sortujNeurony());
    }
}

void WarstwaRad::uczNeurony(vector<double> punkty) {
    int najblizszy;
    for(int i=0; i<punkty.size(); i++) {
        najblizszy = znajdzNajblizszy(punkty[i]);
        neurony[najblizszy].uczNeuron(punkty[i]);
        /*for(int j=0; j<neurony.size(); j++){
            if(j!=najblizszy) neurony[najblizszy].uczNeuron2(punkty[i]);
        }*/ //TO JESLI ROBIMY ZMODYFIKOWANYM WTA
        obliczSigmy();
    }

}

vector<double> WarstwaRad::getY(double x) {
    vector<double> y;
    double pom;
    for(int i=0; i<neurony.size(); i++){
        pom=neurony[i].getWyjscie(x);
        //cout<<pom<<endl;
        y.push_back(pom);
    }
    //cout<<"wielkosc y: "<<y.size()<<endl;
    return y;
}