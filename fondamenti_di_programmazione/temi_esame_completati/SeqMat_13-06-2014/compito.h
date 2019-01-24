#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

struct elem
{
    int size;
    int val;
    elem* pun;
};

class SeqMat
{
    elem* head;
    elem* delElem(elem*& e);
public:
    SeqMat();
    SeqMat(const SeqMat& s);
    void insMat(int size, int value);
    friend ostream& operator << (ostream& os, const SeqMat& s);
    SeqMat& operator -= (int size);
    SeqMat& operator ~ ();
    SeqMat& operator = (const SeqMat& s);
    SeqMat& operator ++ ();
    ~SeqMat();
};

#endif