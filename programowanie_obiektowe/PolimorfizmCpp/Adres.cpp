#include "Adres.h"
#include <iostream>
#include <string>


using namespace std;

void Adres::setAdres(string ul, int numer, string miasto){
    this->miasto = new string;
    *this -> miasto = miasto;
    this->ul = new string;
    *this->ul = ul;
    this->nr = new int;
    *this -> nr = numer;
}

string Adres::getAdres(){
    if(ul!=nullptr && nr!=nullptr && miasto !=nullptr ){
        return "Ul. " + *this->ul + " nr. " +  to_string(*this->nr) + " w mieście: " + *this->miasto;
    }else{
        return "Obiekt nie ma adresu";
    }
}



Adres::Adres():ul(nullptr), nr(nullptr), miasto(nullptr){}

Adres::~Adres(){
    if(ul != nullptr){
        delete ul;
    }
    if(nr != nullptr){
        delete nr;
    }
    if(miasto != nullptr){
        delete miasto;
    }

}

Adres::Adres(const Adres &a){
    if(a.ul){
        this->ul = new string;
        *this->ul = *a.ul;
    }else{
        this->ul=nullptr;
    }
    if(a.nr){
        this->nr = new int;
        *this->nr = *a.nr;
    }else{
        this->nr = nullptr;
    }
    if(a.miasto){
         this->miasto = new string;
        *this->miasto = *a.miasto;
    }else{
        this->miasto = nullptr;
    }

   
   
}
        
Adres::Adres(Adres &&a):ul(a.ul), nr(a.nr), miasto(a.miasto){}
Adres::Adres(string miasto):ul(nullptr), nr(nullptr) {
    this->miasto = new string;
    *this-> miasto = miasto;
}    
