#include "Pracownik.h"
#include "Osoba.h"
#include <iostream>
#include <string>


using namespace std;



Pracownik::Pracownik():przedmioty(nullptr),Osoba(){ przedmioty=new map<string,int>();}
Pracownik::~Pracownik(){
    if(przedmioty !=nullptr){
        delete przedmioty;
    }
}

void Pracownik::addPrzedmiot(string przedmiot){
    if((*this->przedmioty).find(przedmiot) == (*this->przedmioty).end()){
        (*this->przedmioty)[przedmiot];
    }else{
        cout << "ten przedmiot: " <<przedmiot <<" jest juz przypisany" <<endl;
    }
}

void Pracownik::usunPrzedmiot(string przedmiot){
    if((*this->przedmioty).find(przedmiot) != (*this->przedmioty).end()){
        (*this->przedmioty).erase(przedmiot);
    }else{
       cout << przedmiot <<" nie ma takiego przedmiotu" <<endl;
    }
}

void Pracownik::sprawdzPrzedmiot(string przedmiot){
    if((*this->przedmioty).find(przedmiot) != (*this->przedmioty).end()){
        cout << "Pracownik prowadzi ten przedmiot: " << przedmiot <<endl;
    }else{
        cout << "Pracownik nie prowadzi tego przedmiotu: " <<przedmiot <<endl;
    }
}
void Pracownik::przedstaw(){
    if(imie_nazwisko !=nullptr){
        cout << this->getImieNazwisko() << endl;
    }else{
        cout << "Nie podano imienia i nazwiska"<<endl;
    }
    cout<< this->getData()<<endl;
    cout <<this->getAdres()<<endl;
    cout << "Przedmioty pracownika: ";
    if(przedmioty!=nullptr){
        for (map<string,int>::const_iterator iter = (*this->przedmioty).begin(); iter != (*this->przedmioty).end(); iter++){
        cout << iter->first << " ";
        }
    }else{
        cout<<"Brak przedmiotow tego pracownika"<<endl;
    }
}
void Pracownik::listaPrzedmiotow(){
    cout << "Przedmioty pracownika: ";
    if(przedmioty!=nullptr){
        for (map<string,int>::const_iterator iter = (*this->przedmioty).begin(); iter != (*this->przedmioty).end(); iter++){
        cout << iter->first << " ";
        }
    }else{
        cout<<"Brak przedmiotow tego pracownika"<<endl;
    }
}

Pracownik::Pracownik(const Pracownik &p):Osoba(p){
    if(p.przedmioty){
        this->przedmioty  = new map<string, int>;
        *this->przedmioty = *p.przedmioty;
    }else{
        this->przedmioty = nullptr;
    }
    
}
Pracownik::Pracownik(Pracownik &&p):przedmioty(p.przedmioty), Osoba(p){}