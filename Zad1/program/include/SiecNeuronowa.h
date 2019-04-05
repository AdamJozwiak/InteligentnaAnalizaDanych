#ifndef ZAD1_SIECNEURONOWA_H
#define ZAD1_SIECNEURONOWA_H

#include "Warstwa.h"

using namespace std;

class SiecNeuronowa {
private:
    vector<Warstwa*> warstwy;
public:
    void dodajWarstwe(Warstwa*);
    void usunWarstwe(Warstwa*);
};

#endif
