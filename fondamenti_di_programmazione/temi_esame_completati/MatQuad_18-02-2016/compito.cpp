#include "compito.h"

ostream& operator<<(ostream& os, const MatQuad& m){
    for(int i = 0; i < m.s; i++){
        for(int j = 0; j < m.s; j++)
            os << *(m.m+i*m.s+j) << " ";
        os << endl;
    }
    return os;
}

MatQuad::MatQuad(int size){
    this->s = size;
    m = new int[size*size];
    for(int i = 0; i < size*size; i++)
        m[i] = 0;
}

MatQuad::~MatQuad(){
    delete[] m;
}

void MatQuad::aggiorna(int* v, int dim){
    int min = (s*s>dim) ? dim : s*s;
    for(int i = 0; i < min; i++){
        m[i] = v[i];
    }
}

bool MatQuad::trova(){
    for(int i = 0; i < s; i++){
        int count = 0;
        for(int j = 0; j < s; j++){
            //
            if(count == 2)
                return true;
            if(j < s-1){
                if(*(m+i*s+j) == *(m+i*s+j+1))
                    count++;
                else
                    count = 0;
            }
        }
    }
    return false;
}

void MatQuad::raddoppia(){
    int old_s = s;
    s = s*2;
    int *old_m = m;
    m = new int[s*s];
    // Q1
    for(int i = 0; i < old_s; i++)
        for(int j = 0; j < old_s; j++)
            *(m+i*s+j) = 8; // m[i][j] = 8
    // Q2
    for(int i = 0; i < old_s; i++)
        for(int j = old_s; j < s; j++)
            *(m+i*s+j) = *(old_m+i*old_s+(j-old_s));
    // Q3
    for(int i = old_s; i < s; i++)
        for(int j = 0; j < old_s; j++)
            *(m+i*s+j) = *(old_m+((i-old_s)*old_s)+j);
    // Q4
    for(int i = old_s; i < s; i++)
        for(int j = old_s; j < s; j++)
            *(m+i*s+j) = 9; // m[i][j] = 9
    delete[] old_m;
}
