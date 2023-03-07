#ifndef _cvor_h_
#define _cvor_h_

#include <string>
#include <iostream>
#include <list>
#include <stack>

#include "greske.h"

class Komentar;

using namespace std;

class Komentar;

class Cvor {
public:
	Cvor(string opis, int nivo) : opis(opis), nivo(nivo) {}
	virtual void dodajKomentar(Komentar*);
	bool operator==(Cvor& cvor) {
		return opis == cvor.opis;
	}
	int getNivo() {
		return nivo;
	}
	string getOpis() {
		return opis;
	}
	list<pair<Komentar*, int>>& getSinovi() {
		return sinovi;
	}
protected:
	virtual void izbrisi() = 0;
private:
	int nivo;
	string opis;
	list<pair<Komentar*, int>> sinovi;
};

#endif _cvor_h_