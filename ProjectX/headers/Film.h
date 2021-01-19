#pragma once

#include <iostream>
#include <string>
#include "Sala.h"

using namespace std;

class Film
{
public:
	Film(); // constructor implicit
	Film(int, string, string, int, float); // constructor explicit
	Film(int, string, string, int, float, Sala); // constructor explicit
	Film(const Film&); // constructor de copiere
	~Film(); // destructor

	Film& operator=(const Film&); // forma supraincarcata a lui =

	Film operator+(int plusVarsta);

	bool operator!();

	Film operator++();

	explicit operator int();

	void setCod(int);
	int getCod();

	void setNume(string);
	string getNume();

	void setTip(const char*);
	char* getTip();

	void setCategorie(string);
	string getCategorie();

	void setMinim(int);
	int getMinim();

	void setRating(float);
	float getRating();

	void setSala(Sala sala);
	Sala getSala();

	static void setDistribuitor(string distribuitor);
	static string getDistribuitor();

	static float getMedieRating(Film* filme, int nrFilme);

	friend bool operator==(const Film& f1, const Film& f2);
	friend ostream& operator<<(ostream&, Film);
	friend istream& operator>>(istream&, Film&);

private:
	int cod;
	string nume;
	char* tip; // e.g. 2D / 3D
	string categorie; // e.g. fantezie / romantic 
	int minimVarsta;  // e.g. 18 - interzis minorilor / 15 - nerecomendat sub 15 ani etc
	float rating; // e.g. nota filmului e.g. 7.32 pe IMDb de la 1 la 10
	Sala sala; // sala unde ruleaza filmul

	static string distribuitor;
};



