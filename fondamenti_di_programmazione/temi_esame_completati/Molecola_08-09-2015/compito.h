#ifndef COMPITO_H
#define COMPITO_H

#include<iostream>
using namespace std;

struct elem
{
    char* s;
    int n;
    elem* pun;
};

class Molecola
{
    elem* head;
public:
    Molecola();
    Molecola(const Molecola& m);
    void aggiungi(const char* s, int n);
    friend ostream& operator << (ostream& os, const Molecola& m);
    void elimina(const char* s);
    // Parte 2
    Molecola& operator += (const Molecola& m);
    Molecola& operator = (const Molecola& m);
    ~Molecola();
};

#endif