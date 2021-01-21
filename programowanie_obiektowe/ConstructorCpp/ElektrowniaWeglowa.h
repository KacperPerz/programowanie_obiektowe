#include "Logger.h"
#include "Stopper.h"
#include <iostream>
#include <string>
using namespace std;

//zastosowano dziedzieczenie prywatne, tak aby metod klasy Logger mozna bylo uzywac jedynie poprzez metody klasy ElektrowniaWeglowa
//aby mozna bylo korzystac z metod klasy Logger z poziomu main'a nalezaloby dopisac po dwukropku formule "public"
class ElektrowniaWeglowa : Logger, public Stopper{
    private:
        double* maxIloscWegla; //w tonach kg
        double* stanMagazynowyWegla;
        double* sprawnoscElektrowni;
        unsigned short* liczbaPracownikow;
        int* pensjaPracownika;
        
    public:
        
        ElektrowniaWeglowa();
        ElektrowniaWeglowa(const ElektrowniaWeglowa &e);
        ElektrowniaWeglowa(int pensjaPracownika);
        ElektrowniaWeglowa(ElektrowniaWeglowa&& el);
        ~ElektrowniaWeglowa() {
            if(this->maxIloscWegla != nullptr)
                delete  maxIloscWegla;
            if(this->stanMagazynowyWegla != nullptr)
                delete stanMagazynowyWegla;
            if(this->liczbaPracownikow != nullptr)
                delete liczbaPracownikow;
            if(this->sprawnoscElektrowni != nullptr)
                delete sprawnoscElektrowni;
            if(this->pensjaPracownika != nullptr)
                delete pensjaPracownika;
        }
        void setMaxIloscWegla();
        double getMaxIloscWegla();
        void setSprawnoscElektrowni();
        double getSprawnoscElektrowni();
        void setStanMagazynowyWegla();
        double getStanMagazynowyWegla();
        void setLiczbaPracownikow();
        unsigned short getLiczbaPracownikow() const;
        void setPensjaPracownika();
        int getPensjaPracownika();
        void zwolnijPracownikow();
        void addWegielDoMagazynu();
        void przerzucWegiel();

};