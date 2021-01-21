#pragma once

#include <iostream>
#include <string>

#include "Adres.h"
#include "Data.h"

using namespace std;


class Osoba :public Adres, public Data{
    protected:
        string *imie_nazwisko;
    public:
        Osoba();
        virtual ~Osoba();
        void setImieNazwisko(string);
        string getImieNazwisko();
        Osoba(const Osoba &);
        Osoba(Osoba &&);
        Osoba(string);
        //void przedstaw();
        virtual void przedstaw()=0;
};