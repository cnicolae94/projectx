#pragma once

#include <iostream>
#include <string>

using namespace std;

class Aliment
{
public:
	Aliment();
	Aliment(int, string, float, int);
	~Aliment();

	void setCod(int);
	int getCod();

	void setTip(const char*);  
	char* getTip();

	void setNume(string); 
	string getNume();

	void setPret(float);
	float getPret();

	void setGramaj(int);
	int getGramaj();
		
private:
	int cod;
	char* tip; // S / M / L / XL / XXL
	string nume;
	float pret;
	int gramaj;
};