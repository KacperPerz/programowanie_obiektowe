#pragma once
#include "Student.h"
#include "FabrykaOsob.h"
#include <iostream>
#include <string>

using namespace std;

class FabrykaStudentow: public FabrykaOsob{
    public:
        Student* utworz();
};