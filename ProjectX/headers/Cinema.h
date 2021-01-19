#pragma once

#include <string>
#include "..\headers\Sala.h"
#include "..\headers\Film.h"
#include "..\headers\Bilet.h"

class Cinema
{
public:
	Cinema();
	Cinema(string, Sala*, int, Film*, int);

	void setNume(string nume);
	string getNume();

	void setSali(Sala* sali, int nrSali);
	Sala* getSali();

	static void intro();

	void emiteBilet();

private:
	string nume;
	Sala* sali;
	int nrSali;
	Film* filme;
	int nrFilme;
};

