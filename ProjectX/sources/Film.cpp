#include "..\headers\Film.h"
#include "null_exception.cpp"

Film::Film() : cod(-1)
{
	nume = "Undefined";
	tip = nullptr;
	oreRulare = nullptr;
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

float Film::getMedieRating()
{
	float a = 7;
	return a;
}



