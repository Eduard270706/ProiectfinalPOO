#ifndef JUCATORFORMA_H_INCLUDED
#define JUCATORFORMA_H_INCLUDED

#include "Decorator.h"

class JucatorForma:public Decorator
{
public:
    JucatorForma(std::shared_ptr<Jucator> j)
        :Decorator(j){}

    double calculPerformanta() const override
    {
        double p = jucator->calculPerformanta();
        if(p>=90)
            return p+15;
        else if(p>=75)
            return p+10;
        else
            return p+6;
    }

    void afisare(std::ostream& out) const override
    {
        jucator->afisare(out);
        out<<" In forma";
    }
};

#endif
