#include "Echipa.h"
#include "Atacant.h"
#include "Mijlocas.h"
#include "Fundas.h"
#include "Portar.h"
#include "Exceptii.h"

#include <utility>
#include <iostream>

Echipa::Echipa(const std::string& nume):nume(nume),victorii(0),egaluri(0),infrangeri(0),goluri_date(0),goluri_primite(0),puncte(0) {}
Echipa::Echipa(const Echipa& e):lot(e.lot),nume(e.nume),victorii(e.victorii),egaluri(e.egaluri),infrangeri(e.infrangeri),goluri_date(e.goluri_date),
    goluri_primite(e.goluri_primite),puncte(e.puncte) {}
Echipa& Echipa::operator =(Echipa e)
{
    swap(*this,e);
    return *this;
}
void swap(Echipa& e1,Echipa& e2)
{
    using std::swap;
    swap(e1.lot,e2.lot);
    swap(e1.nume,e2.nume);
    swap(e1.victorii,e2.victorii);
    swap(e1.egaluri,e2.egaluri);
    swap(e1.infrangeri,e2.infrangeri);
    swap(e1.goluri_date,e2.goluri_date);
    swap(e1.goluri_primite,e2.goluri_primite);
    swap(e1.puncte,e2.puncte);
}
const std::vector<std::shared_ptr<Jucator>> Echipa::getlot()const
{
    return lot;
}
void Echipa::adaugajucator(const std::shared_ptr<Jucator>&j)
{
    lot.push_back(j);
}
std::string Echipa::getnume()const
{
    return nume;
}
int Echipa::getvictorii()const
{
    return victorii;
}
int Echipa::getegaluri()const
{
    return egaluri;
}
int Echipa::getinfrangeri()const
{
    return infrangeri;
}
int Echipa::getgoluri_date()const
{
    return goluri_date;
}
int Echipa::getgoluri_primite()const
{
    return goluri_primite;
}
int Echipa::getpuncte()const
{
    return puncte;
}
int Echipa::getgolaveraj()const
{
    return goluri_date-goluri_primite;
}
int Echipa::getmeciuri()const
{
    return victorii+infrangeri+egaluri;
}
double Echipa::performanta_medie()const
{
    if(lot.empty())
        return 0;
    double sum=0;
    for(const auto&j:lot)
        sum+=j->calculPerformanta();
    return sum/lot.size();
}
std::shared_ptr<Jucator> Echipa::celmaibun(const std::vector<std::shared_ptr<Jucator>>& lot)
{
    if(lot.empty())
        return nullptr;
    auto thebest=lot[0];
    for(size_t i=1; i<lot.size(); i++)
        if(lot[i]->calculPerformanta()>thebest->calculPerformanta())
            thebest=lot[i];
    return thebest;
}
int Echipa::numar_atacanti()const
{
    int cnt=0;
    for(const auto& j:lot)
    {
        if(std::dynamic_pointer_cast<Atacant>(j))
            cnt++;
    }
    return cnt;
}
int Echipa::numar_mijlocasi()const
{
    int numar_mijlocasi=0;
    for(const auto&j:lot)
    {
        if(std::dynamic_pointer_cast<Mijlocas>(j))
            numar_mijlocasi++;
    }
    return numar_mijlocasi;
}
int Echipa::numar_fundasi()const
{
    int numar_fundasi=0;
    for(const auto&j:lot)
        if(std::dynamic_pointer_cast<Fundas>(j))
            numar_fundasi++;
    return numar_fundasi;
}
int Echipa::numar_portari()const
{
    int numar_portar=0;
    for(const auto&j:lot)
        if(std::dynamic_pointer_cast<Portar>(j))
            numar_portar++;
    return numar_portar;
}
void Echipa::afisarelot()const
{
    std::cout<<"Lotul echipei: "<<nume<<'\n';
    for(const auto& j:lot)
        std::cout<<"- "<<*j<<'\n';
    std::cout<<'\n';
}
void Echipa::actualizeazastatistici(int goluriinscrise,int goluriluate)
{
    goluri_date+=goluriinscrise;
    goluri_primite+=goluriluate;
    if(goluriinscrise>goluriluate)
    {
        victorii+=1;
        puncte+=3;
    }
    else if(goluriinscrise==goluriluate)
    {
        egaluri+=1;
        puncte+=1;
    }
    else
        infrangeri+=1;
}
Echipa Echipa::citeste_echipa(std::istream& f)
{
    std::string nume_echipa;
    int numar_jucatori;
    if(!(f>>nume_echipa>>numar_jucatori))
        throw Exceptie_date("Date echipa invalide");
    if(numar_jucatori<=0)
        throw Exceptie_date("Numar jucatori invalid");
    Echipa e(nume_echipa);
    for(int i=0; i<numar_jucatori; i++)
    {
        e.adaugajucator(Jucator::citestejuc(f));
    }
    return e;
}
