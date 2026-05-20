#include "Portar.h"

Portar::Portar(const std::string& nume,const int nr_tricou,const double rating,const int reflexe,const int joc_picior,const int pozitionare,const int plonjon)
        :Jucator(nume,nr_tricou,rating),reflexe(reflexe),joc_picior(joc_picior),pozitionare(pozitionare),plonjon(plonjon) {}
    Portar::Portar(const Portar& other):Jucator(other),reflexe(other.reflexe),joc_picior(other.joc_picior),pozitionare(other.pozitionare),plonjon(other.plonjon){}
    Portar& Portar::operator=(const Portar& p)
    {
        if(this!=&p)
        {
        Jucator::operator=(p);
        reflexe=p.reflexe;
        joc_picior=p.joc_picior;
        pozitionare=p.pozitionare;
        plonjon=p.plonjon;
        }
        return *this;
    }
    double Portar::calculPerformanta()const
    {
        return 0.20*rating+0.30*reflexe+0.10*joc_picior+0.20*pozitionare+0.20*plonjon;
    }
    std::string Portar::pozitie()const
    {
        return "Portar";
    }
    void Portar::afisare(std::ostream& out) const
    {
        Jucator::afisare(out);
        out<< ", reflexe: "<<reflexe
           << ", joc_picior: "<<joc_picior
           << ", pozitionare: "<<pozitionare
           << ", plonjon: "<<plonjon;
    }
