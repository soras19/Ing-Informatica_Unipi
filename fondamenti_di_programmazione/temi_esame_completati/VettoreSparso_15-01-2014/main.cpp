#include <iostream>
#include "compito.h"
using namespace std;

int main(){
  // --- PRIMA PARTE ---
  cout<<"\nTest del costruttore ( deve stampare [7]{} )"<<endl;
  VettoreSparso s(7); // crea un VettoreSparso di 7 elementi tutti nulli e nessuna entrata
  cout<<s<<endl;      // stampa a video il vettore sparso
		
  cout<<"\nTest della set ( deve stampare [7]{(-2,1)(4,3)(8,5)} )"<<endl;
  s.set(8,5);      // aggiunge l'entrata (8,5)
  s.set(-2,1);     // aggiunge l'entrata (-2,1)
  s.set(4,3);      // aggiunge l'entrata (4,3)  
  cout<<s<<endl;
	
  // --- SECONDA PARTE ---
  cout<<"\nTest della visualizzaComeDenso ( deve stampare < 0 -2 0 4 0 8 0 > )"<<endl;
  s.visualizzaComeDenso();
	cout<<endl;

  cout<<"\nTest della reset ( deve stampare [7]{(-9,1)(8,5)} )"<<endl;
  s.set(-9,1);     // cambia il valore dell'entrata di indice 1	
  s.reset(3);      // elimina l'entrata di indice 3, ossia la (4,3)
  cout<<s<<endl;
	
	cout<<"\nTest dell'operatore *= ( deve stampare [7]{(-18,1)(16,5)} )"<<endl;
  s*=2;
  cout<<s<<endl;

  cout<<"\nAltro test dell'operatore *=, nel caso k=0 ( deve stampare [7]{} )"<<endl;
  s*=0;
  cout<<s<<endl;

	{	
    cout<<"\nAltro test della reset e test del distuttore ( deve stampare [9]{} )"<<endl;
		VettoreSparso s2(9);
		s2.set(-5,4);
		s2.reset(4);
		cout<<s2<<endl;
    //  qui avviene la chiamata al distruttore dell'oggetto s2
	} 
	return 0;
}
