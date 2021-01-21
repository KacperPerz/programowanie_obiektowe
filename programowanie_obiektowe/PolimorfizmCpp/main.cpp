#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Osoba.h"
#include "Student.h"
#include "Pracownik.h"
#include "FabrykaOsob.h"
#include "FabrykaStudentow.h"
#include "FabrykaPracownikow.h"


using namespace std;

void foo(Osoba &o){
    o.przedstaw();
}
void bar(Osoba *o){
    o->przedstaw();
}

int main(){
    
    /*
    Osoba o1;
    o1.setImieNazwisko("Satoshi Nakamoto");
    o1.setAdres("Meiji-dori",7,"Tokyo");
    o1.setData(31,10,2008);
    o1.przedstaw();
    foo(o1);
    bar(&o1);
    */

    
    Student s;
    s.setImieNazwisko("Dawid Plaskowski");
    s.setData(16,2,2000);
    s.setAdres("Grunwaldzka",77,"Poznan");
    s.addOcena("Chemia",5);
    s.addOcena("Matematyka",5);
    //cout<<s.getOcena("Chemia")<<endl;
    //s.przedstaw();
    //foo(s); //zad 12 wywolana metoda przedstaw() z klasy Osoba. 
    //bar(&s); // to samo co dla foo(s)
    

    
    Pracownik p;
    p.setImieNazwisko("Aaa Bbb");
    p.addPrzedmiot("Informatyka");
    //p.sprawdzPrzedmiot("Informatyka");
    p.addPrzedmiot("Matematyka");
    //p.przedstaw();
    
    //foo(p); //zad 12 wywolana metoda przedstaw() z klasy Osoba. 
    //bar(&p); // to samo co dla foo(p)


    //foo(s);
    //bar(&s);
    //foo(p);
    //bar(&p);

    //zad 14: Po wpisaniu "virtual" przed metode przedstaw() klasy Osoba, klasy potomne Student, Pracownik wywoluja wlasne implementacje tej metody.
    //Ten dodatek powoduje, ze powstala metoda abstrakcyjna/wirtualna zyskuje swoja implementacje okreslona klasa, ktora odziedziczyle te metode. 
    

    /*
    Pracownik *p1 = new Pracownik;
    Osoba *o1 = static_cast<Osoba *>(p1);
    Osoba *o2 = static_cast<Pracownik *>(o1) ;
    Osoba *o3 = new Osoba; //object of abstract class type "Osoba" is not allowed: -- function "Osoba::przedstaw" is a pure virtual function
    
    Pracownik *p2 = static_cast<Pracownik *>(o3) ;
    //static_cast konwertuje wskaznik na klase pochodna obiektu na wskaznik obiektu klasy od ktorej klasa pochodna dziedziczyla i odwrotnie

    */

   /*
    Pracownik *p3 = new Pracownik ;
    Osoba *o4 = dynamic_cast<Osoba *>(p3 ) ;
    Pracownik *p4 = dynamic_cast<Osoba *>(o4 ) ; //a value of type "Osoba *" cannot be used to initialize an entity of type "Pracownik *
    //proba przekonwertowania klasy bazowwej na pochodna, gdzie nie kazdy obiekt dziedziczacy po klasie Osobie jest rowniez Pracownikiem
    */

   /*
    Osoba *o5 = new Osoba;
    Pracownik *p5  = dynamic_cast<Pracownik *> (o5);
    if(p5 = nullptr) cout << "Blad"<<endl;
    else p5->listaPrzedmiotow(); //segmentation fault
    //Ze strony https://en.cppreference.com/w/cpp/language/dynamic_cast:
    //"If the cast is successful, dynamic_cast returns a value of type new-type. If the cast fails and new-type is a pointer type, 
    //it returns a null pointer of that type. If the cast fails and new-type is a reference type, 
    //it throws an exception that matches a handler of type std::bad_cast.""

    //Nalezy zatem unikac porownywan dynamic_cast z nullptr, poniewaz nullptr jest zwracany jezeli zmienna na ktora rzutujemy jest wskaznikiem.
    //W innym przypadku jest ona obslugiwana przez wyjatek zwiazany z typem std::bad_cast
   */

    
    map<string,FabrykaOsob*> m;
    m["pracownik"]= new FabrykaPracownikow();
    m["student"]= new FabrykaStudentow();
    //kompiluje sie poprawnie, rzutowanie na wskaznik klasy osoba, pozwala stworzyc inne klasy dzidziczace po niej i przechowac je w kontenerze "map"
    
    vector<Osoba*> tablicaOsob;
    bool flaga=true;
    string currentCommand;
    while(flaga){
        cout<<" Stworz studenta - wpisz 'student'\n Stworz pracownika - wpisz 'pracownik' \n Zakoncz petle - wpisz 'end'\n"<<endl;
        cin >> currentCommand;
        if(currentCommand=="student" ||currentCommand=="pracownik" ){
            tablicaOsob.push_back(m[currentCommand]->utworz());
        }
        else if(currentCommand=="end"){
            flaga=false;
        }
        else{
            cout<<"Nieobslugiwana komenda\n"<<endl;
        }
    }

    for (auto const& i : tablicaOsob){
        i->przedstaw();
        cout<<endl;
    }
    //Z sukcesem mozna generowac nowe obiekty i wstawiac je do wektora tablicaOsob, metoda utworz tworza sie odpowiednie obiekty zadanej klasy z ustawionymi wartosciami na nullptr







    

}