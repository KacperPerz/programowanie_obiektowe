#include <iostream>
#include <string>
using namespace std;

class ElektrowniaWeglowa{
    private:
        double maxIloscWegla; //w tonach kg
        double stanMagazynowyWegla;
        double sprawnoscElektrowni;
        unsigned short liczbaPracownikow = 0;
        bool flaga = false;
        int pensjaPracownika;

        
    public:
        ElektrowniaWeglowa() {
            this->stanMagazynowyWegla = 0;
            this->liczbaPracownikow = 0;
        }
        void setMaxIloscWegla() {
            if(!flaga) {
                cout<<"Podaj maksymalna ilosc (tony kg) wegla: ";
                double a;
                cin>>a;
                this->maxIloscWegla = a;
            } else {
                cout<<"Parametr juz zostal ustawiony." << endl;
            }
            this->flaga = true;
        }
        void getMaxIloscWegla() {
            cout << endl << "Maksymalna ilosc wegla w podajniku: " << this->maxIloscWegla << endl;
        }
        void setSprawnoscElektrowni() {
            double a;
            do{
                cout << "Okresl sprawnosc elektrowni z przedzialu (0,1> :";
                cin>>a;
            }while(!(a <= 1 && a>0));
            this->sprawnoscElektrowni = a;
        }
        void getSprawnoscElektrowni() {
            cout << endl << "Sprawnosc elektrowni: " << this->sprawnoscElektrowni << endl;
        }
        void getStanMagazynowyWegla() {
            cout << endl << "Stan magazynowy wegla: " << this->stanMagazynowyWegla;
        }
        void setLiczbaPracownikow() {
            unsigned short a;
            cout << endl << "Prosze podac liczbe przyjetych pracownikow: " << endl;
            cin>>a;
            this->liczbaPracownikow = a;
        }
        void getLiczbaPracownikow() {
            cout << endl << "Liczba pracownikow: " << this->liczbaPracownikow << endl;
        }
        void setPensjaPracownika() {
            int a;
            cout << endl << "Podaj wartosc pensji: ";
            cin>>a;
            if(a>0) {
                this->pensjaPracownika = a;
                cout << "Miesieczny koszt wynosi: " << this->liczbaPracownikow * a << endl;
            } else {
                cout << "Szanuj robotnika, burżuju." << endl;
            }
        }
        void getPensjaPracownika() {
            cout << endl << "Pensja pracownika wynosi: " << this->pensjaPracownika << endl;
        }
        void zwolnijPracownikow() {
            cout << endl << "Aktualnie pracuje " << this->liczbaPracownikow << ". Ilu pracownikow zwolnic: ";
            unsigned short a;
            cin>>a;
            if(a<0 || a>=liczbaPracownikow) {
                this->liczbaPracownikow -= a;
                cout << endl << "Zwolniles " << a << " pracownikow." << endl;
            } else {
                cout << endl << "Nie masz tylu pracownikow." << endl;
            }
        }
        void addWegielDoMagazynu() {
            cout << endl << "Ile wegla dodac do stanu magazynowego? Podaj wartosc: ";
            double a;
            cin >> a;
            this->stanMagazynowyWegla += a;
            cout << endl;
        }
        void przerzucWegiel() {
            double a=0;
            if(this->stanMagazynowyWegla >= this->maxIloscWegla) {
                this->stanMagazynowyWegla -= maxIloscWegla;
                a = maxIloscWegla;
            } else {
                a = stanMagazynowyWegla;
                stanMagazynowyWegla = 0;
            }
            cout << endl << "Przerzucono " << a << " t kilogramow wegla" << endl;
        }

};

int main() {
    ElektrowniaWeglowa e;
    // e.setMaxIloscWegla();
    // e.setMaxIloscWegla();
    // e.getMaxIloscWegla();
    // e.addWegielDoMagazynu();
    // e.przerzucWegiel();
    // e.getStanMagazynowyWegla();
    // e.setSprawnoscElektrowni();
    // e.getSprawnoscElektrowni();
    e.setPensjaPracownika();
    e.setLiczbaPracownikow();
    e.setPensjaPracownika();
    // e.zwolnijPracownikow();
    
}