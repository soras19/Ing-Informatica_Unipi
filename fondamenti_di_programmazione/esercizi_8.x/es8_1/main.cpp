#include "iscrizione.h"
#include <iostream>
using namespace std;

int main() {
    
  // PRIMA PARTE
    
  elem* L;
  init(L);
  visualizza(L);

  aggiungi(L, "mario.bianchi", 24);
  aggiungi(L, "sergio.rossi", 6);
  aggiungi(L, "sergio.rossi", 4); //gia' presente
  aggiungi(L, "gianni.verdi", 32);
  aggiungi(L, "luigi.neri", 6);   //gia' presente
  visualizza(L);

  // SECONDA PARTE
  
  cout << cerca(L, "mario.bianchi") << endl;
  elimina(L, "mario.bianchi");
  cout << cerca(L, "mario.bianchi") << endl;
  visualizza(L);

  return 0;
}