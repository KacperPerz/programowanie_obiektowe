#pragma once
#include <iostream>
#include <string>

using namespace std;


class Data{
    private:
        int *dzien;
        int *miesiac;
        int *rok;
    public:
        void setData(int, int, int);
        string getData();

        Data();
        ~Data();
        Data(const Data &);
        Data(Data &&);
        Data(int);
};