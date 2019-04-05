#include "SiecNeuronowa.h"

void SiecNeuronowa::dodajWarstwe(Warstwa* warstwa) {
    warstwy.push_back(warstwa);
}

void SiecNeuronowa::usunWarstwe(Warstwa* warstwa) {
    vector<Warstwa*>::iterator it;
    for(it = warstwy.begin(); it != warstwy.end(); it++)
    {
        if(*it == warstwa)
        {
            it = warstwy.erase(it);
            break;
        }
    }
}