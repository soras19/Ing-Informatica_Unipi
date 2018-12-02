#include "compito.h"

Schedario::Schedario(){
    for(int i = 0; i < dim; i++)
        doc[i] = NULL;
}

Schedario::~Schedario(){
    for(int i = 0; i < dim; i++){
        elem* q = doc[i];
        elem* p;
        while(q != NULL){
            p = q->pun;
            delete q;
            q = p;
        }
    }
}

//L1(6)L2(35,48,21)L3(10,12)
ostream& operator<<(ostream& os, const Schedario& s){
    for(int i = 0; i < dim; i++){
        os << "L" << i+1 << "(";
        elem* q = s.doc[i];
        while(q != NULL && q->pun != NULL){
            os << q->tip << ",";
            q = q->pun;
        }
        if(q!=NULL)
            os << q->tip << ")";
        else
            os << ")";
    }
    return os;
}

void Schedario::operator -=(int liv){
    liv--;
    if(liv < 0 || liv > dim)
        return;
    elem* q = doc[liv];
    elem* p;
    while(q != NULL){
        p = q->pun;
        delete q;
        q = p;
    }
    doc[liv] = NULL;
}

void Schedario::promuovi(int liv, int tip){
    liv--;
    if(liv < 0 || liv > dim-1)
        return;
    elem* q = doc[liv];
    elem* p = NULL;
    while(q != NULL){
        int eliminated = 0;
        if(q->tip == tip){
            // Copio q->tip in testa a doc[liv+1]
            aggiungi(liv+2, q->tip);
            // Elimino q->tip
            elem* to_delete = q;
            if(p == NULL){
                doc[liv] = doc[liv]->pun;
                eliminated = 2;
            }
            else{
                // p era l'elemento nella lista precedente a q
                p->pun = q->pun;
                eliminated = 1;
            }
            // Elimino l'elemento che ho promosso
            delete to_delete;
            if(eliminated == 2)
                q = doc[liv];
            else
                q = p->pun;
        }
        // Se non ho eliminato nulla itero normalmente
        if(!eliminated){
            p = q;
            q = q->pun;
        }
    }
    cout << endl;
}

void Schedario::aggiungi(int liv, int tip){
    liv--;
    if(liv < 0 || liv > dim)
        return;
    // Aggiunta in testa
    elem* q = doc[liv];
    doc[liv] = new elem;
    doc[liv]->pun = q;
    doc[liv]->tip = tip;
    return;
}
