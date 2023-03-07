#include "Spisak.h"

ostream& operator<<(ostream& out, Spisak& spisak)
{
    for (int i = 0; i < spisak.pitanja.size(); i++) {
        out << i << " " << spisak.pitanja[i]->getOpis() << endl;
    }
    return out;
}

void Spisak::urediPitanja()
{
    for (Pitanje* pitanje : pitanja) {
        pitanje->uredi();
    }
}

Pitanje* Spisak::najviseKomentara()
{
    if (pitanja.size() == 0) {
        throw GPrazanSpisak();
    }
    Pitanje* max = pitanja[0];
    int i = 0;
    for (Pitanje* pitanje : pitanja) {
        if (i < pitanje->ukBrojKomentara()) {
            i = pitanje->ukBrojKomentara();
            max = pitanje;
        }
    }
    return max;
}

Pitanje* Spisak::nadjiPitanje(int i)
{
    if (i < 0 || i >= pitanja.size()) {
        throw GNePostojiPitanje();
    }
    return pitanja[i];
}

void Spisak::izbrisiPitanje(Pitanje* pitanje)
{
    bool flag = false;
    for (int i = 0; i < pitanja.size(); i++) {
        if (pitanja[i] == pitanje) {
            pitanja.erase(pitanja.begin() + i);
            flag = true;
            break;
        }
    }
    if (flag) {
        delete pitanje;
    }
}
