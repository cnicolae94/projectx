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
	Sala(const Sala&);
	~Sala();

	Sala& operator=(const Sala&);

	Sala operator++();

	bool operator!();

	int& operator[](int index);
	
	explicit operator int();

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

	friend bool operator==(const Sala& s1, const Sala& s2);
	friend ostream& operator<<(ostream&, Sala);  
	friend istream& operator>>(istream&, Sala&);

private:
	int nrSala;					//nr salii
	int* locuri;				// locurile 0 - liber 1 - ocupat
	int nrLocuri;				//nr de locuri
	int nrLocuriOcupate;
	int* oreRulare;			
	int nrOre;
};