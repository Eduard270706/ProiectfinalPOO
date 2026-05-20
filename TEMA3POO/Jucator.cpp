#include "Jucator.h"
#include "Atacant.h"
#include "Mijlocas.h"
#include "Fundas.h"
#include "Portar.h"
#include "Exceptii.h"
#include "JucatorFactory.h"

int Jucator::numar_jucatori=0;
Jucator::Jucator(const std::string& nume,const int nr_tricou,const double rating)
    :nume(nume),nr_tricou(nr_tricou),rating(rating)
{
    numar_jucatori++;
}
Jucator::Jucator(const Jucator& other):nume(other.nume),nr_tricou(other.nr_tricou),rating(other.rating)
{
    numar_jucatori++;
}
Jucator& Jucator:: operator=(const Jucator& j)
{
    if(this!=&j)
    {
        nume=j.nume;
        nr_tricou=j.nr_tricou;
        rating=j.rating;
    }
    return *this;
}
Jucator:: ~Jucator()
{
    numar_jucatori--;
}
int Jucator::nr_juc()
{
    return numar_jucatori;
}
void Jucator::afisare(std::ostream& out)const
{
    out<<"Nume: "<<nume
       <<", tricou: "<<nr_tricou
       <<", rating: "<<rating
       <<", pozitie: "<<pozitie()
       <<", performanta: "<<calculPerformanta();
}
std::ostream&operator <<(std::ostream& out,const Jucator& j)
{
    j.afisare(out);
    return out;
}
std::shared_ptr<Jucator> Jucator::citestejuc(std::istream& f)
{
    std::string pozitie,nume;
    int nr_tricou;
    double rating;
    if(!(f>>pozitie>>nume>>nr_tricou>>rating))
        throw Exceptie_date("Date jucator invalide!");
    if(rating<=0 || nr_tricou<=0)
        throw Exceptie_date("Date rating sau nr_tricou jucator invalide!");
    return JucatorFactory::creeaza_jucator(pozitie,nume,nr_tricou,rating,f);
}
