#include "compito.h"
#include <cstring>
#include <cstdio>
/*
struct Voce{
    char id[6];
    int voto;
    int cfu;
};

class Libretto{
    int _N;
    int _index;
    Voce* voci;

public:
    Libretto(int in_N);
    bool aggiungi(const char* id, int voto, int cfu);
    friend ostream& operator<<(ostream& os, const Libretto& l);
    double media();
    // SECONDA PARTE
    Libretto& operator=(const Libretto& l2);
    int laurea();
    ~Libretto();
};
*/

ostream& operator<<(ostream& os, const Libretto& l){
    for(int i = 0; i < l._N; i++){
        os << "ESAME" << i+1 << ": <";
        if(l.voci[i].voto != 0)
            os << l.voci[i].id << "," << l.voci[i].voto << "," << l.voci[i].cfu;
        os << ">" << endl;
    }
    return os;
}

Libretto::Libretto(int in_N){
    if(in_N < 1)
        in_N = 1;
    _N = in_N;
    _index = 0;
    voci = new Voce[_N];
    for(int i = 0; i < _N; i++){
        memset(voci[i].id, '\0', 6);
        voci[i].voto = 0;
        voci[i].cfu = 0;
    }
}

bool Libretto::aggiungi(const char* id, int voto, int cfu){
    // Controllo che il Libretto non sia pieno
    if(_index == _N)
        return false;
    if(strlen(id) < 0 || strlen(id) > 5)
        return false;
    if(voto < 18 || voto > 33)
        return false;
    if(cfu != 6 && cfu != 9 && cfu != 12)
        return false;
    for(int i = 0; i <= _index; i++){
        // Se l'id in input non era stato ancora inserito
        // inserisco l'esame alla fine del Libretto
        if(i == _index){
            strcpy(voci[i].id, id);
            voci[i].voto = voto;
            voci[i].cfu = cfu;
            _index++;
        }
        // Se l'id dell'esame in input è già stato inserito
        // non faccio nulla
        if(strcmp(voci[i].id, id) == 0)
            return false;
    }
}

double Libretto::media(){
    double media = 0;
    for(int i = 0; i < _index; i++){
        media +=(double) voci[i].voto;
    }
    media = (double) media/_index;
    return media;
}

Libretto& Libretto::operator=(const Libretto& l2){
    if(this == &l2)
        return *this;
    // Se i libretti hanno numero di voci diverse
    // sono costretto a cancellarlo e crearlo da 0
    if(_N != l2._N){
        delete[] voci;
        _N = l2._N;
        voci = new Voce[_N];
    }
    for(int i = 0; i < _N; i++){
        voci[i].voto = l2.voci[i].voto;
        voci[i].cfu = l2.voci[i].cfu;
        memcpy(voci[i].id, l2.voci[i].id, 6);
    }
    _index = l2._index;
    return *this;

}

double Libretto::laurea(){
    if(_index != _N)
        return 0;
    double num = 0; // Numeratore
    double den = 0; // Denominatore
    for(int i = 0; i < _N; i++){
        num += (voci[i].voto * voci[i].cfu);
        den += voci[i].cfu;
    }
    return (double)(num/den)*3+22;
}

Libretto::~Libretto(){
    delete[] voci;
}
