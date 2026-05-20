#include "Atacant.h"

 Atacant::Atacant(const std::string& nume,const int nr_tricou,const double rating,const int viteza,const int sut,const int dribling)
        :Jucator(nume,nr_tricou,rating),viteza(viteza),sut(sut),dribling(dribling) {}
 Atacant::Atacant(const Atacant& other):Jucator(other),viteza(other.viteza),sut(other.sut),dribling(other.dribling){}
 Atacant&Atacant::operator=(const Atacant& a)
    {
        if(this!=&a)
        {
        Jucator::operator=(a);
        viteza=a.viteza;
        sut=a.sut;
        dribling=a.dribling;
        }
        return *this;
    }
double Atacant::calculPerformanta()const
    {
        return 0.30*rating+0.20*viteza+0.30*sut+0.20*dribling;
    }
    std::string Atacant::pozitie()const
    {
        return "Atacant";
    }
    void Atacant::afisare(std::ostream& out) const
    {
        Jucator::afisare(out);
        out<< ", viteza: "<<viteza
           << ", sut: "<<sut
           << ", dribling: "<<dribling;
    }
