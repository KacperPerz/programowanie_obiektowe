#pragma once
#include <iostream>
#include <string>

using namespace std;

class Adres{
    private:
        string *ul; //ulica
        int *nr; //numer domu
        string *miasto;
    public:
        void setAdres(string, int, string);
        string getAdres();
        Adres();
        ~Adres();
        Adres(const Adres &);
        Adres(Adres &&);
        Adres(string);
        

};