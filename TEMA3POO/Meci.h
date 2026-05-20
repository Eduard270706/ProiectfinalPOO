#ifndef MECI_H_INCLUDED
#define MECI_H_INCLUDED

#include <utility>
#include "Echipa.h"

class Meci
{
    Echipa<Jucator>* gazda;
    Echipa<Jucator>* oaspete;
    int golurigazda;
    int golurioaspete;
    bool jucat;
public:
    Meci(Echipa<Jucator>* gazda=nullptr,Echipa<Jucator>* oaspete=nullptr);
    Meci(const Meci& m);
    Meci& operator=(Meci m);

    friend void swap(Meci&m1,Meci&m2);

    void simuleazameci();

    void afisare_program()const;

    void afiseaza_rezultat()const;


};

#endif
