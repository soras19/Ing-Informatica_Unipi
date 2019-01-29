#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

class Disco
{
    static int dischi;
    int* v;     // Array dei settori
    int n;    // Dimensione dell'array
    int size;   // Sector size
    int id;     // Id del prossimo file da memorizzare
    int usati;  // Numero dei settori gia in uso
public:
    Disco(int num);
    int riserva(int dim);
    friend ostream& operator << (ostream& os, const Disco& d);
    void cancella(int id);
    Disco& operator!();
    void deframmenta();
    static int getQuantiDischi();
    ~Disco();
};

#endif