#ifndef COMPITO_H_INCLUDED
#define COMPITO_H_INCLUDED

#include <iostream>
using namespace std;

struct Voce{
    char id[6];
    int voto;
    int cfu;
};

class Libretto{
    int _N;
    int _index;
    Voce* voci;

public:
    Libretto(int in_N);
    bool aggiungi(const char* id, int voto, int cfu);
    friend ostream& operator<<(ostream& os, const Libretto& l);
    double media();
    // SECONDA PARTE
    Libretto& operator=(const Libretto& l2);
    double laurea();
    ~Libretto();

};

#endif /* end of include guard: COMPITO_H_INCLUDED */
