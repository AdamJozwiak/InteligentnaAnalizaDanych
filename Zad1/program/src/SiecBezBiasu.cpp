#include "SiecBezBiasu.h"

void SiecBezBiasu::dodajWarstwe(int lb_neur, int lb_wejsc) {
    WarstwaBezBiasu *warstwa = new WarstwaBezBiasu;
    warstwa->stworzNeurony(lb_neur, lb_wejsc);
    warstwy.push_back(warstwa);
}

void SiecBezBiasu::liczB(int nrWar) {
    Warstwa *next = warstwy[nrWar + 1];

    for (int i = 0; i < warstwy[nrWar]->getNeurony().size(); i++) {
        double b = 0;
        for (int j = 0; j < next->getNeurony().size(); j++) {
            b += next->getNeurony()[j]->getB() * next->getNeurony()[j]->getWagi()[i];
        }
        b = b * warstwy[nrWar]->getNeurony()[i]->pochodnaAktywacji(warstwy[nrWar]->getWejscia());
        warstwy[nrWar]->getNeurony()[i]->setB(b);
    }
}

