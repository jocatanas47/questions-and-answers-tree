#include "Komentar.h"

void Komentar::povecajOcenu(int n) {
	ocena += n;
	for (list<pair<Komentar*, int>>::iterator it = otac->getSinovi().begin(); it != otac->getSinovi().end(); ++it) {
		if (it->first == this) {
			it->second = ocena;
			break;
		}
	}
}

void Komentar::izbrisi() {
	list<pair<Komentar*, int>>::iterator it;
	for (it = otac->getSinovi().begin(); it != otac->getSinovi().end(); ++it) {
		if (it->first == this) {
			break;
		}
	}
	otac->getSinovi().erase(it);
	list<pair<Komentar*, int>> lista(this->getSinovi());
	for (list<pair<Komentar*, int>>::iterator it = lista.begin(); it != lista.end(); ++it) {
		delete it->first;
	}
}
