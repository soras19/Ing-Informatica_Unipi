#include "compito.h"
#include <cstring>

void Ristorante::pop_front()
{
    elem* to_delete = head;
    head = head->pun;
    delete[] to_delete->cognome;
    delete to_delete;
}

void Ristorante::elimina_lista()
{
    while(head)
    {
        pop_front();
    }
}

ostream& operator << (ostream& os, const Ristorante& r)
{
    elem* q = r.head;
    os << "Posti liberi " << r.liberi << ", in attesa ";
    if(!q)
    {
        os << "nessuno";
    }
    else
    {
        while(q != NULL)
        {
            os << q->cognome << "(" << q->num << ") ";
            q = q->pun;
        }
    }
    return os;
}

void Ristorante::push_back(const char* cognome, int num)
{
    elem* q;
    // Caso testa vuota
    if(!head)
    {
        head = new elem;
        q = head;
    }
    // Altrimenti scorro la lista fino in fondo
    else
    {
        q = head;
        while(q->pun != NULL)
            q = q->pun;
        q->pun = new elem;
        q = q->pun;
    }
    q->cognome = new char[strlen(cognome)+1];
    strcpy(q->cognome, cognome);
    q->num = num;
    q->pun = NULL;
}

Ristorante::Ristorante(int n)
{
    if(n <= 0)
        n = 1;
    max = liberi = n;
    head = NULL;
}

void Ristorante::aggiungi(const char* cognome, int num)
{
    if(!cognome || strlen(cognome) == 0 || num <= 0 || num > max)
        return;
    // I clienti prendono posto a sedere se c'e' posto
    // e non c'e' fila
    if(num <= liberi && !head)
    {
        liberi -= num;
    }
    // Altrimenti vanno in coda
    else
    {
        push_back(cognome, num);
    }
}

Ristorante& Ristorante::operator -= (int num)
{
    if(num < 0)
        return *this;
    if(num > max)
    {
        num = max;
    }
    liberi += num;
    // Se ci sono clienti in coda li faccio entrare fino
    // a quando ho posti a sedere liberi 
    while(liberi > 0 && head != NULL)
    {
        if(head->num <= liberi)
        {
            liberi -= head->num;
            pop_front();
        }
        else
        {
            break;
        }            
    }
    return *this;
}

Ristorante::Ristorante(const Ristorante& r)
{
    max = r.max;
    liberi = r.liberi;
    head = NULL;
    elem* q = r.head;
    while(q != NULL)
    {
        push_back(q->cognome, q->num);
        q = q->pun;
    }
}

bool Ristorante::rinuncia(const char* cognome)
{
    if(!cognome || strlen(cognome) == 0)
        return false;
    elem* q = head;
    elem* p = q;
    while(q != NULL)
    {
        if(strcmp(q->cognome, cognome) == 0)
        {
            if(head == q)
                pop_front();
            else
            {
                p->pun = q->pun;
                delete[] q->cognome;
                delete q;
            }
            *this -= 0;
            return true;
        }
        p = q;
        q = q->pun;
    }
    return false;
}

Ristorante::~Ristorante()
{
    elimina_lista();
}