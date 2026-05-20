#ifndef EXCEPTII_H_INCLUDED
#define EXCEPTII_H_INCLUDED

#include <exception>
#include <string>

class Exceptie_campionat:public std::exception
{
    std::string mesaj;
public:
    explicit Exceptie_campionat(const std::string& m):mesaj(m){}
    const char* what() const noexcept override
    {
        return mesaj.c_str();
    }
};

class Exceptie_citirefisier:public Exceptie_campionat
{
public:
    Exceptie_citirefisier():Exceptie_campionat("Fisierul nu a putut fi deschis!"){}
};

class Exceptie_date :public Exceptie_campionat
{
public:
    explicit Exceptie_date(const std::string& m):Exceptie_campionat("Date invalide:"+m){}
};

class Exceptie_pozitie: public Exceptie_campionat
{
public:
    explicit Exceptie_pozitie(const std::string& p):Exceptie_campionat("Pozitie invalida: "+p){}
};


#endif
