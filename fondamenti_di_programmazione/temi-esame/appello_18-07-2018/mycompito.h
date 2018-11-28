#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>

using namespace std;

enum DISCO {GIALLO=1, VERDE, ROSSO, NERO}; // Identifica pesa di ogni disco

class Rastrelliera{
private:
    friend ostream& operator<<(ostream& os, const Rastrelliera& r);
    int dischi[4]; // 0=numero dischi GIALLI ... 3=numero dischi NERI
    // Funzioi di utilita
    void sposta(int* b, DISCO tipo, int nd);
public:
    Rastrelliera(int ng = 10, int nv = 10, int nr = 10, int nn = 10);
    Rastrelliera(const Rastrelliera&);
    int* carica(int ng, int nv, int nr, int nn);
    void scarica(int* bilanciere);
    static int calcolaPeso(int* bilanciere);
};

#endif
