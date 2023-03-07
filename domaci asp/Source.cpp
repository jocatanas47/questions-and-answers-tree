#include "Cvor.h"
#include "Komentar.h"
#include "Pitanje.h"
#include "spisak.h"

#include <iostream>
#include <string>

using namespace std;

void z1(Spisak& spisak) {
	cout << "Opis pitanja: ";
	string opis;
	cin.ignore();
	getline(cin, opis);
	spisak.dodajPitanje(new Pitanje(opis));
}

void z2(Pitanje* pitanje, Komentar* komentar) {
	cout << "Da li zelite da dodate komentar na trenutni odgovor? (da/ne)";
	string tekst;
	cin.ignore();
	getline(cin, tekst);
	Cvor* cvor = nullptr;
	bool flag = true;
	while (flag) {
		if (tekst == "da") {
			cvor = komentar;
			flag = false;
		}
		else {
			if (tekst == "ne") {
				cvor = pitanje;
				flag = false;
			}
			else {
				cout << "Morate da unesete da ili ne" << endl;
			}
		}
	}
	if (cvor == nullptr) {
		throw GNijeSelektovanoPitanje();
	}
	else {
		cout << "Opis Komentara: ";
		string opis;
		getline(cin, opis);
		cvor->dodajKomentar(new Komentar(opis, cvor));
	}
}

Pitanje* z3(Spisak& spisak) {
	cout << "Izaberite redni broj pitanja: ";
	int i;
	cin >> i;
	return spisak.nadjiPitanje(i);
}

 Komentar* z4(Pitanje* trenPitanje) {
	if (trenPitanje == nullptr) {
		throw GNijeSelektovanoPitanje();
	}
	else {
		cout << "Opis trazenog komentara: ";
		string opis;
		cin.ignore();
		getline(cin, opis);
		return trenPitanje->pronadjiOdgovor(opis);
	}
}

void z5(Komentar* trenOdgovor) {
	if (trenOdgovor == nullptr) {
		throw GNijeSelektovanKomentar();
	}
	else {
		cout << "Za koliko zelite da povecate ocenu komentara? ";
		int i;
		cin >> i;
		trenOdgovor->povecajOcenu(i);
	}
}

void z6(Spisak& spisak) {
	spisak.urediPitanja();
	cout << "Pitanja su uredjena!" << endl;
}

void z7(Spisak& spisak) {
	cout << spisak;
}

void z8(Pitanje* trenPitanje) {
	if (trenPitanje == nullptr) {
		throw GNijeSelektovanoPitanje();
	}
	else {
		cout << *trenPitanje;
	}
}

void z9(Komentar* trenKomentar) {
	delete trenKomentar;
	cout << "Komentar uspesno izbrisan" << endl;
}

void z10(Spisak& spisak, Pitanje* pitanje) {
	spisak.izbrisiPitanje(pitanje);
	cout << "Pitanje uspesno izbrisano" << endl;
}

Pitanje* z11(Spisak& spisak) {
	return spisak.najviseKomentara();
}

int main() {
	Spisak spisak;
	Pitanje* trenPitanje = nullptr;
	Komentar* trenKomentar = nullptr;
	cout << "Zahtevi:" << endl
		<< "0. Prekini program" << endl
		<< "1. Dodaj novo pitanje" << endl
		<< "2. Dodaj odgovor na pitanje ili odgovor" << endl
		<< "3. Selektuj pitanje" << endl
		<< "4. Selektuj odgovor" << endl
		<< "5. Povecaj ocenu odgovora" << endl
		<< "6. Uredi odgovore" << endl
		<< "7. Ispisi pitanja" << endl
		<< "8. Ispisi pitanje" << endl
		<< "9. Izbrisi odgovor" << endl
		<< "10. Izbrisi pitanje" << endl
		<< "11. Pitanje sa najvise odgovora" << endl;
	bool loop = true;
	while (loop) {
		try {
			int i;
			cout << "Unesite redni broj zahteva: ";
			cin >> i;
			switch (i) {
			case 1:
				z1(spisak);
				break;
			case 2:
				z2(trenPitanje, trenKomentar);
				break;
			case 3:
				trenPitanje = z3(spisak);
				break;
			case 4:
				trenKomentar = z4(trenPitanje);
				break;
			case 5:
				z5(trenKomentar);
				break;
			case 6:
				z6(spisak);
				break;
			case 7:
				z7(spisak);
				break;
			case 8:
				z8(trenPitanje);
				break;
			case 9:
				z9(trenKomentar);
				trenKomentar = nullptr;
				break;
			case 10:
				z10(spisak, trenPitanje);
				trenPitanje = nullptr;
				break;
			case 11:
				trenPitanje = z11(spisak);
				break;
			case 0:
				loop = false;
				break;
			default:
				break;
			}
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
	}
}