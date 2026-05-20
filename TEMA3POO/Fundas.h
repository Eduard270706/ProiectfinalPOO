#ifndef FUNDAS_H_INCLUDED
#define FUNDAS_H_INCLUDED

#include "Jucator.h"
class Fundas:public Jucator
{
    int viteza;
    int aparare;
    int fizic;
public:
    Fundas(const std::string& nume,const int nr_tricou,const double rating,const int viteza,const int aparare,const int fizic);
    Fundas(const Fundas& other);
    Fundas& operator=(const Fundas& f);
    double calculPerformanta()const override;
    std::string pozitie()const override;
    void afisare(std::ostream& out) const override;

};
#endif
