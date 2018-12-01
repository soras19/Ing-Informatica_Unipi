#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

const int dim = 3;

struct elem{
    int tip;
    elem* pun;
};

class Schedario{

    elem* doc[dim];
public:
    Schedario();
    void aggiungi(int liv, int tip); // Aggiunta in testa
    friend ostream& operator<<(ostream& os, const Schedario& s);
    void operator -=(int liv);
    // SECONDA PARTE
    void promuovi(int liv, int tip);
    ~Schedario();
};

#endif //COMPITO_H
