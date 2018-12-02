#include "compito.h"
#include <cstring>
ostream& operator<<(ostream& os, const GestoreApp& g){
    if(g.l == NULL){
        os << "[]";
        return os;
    }
    elem* q = g.l;
    int i = 0;
    while(q->pun != NULL){
        if(!i++)
            os << "[" << q->str << "], ";
        else
            os << q->str << ", ";
        q = q->pun;
    }
    if(!i)
        os << "[" << q->str << "]";
    else
        os << q->str;
    return os;
}

GestoreApp::GestoreApp(){
    l = NULL;
}

GestoreApp::~GestoreApp(){
    chiudi_tutte();
}

void GestoreApp::operator+=(const char* str){
    // Gestione errori
    if(strlen(str) > 20)
        return;
    // caso testa vuota
    if(l == NULL){
        l = new elem;
        l->pun = NULL;
        strcpy(l->str, str);
    }
    else{
        elem* p = l;
        while(p != NULL){
            if(strcmp(str, p->str) == 0)
                return;
            p = p->pun;
        }
        elem* q = l;
        l = new elem;
        l->pun = q;
        strcpy(l->str, str);
    }
    return;
}

void GestoreApp::foreground(const char* str){
    elem* p = l;
    elem* q = NULL;
    while(p != NULL){
        int ret = strcmp(str, p->str);
        // Se sono in testa non faccio nulla
        if(ret == 0 && p == l)
            return;
        else if(ret == 0){
            // Sposto il nodo p in testa
            elem* testa = l;
            l = p;
            elem* nodo = l->pun;
            l->pun = testa;
            q->pun = nodo;
            return;
        }
        q = p;
        p = p->pun;
    }
    return;
}

void GestoreApp::operator-=(const char* str){
    elem* p = l;
    elem* q = NULL;
    while(p != NULL){
        int ret = strcmp(str, p->str);
        // Se sono in testa non faccio nulla
        if(ret == 0 && p == l){
            l = l->pun;
            delete p;
            return;
        }
        else if(ret == 0){
            // elimino il nodo p previa congiunzione del nodo seguente
            // con quello precedente
            q->pun = p->pun;
            delete p;
            return;
        }
        q = p;
        p = p->pun;
    }
    return;
}

void GestoreApp::chiudi_tutte(){
    while(l != NULL){
        elem* p = l;
        l = l->pun;
        delete p;
    }
}
