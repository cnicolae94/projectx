#include "null_exception.cpp"
#include "..\headers\Sala.h"

Sala::Sala() : nrSala(0)
{
	nrLocuri = 25;
	nrLocuriOcupate = 0;
	nrOre = 5;
	oreRulare = nullptr;
	locuri = nullptr;
}

Sala::Sala(int nrSala, int nrLocuri, int nrOre) : nrSala(nrSala)
{
	this->nrLocuri = nrLocuri;
	nrLocuriOcupate = 0;
	this->nrOre = nrOre;
	oreRulare = nullptr;
	locuri = nullptr;
}

Sala::Sala(int nrSala, int nrLocuri, int* locuri, int nrOre, int* oreRulare) : nrSala(nrSala) 
{
	if (locuri != nullptr && nrLocuri > 0) {
		this->locuri = new int[nrLocuri];
		for (int i = 0; i < nrLocuri; i++) {
			this->locuri[i] = locuri[i];
		}

		this->nrLocuri = nrLocuri;

	} else {
		this->locuri = nullptr;
		this->nrLocuri = 0;
	}

	if (oreRulare != nullptr && nrOre > 0) {
		this->oreRulare = new int[nrOre];
		for (int i = 0; i < nrOre; i++) {
			this->oreRulare[i] = oreRulare[i];
		}
		this->nrOre = nrOre;

	} else {
		this->oreRulare = nullptr;
		this->nrOre = 0;
	}

	nrLocuriOcupate = 0;
}

Sala::~Sala()
{
	if (locuri != nullptr) {
		delete[] locuri;
	}
	if (oreRulare != nullptr) {
		delete[] oreRulare;
	}
}

Sala::Sala(const Sala& s) : nrSala(s.nrSala)
{
	this->nrLocuriOcupate = s.nrLocuriOcupate;

	if (s.locuri != nullptr && s.nrLocuri > 0)
	{
		nrLocuri = s.nrLocuri;
		locuri = new int[s.nrLocuri];
		for (int i = 0; i < s.nrLocuri; i++)
		{
			locuri[i] = s.locuri[i];
		}
	}
	else
	{
		locuri = nullptr;
		nrLocuri = 0;
	}

	if (s.oreRulare != nullptr && s.nrOre > 0)
	{
		nrOre = s.nrOre;
		oreRulare = new int[s.nrOre];
		for (int i = 0; i < s.nrOre; i++)
		{
			oreRulare[i] = s.oreRulare[i];
		}
	}
	else {
		oreRulare = nullptr;
		nrOre = 0;
	}
}

Sala& Sala::operator=(const Sala& s)
{
	nrSala = s.nrSala;
	nrLocuriOcupate = s.nrLocuriOcupate;

	if (s.locuri != nullptr && s.nrLocuri > 0)
	{
		nrLocuri = s.nrLocuri;
		locuri = new int[s.nrLocuri];
		for (int i = 0; i < s.nrLocuri; i++)
		{
			locuri[i] = s.locuri[i];
		}
	}
	else {
		locuri = nullptr;
		nrLocuri = 0;
	}

	if (s.oreRulare != nullptr && s.nrOre > 0)
	{
		nrOre = s.nrOre;
		oreRulare = new int[s.nrOre];
		for (int i = 0; i < s.nrOre; i++)
		{
			oreRulare[i] = s.oreRulare[i];
		}
	}
	else {
		oreRulare = nullptr;
		nrOre = 0;
	}

	return *this;
}

bool Sala::operator!()
{
	return nrLocuriOcupate == nrLocuri;
}

int& Sala::operator[](int nrLoc) throw (exception)
{
	if (nrLoc >= 0 && nrLoc < nrLocuri && locuri != nullptr) {
		return locuri[nrLoc];
	}
	else {
		throw exception("Numarul locului nu exista!");
	}
}

Sala::operator int()
{
	return nrLocuriOcupate;
}


void Sala::setNrSala(int nrSala)
{
	this->nrSala = nrSala;
}

int Sala::getNrSala()
{
	return nrSala;
}

void Sala::setNrLocuri(int nrLocuri)
{
	this->nrLocuri = nrLocuri;
}

int Sala::getNrLocuri()
{
	return nrLocuri;
}

void Sala::setLocuri(int* locuri)
{
	if (this->locuri != nullptr) {
		delete[] this->locuri;
	}

	if (locuri != nullptr && nrLocuri > 0) {
		this->locuri = new int[nrLocuri];
		for (int i = 0; i < nrLocuri; i++) {
			this->locuri[i] = locuri[i];
		}
		this->nrLocuri = nrLocuri;
	}
	else {
		this->locuri = nullptr;
		this->nrLocuri = 0;
	}
}

int* Sala::getLocuri()
{
	return locuri;
}

void Sala::setNrOre(int nrOre)
{
	this->nrOre = nrOre;
}

int Sala::getNrOre()
{
	return nrOre;
}

Sala Sala::operator++() throw (exception)
{
	if (nrLocuriOcupate < nrLocuri) {
		nrLocuriOcupate++;
		for (int i = nrLocuriOcupate; i < nrLocuri; i++) {
			locuri[i] = 1;
		}
	}
	else {
		throw exception("Sala este plina!");
	}
}
	
void Sala::setOreRulare(int* oreRulare)
{
	if (this->oreRulare != nullptr) {
		delete[] this->oreRulare;
	}

	if (oreRulare != nullptr && nrOre > 0) {
		this->oreRulare = new int[nrOre];
		for (int i = 0; i < nrOre; i++) {
			this->oreRulare[i] = oreRulare[i];
		}
		this->nrOre = nrOre;
	}
	else {
		this->oreRulare = nullptr;
		this->nrOre = 0;
	}
}

int* Sala::getOreRulare()
{
	return oreRulare;
}

bool operator==(const Sala& s1, const Sala& s2)
{
	return (s1.nrSala == s2.nrSala);
}

ostream& operator<<(ostream& out, Sala s)
{
	out << "Nr. Sala: " << s.nrSala << endl;
	out << "Nr. Locuri Total: " << s.nrLocuri << endl;
	out << "Nr. Locuri Ocupate: " << s.nrLocuriOcupate << endl;

	out << "Ore rulare: " << endl;
	for (int i = 0; i < s.nrOre; i++) {
		out << s.oreRulare[i] << " ";
	}
	out << endl;

	return out;
}

istream& operator>>(istream& in, Sala& s) throw (exception)
{
	cout << "Nr. Sala: ";
	in >> s.nrSala;

	cout << "Nr. Locuri: ";
	in >> s.nrLocuri;

	if (s.nrLocuri <= Sala::MAX_LOCURI) {
		s.locuri = new int[s.nrLocuri];
	}
	else {
		throw exception("Nr maxim de locuri depasit!");
	}

	cout << "Nr. Ore de Rulare: ";
	in >> s.nrOre;

	s.oreRulare = new int[s.nrOre];
	for (int i = 0; i < s.nrOre; i++) {
		in >> s.oreRulare[i];
	}

	s.nrLocuriOcupate = 0;

	return in;
}
