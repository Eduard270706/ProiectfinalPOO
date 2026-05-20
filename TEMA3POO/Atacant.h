#ifndef ATACANT_H_INCLUDED
#define ATACANT_H_INCLUDED

#include "Jucator.h"

class Atacant:public Jucator
{
    int viteza;
    int sut;
    int dribling;
public:
    Atacant(const std::string& nume,const int nr_tricou,const double rating,const int viteza,const int sut,const int dribling);
    Atacant(const Atacant& other);
    Atacant& operator=(const Atacant& a);
    double calculPerformanta()const override;
    std::string pozitie()const override;
    void afisare(std::ostream& out) const override;

};


#endif
