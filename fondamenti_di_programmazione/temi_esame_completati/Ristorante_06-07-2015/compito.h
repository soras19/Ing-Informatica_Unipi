#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

struct elem
{
    char* cognome;
    int num;
    elem* pun;
};

class Ristorante
{
    elem* head; // Lista dove vengono conservati i gruppi in Attesa
    int max;
    int liberi;
    void push_back(const char* cognome, int num);
    void pop_front();
    void elimina_lista();
public:
    Ristorante(int n);
    Ristorante(const Ristorante& r);
    void aggiungi(const char* cognome, int num);
    friend ostream& operator << (ostream& os, const Ristorante& r);
    Ristorante& operator -= (int num);
    bool rinuncia(const char* cognome);
    ~Ristorante();
};

#endif