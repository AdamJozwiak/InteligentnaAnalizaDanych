#ifndef ZAD1_WARSTWABEZBIASU_H
#define ZAD1_WARSTWABEZBIASU_H

#include "Warstwa.h"
#include "NeuronBezBiasu.h"

class WarstwaBezBiasu : public Warstwa {
public:
    void stworzNeurony(int lb_neur, int lb_wejsc);
};

#endif //ZAD1_WARSTWABEZBIASU_H
