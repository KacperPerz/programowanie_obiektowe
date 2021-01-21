#include "Wezel.h"
#include <memory>
#include <iostream>
using namespace std;

int main() {
    for(int i=0 ; i<10 ; i++) {
        //unique_ptr<Wezel>(new Wezel()); //10x destrukcja obiektu
        //shared_ptr<Wezel> w1 = make_shared<Wezel>(); takze wyswietla sie 10x napis "destrukcja obiektu", chociaz internet glosi, iz shared_ptr nie pozwala na niszczenie obiektu
        shared_ptr<Wezel> w1 = make_shared<Wezel>();
        shared_ptr<Wezel> w2 = make_shared<Wezel>();
        w2->next = w1;
        w1->next = w2;
        //po dodaniu linijek 10-13 nie wyswietla sie juz informacja o destrukcji obiektu
    }
    

    //w c++ pamiec jest zwalniana w chwili kiedy do obiektu nie ma referencji, obiekt tymczasowy jest niszczony
    //w javie takie obiekty zbierane sa przez garbage collector
    return 0;
}