#include "mycompito.h"

ostream& operator<<(ostream& os, const Rastrelliera& r){
    for(int i = 0; i < NERO; i++){
        switch(i){
            case GIALLO-1:
                os << "GIALLO\t<" << r.dischi[i] << ">\t";
                for(int j = 0; j < r.dischi[i]; j++)
                    os << "[] ";
                os << endl;
                break;
            case VERDE-1:
                os << "VERDE\t<" << r.dischi[i] << ">\t";
                for(int j = 0; j < r.dischi[i]; j++)
                    os << "[] ";
                os << endl;
                break;
            case ROSSO-1:
                os << "ROSSO\t<" << r.dischi[i] << ">\t";
                for(int j = 0; j < r.dischi[i]; j++)
                    os << "[] ";
                os << endl;
                break;
            case NERO-1:
                os << "NERO\t<" << r.dischi[i] << ">\t";
                for(int j = 0; j < r.dischi[i]; j++)
                    os << "[] ";
                os << endl;
                break;
        }
    }
    return os;
}
void bastardaeva(int* bilanciere){
    cerr << "\nCalling BASTARDAEVA:\n";
    for(int i = 0; i<4; i++){
        cerr << "DEBUG--------- i= " << i << " ,bilanciere[i]= ";
        cerr << bilanciere[i] << " ------------\n";
    }
    cerr << "\nEND\n";
}
Rastrelliera::Rastrelliera(int ng, int nv, int nr, int nn){
    if (ng < 0) ng = 10;
	if (nv < 0) nv = 10;
	if (nr < 0) nr = 10;
	if (nn < 0) nn = 10;
    dischi[GIALLO-1] = ng;
    dischi[VERDE-1] = nv;
    dischi[ROSSO-1] = nr;
    dischi[NERO-1] = nn;
}

void Rastrelliera::sposta(int* b, DISCO tipo, int nd){
    b[tipo-1] += nd;
    dischi[tipo-1] -= nd;
}

int* Rastrelliera::carica(int ng, int nv, int nr, int nn){
    if (ng < 0 || ng > dischi[GIALLO-1] ) return NULL;
    if (nv < 0 || nv > dischi[VERDE-1] ) return NULL;
    if (nr < 0 || nr > dischi[ROSSO-1] ) return NULL;
    if (nn < 0 || nn > dischi[NERO-1] ) return NULL;
    dischi[GIALLO-1] -= ng;
    dischi[VERDE-1] -= nv;
    dischi[ROSSO-1] -= nr;
    dischi[NERO-1] -= nn;
    int* b = new int[4];
    b[0] = ng;
    b[1] = nv;
    b[2] = nr;
    b[3] = nn;
    return b;
}

void Rastrelliera::scarica(int* bilanciere){
    if(!bilanciere)
        return;
    sposta(bilanciere, GIALLO, -bilanciere[GIALLO-1]);
    sposta(bilanciere, VERDE, -bilanciere[VERDE-1]);
    sposta(bilanciere, ROSSO, -bilanciere[ROSSO-1]);
    sposta(bilanciere, NERO, -bilanciere[NERO-1]);
    delete[] bilanciere;
}

int Rastrelliera::calcolaPeso(int* bilanciere){
    bastardaeva(bilanciere);
    int somma = bilanciere[0] * GIALLO;
    for(int i = 1; i < NERO; i++){
        somma += bilanciere[i] * (i+1);
        //cerr << "\n\nDEBUG--------- i= " << i << " ,bilanciere[i]= " << bilanciere[i] << " ------------\n\n";
    }
    return somma;
}
