#ifndef _greske_h_
#define _greske_h_

#include <exception>

using namespace std;

class GNemaMestaZaSina : public exception {
public:
	GNemaMestaZaSina() : exception("Greska: Moguce je dodati maksimalno 10 sinova") {}
};

class GNijeSelektovanoPitanje : public exception {
public:
	GNijeSelektovanoPitanje() : exception("Greska: Niste selektovali pitanje") {}
};

class GNijeSelektovanKomentar : public exception {
public:
	GNijeSelektovanKomentar() : exception("Greska: Niste selektovali komentar") {}
};

class GNePostojiPitanje : public exception {
public:
	GNePostojiPitanje() : exception("Greska: Ne postoji pitanje sa tim rednim brojem") {}
};

class GPrazanSpisak : public exception {
public:
	GPrazanSpisak() : exception("Greska: Spisak je prazan") {}
};

#endif _greske_h_