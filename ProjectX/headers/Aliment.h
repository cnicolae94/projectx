#pragma once

#include <iostream>
#include <string>

using namespace std;

class Aliment
{

public:
	Aliment();
	Aliment(int, string, float, int);

	void setCodA(int);
	int getCodA();

	void setTip(char*);  // avocado
	char* getTipA();

	void setNume(string); 
	string getNumeA();

	void setPret(float);
	float getPretA();

	void setGramaj(int);
	int getGramajA();
		
private:
	int cod;
	char* tip;  // avocado 
	string nume;
	float pret;
	int gramaj;
};