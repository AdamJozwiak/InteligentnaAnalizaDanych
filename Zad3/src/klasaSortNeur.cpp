#include <iostream>
#include "klasaSortNeur.h"
using namespace std;

bool klasaSortNeur::operator()(NeuronRad a, NeuronRad b) const{
        return a.getPom() < b.getPom();
    }