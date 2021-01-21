#include "ElektrowniaWeglowa.h"
#include <iostream>
using namespace std;

void foo(ElektrowniaWeglowa e);
void bar(const ElektrowniaWeglowa &e);
void baz(ElektrowniaWeglowa &e);
void qux(ElektrowniaWeglowa &&e);


int main() {
    ElektrowniaWeglowa e;
    e.setStanMagazynowyWegla();
    e.setLiczbaPracownikow();
    e.setSprawnoscElektrowni();
    e.setMaxIloscWegla();
    e.setPensjaPracownika();

    //e.addWegielDoMagazynu();
    e.zwolnijPracownikow();

    ElektrowniaWeglowa *e2 = new ElektrowniaWeglowa(e);
    cout<<e2->getLiczbaPracownikow()<<endl;
    e2->zwolnijPracownikow();
    cout<<e.getLiczbaPracownikow();

    for(int i=0 ; i<10 ; i++) {
        
    }
    
}

//praca na kopii obiektu
void foo(ElektrowniaWeglowa e) {
    cout << "W tej fabryce pracuje " << e.getLiczbaPracownikow() << " pracownikow." << endl;
}
//praca na obiekcie i brak mozliwosci jego zmiany poprzez funkcje
void bar(const ElektrowniaWeglowa &e) {
    cout << "W tej fabryce pracuje " << e.getLiczbaPracownikow() << " pracownikow." << endl;
}
//praca na obiekcie i mozliwosc jego zmiany poprzez funkcje
void baz(ElektrowniaWeglowa &e) {
    cout << "W tej fabryce pracuje " << e.getLiczbaPracownikow() << " pracownikow." << endl;
}
//obiekt tworzony lokalnie (np. w parametrze funkcji) celem utworzenia r-wartosci
void qux(ElektrowniaWeglowa &&e) {
    cout << "W tej fabryce pracuje " << e.getLiczbaPracownikow() << " pracownikow." << endl;
}

//w Javie nie ma wielokrotnego dziedziczenia, można za to w jednej klasie stworzyć obiekty różnych klas i pracować na tych obiektach
//W c++ istnieje ryzyko, że nazwy atrybutów klas dziedziczonych powtarzają się, przez co klasa nadrzędna może mieć problem z odwoływaniem się
//do poszczególnych pól