#ifndef PORTAR_H_INCLUDED
#define PORTAR_H_INCLUDED

#include "Jucator.h"

class Portar:public Jucator
{
    int reflexe;
    int joc_picior;
    int pozitionare;
    int plonjon;
public:
    Portar(const std::string& nume,const int nr_tricou,const double rating,const int reflexe,const int joc_picior,const int pozitionare,const int plonjon);

    Portar(const Portar& other);
    Portar& operator=(const Portar& p);

    double calculPerformanta()const override;

    std::string pozitie()const override;

    void afisare(std::ostream& out) const override;

};
#endif
