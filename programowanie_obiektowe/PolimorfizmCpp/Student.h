#pragma once
#include <iostream>
#include <string>
#include <map>

#include "Osoba.h"


using namespace std;

class Student: public Osoba{
    private:
        map<string, int> *oceny;
    public:
        Student();
        ~Student();
        void addOcena(string, int);
        string getOcena(string);
        void getOceny();
        void przedstaw();
        
        Student(const Student &);
        Student(Student &&);
        
};