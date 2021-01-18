#pragma once

#include <iostream>
#include <string>

using namespace std;

class Film
{

public:
	Film();
	Film(int, string, string, int, float);

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

	static float getMedieRating();

private:
	int cod;
	string nume;
	char* tip; // e.g. 2D / 3D
	string categorie; // e.g. fantezie / romantic 
	int minimVarsta;  // e.g. 18 - interzis minorilor / 15 - nerecomendat sub 15 ani etc
	float rating; // e.g. nota filmului e.g. 7.32 pe IMDb de la 1 la 10
	static float medieRating;
};



