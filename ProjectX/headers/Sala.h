#pragma once

#include <iostream>
#include <string>

using namespace std;

class Sala
{
public:
	const static int MAX_LOCURI = 100; //nr max de locuri a unei sali

	Sala();
	Sala(int, int, int);
	Sala(int, int, int*, int, int*);

	void setNrSala(int);
	int getNrSala();

	void setNrLocuri(int);
	int getNrLocuri();
	
	void setLocuri(int*);
	int* getLocuri();

	void setNrOre(int);
	int getNrOre();

	void setOreRulare(int*);
	int* getOreRulare();

private:
	int nrSala;					//nr salii
	int* locuri;				//locurile ocupate
	int nrLocuri;				//nr de locuri
	int* oreRulare;			
	int nrOre;
};