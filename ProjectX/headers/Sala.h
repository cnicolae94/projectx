#pragma once

#include <iostream>
#include <string>

using namespace std;

class Sala
{
public:
	Sala();
	Sala(int);

	void setNrSala(int);
	int getNrSala();
	/*
	void setNrMax(int);
	const int getNrMax();
	
	void setNrLocuri(int*);
	int* getNrLocuri();

	void setOreRulare(int*);
	int* getOreRulare();
	|*/

private:
	int nrSala;					//nr salii
	//int nrMaxLocuri;		//nr max de locuri
	//int* locuri;				//locurile ocupate
	//int* oreRulare;
};