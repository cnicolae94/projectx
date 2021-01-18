#include "..\headers\Aliment.h"
#include "null_exception.cpp"

using namespace std;

Aliment::Aliment() : codA(-1)
{
	tipA = nullptr;
	numeA = "Undefined";
	pretA = 1.11;
	gramajA = 10;
}

Aliment::Aliment(int codA, string numeA, float pretA, int gramajA) : codA(codA) //avocado - merge linia asta?
{
	this->tipA = nullptr;
	this->numeA = nume;
	this->pretA = pret;
	this->gramajA = gramaj;
}

void Aliment::setCodA(int codA)
{
	this->codA = codA;
}

int Aliment::getCodA()
{
	return codA;
}

void Aliment::setTipA(const char* tipA)
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

char* Aliment::getTipA()
{
	return tip;
}

void Aliment::setNumeA(string numeA)
{
	this->nume = nume;
}

string Aliment::getNumeA();
{
	return nume;
}

void Aliment::setPretA(float pretA)
{
	this->pret = pret;
}

float Aliment::getPretA();
{
	return pret;
}

void Aliment::setGramajA(int gramajA)
{
	this->gramaj = gramaj;
}

int Aliment::getGramajA();
{
	return gramaj;
}