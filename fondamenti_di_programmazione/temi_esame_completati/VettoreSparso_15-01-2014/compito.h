#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

struct elem{
	int val, i;
	elem* pun;
};

class VettoreSparso
{
	elem* head;
	int dim;
	void svuota();
public:
	VettoreSparso(int d);
	void set(int val, int index);
	friend ostream& operator << (ostream& os, const VettoreSparso& v);
	void visualizzaComeDenso();
	void reset(int index);
	VettoreSparso& operator *= (int k);
	~VettoreSparso();
};

#endif
