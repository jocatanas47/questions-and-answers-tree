#include "Cvor.h"

void Cvor::dodajKomentar(Komentar* komentar) {
	if (sinovi.size() >= 10) {
		throw GNemaMestaZaSina();
	}
	else {
		sinovi.push_back(pair<Komentar*, int> (komentar, 0));
	}
}