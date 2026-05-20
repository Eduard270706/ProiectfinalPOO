#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "Jucator.h"
#include "Exceptii.h"
#include "Campionat.h"

void alege_optiunea()
{
    std::cout<<"========Meniu optiuni========"<<'\n';
    std::cout<<" 0 pentru:Iesire program!\n";
    std::cout<<" 1 pentru:Generarea programelor campionatelor(obligatoriu doar o data)!\n";
    std::cout<<" 2 pentru:Simularea unei etape din fiecare campionat!\n";
    std::cout<<" 3 pentru:Simularea tuturor etapelor din fiecare campionat!\n";
    std::cout<<" 4 pentru:Afisarea clasamentelor din fiecare liga!\n";
    std::cout<<" 5 pentru:Afisarea rezultatelor etapelor din fiecare liga!\n";
    std::cout<<" 6 pentru:Afisarea numar obiecte de tip jucator!\n";
    std::cout<<" 7 pentru:Afisarea loturilor echipelor pentru un anumit campionat citit de la tastatura!\n";
    std::cout<<" 8 pentru:Afisarea celui mai bun jucator din fiecare echipa pentru un anumit campionat citit de la tastatura!\n";
    std::cout<<" 9 pentru:Afisare numar jucatori pe o anumita pozitie din fiecare campionat!\n";
    std::cout<<" 10 pentru:Sortarea jucatorilor dupa performanta!\n";
}
int main()
{
    ///Cand spune citire campionat sa se introduca:PREMIER_LEAGUE SAU LALIGA(EXACT ASA CUM SUNT SCRISE AICI)
    srand(time(nullptr));
    try
    {
        std::ifstream f("date.in");
        if(!f)
            throw Exceptie_citirefisier();
        std::vector<Campionat> campionate;
        int nr_campionate;
        if(!(f>>nr_campionate))
            throw Exceptie_date("Numar campionate invalid");
        for(int i=0; i<nr_campionate; i++)
        {
            Campionat c=Campionat::citeste_campionat(f);
            campionate.push_back(c);
        }
        int optiune;
        do
        {
            alege_optiunea();
            std::cout<<'\n';
            std::cout<<"Alege optiunea pe care o doresti:";
            if(!(std::cin>>optiune))
                throw Exceptie_date("Optiune meniu invalida!");
            std::cout<<'\n';
            switch(optiune)
            {
            case 1:
            {
                for(auto&c:campionate)
                {
                    c.genereaza_program();
                    c.afiseaza_rezultate();
                }

                break;
            }
            case 2:
            {
                for(auto&c:campionate)
                {
                    c.simuleaza_o_etapa();
                    std::cout<<'\n';
                }
                std::cout<<"Etapa a fost jucata!"<<'\n';
                std::cout<<'\n';
                break;
            }
            case 3:
            {
                for(auto& c:campionate)
                {
                    c.simuleaza_campionatul();
                }
                std::cout<<"Toate etapele din fiecare campionat au fost jucate!"<<'\n';
                std::cout<<'\n';
                break;
            }
            case 4:
            {
                for(const auto& c:campionate)
                {
                    c.afiseaza_clasament();
                    std::cout<<'\n';
                }
                break;
            }
            case 5:
            {
                for(auto& c:campionate)
                {
                    c.afiseaza_rezultate();
                    std::cout<<'\n';
                }
                break;
            }
            case 6:
            {
                std::cout<<"Numarul de jucatori este:"<<Jucator::nr_juc()<<'\n';
                std::cout<<'\n';
                break;
            }
            case 7:
            {
                std::string nume;
                std::cout<<"Alege campionatul: ";
                std::cin>>nume;
                int ok=0;
                for(const auto& c:campionate)
                    if(c.get_nume_campionat()==nume)
                    {
                        c.afisare_lot_echipe();
                        ok=1;
                    }
                if(ok==0)
                    std::cout<<"Campionat citit gresit"<<'\n';
                std::cout<<'\n';
                break;
            }
            case 8:
            {
                std::string nume;
                std::cout<<"Alege campionatul: ";
                std::cin>>nume;
                int ok=0;
                for(const auto&c:campionate)
                    if(c.get_nume_campionat()==nume)
                    {
                        ok=1;
                        c.afiseaza_cel_mai_bun_jucator_echipe();
                    }
                if(ok==0)
                    std::cout<<"Campionat citit gresit"<<'\n';
                std::cout<<'\n';
                break;
            }
            case 9:
            {
                for(const auto& c:campionate)
                {
                    c.afisare_pozitie_jucatori_echipa_fiecare_campionat();
                    std::cout<<'\n';
                }
                break;
            }
            case 10:
            {
                std::string nume;
                std::cout << "Alege campionatul: ";
                std::cin >> nume;
                int ok = 0;
                for(auto& c:campionate)
                {
                    if(c.get_nume_campionat()==nume)
                    {
                        ok = 1;

                        for(auto& e:c.getechipe())
                        {
                            sorteaza_dupa_performanta(e.getlot());

                            std::cout << "Lot sortat pentru echipa: "
                                      << e.getnume() << '\n';

                            e.afisarelot();
                        }
                    }
                }
                if(ok==0)
                    std::cout<<"Campionat citit gresit\n";

                std::cout<<'\n';

                break;
            }
            case 0:
            {
                std::cout<<"Program realizat cu succes!\n";
                break;
            }
            default:
            {
                std::cout<<"Nu exista aceasta optiune!\n";
                break;
            }
            }
        }
        while(optiune!=0);
    }
    catch(const Exceptie_campionat& e)
    {
        std::cout<<"Eroare: "<<e.what()<<'\n';
    }
    catch(const std::exception& e)
    {
        std::cout<<"Eroare normala: "<<e.what()<<'\n';
    }
    return 0;

}
