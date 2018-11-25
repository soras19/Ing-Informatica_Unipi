#include <iostream>
using namespace std;

class Display{
  int N;
  bool **p;

  void alloca();   // funzioni di utilita'
  void dealloca(); // funzione di utilita'
  
  Display(const Display &); // mascheramento costr. di copia

  public:

  // PRIMA PARTE
  Display(int);
  bool set(char);
  friend ostream & operator <<(ostream &, const Display &);
  
  // SECONDA PARTE  
  Display& operator |=(const Display &);
  void specchia();
  Display& operator =(const Display &);
  ~Display(){dealloca();};
};


