#include "compito.h"

#include <iostream>
using namespace std;

// Operazione di uscita
ostream& operator<<(ostream& os, const Scrabble& s){
    for(int i = 0; i < s.N; i++){
        for(int j = 0; j < s.N; j++)
            os << s.tabella[i][j] << ' ';
        os << endl;
    }
    return os;
}

Scrabble& Scrabble::operator=(const Scrabble& s){
    // Controllo che non sto facendo un assegnamento del tipo
    // s = s
    if(&s == this)
        return *this;

    // Se le dimensioni delle tabelle sono diverse
    // elimino la precedente per crearne una con la
    // dimensione di s.N
    if(N != s.N){
        for(int i=0; i<N; i++)
            delete[] tabella[i];
        delete[] tabella;
        N = s.N;
        tabella = new char*[N];
        for(int i = 0; i < N; i++)
            tabella[i] = new char[N];
    }
    // Copio i caratteri dalla tabella di S a quella di this
    for(int i = 0; i<N; i++)
        for(int j = 0; j < N; j++)
            this->tabella[i][j] = s.tabella[i][j];
    return *this;
}

// Costruttore
Scrabble::Scrabble(int Ne){
    if(Ne < 4){
        Ne=4;
    }
    N = Ne;
    tabella = new char*[N];
    for(int i = 0; i < N; i++){
        tabella[i] = new char[N];
        for(int j=0; j<N; j++){
            tabella[i][j] = '-';
        }
    }
}
// aggiunge la stringa str, a partire da tabella[r][c] in direzione
// dir che può assumere due valori: 'O'=orizzontale,
// 'V' = verticale
void Scrabble::aggiungi(const char* str, int r, int c, const char dir){
    // Controllo che la stringa inserita sia di lunghezza <= N
    int size_s = str_size(str);
    if(size_s > N)
        return;
    // Controllo che r e c siano compresi tra 0 ed N-1
    if(r>=N || c>=N || r<0 || c<0)
        return;
    if(dir == 'O'){
        if(size_s > N-c)
            return;
        for(int i = 0; i < size_s; i++){
            // Se in quel punto della tabella ho già inserito una
            // lettera ma è uguale a quella che voglio inserire
            // oppure in quel punto è ancora vuota
            // mi va bene e continuo
            if(( tabella[r][c+i] != '-' && tabella[r][c+i] == str[i] ) || tabella[r][c+i]=='-'){
                continue;
            }
            else return;

        }
        // Inserimento in seconda battuna per far rimanere inalterata
        // la tabella in caso di input invalido
        for(int i = 0; i < size_s; i++)
            tabella[r][c+i] = str[i];
    }
    else if(dir == 'V'){
        if(size_s > N-r)
            return;
        for(int i = 0; i < size_s; i++){
            // Se in quel punto della tabella ho già inserito una
            // lettera ma è uguale a quella che voglio inserire
            // oppure in quel punto è ancora vuota
            // mi va bene e continuo
            if((tabella[r+i][c] != '-' && tabella[r+i][c] == str[i]) || tabella[r+i][c]=='-'){
                continue;
            }
            else return;

        }
        // Inserimento in seconda battuna per far rimanere inalterata
        // la tabella in caso di input invalido
        for(int i = 0; i < size_s; i++)
            tabella[r+i][c] = str[i];
    }
    return;
}

bool Scrabble::esiste(const char* str){
    int size_s = str_size(str);
    if(size_s > N)
        return false;
    bool ret = false;
    // orizzontale , i=riga, j=colonna
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << "i= " << i << "j= " << j << endl;
            if(size_s > N-j) //Passo alla riga successiva
                break;
            if(tabella[i][j] == str[0]){
                for(int k=1; k<N-j; k++){
                    if(str[k]==tabella[i][j+k])
                        ret = true;
                    else{
                        ret = false;
                        break;
                    }
                }
            }
            if(ret)
                return ret;
        }
    }
    // verticale,  i=riga, j=colonna
    for(int j = 0; j < N; j++){
        for(int i = 0; i < N; i++){
            if(size_s > N-j) //Passo alla c successiva
                break;
            if(tabella[i][j] == str[0]){
                for(int k=1; k<N-j; k++){
                    if(str[k]==tabella[i][j+k])
                        ret = true;
                    else{
                        ret = false;
                        break;
                    }
                }
            }
            if(ret)
                return ret;
        }
    }
    return ret;
}

int Scrabble::str_size(const char* str){
    int i;
    for(i = 0; str[i] != '\0'; i++){
    }
    return i;
}
