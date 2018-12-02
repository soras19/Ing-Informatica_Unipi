#ifndef COMPITO_H_INCLUDED
#define COMPITO_H_INCLUDED

#include <iostream>
using namespace std;

struct elem {
    char str[21];
    elem* pun;
};

class GestoreApp{

    elem* l;

public:
    GestoreApp();
    void operator+=(const char* str);
    friend ostream& operator<<(ostream& os, const GestoreApp& g);
    // SECONDA PARTE
    void foreground(const char* str);
    void operator-=(const char* str);
    void chiudi_tutte();
    ~GestoreApp();
};


#endif /* end of include guard: COMPITO_H_INCLUDED */
