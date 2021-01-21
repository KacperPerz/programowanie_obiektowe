#include "Stopper.h"
using namespace std;

Stopper::Stopper() {
    this->pocz = std::chrono::milliseconds(0);
}

void Stopper::start() {
    this->pocz = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
}

void Stopper::stop() {
    this->kon = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
    this->czas = this->kon.count() - this->pocz.count();
}

void Stopper::reset() {
    this->czas = 0;
}

void Stopper::pokazStoper() {
    cout << "Czas [ms] wynosi: " << this->czas << endl;
}