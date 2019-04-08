#ifndef ZAD1_SIECBEZBIASU_H
#define ZAD1_SIECBEZBIASU_H

#include "SiecNeuronowa.h"
#include "WarstwaBezBiasu.h"

class SiecBezBiasu : public SiecNeuronowa {
public:
    void dodajWarstwe(int lb_neur, int lb_wejsc);

    void liczB(int nrWar);
};
#endif //ZAD1_SIECBEZBIASU_H
