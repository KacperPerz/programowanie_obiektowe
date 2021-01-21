#include "Osoba.h"
#include <iostream>
#include <string>

using namespace std;


void Osoba::setImieNazwisko(string s){
    this->imie_nazwisko = new string;
    *this->imie_nazwisko = s;
}

string Osoba::getImieNazwisko(){
    return *this->imie_nazwisko;
}

void Osoba::przedstaw(){
    cout << this->getImieNazwisko() << endl;
    cout << this->getData()<<endl;
    cout << this->getAdres()<<endl;
}


Osoba::Osoba():imie_nazwisko(nullptr),Data(),Adres(){}

Osoba::~Osoba(){
    if(imie_nazwisko != nullptr){
        delete imie_nazwisko;
    }
}

Osoba::Osoba(const Osoba &o):Data(o), Adres(o){
    if(o.imie_nazwisko){
         this->imie_nazwisko = new string;
        *this->imie_nazwisko = *o.imie_nazwisko;
    }else{
        this->imie_nazwisko = nullptr;
    }
    
}

Osoba::Osoba(Osoba &&o):imie_nazwisko(o.imie_nazwisko),Data(o), Adres(o){}
        
Osoba::Osoba(string s){
    this->imie_nazwisko = new string;
    *this->imie_nazwisko = s;
}