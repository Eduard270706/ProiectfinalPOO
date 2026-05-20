#ifndef MIJLOCAS_H_INCLUDED
#define MIJLOCAS_H_INCLUDED

#include "Jucator.h"
class Mijlocas:public Jucator
{
    int viteza;
    int precizie_pase;
    int demarcare;
public:
    Mijlocas(const std::string& nume,const int nr_tricou,const double rating,const int viteza,const int precizie_pase,const int demarcare);
    Mijlocas(const Mijlocas& other);
    Mijlocas& operator=(const Mijlocas& m);
    double calculPerformanta()const override;
    std::string pozitie()const override;
    void afisare(std::ostream& out) const override;

};
#endif
