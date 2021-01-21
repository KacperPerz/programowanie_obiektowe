#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
 


class Samochod{
    private:
        float pojemnosc_baku;
        float poziom_paliwa;
        unsigned int liczba_kilometrow;
        string model;
    
    public:
        //konstruktor bezparametrowy
        Samochod() {
            this->pojemnosc_baku = 60;
            this->poziom_paliwa = 30;
            this->liczba_kilometrow = 200000;
            model = "fiat";
        }
        
        //konstruktor przyjmujacy jako argument model samochodu oraz jego pojemnosc
        Samochod(const float pojemnosc_baku, string model) {
            this->poziom_paliwa = 10.0;
            this->liczba_kilometrow = 100;
            this->pojemnosc_baku = pojemnosc_baku;
            this->model = model;
        }

        Samochod& operator ++ () { // prefix ++, bez parametrów, zwraca referencję
            cout<<"prefix ++\n";
            this->zwieksz_kilometry(1);
            return *this;
        }
        Samochod operator ++ (int) { //postfix ++ , parametr, zwraca wartość
            cout<<"postfix ++\n";
            Samochod tmp = *this;
            this->zwieksz_kilometry(1);
            return tmp;
        }
        
        float getPojemnoscBaku() const{
            return pojemnosc_baku;
        }
        unsigned int getLiczbaKilometrow(){
            return liczba_kilometrow;
        }
        void zwieksz_kilometry(unsigned int q){
            this->liczba_kilometrow += q;
        }
        string odczytajNazwe(){
            return this->model;
        }
        void klakson() {
            cout << "turuu" << endl;
        }
        void operator + (int k) {
            for(int i=0 ; i<k ; i++) {
                klakson();
            }
        }
        operator bool() const {
            if((this->model != "") && (this->pojemnosc_baku > 0))
                return true;
            return false;
        }
        bool operator !() const {
            if(!((this->model != "") && (this->pojemnosc_baku > 0)))
                return true;
            return false;
        }
        //korzystamy z klasy ostream, ktora aby miec dostep do skladowych klasy Samochod, musi byc klasa zaprzyjazniona
        friend ostream & operator << (ostream &os, const Samochod &samochod) {
            os << samochod.model << " " <<samochod.poziom_paliwa<<"\n";
            return os;
        }
        //const to dodatkowe zabezpieczenie przed tym, aby nasza funkcja niczego nie zmieniala w parametrach obiektu
        bool operator < (const Samochod &samochod) const{
            return this->model < samochod.model;
        }
        bool operator|= (string model) {
            if(this->model == model)
                return true;
            return false;
        }
        void operator , (const Samochod &s) {
            cout << this->model << " " << s.model;
        }

};
struct cmp {
    bool operator() (const Samochod &a, const Samochod &b) const {
        return a.getPojemnoscBaku() < b.getPojemnoscBaku();
    }
};

int main(){
	// Samochod s1(123, "toyota");
	// cout<<s1.getLiczbaKilometrow()<<"\n";
	// s1++;
	// cout<<s1.getLiczbaKilometrow()<<"\n";
	// ++s1;
	// cout<<s1.getLiczbaKilometrow()<<"\n";
	// cout<<s1.getLiczbaKilometrow()<<"\n";
    // s1 + 2;

    // Samochod s2;
    // cout<<s2.odczytajNazwe();

    Samochod s1(123,"audi");
    Samochod s2(0, "bmw");
    Samochod s3(200, "");
    if(s1) {
        cout << "wartosc true 1" << endl;
    } if(!s1) {
        cout << "wartosc false 1" << endl;
    }if(s2) {
        cout << "wartosc true 2" << endl;
    } if(!s2) {
        cout << "wartosc false 2" << endl;
    }if(s3) {
        cout << "wartosc true 3" << endl;
    } if(!s3) {
        cout << "wartosc false 3" << endl;
    }
    cout << s1;
    cout << (s1 < s2);
    
    vector<Samochod> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    sort(v.begin(), v.end());
    for(auto it=v.begin() ; it!=v.end() ; ++it) {
        cout << *it << endl;
    }

    set<Samochod, cmp> s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    for(auto it=s.begin() ; it!=s.end() ; ++it) {
        cout << *it << endl;
    }
    cout << "--" << (s1 |= "audi") << "--" << endl;
    s1,s2,s3;
}