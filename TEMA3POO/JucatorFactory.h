#ifndef JUCATORFACTORY_H_INCLUDED
#define JUCATORFACTORY_H_INCLUDED


#include <memory>
#include <string>
#include "Jucator.h"
#include "Atacant.h"
#include "Mijlocas.h"
#include "Fundas.h"
#include "Portar.h"
#include "Exceptii.h"

class JucatorFactory
{
public:
   static std::shared_ptr<Jucator> creeaza_jucator(const std::string& pozitie,const std::string& nume,int nr_tricou,double rating,std::istream& f)
   {
        if(pozitie=="Portar")
    {
        int reflexe,joc_picior,pozitionare,plonjon;
        if(!(f>>reflexe>>joc_picior>>pozitionare>>plonjon))
            throw Exceptie_date("Date portar invalide!");
        return std::make_shared<Portar>(nume,nr_tricou,rating,reflexe,joc_picior,pozitionare,plonjon);
    }

    if(pozitie=="Fundas")
    {
        int viteza,aparare,fizic;
        if(!(f>>viteza>>aparare>>fizic))
            throw Exceptie_date("Date fundas invalide!");
        return std::make_shared<Fundas>(nume,nr_tricou,rating,viteza,aparare,fizic);
    }
    if(pozitie=="Mijlocas")
    {
        int viteza,precizie_pase,demarcare;
        if(!(f>>viteza>>precizie_pase>>demarcare))
            throw Exceptie_date("Date mijlocas invalide!");
        return std::make_shared<Mijlocas>(nume,nr_tricou,rating,viteza,precizie_pase,demarcare);
    }

    if(pozitie=="Atacant")
    {
        int viteza,sut,dribling;
        if(!(f>>viteza>>sut>>dribling))
            throw Exceptie_date("Date atacant invalide!");
        return std::make_shared<Atacant>(nume,nr_tricou,rating,viteza,sut,dribling);
    }
    throw Exceptie_pozitie(pozitie);
   }
};

#endif
