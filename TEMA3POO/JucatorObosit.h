#ifndef JUCATOROBOSIT_H_INCLUDED
#define JUCATOROBOSIT_H_INCLUDED


class JucatorObosit:public Decorator
{
public:
    JucatorObosit(std::shared_ptr<Jucator> j)
        :Decorator(j){}

    double calculPerformanta() const override
    {
        double p=jucator->calculPerformanta();
        if(p>=85)
            return p-7;
        else if(p>=70)
            return p-10;
        else
            return p-15;
    }

    void afisare(std::ostream& out) const override
    {
        jucator->afisare(out);
        out<<" Obosit";
    }
};

#endif
