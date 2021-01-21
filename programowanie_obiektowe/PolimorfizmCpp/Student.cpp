#include <iostream>
#include <string>

#include "Student.h"

using namespace std;

Student::Student(): oceny(nullptr),Osoba(){
    oceny=new map<string,int>();
};
Student::~Student(){
    if(oceny != nullptr){
        delete oceny;
    }
}

void Student::addOcena(string przedmiot, int ocena){
    //oceny=new map<string,int>();
    if(2<=ocena <=5){
        (*this->oceny)[przedmiot] = ocena;
    } 
}
 
string Student::getOcena(string przedmiot){
    if((*this->oceny)[przedmiot]){
        return "Z przedmiotu: " + przedmiot + " ocena: " + to_string((*this->oceny)[przedmiot]);
    }
    else{
        return przedmiot + ": brak oceny";
    }
}

void Student::getOceny(){
    cout << "Oceny: "<< endl;
    for (map<string,int>::const_iterator iter = (*this->oceny).begin(); iter != (*this->oceny).end(); iter++){
        cout << iter->first << ": " << iter->second<< endl; 
        }
}

void Student::przedstaw(){
    if(imie_nazwisko !=nullptr){
        cout << this->getImieNazwisko() << endl;
    }else{
        cout << "Zle podano imie i nazwisko studenta"<<endl;
    }
    cout <<  this->getData()<<endl;
    cout <<  this->getAdres()<<endl;
    //this->getOceny();
    if(oceny!=nullptr) {    
        cout << "Oceny: "<< endl;
        for (map<string,int>::const_iterator iter = (*this->oceny).begin(); iter != (*this->oceny).end(); iter++){
            cout << iter->first << ": " << iter->second<< endl; 
        }
    }
    else{cout<<"Student nie ma ocen" <<endl;}
}




Student::Student(const Student &s):Osoba(s){
    if(s.oceny){
        this->oceny = new map<string, int>;
        *this->oceny = *s.oceny;
    }else{
        this->oceny = nullptr;
    }
    
}
Student::Student(Student &&s):oceny(s.oceny),Osoba(s){}
