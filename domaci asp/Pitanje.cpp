#include "Pitanje.h"

int Pitanje::ukBrojKomentara() {
	int i = 0;
	stack<Komentar*> stek;
	for (list<pair<Komentar*, int>>::reverse_iterator rit = getSinovi().rbegin(); rit != getSinovi().rend(); ++rit) {
		stek.push(rit->first);
	}
	while (!stek.empty()) {
		Komentar* tren = stek.top();
		stek.pop();
		i++;
		for (list<pair<Komentar*, int>>::reverse_iterator rit = tren->getSinovi().rbegin(); rit != tren->getSinovi().rend(); ++rit) {
			stek.push(rit->first);
		}
	}
	return i;
}

void Pitanje::uredi() {
	stack<Komentar*> stek;
	for (list<pair<Komentar*, int>>::reverse_iterator rit = getSinovi().rbegin(); rit != getSinovi().rend(); ++rit) {
		stek.push(rit->first);
	}
	getSinovi().sort([](const pair<Komentar*, int>& x, const pair<Komentar*, int>& y) {return x.second > y.second; });
	while (!stek.empty()) {
		Komentar* tren = stek.top();
		stek.pop();
		for (list<pair<Komentar*, int>>::reverse_iterator rit = tren->getSinovi().rbegin(); rit != tren->getSinovi().rend(); ++rit) {
			stek.push(rit->first);
		}
		tren->getSinovi().sort([](const pair<Komentar*, int>& x, const pair<Komentar*, int>& y) {return x.second > y.second; });
	}
}

Komentar* Pitanje::pronadjiOdgovor(string opis) {
	stack<Komentar*> stek;
	for (list<pair<Komentar*, int>>::reverse_iterator rit = getSinovi().rbegin(); rit != getSinovi().rend(); ++rit) {
		stek.push(rit->first);
	}
	while (!stek.empty()) {
		Komentar* tren = stek.top();
		stek.pop();
		if (tren->getOpis() == opis) {
			return tren;
		}
		for (list<pair<Komentar*, int>>::reverse_iterator rit = tren->getSinovi().rbegin(); rit != tren->getSinovi().rend(); ++rit) {
			stek.push(rit->first);
		}
	}
	return nullptr;
}

void Pitanje::izbrisi() {
	list<pair<Komentar*, int>> lista(this->getSinovi());
	for (list<pair<Komentar*, int>>::iterator it = lista.begin(); it != lista.end(); ++it) {
		delete it->first;
	}
}

ostream& operator<<(ostream& out, Pitanje& pitanje) {
	stack<Komentar*> stek;
	out << pitanje.getOpis() << endl;
	for (list<pair<Komentar*, int>>::reverse_iterator rit = pitanje.getSinovi().rbegin(); rit != pitanje.getSinovi().rend(); ++rit) {
		stek.push(rit->first);
	}
	while (!stek.empty()) {
		Komentar* tren = stek.top();
		stek.pop();
		string indent = "";
		for (int i = 0; i < tren->getNivo(); i++) {
			indent += " ";
		}
		out << indent << tren->getOpis() << " (" << tren->getOcena() << ")" << endl;
		for (list<pair<Komentar*, int>>::reverse_iterator rit = tren->getSinovi().rbegin(); rit != tren->getSinovi().rend(); ++rit) {
			stek.push(rit->first);
		}
	}
	return out;
}