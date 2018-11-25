#include "compito.h"

//-------------------------------
// Funzioni di utilita'
//-------------------------------

void Display::alloca(){
  p = new bool*[N];
  for (int r=0; r<N; r++)
    p[r] = new bool[N];
}

void Display::dealloca(){
  for (int r=0; r<N; r++)
    delete [] p[r];
  delete [] p;
}

//-------------------------------
// PRIMA PARTE
//-------------------------------
Display::Display(int N1){
  if ( N1<=0 || (N1%2)==0 )
    N = 5;
  else 
    N = N1;
  alloca();
  for (int r=0; r<N; r++){
    for (int c=0; c<N; c++)
      p[r][c] = false;
  }
}

bool Display::set(char ch){ 
  int r,c;
  switch (ch){
    case '-':
      r = N/2;
      for(c=0;c<N;c++)
        p[r][c] = true;
      return true;
    case '|':
      c = N/2;
      for(r=0;r<N;r++)
        p[r][c] = true;
      return true;
    case '/':
      for(r=0;r<N;r++)
        p[r][N-r-1] = true;
      return true;	    
    default:
      return false;
  }
}

ostream & operator <<(ostream &os, const Display &d){
  for (int r=0; r < d.N; r++){
    for (int c=0; c < d.N; c++)
      if (d.p[r][c])
        os<<'1';
      else
	 os<<'0';
    os<<endl;
  }
  return os;
}

//-------------------------------
// SECONDA PARTE
//-------------------------------

Display & Display::operator |=(const Display &d){
  if (N != d.N)
    return *this;
  for (int r=0; r < N; r++)
    for (int c=0; c < N; c++)
      if ( d.p[r][c] )
        p[r][c] = true;
  return *this;
}

void Display::specchia(){
  for (int r=0; r<N; r++)
    for (int c=0; c<N/2; c++){
      int aux = p[r][c];
      p[r][c] = p[r][N-c-1];
      p[r][N-c-1] = aux;
  }
}

Display & Display::operator =(const Display &d){
  if ( this != &d ){
    if ( N != d.N){
      dealloca();
      N = d.N;
      alloca();      
    }
    for (int r=0; r<N; r++)
      for (int c=0; c<N; c++)
        p[r][c] = d.p[r][c];
  }
  return *this;
}


