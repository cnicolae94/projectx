#pragma once

#include <iostream>
#include <string>
#include "Film.h"

using namespace std;

class Bilet
{
public:

	Bilet();
	Bilet(int, Film, int, int, int, float);

	void setCod(int);
	int getCod();

	void setFilm(Film);
	Film getFilm();

	void setNrSala(int);
	int getNrSala();

	void setNrLoc(int);
	int getNrLoc();

	void setOraFilm(int);
	int getOraFilm();

	void setPret(float);
	float getPret();

private:
	int cod;
	Film film;
	int nrSala;
	int nrLoc;
	int oraFilm;
	float pret;
	
};


