#include <iostream>
#include <ctime>
#include "NieWiem.h"

int main() {
    srand(time(NULL));
    NieWiem nieWiem(10);
    vector<double[2]> wektor;
    wektor.push_back({3.0,4.0});
    wektor.push_back({30.0,40.0});
    nieWiem.prostokat(wektor,200);
    for(int i=0;i<50;i++){
        nieWiem.algKohonen();
        nieWiem.lotto();
    }

    return 0;
}