#ifndef _spisak_h_
#define _spisak_h_

#include <vector>
#include <iostream>

#include "Pitanje.h"

using namespace std;

class Spisak {
public:
	void urediPitanja();
	Pitanje* najviseKomentara();
	Pitanje* nadjiPitanje(int);
	void dodajPitanje(Pitanje* pitanje) {
		pitanja.push_back(pitanje);
	}
	void izbrisiPitanje(Pitanje*);
	friend ostream& operator<<(ostream&, Spisak&);
private:
	vector<Pitanje*> pitanja;
};

#endif _spisak_h_