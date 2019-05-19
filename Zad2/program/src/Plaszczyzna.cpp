#include "Plaszczyzna.h"
Plaszczyzna::Plaszczyzna(int iloscNeur) {
    for(int i=0; i<iloscNeur; i++){
        Neuron neuron;
        neurony.push_back(neuron);
    }
    alpha=0.1;
}

void Plaszczyzna::prostokat(vector<Punkt> wierzcholki, int n)  {
    for(int i=0; i<n; i++) {
        double xy[2];
        do {
            xy[0] = (double) (-10000 + rand() % 20000) / 100;
            xy[1] = (double) (-10000 + rand() % 20000) / 100;
        } while (xy[0] < wierzcholki[0].getX() || xy[1] < wierzcholki[0].getY() || xy[0] > wierzcholki[1].getX() ||
                 xy[1] > wierzcholki[1].getY());
       Punkt punkt(xy[0],xy[1]);
        punkty.push_back(punkt);
    }
}

void Plaszczyzna::lotto() {
    random_shuffle(punkty.begin(),punkty.end());
}

int Plaszczyzna::znajdzNajblizszy(int i) {
    double odl=sqrt(pow(punkty[i].getX()-neurony[0].getX(),2) + pow(punkty[i].getY()-neurony[0].getY(),2));
    double winNum=0;
    double pom;
    for(int j=1; j<neurony.size(); j++){
        pom=sqrt(pow(punkty[i].getX()-neurony[j].getX(),2) + pow(punkty[i].getY()-neurony[j].getY(),2));
        if(pom<odl) {odl=pom; winNum=j;}
    }
    return winNum;

}

double Plaszczyzna::theta(int j, int winNum) {
    return exp(-(pow(neurony[j].getX()-neurony[winNum].getX(),2) + pow(neurony[j].getY()-neurony[winNum].getY(),2))/ 11 ); ///e^(-smiesznyznaczek^2/lambda^2)
}


void Plaszczyzna::algKohonen() {

    for(int i=0; i<neurony.size(); i++) {neurony[i].clear();}

    for(int i=0; i<punkty.size();i++)
    {
        int winNum=znajdzNajblizszy(i);
        neurony[winNum].addPkt(punkty[i]);
        for(int j=0; j<neurony.size(); j++){
            double nowyX=neurony[j].getX()+alpha*theta(j,winNum)*(punkty[i].getX()-neurony[j].getX());
            double nowyY=neurony[j].getY()+alpha*theta(j,winNum)*(punkty[i].getY()-neurony[j].getY());
            neurony[j].setXY(nowyX, nowyY);
        }
    }
}

void Plaszczyzna::sortNeur(int num) {
    int i,j;
    double pom;
    Neuron pom2;
    for(i=1; i<neurony.size(); i++){
        pom=sqrt(pow(punkty[num].getX()-neurony[i].getX(),2) + pow(punkty[num].getY()-neurony[i].getY(),2));
        pom2=neurony[i];
        for(j=i-1; j>=0; j--){
            if(pom < sqrt(pow(punkty[num].getX()-neurony[j].getX(),2) + pow(punkty[num].getY()-neurony[j].getY(),2)))
                neurony[j+1]=neurony[j];
            else
                break;
        }
        neurony[j+1]=pom2;
    }
}

void Plaszczyzna::algGazNeur() {
    for(int i=0; i<neurony.size(); i++) {neurony[i].clear();}

    for(int i=0; i<punkty.size();i++)
    {
        sortNeur(i);
        neurony[0].addPkt(punkty[i]);
        //int winNum=znajdzNajblizszy(i);
        //neurony[winNum].addPkt(punkty[i]);
        for(int j=0; j<neurony.size(); j++){
            double nowyX=neurony[j].getX()+alpha*exp(-j/10)*(punkty[i].getX()-neurony[j].getX());
            double nowyY=neurony[j].getY()+alpha*exp(-j/10)*(punkty[i].getY()-neurony[j].getY());
            neurony[j].setXY(nowyX, nowyY);
        }
    }

}

void Plaszczyzna::algSrednich() {
    for(int i=0; i<neurony.size(); i++) {neurony[i].clear();}

    for(int i=0; i<punkty.size();i++)
    {
        int winNum=znajdzNajblizszy(i);
        neurony[winNum].addPkt(punkty[i]);
    }
    for(int i=0; i++; i<neurony.size()){
        neurony[i].usrednij();
    }
}


vector<Punkt> Plaszczyzna::getPunkty() {
    return punkty;
}

vector<Neuron> Plaszczyzna::getNeurony() {
    return neurony;
}

