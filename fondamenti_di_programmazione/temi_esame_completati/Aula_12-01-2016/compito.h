#ifndef COMPITO_H_INCLUDED
#define COMPITO_H_INCLUDED

#include <iostream>
using namespace std;

class Aula{
    int N; //Numero di postazioni
     // Dove per postazione[i] si intende puntatore al primo carattere dell'ID
     // dell'utente attuale
    char** postazione;
public:
    // PRIMA PARTE
    Aula(int n);
    bool aggiungi(const char* id);
    friend ostream& operator<<(ostream& os, const Aula& a);
    void elimina(int p);
    // SECONDA PARTE
    Aula(const Aula& a); // Costruttore di copia;
    Aula& operator!();
    ~Aula();
};

#endif //COMPITO_H_INCLUDE
