#include "..\headers\Cinema.h"

Cinema::Cinema() : nume("CinemaTix")
{
	sali = nullptr;
	nrSali = 0;
}

Cinema::Cinema(string nume, Sala* sali, int nrSali) : nume(nume)
{
	if (sali != nullptr && nrSali > 0) {
		this->sali = new Sala[nrSali];
		for (int i = 0; i < nrSali; i++) {
			this->sali[i] = sali[i];
		}

		this->nrSali = nrSali;
	} else { 
		this->sali = nullptr;
		this->nrSali = 0;
	}
}

void Cinema::setNume(string nume)
{
	this->nume = nume;
}

string Cinema::getNume()
{
	return nume;
}

void Cinema::setSali(Sala* sali, int nrSali)
{
	if (sali != nullptr && nrSali > 0) {
		this->sali = new Sala[nrSali];
		for (int i = 0; i < nrSali; i++) {
			this->sali[i] = sali[i];
		}

		this->nrSali = nrSali;
	} else { 
		this->sali = nullptr;
		this->nrSali = 0;
	}
}

Sala* Cinema::getSali()
{
	return sali;
}

