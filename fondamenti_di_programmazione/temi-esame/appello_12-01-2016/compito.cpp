#include "compito.h"
#include <cstring>

const int dim_id = 21;

ostream& operator<<(ostream& os, const Aula& a){
    for(int i = 0; i < a.N; i++){
        if(a.postazione[i][0] == '\0')
            os << "POSTAZIONE" << i+1 << ":<libera>" << endl;
        else
            os << "POSTAZIONE" << i+1 << ":" << a.postazione[i] << endl;
    }
    return os;
}

Aula& Aula::operator!(){
    // Se non è piena non faccio nulla
    for(int i = 0; i < N; i++)
        if(postazione[i][0] == '\0')
            return (*this);
    for(int i = 0; i < N; i++){
        for(int j=N-1; j > i; j--){
            if(strcmp(postazione[j], postazione[i]) < 0){ // 'ciao','mondo' = -1
                char *aux = postazione[i];
                postazione[i] = postazione[j];
                postazione[j] = aux;
            }
        }
    }
    return (*this);
}

Aula::~Aula(){
    for(int i = 0; i < N; i++)
        delete[] postazione[i];
    delete[] postazione;
}

Aula::Aula(const Aula& a){
    N = a.N;
    postazione = new char*[N];
    for(int i = 0; i < N; i++){
        postazione[i] = new char[dim_id];
        strcpy(postazione[i], a.postazione[i]);
    }
}

Aula::Aula(int n){
    if(n < 0){
        cout << "L'aula non puo' avere " << n << " postazioni\n";
        cout << "Imposto n = 0 di default\n";
    }
    postazione = new char*[n];
    // Ogni id potrà contenere al massimo dim_id-1 caratteri + '\0'
    for(int i = 0; i < n; i++){
        postazione[i] = new char[dim_id];
        memset(postazione[i], '\0', dim_id);
    }
    this->N = n;
}

bool Aula::aggiungi(const char* id){
    int id_size = strlen(id);
    //if(postazione[0][0] != '\0')
    // Controllo se id già è in qualche postazione
    /*for(int i = 0; i < N; i++)
        if(strcmp(id, postazione[i]) == 0)
            return false;*/
    for(int i = 0; i < N; i++){
        if(strcmp(id, postazione[i]) == 0)
            return false;
        if(postazione[i][0] == '\0'){
            strcpy(postazione[i], id);
            return true;
        }
    }
    return false;
}

void Aula::elimina(int p){
    if(p >= N || p <= 0)
        return;
    else
        memset(postazione[p-1], '\0', dim_id);
}
