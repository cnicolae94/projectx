#include "null_exception.cpp"
#include "..\headers\Sala.h"

Sala::Sala()
{
	//nrMaxLocuri = 100;
	nrSala = 1;
	//oreRulare = nullptr;
	//locuri = nullptr;
}

Sala::Sala(int nrSala) : nrSala(nrSala)
{
	oreRulare = nullptr;
	locuri = nullptr;
	nrMaxLocuri = 100;
}

void Sala::setNrSala(int nrSala)
{
	this->nrSala = nrSala;
}
//
//int Sala::getNrSala()
//{
//	return nrSala;
//}
/*

void Sala::setNrMax(int nrMaxLocuri)
{
	this->nrMaxLocuri = nrMaxLocuri;
}

const Sala::getNrMax()
{
	return nrMaxLocuri;
}

void Sala::setNrLocuri(int* nrLocuri)
{
	// this->nrLocuri = nrLocuri;
}

int* Sala::getNrLocuri()
{
	int* p;
	p[0] = 1; 
	return p;
	// return nrLocuri;
}

void Sala::setOreRulare(int* oreRulare)
{
	this->oreRulare = oreRulare;
}

int* Sala::getOreRulare()
{
	return oreRulare;
}
*/

