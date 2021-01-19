#pragma once

#include <string>
#include "..\headers\Sala.h"

class Cinema
{
public:
	Cinema();
	Cinema(string, Sala*, int);

	void setNume(string nume);
	string getNume();

	void setSali(Sala* sali, int nrSali);
	Sala* getSali();

private:
	string nume;
	Sala* sali;
	int nrSali;
};

