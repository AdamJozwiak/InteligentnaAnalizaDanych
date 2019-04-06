#ifndef ZAD1_TRENER_H
#define ZAD1_TRENER_H

class Trener {
private:
    double* wejscie;
    int* odpowiedz;
public:
    Trener(double* wejscia, int lb_wejsc, int* odpowiedz);
    Trener();
    void setWejscie(double* input, int lb_wejsc);
    double* getWejscie();
    int* getOdp();
};
#endif
