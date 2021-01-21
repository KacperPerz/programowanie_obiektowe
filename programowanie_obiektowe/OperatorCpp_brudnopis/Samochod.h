#include <string>
#include <iostream>

class Samochod{
    private:
        float pojemnosc_baku;
        float poziom_paliwa;
        unsigned int liczba_kilometrow;
        std::string model;
    public:
        Samochod();
        Samochod(std::string model, float pojemnosc_baku);
        float getPojemnoscBaku();
        void zatrab();
        void operator + (int q);
        
};