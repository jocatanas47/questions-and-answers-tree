#ifndef _pitanje_h_
#define _pitanje_h_

#include <string>
#include <stack>
#include <algorithm>

#include "Cvor.h"
#include "Komentar.h"

class Pitanje : public Cvor {
public:
	Pitanje(string opis) : Cvor(opis, 0) {}
	int ukBrojKomentara();
	void uredi();
	friend ostream& operator<<(ostream&, Pitanje&);
	Komentar* pronadjiOdgovor(string opis);
	~Pitanje() {
		izbrisi();
	}
protected:
	virtual void izbrisi();
private:
};

#endif _pitanje_h_