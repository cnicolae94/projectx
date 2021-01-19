#include "..\headers\Aliment.h"
#include "null_exception.cpp"

using namespace std;

Aliment::Aliment() : cod(-1)
{
	tip = nullptr;
	nume = "Undefined";
	pret = 1.11;
	gramaj = 10;
}

Aliment::Aliment(int cod, string nume, float pret, int gramaj) : cod(cod) //avocado - merge linia asta?
{
	this->tip = nullptr;
	this->nume = nume;
	this->pret = pret;
	this->gramaj = gramaj;
}

Aliment::~Aliment()
{
	if (tip != nullptr) {
		delete[] tip;
	}
}

void Aliment::setCod(int cod)
{
	this->cod = cod;
}

int Aliment::getCod()
{
	return cod;
}

void Aliment::setTip(const char* tip)
{
	if (tip != nullptr) {
		if (this->tip != nullptr) {
			delete[] this->tip;
		}
		this->tip = new char[strlen(tip) + 1];
		strcpy_s(this->tip, strlen(tip) + 1, tip);
	}
	else {
		throw null_exception("tip null");
	}
}

char* Aliment::getTip()
{
	return tip;
}

void Aliment::setNume(string numeA)
{
	this->nume = nume;
}

string Aliment::getNume()
{
	return nume;
}

void Aliment::setPret(float pretA)
{
	this->pret = pret;
}

float Aliment::getPret()
{
	return pret;
}

void Aliment::setGramaj(int gramaj)
{
	this->gramaj = gramaj;
}

int Aliment::getGramaj()
{
	return gramaj;
}