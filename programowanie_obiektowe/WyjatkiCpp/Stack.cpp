#include <vector>
#include <iostream>
#include <string>
using namespace std;

//noexcept znaczy, ze funkcja nie moze zwracac wyjatkow
class StackException : public exception {
    public:
        StackException() {};
        virtual const char* what() const noexcept override {
            return "Bledna_operacja_na_stosie!"; 
        }
};
class StackEmptyException : public StackException {
    string message;
    public:
        StackEmptyException(){};
        StackEmptyException(string p) {
            this->message = p;
        }
        virtual const char* what() const noexcept override {
            return message.c_str();
        }
};
class StackFullException : public StackException {
    int element = 0;
    int maxStackSize = 0;
    string message;

    public:
        StackFullException(){};
        StackFullException(string p, int& e, int& s) {
            this->message = p;
            this->element = e;
            this->maxStackSize = s;
        }
        virtual const char* what() const noexcept override {
            return message.c_str();
        }
};
class Stack{
    private:
        int maxStackSize;
        vector<int> dfs;
        int top;
    public:

        Stack() {
            maxStackSize = 10;
        }
        Stack(int max) {
            maxStackSize = max;
        }
        void push(int newItem) {
            if(dfs.size() < maxStackSize) {
                dfs.push_back(newItem);
                this->top = newItem;
            }
            else throw StackFullException("Stos jest pelny.", newItem, maxStackSize );
        }
        int pop() {
            if(dfs.size() > 0 ) {
                dfs.pop_back();
                this->top = dfs.front();
                return top;
            }
            else throw StackEmptyException("Stos jest juz pusty.");
        }
};