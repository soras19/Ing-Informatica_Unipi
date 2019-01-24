#include <iostream>
#include "compito.h"
using namespace std;
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
int main(){
  // --- PRIMA PARTE ---   
  SeqMat s; // costruzione di una sequenza di matrici vuota    		
  cout<<"\nTest della insMat e dell'operatore di uscita"<<endl;
  s.insMat(4,3); // aggiunge una matrice 4x4 con tutti elementi pari a 3
  s.insMat(2,1); // aggiunge una matrice 2x2 con tutti elementi pari a 1
  s.insMat(2,5); // aggiunge una matrice 2x2 con tutti elementi pari a 5
  s.insMat(1,9); // aggiunge una matrice 1x1 con elemento 9
  s.insMat(4,7); // aggiunge una matrice 4x4 con tutti elementi pari a 7
  s.insMat(2,4); // aggiunge una matrice 2x2 con tutti elementi pari a 4
  cout<<s<<endl;

  cout<<"Test dell'operatore -= (deve eliminare le due matrici 4x4)"<<endl;
  s-=4;
  cout<<s<<endl;	
	
  // --- SECONDA PARTE ---	
  
  cout<<"Test dell'operatore ~ (deve fondere le 2 matrici 2x2 in una con tutti 6)"<<endl;
  cout<<~s<<endl;

  cout<<"Test operatore di assegnamento (s2 deve essere uguale ad s)"<<endl;
  SeqMat s2;
  s2.insMat(4,4);
  s2 = s;
  cout<<s2<<endl;

  cout<<"Test dell'incremento unario prefisso"<<endl;
  cout<<"(deve stampare le tre matrici di dimensioni incrementate di 1)"<<endl;
  cout<<++s<<endl;

  {
    cout<<"\nTest del distuttore su s3"<<endl;
    SeqMat s3;
    s3.insMat(5,9);        
  } 
  return 0;
}