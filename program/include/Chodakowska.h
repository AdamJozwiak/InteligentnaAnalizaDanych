#ifndef ANALIZA_CHODAKOWSKA_H
#define ANALIZA_CHODAKOWSKA_H
class Chodakowska{
private:
    float* wej;
    bool odp;
public:
    Chodakowska(float x,float y,bool odp);
    Chodakowska();
    void setWej(float x, float y);
    void setOdp(bool odp);
    float* getWej();
    bool getOdp();
};

#endif
