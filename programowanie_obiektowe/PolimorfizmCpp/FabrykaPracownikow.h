#pragma once
#include "Pracownik.h"
#include "FabrykaOsob.h"
#include <iostream>
#include <string>

using namespace std;

class FabrykaPracownikow: public FabrykaOsob{
    public:
        Pracownik* utworz();
};