#include "..\headers\Bilet.h"
#include "..\headers\Film.h"
#include "null_exception.cpp"

using namespace std;

Bilet::Bilet() : cod(-1)
{
	nrSala = 0;
	nrLoc = 0;
	oraFilm = 25;
	pret = -1;

}

Bilet::Bilet(int cod, Film film, int nrSala, int nrLoc, int oraFilm, float pret) : cod(cod)
{
	this->film = film;
	this->nrSala = nrSala;
	this->nrLoc = nrLoc;
	this->oraFilm = oraFilm;
	this->pret = pret;
}

void Bilet::setCod(int cod)
{
	this->cod = cod;
}

int Bilet::getCod()
{
	return cod;
}

void Bilet::setFilm(Film film)
{
	this->film = film;
}

Film Bilet::getFilm()
{
	return film;
}

void Bilet::setNrSala(int nrSala)
{
	this->nrSala = nrSala;
}

int Bilet::getNrSala()
{
	return nrSala;
}

void Bilet::setNrLoc(int nrLoc)
{
	this->nrLoc = nrLoc;
}

int Bilet::getNrLoc()
{
	return nrLoc;
}

void Bilet::setOraFilm(int oraFilm)
{
	this->oraFilm = oraFilm;
}

int Bilet::getOraFilm()
{
	return oraFilm;
}


void Bilet::setPret(float pret)
{
	this->pret = pret;
}

float Bilet::getPret()
{
	return pret;
}
