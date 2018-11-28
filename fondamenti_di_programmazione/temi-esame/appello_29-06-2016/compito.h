#ifndef COMPITO_H_INCLUDED
#define COMPITO_H_INCLUDED

#include <iostream>
using namespace std;



class Scrabble{
    int N;
    char** tabella;
    // funzioni di utility
    int str_size(const char*);
public:
    Scrabble& operator=(const Scrabble&);
    Scrabble(int Ne);
    bool esiste(const char* str);
    void aggiungi(const char* str, int r, int c, const char dir);
    friend ostream& operator<<(ostream& os, const Scrabble& s);

    //SECONDA PARTE
    //

};

#endif
