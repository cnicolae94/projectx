#include "..\headers\Film.h"
#include "null_exception.cpp"


string Film::distribuitor = "Media Pro Pictures";

Film::Film() : cod(-1)
{
	nume = "Undefined";
	tip = nullptr;
	categorie = "N/A";
	minimVarsta = 1;
	rating = 11;
}

Film::Film(int cod, string nume, string categorie, int minimVarsta, float rating) : cod(cod)
{
	this->nume = nume;
	this->tip = nullptr;
	this->categorie = categorie;
	this->minimVarsta = minimVarsta;
	this->rating = rating;
}

Film::Film(int cod, string nume, string categorie, int minimVarsta, float rating, Sala sala) : cod(cod)
{
	this->nume = nume;
	this->tip = nullptr;
	this->categorie = categorie;
	this->minimVarsta = minimVarsta;
	this->rating = rating;
	this->sala = sala;
}

Film::Film(const Film& f) : cod(f.cod)
{
	nume = f.nume;

	if (f.tip != nullptr) {
		int len = strlen(f.tip) + 1;
		tip = new char[len];
		strcpy_s(tip, len, f.tip);
	}
	else {
		tip = nullptr;
	}

	categorie = f.categorie;
	minimVarsta = f.minimVarsta;
	rating = f.rating;
}

Film::~Film()
{
	if (tip != nullptr) {
		delete[] tip;
	}
}

Film& Film::operator=(const Film& f)
{
	if (tip != nullptr) {
		delete[] tip;
	}

	cod = f.cod;
	nume = f.nume;
	categorie = f.categorie;
	minimVarsta = f.minimVarsta;
	rating = f.rating;
	sala = f.sala;

	if (f.tip != nullptr) {
		int len = strlen(f.tip) + 1;
		tip = new char[len];
		strcpy_s(tip, len, f.tip);
	}
	else {
		tip = nullptr;
	}

	return *this;
}

void Film::setCod(int cod)
{
	this->cod = cod;
}

int Film::getCod()
{
	return cod;
}

void Film::setNume(string nume)
{
	this->nume = nume;
}

string Film::getNume()
{
	return nume;
}

void Film::setTip(const char* tip)
{
	if (tip != nullptr) {
		if (this->tip != nullptr) {
			delete[] this->tip;
		}
		this->tip = new char[strlen(tip) + 1];
		strcpy_s(this->tip, strlen(tip) + 1, tip);
	} else {
		throw null_exception("tip null");
	}
}

char* Film::getTip()
{
	return tip;
}

void Film::setCategorie(string categorie)
{
	this->categorie = categorie;
}

string Film::getCategorie()
{
	return categorie;
}

void Film::setMinim(int minimVarsta)
{
	this->minimVarsta = minimVarsta;
}

int Film::getMinim()
{
	return minimVarsta;
}

void Film::setRating(float rating)
{
	this->rating = rating;
}

float Film::getRating()
{
	return rating; 
}

void Film::setSala(Sala sala)
{
	this->sala = sala;
}

Sala Film::getSala()
{
	return sala;
}

Film Film::operator+(int plusVarsta)
{
	if (plusVarsta < 0) {
		throw 500;
	}

	Film copie = *this;
	copie.minimVarsta += plusVarsta;
	return copie;
}

bool Film::operator!()
{
	return rating > 5;
}

Film Film::operator++()
{
	this->rating++;
	return *this;
}

Film::operator int()
{
	return cod;
}

void Film::setDistribuitor(string distributor)
{
	Film::distribuitor = distribuitor;
}

string Film::getDistribuitor()
{
	return distribuitor;
}

float Film::getMedieRating(Film* filme, int nrFilme)
{
	float suma = 0;
	int contor = 0;
	
	for (int i = 0; i < nrFilme; i++) {
		if (filme[i].rating > 0) {
			suma += filme[i].rating;
			contor++;
		}
	}

	return (contor > 0) ? (suma / contor) : 0;
}

bool operator==(const Film& f1, const Film& f2)
{
	return (f1.nume == f2.nume &&
		f1.categorie == f2.categorie);
}

ostream& operator<<(ostream& out, Film f)
{
	out << "Cod: " << f.cod << endl;
	out << "Nume: " << f.nume << endl;
	if (f.tip != nullptr) {
		out << "Tip: " << f.tip << endl;
	}
	out << "Categorie: " << f.categorie << endl;
	out << "Varsta minima de vizionare: " << f.minimVarsta << endl;
	out << "Rating: " << f.rating << endl;
	out << "Distribuitor: " << Film::distribuitor << endl;

	return out;
}

istream& operator>>(istream& in, Film& f)
{
	cout << "Cod: ";
	in >> f.cod;

	cout << "Nume: ";
	getline(in, f.nume);

	cout << "Tip: ";
	delete[] f.tip;

	char buffer[100];
	in.clear();
	in.ignore(2);
	in.getline(buffer, 99);
	f.tip = new char[strlen(buffer) + 1];
	strcpy_s(f.tip, strlen(buffer) + 1, buffer);

	cout << "Categorie: ";
	getline(in, f.categorie);

	cout << "Minim varsta vizionare: ";
	in >> f.minimVarsta;

	cout << "Rating: ";
	in >> f.rating;

	return in;
}
