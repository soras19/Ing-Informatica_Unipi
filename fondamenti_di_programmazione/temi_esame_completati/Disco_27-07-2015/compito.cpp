#include "compito.h"

int Disco::dischi = 0;

ostream& operator << (ostream& os, const Disco& d)
{
    for(int i = 0; i < d.n; i++)
    {
        os << d.v[i];
    }
    return os;
}

Disco::Disco(int num)
{
    if(num <= 0)
        num = 1;
    n = num;
    v = new int[n];
    for(int i = 0; i < n; i++)
        v[i] = 0;
    id = 1;
    Disco::dischi++;
    usati = 0;
    size = 1024;
}

int Disco::riserva(int dim)
{
    if(dim <= 0)
        return 0;
    // Controllo se il file sta nei settori liberi
    int settoriDaAllocare = dim/size;
    if(dim % size > 0)
        settoriDaAllocare++;
    if(n - usati < settoriDaAllocare)
        return 0;
    
    // Alloco i settori per il file->id
    int settoriAllocati = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] == 0)   
        {
            v[i] = id;
            settoriAllocati++;
        }
        if(settoriAllocati == settoriDaAllocare)
            break;
    }
    usati += settoriAllocati;
    return id++;
}

void Disco::cancella(int id)
{
    for(int i = 0; i < n; i++)
    {
        if(v[i] == id)
        {
            v[i] = 0;
            usati--;
        }
    }
}

Disco& Disco::operator!()
{
    id = 1;
    usati = 0;
    for(int i = 0; i < n; i++)
        v[i] = 0;
    return *this;
}

void Disco::deframmenta()
{
    for(int j = n-1; j > 0; j--)
        for(int i = 0; i < j; i++)
            if(v[i] < v[i+1])
            {
                // scambia(v[i+1], v[i])
                int c = v[i+1];
                v[i+1] = v[i];
                v[i] = c;
            }
}

int Disco::getQuantiDischi()
{
    return dischi;
}

Disco::~Disco()
{
    delete[] v;
    Disco::dischi--;
}