#include "compito.h"
#include <iostream>
using namespace std;

int main(){

  //PRIMA PARTE
  cout<<"1/8 Test del costruttore (deve creare un Display 5x5 con tutti i led spenti)"<<endl;
  Display d1(4); 
  cout<<d1<<endl;
	
  cout<<"2/8 Test della set('-') (deve stampare la riga centrale accesa)"<<endl;
  d1.set('-');
  cout<<d1<<endl;
  
  cout<<"3/8 Test della set('|') (deve stampare la colonna centrale accesa)"<<endl;
  Display d2(5);
  d2.set('|');
  cout<<d2<<endl;
	
  cout<<"4/8 Test della set('/') (deve stampare la diagonale ascendente accesa)"<<endl;
  Display d3(7);
  d3.set('/');   
  cout<<d3<<endl;
	
  // SECONDA PARTE

  cout<<"5/8 Test dell'or bit a bit (deve stampare il segno '+')"<<endl;
  d1|=d2;
  cout<<d1<<endl;
	
  cout<<"6/8 Test della 'specchia' (deve stampare la diagonale discendente 7x7 accesa)"<<endl;
  d3.specchia();
  cout<<d3<<endl;
  
  {
    Display d4(3);
    cout<<"7/8 Test dell'operatore di assegnamento (deve stampare l'asta '|' 5x5)"<<endl;
    d4=d2;
    cout<<d4<<endl;
    cout<<"8/8 Test (implicito) del distruttore"<<endl;
  }
  
  return 0;
}
