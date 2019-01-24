#include "compito.h"
#include <iostream>
using namespace std;

int main(){

  //PRIMA PARTE  
  cout<<"-----------------------------------------------------------------"<<endl;
  cout<<"Test del costruttore, della acquista e dell'operatore di uscita"<<endl;
  cout<<"(deve stampare: 40<C>[90=>50]Esselunga )"<<endl;
  Prepagata p1(90); // crea una carta prepagata con 90 euro di credito.
  p1.acquista(40,"Esselunga");
  cout<<p1;
  
  p1.acquista(35,"Carrefour");
  cout<<"-----------------------------------------------------------------"<<endl;
  cout<<"Ora deve stampare anche questa riga: '35<C>[50=>15]Carrefour'"<<endl;
  cout<<p1;
  
  cout<<"-----------------------------------------------------------------"<<endl;
  cout<<"Ed ora anche questa riga: '22<S>[15=>-7]Ikea'"<<endl;
  p1.acquista(22,"Ikea");
  cout<<p1;  

  // SECONDA PARTE
  cout<<"-----------------------------------------------------------------"<<endl;
  cout<<"Visualizzo il saldo potenziale della carta p1 (deve stampare -7)"<<endl;
  cout<<int(p1)<<endl;
  
  cout<<"-----------------------------------------------------------------"<<endl;
  cout<<"Test dell'operatore ! (debbono essere presente solo acq. coperti)"<<endl;  
  cout<<!p1; // modifica p1 eliminando gli acquisti scoperti   
 
  {
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"Test del costruttore di copia (il cont. di p2 deve essere = a p1)"<<endl;
    Prepagata p2(p1);
    cout<<p2;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"Test (implicito) del distruttore"<<endl;
  }
  cout<<"-----------------------------------------------------------------"<<endl;
  
  return 0;
}