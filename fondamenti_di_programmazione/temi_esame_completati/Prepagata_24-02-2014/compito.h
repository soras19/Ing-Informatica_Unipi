#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

struct elem
{
    char* nome;
    int importo;
    elem* pun;
};

class Prepagata
{
    int saldo;
    elem* head;
    void cancellaDa(elem*& q);
public:
    Prepagata(int crIn);
    Prepagata(const Prepagata&);
    bool acquista(int importo, const char* nome);
    friend ostream& operator << (ostream& os, const Prepagata& p);
    // Parte 2
    operator int();
    Prepagata& operator!();
    ~Prepagata();
};

#endif