#include "ElektrowniaWeglowa.h"

//do list inicjalizacyjnych kazdego z konstruktorow nalezy dopisac inicjalizacje (na poczatku) obiektu typu Logger

//konstruktor domyslny
ElektrowniaWeglowa::ElektrowniaWeglowa():Logger(true),Stopper(),maxIloscWegla(nullptr),stanMagazynowyWegla(nullptr),sprawnoscElektrowni(nullptr),liczbaPracownikow(nullptr),
pensjaPracownika(nullptr){
    this->reset();
    this->log("Konstruktor domyślny");
}

//konstruktor - kopiowanie glebokie
ElektrowniaWeglowa::ElektrowniaWeglowa(const ElektrowniaWeglowa &e):Logger(true),Stopper(),maxIloscWegla(new double(*e.maxIloscWegla))
,stanMagazynowyWegla(new double(*e.stanMagazynowyWegla)),sprawnoscElektrowni(new double(*e.sprawnoscElektrowni)),liczbaPracownikow(new unsigned short(*e.liczbaPracownikow)),
pensjaPracownika(new int(*e.pensjaPracownika)){
    this->reset();
    this->log("Konstruktor kopiujacy");
}

//konstruktor z parametrem
ElektrowniaWeglowa::ElektrowniaWeglowa(int pensjaPracownika):Logger(true),Stopper(),maxIloscWegla(nullptr),stanMagazynowyWegla(nullptr),sprawnoscElektrowni(nullptr),liczbaPracownikow(nullptr) {
    *this->pensjaPracownika = pensjaPracownika;
    this->reset();
    this->log("Konstruktor z parametrem.");
}

//konstruktor przenoszacy
ElektrowniaWeglowa::ElektrowniaWeglowa(ElektrowniaWeglowa &&e) : Logger(true), Stopper() {
    this->reset();
    this->log("Konstruktor przenoszacy");
    pensjaPracownika = move(e.pensjaPracownika);
    maxIloscWegla = move(e.maxIloscWegla);
    stanMagazynowyWegla = move(e.stanMagazynowyWegla);
    sprawnoscElektrowni = move(e.sprawnoscElektrowni);
    liczbaPracownikow = move(e.liczbaPracownikow);
}


void ElektrowniaWeglowa::setMaxIloscWegla() {
    log("Metoda: maksymalna ilosc wegla\n");
    this->maxIloscWegla = new double;
    
    cout << "Podaj maksymalna ilosc (tony kg) wegla: ";
    double a;
    cin >> a;
    *this->maxIloscWegla = a;
}
double ElektrowniaWeglowa::getMaxIloscWegla() {
    return *this->maxIloscWegla;
}
void ElektrowniaWeglowa::setSprawnoscElektrowni() {
    log("Metoda: sprawnosc elektrowni\n");
    this->sprawnoscElektrowni = new double;
    double a;
    do{
        cout << "Okresl sprawnosc elektrowni z przedzialu (0,1> :";
        cin >> a;
    } while (!(a <= 1 && a > 0));
    *this->sprawnoscElektrowni = a;
}
double ElektrowniaWeglowa::getSprawnoscElektrowni() {
    return *this->sprawnoscElektrowni;
}
void ElektrowniaWeglowa::setStanMagazynowyWegla() {
    log("Metoda: stan magazynowy wegla\n");
    this->stanMagazynowyWegla = new double;
    double a;
    cout << endl << "Okresl stan magazynowy wegla: ";
    cin>>a;
    *this->stanMagazynowyWegla = a;
}
double ElektrowniaWeglowa::getStanMagazynowyWegla() {
    return *this->stanMagazynowyWegla;
}
void ElektrowniaWeglowa::setLiczbaPracownikow() {
    log("Metoda: liczba pracownikow\n");
    this->liczbaPracownikow = new unsigned short;
    unsigned short a;
    cout << endl << "Prosze podac liczbe przyjetych pracownikow: " << endl;
    cin>>a;
    *this->liczbaPracownikow = a;
}

unsigned short ElektrowniaWeglowa::getLiczbaPracownikow() const{
    return *this->liczbaPracownikow;
}

void ElektrowniaWeglowa::setPensjaPracownika() {
    log("Metoda: pensja pracownikow\n");
    this->pensjaPracownika = new int;
    int a;
    cout << endl << "Podaj wartosc pensji: ";
    cin>>a;
    while(a<=0) {
        cout << "Szanuj robotnika, burżuju." << endl;
        cin>>a;
    }         
    *this->pensjaPracownika = a;
    cout << "Miesieczny koszt wynosi: " << *this->liczbaPracownikow * a << endl;
}
int ElektrowniaWeglowa::getPensjaPracownika() {
    return *this->pensjaPracownika;
}
void ElektrowniaWeglowa::zwolnijPracownikow() {
    cout << endl << "Aktualnie pracuje " << *this->liczbaPracownikow << ". Ilu pracownikow zwolnic: ";
    unsigned short a;
    cin>>a;
    if(!(a<0 || a>*this->liczbaPracownikow)) {
        *this->liczbaPracownikow -= a;
        cout << endl << "Zwolniles " << a << " pracownikow." << endl;
        cout << "Teraz pracuje " << *this->liczbaPracownikow << " pracownikow." << endl;
    } else {
        cout << endl << "Nie masz tylu pracownikow." << endl;
    }
}
void ElektrowniaWeglowa::addWegielDoMagazynu() {
    cout << endl << "Ile wegla dodac do stanu magazynowego? Podaj wartosc: ";
    double a;
    cin >> a;
    *this->stanMagazynowyWegla += a;
    cout << endl;
}
void ElektrowniaWeglowa::przerzucWegiel() {
    double a=0;
    if(*this->stanMagazynowyWegla >= *this->maxIloscWegla) {
        *this->stanMagazynowyWegla -= *this->maxIloscWegla;
        a = *this->maxIloscWegla;
    } else {
        a = *this->stanMagazynowyWegla;
        *this->stanMagazynowyWegla = 0;
    }
    cout << endl << "Przerzucono " << a << " t kilogramow wegla" << endl;
}
