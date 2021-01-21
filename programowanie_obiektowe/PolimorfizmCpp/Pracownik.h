#pragma once
#include "Osoba.h"
#include <iostream>
#include <string>
#include <map>


using namespace std;


class Pracownik: public Osoba{
    private:
        map<string, int> *przedmioty;
    public:
        Pracownik();
        ~Pracownik();
        void addPrzedmiot(string);
        void usunPrzedmiot(string);
        void sprawdzPrzedmiot(string);
        void przedstaw();
        void listaPrzedmiotow();
        Pracownik(const Pracownik &);
        Pracownik(Pracownik &&);
        
};