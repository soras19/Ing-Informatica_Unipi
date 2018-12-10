#include <iostream>
#include "compito.h"
using namespace std;

int main()
{

   // --- PRIMA PARTE ---
   Tetris t;
   t.stampa();		
				
   t.ins('P',0);	// successo      
   t.ins('A',1);	// successo
   t.ins('R',3);	// fallimento
   t.stampa();

	
   // --- SECONDA PARTE ---
	
   // test della funzione 'vuote' (deve produrre 2 in questo caso)
   cout<<"Il numero di righe vuote in t e': "<<t.vuote()<<endl;
		
   // test della 'confronta' (nell'esempio deve dire che t1 e t2 *HANNO* la stessa sagoma)
   Tetris t1;
   t1.ins('P',0);   
   t1.ins('P',0);  
   t1.ins('P',0);
   t1.stampa();
   
   Tetris t2;
   t2.ins('A',0);
   t2.stampa();
   
   if (t1.confronta(t2))
      cout<<"t1 e t2 *HANNO* la stessa sagoma"<<endl<<endl;
   else
      cout<<"t1 e t2 *NON* hanno la stessa sagoma"<<endl<<endl;
		
   // test della funzione 'elimina'
   Tetris t3;
   t3.ins('P',0); t3.ins('R',0); t3.ins('P',2);
   t3.ins('A',3); t3.ins('A',4); 
   t3.ins('A',1); // (notare che quest'ultimo inserimento fallisce)
     
   t3.stampa();
   t3.elimina();
   t3.stampa();

   return 0;
}