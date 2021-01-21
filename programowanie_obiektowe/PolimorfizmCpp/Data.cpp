#include "Data.h"
#include <iostream>
#include <string>
#include <ctime>


using namespace std;




void Data::setData(int dzien, int miesiac, int rok){
    time_t t=time(NULL);
    tm* timePtr=localtime(&t);

    int curr_year=timePtr->tm_year + 1900;
    if(1900<rok<=curr_year){
        
        if(1<=miesiac<=12){

            if(miesiac%2==1 && 1<dzien<=31){
                    this->rok = new int;
                    *this -> rok = rok;
                    this->miesiac = new int;
                    *this -> miesiac = miesiac;
                    this->dzien = new int;
                    *this -> dzien = dzien;
            }
            else if(miesiac==2 && 1<dzien<=28){
                    this->rok = new int;
                    *this -> rok = rok;
                    this->miesiac = new int;
                    *this -> miesiac = miesiac;
                    this->dzien = new int;
                    *this -> dzien = dzien;    
            }
            
            else if( miesiac==4||miesiac==6||miesiac==8||miesiac==10||miesiac==12 && 1<dzien<=30){
                    this->rok = new int;
                    *this -> rok = rok;
                    this->miesiac = new int;
                    *this -> miesiac = miesiac;
                    this->dzien = new int;
                    *this -> dzien = dzien;
            }
            else{
                cout<<"Zle podany dzien dla danego miesiaca\n";
            }

            
        }
        else{
            cout<<"Zle podany miesiac\n";
        }
    }
    else{
        cout<<"Zle podany rok\n";
    }
}

string Data::getData(){
    if(dzien !=nullptr && miesiac != nullptr && rok != nullptr){
        return "Data:"+to_string(*this->dzien) + "." +  to_string(*this->miesiac) + "." + to_string(*this->rok);
    }
    else{
        return "Nie podano daty";
    }
}



Data::Data():dzien(nullptr),miesiac(nullptr), rok(nullptr){}

Data::~Data(){
    if(dzien != nullptr){
        delete dzien;
    }
    if(miesiac != nullptr){
        delete miesiac;
    }
    if(rok != nullptr){
        delete rok;
    }
}

Data::Data(const Data &d){
    if(d.dzien){
        this -> dzien = new int;
        *this -> dzien = *d.dzien;
    }else{
        this-> dzien = nullptr;
    }
    if(d.miesiac){
        this->miesiac = new int;
        *this->miesiac = *d.miesiac;
    }else{
        this->miesiac = nullptr;
    }
    if(d.rok){
        this->rok = new int;
        *this->rok  = *d.rok;
    }else{
        this->rok = nullptr;
    }
    

}
Data::Data(Data &&d):dzien(d.dzien), miesiac(d.miesiac), rok(d.rok){}

Data::Data(int r): dzien(nullptr), miesiac(nullptr){
    this->rok = new int;
    *this->rok = r;
}


