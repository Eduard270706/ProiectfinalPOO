#ifndef ETAPA_H_INCLUDED
#define ETAPA_H_INCLUDED

#include "Meci.h"
#include <vector>

class Etapa
{
    std::vector<Meci> meciuri;
    int nr;
public:
    Etapa(int nr=0);

    void adauga_meci(const Meci& m);

    void simuleaza_etapa();

    void afisare_program()const;

    void afisare_rezultat()const;

};

#endif
