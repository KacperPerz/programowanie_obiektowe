#include "Samochod.h"
using namespace std;

Samochod::Samochod() {
    pojemnosc_baku = 60;
    poziom_paliwa = 30;
    liczba_kilometrow = 150000;
    model = "fiat";
}
Samochod::Samochod(string model, float pojemnosc_baku) {
    this->model = model;
    this->pojemnosc_baku = pojemnosc_baku;
    this->poziom_paliwa = pojemnosc_baku/2;
    this->liczba_kilometrow = 150000;
}
void Samochod::zatrab() {
    cout << "tutuu" << endl;
}
float Samochod::getPojemnoscBaku() {
    return pojemnosc_baku;
}
void operator + (Samochod & s, int q) {
    for(int i=0 ; i<q; i++) {
        s.zatrab();
    }
};