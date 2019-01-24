#include "compito.h"
#include <cstring>
/*
struct elem
{
    char* nome;
    int importo;
    elem* pun;
};

class Prepagata
{
    int saldo;
    
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
*/

void Prepagata::cancellaDa(elem*& q)
{
    while(q != NULL)
    {
        elem* tmp = q->pun;
        delete[] q->nome;
        delete q;
        q = tmp;
    }
}
ostream& operator << (ostream& os, const Prepagata& p)
{
    elem* q = p.head;
    int saldo_tot = p.saldo;
    while(q != NULL)
    {   
        os << q->importo << "<";
        if(saldo_tot - q->importo >= 0)
            os << "C";
        else
            os << "S";
        os << ">[" << saldo_tot << "=>" << saldo_tot - q->importo;
        os << "]" << q->nome << endl;
        saldo_tot = saldo_tot - q->importo;
        q = q->pun;
    }
    return os;
}

Prepagata::Prepagata(int crIn)
{
    if(crIn < 0)
        crIn = 0;
    saldo = crIn;
    head = NULL;
}

Prepagata::Prepagata(const Prepagata& p2)
{
    saldo = p2.saldo;
    if(p2.head)
    {
        head = new elem;
        head->pun = NULL;
        head->nome = new char[strlen(p2.head->nome)+1];
        strcpy(head->nome, p2.head->nome);
        head->importo = p2.head->importo;
        elem* q = head;
        elem* p = p2.head->pun;
        while(p != NULL)
        {
            q->pun = new elem;
            q = q->pun;
            q->pun = NULL;
            q->nome = new char[strlen(p->nome)+1];
            strcpy(q->nome, p->nome);
            q->importo = p->importo;
            p = p->pun;
        }
    }
    else
    {
        head = NULL;
    }
    
}

bool Prepagata::acquista(int importo, const char* nome)
{
    // Sanity check dell'input
    if(!nome || strlen(nome) == 0 || importo < 0)
        return false;
    // Caso testa vuota
    if(!head)
    {
        head = new elem;
        head->pun = NULL;
        head->nome = new char[strlen(nome)+1];
        strcpy(head->nome, nome);
        head->importo = importo;
    }
    // Caso inserimento in coda
    else
    {
        elem* q = head;
        while(q->pun != NULL)
            q = q->pun;
        q->pun = new elem;
        q = q->pun;
        q->pun = NULL;
        q->nome = new char[strlen(nome)+1];
        strcpy(q->nome, nome);
        q->importo = importo;
    }
    return true;
}

Prepagata::operator int()
{
    elem* q = head;
    int saldo_tot = saldo;
    while(q != NULL)
    {   
        saldo_tot -= q->importo;
        q = q->pun;
    }
    return saldo_tot;
}

Prepagata& Prepagata::operator!()
{
    if(head->importo > saldo)
    {
        cancellaDa(head);
    }
    else
    {
        elem* q = head;
        elem* p = q;
        int saldo_tot = saldo;
        while(q != NULL)
        {   
            if(saldo_tot - q->importo < 0)
            {
                cancellaDa(q);
                p->pun = NULL;
                break;
            }
            saldo_tot = saldo_tot - q->importo;
            p = q;
            q = q->pun;
        }
    }
    return *this;
}

Prepagata::~Prepagata()
{
    cancellaDa(head);
}