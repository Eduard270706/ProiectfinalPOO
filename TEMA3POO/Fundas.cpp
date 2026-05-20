#include "Fundas.h"

Fundas::Fundas(const std::string& nume,const int nr_tricou,const double rating,const int viteza,const int aparare,const int fizic)
    :Jucator(nume,nr_tricou,rating),viteza(viteza),aparare(aparare),fizic(fizic) {}
Fundas::Fundas(const Fundas& other):Jucator(other),viteza(other.viteza),aparare(other.aparare),fizic(other.fizic) {}
Fundas& Fundas::operator=(const Fundas& f)
{
    if(this!=&f)
    {
        Jucator::operator=(f);
        viteza=f.viteza;
        aparare=f.aparare;
        fizic=f.fizic;
    }
    return *this;
}
double Fundas::calculPerformanta()const
{
    return 0.30*rating+0.10*viteza+0.30*aparare+0.30*fizic;
}
std::string Fundas::pozitie()const
{
    return "Fundas";
}
void Fundas::afisare(std::ostream& out) const
{
    Jucator::afisare(out);
    out<< ", viteza: "<<viteza
       << ", aparare: "<<aparare
       << ", fizic: "<<fizic;
}
