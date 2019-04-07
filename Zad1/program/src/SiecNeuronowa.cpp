#include "SiecNeuronowa.h"

void SiecNeuronowa::dodajWarstwe(int lb_neur, int lb_wejsc) {
    Warstwa warstwa(lb_neur,lb_wejsc);
    warstwy.push_back(warstwa);
}

/*void SiecNeuronowa::usunWarstwe(Warstwa warstwa) {
    vector<Warstwa*>::iterator it;
    for(it = warstwy.begin(); it != warstwy.end(); it++)
    {
        if(*it == warstwa)
        {
            it = warstwy.erase(it);
            break;
        }
    }
}*/

vector<Warstwa>& SiecNeuronowa::getWarstwy() {
    return warstwy;
}

/*double SiecNeuronowa::E(double *y, double *odp,int n) {

}*/

void SiecNeuronowa::liczB(int nrWar)
{
    Warstwa next=warstwy[nrWar+1];

    for(int i=0; i<warstwy[nrWar].getNeurony().size(); i++)
    {
        double b=0;
        for(int j=0; j<next.getNeurony().size(); j++)
        {
            b+=next.getNeurony()[j].getB()*next.getNeurony()[j].getWagi()[i+1];
        }
        b=b*warstwy[nrWar].getNeurony()[i].pochodnaAktywacji(warstwy[nrWar].getWejscia());
        warstwy[nrWar].getNeurony()[i].setB(b);

    }
}

void SiecNeuronowa::firstB(double *odp) {
    //Warstwa warstwy.back()=warstwy.back();
    double wynik;
    for (int i=0; i< warstwy.back().getNeurony().size(); i++)
    {
        wynik=(warstwy.back().getY()[i]-odp[i])*warstwy.back().getNeurony()[i].pochodnaAktywacji(warstwy.back().getWejscia()); //(y-odp) * f'(suma)
        warstwy.back().getNeurony()[i].setB(wynik); //zapisujemy ta wartosc dla kazdego neurony z warstwy wyjsciowej w danym wzorcu
    }

}

double* SiecNeuronowa::getY(double *wejscia) {
    warstwy[0].obliczY(wejscia);
    for (int i = 1; i <warstwy.size() ; i++) {
        warstwy[i].obliczY(warstwy[i-1].getY());
    }
    return warstwy.back().getY();
}


void SiecNeuronowa::uczSiec(double** zestaw, double** odp, int N) {

    for (int i = 0; i < warstwy.size(); i++) {

        for (int j = 0; j < warstwy[i].getNeurony().size(); j++) {
            //warstwy[i].getNeurony()[j].dzielPoch(N);
           // warstwy[i].getNeurony()[j].zmienWagi();
            warstwy[i].getNeurony()[j].zerPoch();

        }
    }

    E=0;
    for (int i = 0; i < N; i++)
    {
        ////propagacja
        warstwy[0].obliczY(zestaw[i]);
        for (int j = 1; j < warstwy.size(); j++) {
            warstwy[j].obliczY(warstwy[j-1].getY());
        }
       // blad+=E(warstwy[warstwy.size()-1].getY(),odp[i],n);


       //wsteczna propagacja

       firstB(odp[i]);
        for(int j=warstwy.size()-2; j>=0; j--)
        {
            liczB(j);

        }

        for (int j = warstwy.size()-1; j>=0; j--)
        {

            for(int k=0; k<warstwy[j].getNeurony().size(); k++)
            {
                warstwy[j].getNeurony()[k].sumPoch(warstwy[j].getWejscia());
            }

        }
        for (int j = 0; j < warstwy.back().getNeurony().size(); j++) {
            E=E+pow((warstwy.back().getY()[j]-odp[i][j]),2);
        }
    }

    E/=2*N*4;

    for (int i = 0; i < warstwy.size(); i++) {

        for (int j = 0; j < warstwy[i].getNeurony().size(); j++) {
            warstwy[i].getNeurony()[j].dzielPoch(N);
            warstwy[i].getNeurony()[j].zmienWagi();
            //warstwy[i].getNeurony()[j].zerPoch();

        }
    }


    /*warstwy[0].obliczY(zestaw[i]);
    for (int j = 0; j < warstwy.size(); j++) {
        warstwy[j].obliczY(warstwy[j-1].getY());
    }*/

    //return warstwy[warstwy.size()-1].getY;

}
