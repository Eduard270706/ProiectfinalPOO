#ifndef JUCATOR_H_INCLUDED
#define JUCATOR_H_INCLUDED

#include <string>
#include <memory>
#include <iostream>

class Jucator
{
protected:
    std::string nume;
    int nr_tricou;
    double rating;
    static int numar_jucatori;
public:
    Jucator(const std::string& nume,const int nr_tricou,const double rating);
    Jucator(const Jucator& other);
    Jucator& operator=(const Jucator& j);
    virtual double calculPerformanta() const=0;
    virtual std::string pozitie()const=0;
    virtual ~Jucator();
    static int nr_juc();
    virtual void afisare(std::ostream& out)const;
    friend std::ostream& operator <<(std::ostream& out,const Jucator& j);
    static std::shared_ptr<Jucator> citestejuc(std::istream& f);

};


#endif
