#include "Etapa.h"
#include <iostream>

Etapa::Etapa(int nr):nr(nr) {}
void Etapa::adauga_meci(const Meci& m)
{
    meciuri.push_back(m);
}
void Etapa::simuleaza_etapa()
{
    std::cout<<"=========Rezultate etapa "<<nr<<"============="<<'\n';
    for(auto& meci:meciuri)
    {
        meci.simuleazameci();
        meci.afiseaza_rezultat();
    }
    std::cout<<'\n';
}
void Etapa::afisare_program()const
{
    for(const auto& meci:meciuri)
    {
        meci.afisare_program();
    }
}
void Etapa::afisare_rezultat()const
{
    std::cout<<"Rezultate etapa "<<nr<<":"<<'\n';
    std::cout<<'\n';
    for(const auto& meci:meciuri)
    {
        meci.afiseaza_rezultat();
    }
    std::cout<<'\n';
}
