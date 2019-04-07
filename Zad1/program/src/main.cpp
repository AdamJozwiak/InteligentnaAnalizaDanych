#include <iostream>
#include "SiecNeuronowa.h"
#include <fstream>
using namespace std;

int main() {
    ifstream fin;
    fin.open("C:\\Users\\Michał\\Desktop\\xd.txt");

    SiecNeuronowa siecNeuronowa;
    siecNeuronowa.dodajWarstwe(4,4);
    siecNeuronowa.dodajWarstwe(3,4);
    siecNeuronowa.dodajWarstwe(4,3);
    double **zestaw=new double*[4];//{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    for(int i=0; i<4; i++)
    {
        zestaw[i]=new double[4];
        for(int j=0; j<4; j++)
        {
            //fin>>zestaw[i][j];
            if(i==j) zestaw[i][j]=1;
            else zestaw[i][j]=0;
            cout<<zestaw[i][j]<<" ";
        }
        cout<<endl;
    }
    /*double h;
    while (fin>>h){
        cout<<h<<" ";
    }*/
    fin.close();
    vector<Warstwa> dzialaj=siecNeuronowa.getWarstwy();
    //dzialaj[0].obliczY(zestaw[0]);

    for(int i=0; i<10000; i++) {
       cout<< siecNeuronowa.getWarstwy()[2].getNeurony()[1].getWagi()[0]<<endl;
        siecNeuronowa.uczSiec(zestaw, zestaw, 4);
        //cout<<siecNeuronowa.E<<endl;
    }

    /*for (int i = 0; i < 4; i++) {


        double *lament = siecNeuronowa.getY(zestaw[i]);
        for (int k = 0; k < 4; k++) {
            cout << lament[k] << " ";

        }
        cout<<endl;
    }*/

    return 0;
}