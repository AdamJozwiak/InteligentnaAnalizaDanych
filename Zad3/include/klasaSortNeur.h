
#include "NeuronRad.h"
#ifndef ZAD3_KLASASORTNEUR_H
#define ZAD3_KLASASORTNEUR_H

class klasaSortNeur{
public:
    bool operator()(NeuronRad a, NeuronRad b) const;
};

#endif //ZAD3_KLASASORTNEUR_H
