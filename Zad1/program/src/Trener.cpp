#include "Trener.h"

Trener::Trener(double* input, int lb_wejsc, int* odpowiedz) {
    wejscie=new double[lb_wejsc];
    wejscie[0]=1;
    for(int i = 1; i <= lb_wejsc; i++)
    {
        wejscie[i] = input[i];              //Dalem input, bo bylo wejscia i mozna bylo dostac pierdolca
    }

    this->odpowiedz = odpowiedz;
}

double* Trener::getWejscie() {
    return wejscie;
}

void Trener::setWejscie(double* input, int lb_wejsc) {

    for(int i = 0; i <= lb_wejsc; i++)
    {
        if(i == lb_wejsc)
        {
            wejscie[i] = 1;
            break;
        }
        wejscie[i] = input[i];
    }
}

int* Trener::getOdp() {
    return odpowiedz;
}