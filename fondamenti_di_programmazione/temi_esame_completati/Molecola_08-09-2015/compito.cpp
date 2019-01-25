#include "compito.h"
#include <cstring>

Molecola::Molecola()
{
    head = NULL;
}

ostream& operator << (ostream& os, const Molecola& m)
{
    elem* q = m.head;
    os << "<";
    while(q->pun != NULL)
    {
        os << q->s << q->n << '-';
        q = q->pun;
    }
    os << q->s << q->n << ">";
    return os;
}

void Molecola::aggiungi(const char* str, int n)
{
    if(!str || strlen(str) == 0 || n <= 0)
        return;
    else
    {
        // Cerco l'atomo nella molecola
        elem* q = head;
        while(q != NULL)
        {
        // Se lo trovo gli aggiungo n atomi        
            if(strcmp(str, q->s) == 0)
            {
                q->n += n;
                return;
            }
            q = q->pun;
        }
        // Altrimenti inserisco in testa la nuova molecola
        elem* old = head;
        head = new elem;
        head->pun = old;
        head->s = new char[strlen(str)+1];
        strcpy(head->s, str);
        head->n = n;
    }
    
}

void Molecola::elimina(const char* str)
{
    // Cerco l'atomo nella molecola
    elem* q = head;
    elem* p = q;
    while(q != NULL)
    {
    // Se lo trovo lo elimino e termino il ciclo      
        if(strcmp(str, q->s) == 0)
        {
            // Caso elimina in testa
            if(p == q)
            {
                head = head->pun;
            }
            else
            {
                p->pun = q->pun;   
            }                
            delete[] q->s;
            delete q;
            break;
        }
        p = q;
        q = q->pun;
    }
}

Molecola::Molecola(const Molecola& m)
{
    if(!m.head)
        head = NULL;
    else
    {
        head = new elem;
        head->s = new char[strlen(m.head->s)+1];
        strcpy(head->s, m.head->s);
        head->n = m.head->n;
        elem* q = head;
        elem* p = m.head->pun;
        while(p)
        {
            q->pun = new elem;
            q = q->pun;
            q->s = new char[strlen(p->s)+1];
            strcpy(q->s, p->s);
            q->n = p->n;
            p = p->pun;
        }
    }
    
}

Molecola& Molecola::operator = (const Molecola& m)
{
    if(this != &m)
    {
        while(head)
        {
            elem* to_delete = head;
            head = head->pun;
            delete[] to_delete->s;
            delete to_delete;
        }
        if(!m.head)
            head = NULL;
        else
        {
            head = new elem;
            head->s = new char[strlen(m.head->s)+1];
            strcpy(head->s, m.head->s);
            head->n = m.head->n;
            elem* q = head;
            elem* p = m.head->pun;
            while(p)
            {
                q->pun = new elem;
                q = q->pun;
                q->s = new char[strlen(p->s)+1];
                strcpy(q->s, p->s);
                q->n = p->n;
                p = p->pun;
            }
        }
    }
    return *this;
}

Molecola& Molecola::operator += (const Molecola& m)
{
    Molecola tmp(m);
    elem* q = tmp.head;
    elem* buffer;
    while(q != NULL)
    {
        elem* p = head;
        bool isPresent = false;
        while(p != NULL)
        {
            if(strcmp(p->s, q->s) == 0)
            {
                p->n += q->n;
                q = q->pun;
                tmp.elimina(p->s);
                isPresent = true;
                break;
            }
            p = p->pun;
        }
        if(!isPresent)
            q = q->pun;
    }
    elem* old_head = head;
    if(tmp.head != NULL)
    {
        head = new elem;
        head->s = new char[strlen(tmp.head->s)+1];
        strcpy(head->s, tmp.head->s);
        head->n = tmp.head->n;
        elem* q = head;
        elem* p = tmp.head->pun;
        while(p)
        {
            q->pun = new elem;
            q = q->pun;
            q->s = new char[strlen(p->s)+1];
            strcpy(q->s, p->s);
            q->n = p->n;
            p = p->pun;
        }
        q->pun = old_head;
    }
    return *this;
}

Molecola::~Molecola()
{
    while(head)
    {
        elem* to_delete = head;
        head = head->pun;
        delete[] to_delete->s;
        delete to_delete;
    }
}