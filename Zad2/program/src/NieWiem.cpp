#include "NieWiem.h"
#include "gnuplot_i.hpp"
NieWiem::NieWiem(int iloscNeur) {
    for(int i=0; i<iloscNeur; i++){
        Neuron neuron;
        neurony.push_back(neuron);
    }
    alpha=0.1;
}

void NieWiem::prostokat(vector<Punkt> wierzcholki, int n)  {
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

void NieWiem::lotto() {
    random_shuffle(punkty.begin(),punkty.end());
}

int NieWiem::znajdzNajblizszy(int i) {
    double odl=sqrt(pow(punkty[i].getX()-neurony[0].getX(),2) + pow(punkty[i].getY()-neurony[0].getY(),2));
    double winNum=0;
    double pom;
    for(int j=1; j<neurony.size(); j++){
        pom=sqrt(pow(punkty[i].getX()-neurony[j].getX(),2) + pow(punkty[i].getY()-neurony[j].getY(),2));
        if(pom<odl) {odl=pom; winNum=j;}
    }
    return winNum;

}

double NieWiem::theta(int j, int winNum) {
    return exp(-(pow(neurony[j].getX()-neurony[winNum].getX(),2) + pow(neurony[j].getY()-neurony[winNum].getY(),2))/ 10 ); ///e^(-smiesznyznaczek^2/lambda^2)
}


void NieWiem::algKohonen() {
    for(int i=0; i<punkty.size();i++)
    {
        double winNum=znajdzNajblizszy(i);
        for(int j=0; j<neurony.size(); j++){
            double nowyX=neurony[j].getX()+alpha*theta(j,winNum)*(punkty[i].getX()-neurony[j].getX());
            double nowyY=neurony[j].getY()+alpha*theta(j,winNum)*(punkty[i].getY()-neurony[j].getY());
            neurony[j].setXY(nowyX, nowyY);
        }
    }
}

vector<Punkt> NieWiem::getPunkty() {
    return punkty;
}

