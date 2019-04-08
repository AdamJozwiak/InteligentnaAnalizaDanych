#include "WarstwaBezBiasu.h"

void WarstwaBezBiasu::stworzNeurony(int lb_neur, int lb_wejsc) {
    this->lb_wejsc = lb_wejsc;
    y = new double[lb_neur];
    for (int i = 0; i < lb_neur; i++) {
        NeuronBezBiasu *neuron = new NeuronBezBiasu(lb_wejsc);
        neurony.push_back(neuron);
    }
}
