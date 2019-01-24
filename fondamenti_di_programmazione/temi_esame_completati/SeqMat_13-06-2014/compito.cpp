#include "compito.h"

elem* SeqMat::delElem(elem*& e)
{
    elem* pun = e->pun;
    delete e;
    return pun;
}

ostream& operator << (ostream& os, const SeqMat& s)
{
    os << "INIZIO_SEQUENZA" << endl;
    elem* q = s.head;
    while(q != NULL)
    {
        for(int i = 0; i < q->size; i++)
        {
            for(int j = 0; j < q->size; j++)
                os << q->val;
            os << endl;
        }
        q = q->pun;
    }
    os << "FINE_SEQUENZA" << endl;
    return os;
}

SeqMat::SeqMat()
{
    head = NULL;
}

SeqMat::~SeqMat()
{
    while(head)
        head = delElem(head);
}

void SeqMat::insMat(int size, int value)
{
    if(size <= 0)
        return;
    if(!head)
    {
        head = new elem;
        head->pun = NULL;
        head->size = size;
        head->val = value;
    }
    else
    {
        elem* q = head;
        elem* p = q;
        // Prendo la coda della lista con p
        while(q != NULL)
        {
            p = q;
            q = q->pun;
        }
        p->pun = new elem;
        q = p->pun;
        q->pun = NULL;
        q->size = size;
        q->val = value; 
    }
}

SeqMat& SeqMat::operator -= (int k)
{
    if(k > 0 && head)
    {
        while(head->size == k)
        {
            head = delElem(head);
        }
        elem* q = head;
        elem* p = q;
        while(q != NULL)
        {
            if(q->size == k)
            {
                q = delElem(q);
                p->pun = q;
                // Caso fine della lista
                if(!q)
                    break;
            }
            p = q; 
            q = q->pun;
        }
    }
    return *this;
}

SeqMat& SeqMat::operator ~ ()
{
    if(head != NULL)
    {
        elem* q = head;
        while(q != NULL)
        {
            int sum = 0;//contaRicorrenze(q, q->size);
            while(q->pun != NULL && q->pun->size == q->size)
            {
                sum += q->pun->val;
                q->pun = delElem(q->pun);
            }
            q->val += sum;
            q = q->pun;
        }
    }
    return *this;
}
SeqMat::SeqMat(const SeqMat& s)
{
    if(s.head)
    {
        head = new elem;
        head->pun = NULL;
        head->size = s.head->size;
        head->val = s.head->val;
        elem* q = head;
        elem* p = s.head->pun;
        while(p != NULL)
        {
            q->pun = new elem;
            q = q->pun;
            q->pun = NULL;
            q->size = p->size;
            q->val = p->val;
            p = p->pun;
        }
    }
    else
    {
        head == NULL;
    }    
}
SeqMat& SeqMat::operator = (const SeqMat& s)
{
    if(this != &s)
    {  
    // Elimino tutte le matrici attualmente presenti
        while(head)
            head = delElem(head);
        if(s.head)
        {
            head = new elem;
            head->pun = NULL;
            head->size = s.head->size;
            head->val = s.head->val;
            elem* q = head;
            elem* p = s.head->pun;
            while(p != NULL)
            {
                q->pun = new elem;
                q = q->pun;
                q->pun = NULL;
                q->size = p->size;
                q->val = p->val;
                p = p->pun;
            }
        }
        else
        {
            head == NULL;
        }
    }
    return *this;
}

SeqMat& SeqMat::operator ++ ()
{
    elem* q = head;
    while(q)
    {
        q->size++;
        q = q->pun;
    }
    return *this;
}