#include <iostream>
#include <cstring>
using namespace std;

struct riga{ 
  char id[6];
  int voto;
  int cfu;
};

class Libretto{
  riga* vett;
  int nVoci;
  int quanteVoci;	
  Libretto(const Libretto&);  // mascheramento costr. copia
 
public:
  Libretto(int);    
  bool aggiungi(const char*, int, int);
  double media()const;
  friend ostream& operator<<(ostream&, const Libretto&);
  // --- SECONDA PARTE ---
  Libretto& operator = (const Libretto&);
  double laurea()const;
  ~Libretto();
};

