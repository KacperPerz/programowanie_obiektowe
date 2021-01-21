#include "FabrykaPracownikow.h"
#include <iostream>
#include <string>


using namespace std;

Pracownik* FabrykaPracownikow::utworz(){
    Pracownik *p = new Pracownik();
    return p;
}