#ifndef DECORATOR_H_INCLUDED
#define DECORATOR_H_INCLUDED

#include "Jucator.h"
#include <string>

class Decorator:public Jucator
{
    protected:
    std::shared_ptr<Jucator> jucator;
    public:
    Decorator(std::shared_ptr<Jucator> j):Jucator(*j),jucator(j){}
    void afisare(std::ostream& out)const override
    {
        jucator->afisare(out);
    }
     std::string pozitie() const override
    {
        return jucator->pozitie();
    }

    double calculPerformanta() const override
    {
        return jucator->calculPerformanta();
    }
};

#endif
