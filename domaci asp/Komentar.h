#ifndef _komentar_h_
#define _komentar_h_

#include <string>

#include "Cvor.h"

class Komentar : public Cvor {
public:
	Komentar(string opis, Cvor* otac) : Cvor(opis, otac->getNivo() + 1), otac(otac) {}
	void povecajOcenu(int);
	int getOcena() {
		return ocena;
	}
	Cvor* getOtac() {
		return otac;
	}
	~Komentar() {
		izbrisi();
	}
protected:
	virtual void izbrisi();
private:
	int ocena = 0;
	Cvor* otac;
};

#endif _komentar_h_