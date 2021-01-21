#include <iostream>
#include "Stack.cpp"
using namespace std;

//e.what() zwraca komunikat klasy StackException
void foo(Stack &s){
    try{
        for(int i=0 ; i<10 ; i++){
            cout<<i<<endl;
            s.push(i);
        }
    }catch(StackException e) {
        cout << e.what() << endl;
    }
}
//e.what() zwraca komunikat klasy StackFullException
void bar(Stack &s) {
    try{
        for(int i=0 ; i<10 ; i++) {
            s.push(i);
            cout<<i<<endl;
        }
    }catch(StackException &e) {
        cout << e.what() << endl;
    }
}

int main(){

    Stack stos(3);
    bar(stos);
    foo(stos);
    try{
        stos.pop();
    }catch (StackEmptyException e){
        cout << e.what() << endl;
    }
    try{
        stos.push(4);
    }catch (StackFullException e){
        cout << e.what() << endl;
    }

}