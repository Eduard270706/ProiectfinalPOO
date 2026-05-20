#include "Campionat.h"
#include <algorithm>
#include <iomanip>
#include "Exceptii.h"


Campionat::Campionat(const std::string& nume_campionat):nume_campionat(nume_campionat),etapa_curenta(0) {}
void Campionat::adauga_echipa(const Echipa<Jucator>& e)
{
    echipe.push_back(e);
}
std::string Campionat::get_nume_campionat()const
{
    return nume_campionat;
}
void Campionat::genereaza_program()
{
    etape.clear();
    etapa_curenta=0;
    int n=static_cast<int>(echipe.size());
    std::vector<Echipa<Jucator>*> lista;
    for(auto& echipa:echipe)
        lista.push_back(&echipa);
    if(n%2==1)
    {
        lista.push_back(nullptr);
        n++;
    }
    int etape_tur=n-1;
    int meciuri_etapa=n/2;
    std::vector<Echipa<Jucator>*>rotatie=lista;
    for(int etapa_index=1; etapa_index<=etape_tur; etapa_index++)
    {
        Etapa etapa(etapa_index);
        for(int i=0; i<meciuri_etapa; i++)
        {
            Echipa<Jucator>* echipa1=rotatie[i];
           Echipa<Jucator>* echipa2=rotatie[n-i-1];
            if(echipa1!=nullptr && echipa2!=nullptr)
            {
                if(etapa_index%2==0)
                    etapa.adauga_meci(Meci(echipa1,echipa2));
                else
                    etapa.adauga_meci(Meci(echipa2,echipa1));
            }
        }
        etape.push_back(etapa);
        std::vector<Echipa<Jucator>*>noua_rotatie;
        noua_rotatie.push_back(rotatie[0]);
        noua_rotatie.push_back(rotatie[n-1]);
        for(int i=1; i<n-1; i++)
            noua_rotatie.push_back(rotatie[i]);
        rotatie=noua_rotatie;
    }
    rotatie=lista;
    for(int etapa_index=1; etapa_index<=etape_tur; etapa_index++)
    {
        Etapa etapa(etapa_index+etape_tur);
        for(int i=0; i<meciuri_etapa; i++)
        {
            Echipa<Jucator>* echipa1=rotatie[i];
            Echipa<Jucator>* echipa2=rotatie[n-1-i];
            if(echipa1!=nullptr && echipa2!=nullptr)
            {
                if(etapa_index%2==0)
                    etapa.adauga_meci(Meci(echipa2,echipa1));
                else
                    etapa.adauga_meci(Meci(echipa1,echipa2));
            }
        }
        etape.push_back(etapa);
        std::vector<Echipa<Jucator>*>noua_rotatie;
        noua_rotatie.push_back(rotatie[0]);
        noua_rotatie.push_back(rotatie[n-1]);
        for(int i=1; i<n-1; i++)
            noua_rotatie.push_back(rotatie[i]);
        rotatie=noua_rotatie;
    }

}
std::vector<Echipa<Jucator>>& Campionat::getechipe()
{
    return echipe;
}
void Campionat::simuleaza_o_etapa()
{
    std::cout<<"\n==========="<<nume_campionat<<"============"<<'\n';
    std::cout<<'\n';
    if(etapa_curenta>=static_cast<int>(etape.size()))
        std::cout<<"Campionatul s a terminat!Toate etapele au fost jucate!"<<'\n';
    else
    {
        etape[etapa_curenta].simuleaza_etapa();
        etapa_curenta++;
    }
}
void Campionat::afisare_lot_echipe()const
{
    std::cout<<"\n==========="<<nume_campionat<<"============="<<'\n';
    for(const auto&e:echipe)
    {
        e.afisarelot();
        std::cout<<'\n';
    }
}
void Campionat::afiseaza_cel_mai_bun_jucator_echipe()const
{
    std::cout<<"Cei mai buni jucatori din campionatul "<<nume_campionat<<":"<<'\n';
    std::cout<<'\n';
    for(const auto& e:echipe)
    {
        std::cout<<e.getnume()<<":";
        std::shared_ptr<Jucator>j=Echipa<Jucator>::celmaibun(e.getlot());
        if(j!=nullptr)
        {
            std::cout<<*j<<'\n';
            std::cout<<'\n';
        }
        else
        {
            std::cout<<"Nu exista"<<'\n';
            std::cout<<'\n';
    }
    }
}
void Campionat::afisare_pozitie_jucatori_echipa_fiecare_campionat()const
{
    std::cout<<"=============="<<nume_campionat<<"==========="<<'\n';
    for(const auto& e:echipe)
    {
        std::cout<<e.getnume()<<": "<<"Atacanti:"<<e.numar_atacanti()<<" Mijlocasi:"<<e.numar_mijlocasi()<<" Fundasi:"<<e.numar_fundasi()<<" Portari:"<<e.numar_portari()<<'\n';
        std::cout<<'\n';
    }
}
void Campionat::simuleaza_campionatul()
{
    std::cout<<"\n==========="<<nume_campionat<<"============"<<'\n';
    std::cout<<'\n';
    while(etapa_curenta<static_cast<int>(etape.size()))
        simuleaza_o_etapa();
}
void Campionat::afiseaza_rezultate()
{
    std::cout<<"\n==========="<<nume_campionat<<"============"<<'\n';
    std::cout<<std::endl;
    for(const auto&etapa:etape)
        etapa.afisare_rezultat();
}
void Campionat::afiseaza_clasament()const
{
    std::cout<<"============CLASAMENT "<<nume_campionat<<" ============="<<'\n';
    std::vector<Echipa<Jucator>>clasament=echipe;
    std::sort(clasament.begin(),clasament.end(),[](const Echipa<Jucator>& e1,const Echipa<Jucator>& e2)
    {
        bool rezultat;
        if(e1.getpuncte()!=e2.getpuncte())
        {
            if(e1.getpuncte()>e2.getpuncte())
                rezultat=true;
            else
                rezultat=false;
            return rezultat;
        }
        if(e2.getgolaveraj()!=e1.getgolaveraj())
        {
            if(e1.getgolaveraj()>e2.getgolaveraj())
                rezultat=true;
            else
                rezultat=false;
            return rezultat;
        }
        if(e1.getgoluri_date()!=e2.getgoluri_date())
        {
            if(e1.getgoluri_date()>e2.getgoluri_date())
                rezultat=true;
            else
                rezultat=false;
            return rezultat;
        }
        return e1.getnume()<e2.getnume();
    });
    std::cout<<std::left<<std::setw(5)<<"LOC"<<std::setw(20)<<"ECHIPA"<<std::setw(5)<<"PCT"<<std::setw(5)<<"MJ"<<std::setw(5)<<"V"<<std::setw(5)<<"E"
             <<std::setw(5)<<"I"<<std::setw(5)<<"GV"<<'\n';
    int loc=1;
    for(const auto&echipa:clasament)
    {
        std::cout<<std::left<<std::setw(5)<<loc<<std::setw(20)<<echipa.getnume()<<std::setw(5)<<echipa.getpuncte()<<std::setw(5)<<echipa.getmeciuri()<<std::setw(5)<<echipa.getvictorii()<<std::setw(5)
                 <<echipa.getegaluri()<<std::setw(5)<<echipa.getinfrangeri()<<std::setw(5)<<echipa.getgolaveraj()<<'\n';
        loc++;
    }
}
Campionat Campionat::citeste_campionat(std::istream& f)
{
    std::string nume_campionat;
    int nr_echipe;
    if(!(f>>nume_campionat>>nr_echipe))
        throw Exceptie_date("Date campionat invalide!");
    if(nr_echipe<=0)
        throw Exceptie_date("Numar echipe invalid!");
    Campionat c(nume_campionat);
    for(int i=0; i<nr_echipe; i++)
    {
        c.adauga_echipa(Echipa<Jucator>::citeste_echipa(f));
    }
    return c;
}
