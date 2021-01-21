#pragma once
#include "Osoba.h"
#include <iostream>
#include <string>

using namespace std;

class FabrykaOsob{
    public:
        virtual Osoba* utworz() = 0;
};