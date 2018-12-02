#ifndef COMPITO_H_INCLUDED
#define COMPITO_H_INCLUDED

#include <iostream>
using namespace std;
// Inizio 16:10
// Fine   17:07
class MatQuad{
    int s;
    int* m;
public:
    MatQuad(int size);
    void aggiorna(int* v, int dim);
    friend ostream& operator<<(ostream& os, const MatQuad& m);
    bool trova();
    // SECONDA PARTE
    void raddoppia();
    ~MatQuad();
};

#endif // COMPITO_H_INCLUDED
