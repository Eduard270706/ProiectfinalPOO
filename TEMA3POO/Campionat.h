#ifndef CAMPIONAT_H_INCLUDED
#define CAMPIONAT_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include "Echipa.h"
#include "Etapa.h"

class Campionat
{
    std::vector<Echipa<Jucator>> echipe;
    std::vector<Etapa> etape;
    std::string nume_campionat;
    int etapa_curenta;
public:
    Campionat(const std::string& nume_campionat);
    void adauga_echipa(const Echipa<Jucator>& e);

    std::vector<Echipa<Jucator>>& getechipe();

    std::string get_nume_campionat()const;

    void genereaza_program();

    void afisare_lot_echipe()const;

    void simuleaza_o_etapa();

    void simuleaza_campionatul();

    void afiseaza_cel_mai_bun_jucator_echipe()const;

    void afisare_pozitie_jucatori_echipa_fiecare_campionat()const;

    void afiseaza_rezultate();

    void afiseaza_clasament()const;

    static Campionat citeste_campionat(std::istream& f);

};

#endif
