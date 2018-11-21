#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

/*Esempio di funzione per l'inserimento in una pila di char*/
inline void input_char(Stack<char>& pila);
/*Esempio di funzione per l'inserimento in una pila di int, float o double*/
template<class T> void input_numbers(Stack<T>& pila);

int main(int argc, char const *argv[])
{
    Stack<char> char_stack;
    input_char(char_stack);
    while(!char_stack.isEmpty()){
        cout << char_stack.pop();
    }
    Stack<int> int_stack;
    input_numbers(int_stack);
    int_stack.print();
    return 0;
}

inline void input_char(Stack<char>& pila){
    cout << "Inserisci la stringa da inserire nella Pila:\n";
    for(char i = getchar(); i!='\n'; i = getchar())
        pila.push(i);
}

template<class T> void input_numbers(Stack<T>& pila){
    cout << "\nInserisci i numeri e premi invio una volta finito:\n";
    T c;
    std::string line;
    std::getline(cin, line);
    std::istringstream iss(line);
    while ( iss >> c) {    
        pila.push(c);
    }
}