#include "Mijlocas.h"

Mijlocas::Mijlocas(const std::string& nume,const int nr_tricou,const double rating,const int viteza,const int precizie_pase,const int demarcare)
        :Jucator(nume,nr_tricou,rating),viteza(viteza),precizie_pase(precizie_pase),demarcare(demarcare) {}
    Mijlocas::Mijlocas(const Mijlocas& other):Jucator(other),viteza(other.viteza),precizie_pase(other.precizie_pase),demarcare(other.demarcare){}
    Mijlocas&Mijlocas:: operator=(const Mijlocas& m)
    {
        if(this!=&m)
        {
            Jucator::operator=(m);
            viteza=m.viteza;
            precizie_pase=m.precizie_pase;
            demarcare=m.demarcare;
        }
        return *this;
    }
    double Mijlocas::calculPerformanta()const
    {
        return 0.30*rating+0.15*viteza+0.30*precizie_pase+0.25*demarcare;
    }
    std::string Mijlocas::pozitie()const
    {
        return "Mijlocas";
    }
    void Mijlocas::afisare(std::ostream& out) const
    {
        Jucator::afisare(out);
        out<< ", viteza: "<<viteza
           << ", precizie_pase: "<<precizie_pase
           << ", demarcare: "<<demarcare;
    }
