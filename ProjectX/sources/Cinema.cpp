#include "..\headers\Cinema.h"

Cinema::Cinema() : nume("CinemaTix")
{
	sali = nullptr;
	filme = nullptr;
	nrSali = 0;
	nrFilme = 0;
}

Cinema::Cinema(string nume, Sala* sali, int nrSali, Film* filme, int nrFilme) : nume(nume)
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

	if (filme != nullptr && nrFilme > 0) {
		this->filme = new Film[nrFilme];
		for (int i = 0; i < nrFilme; i++) {
			this->filme[i] = filme[i];
		}

		this->nrFilme = nrFilme;
	} else { 
		this->filme = nullptr;
		this->nrFilme = 0;
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

void Cinema::intro()
{
	cout << "Bine ati venit la CinemaTix. Cinema-ul digital care te ajuta sa \
gestionezi emiterea de bilete in 2 timpi si 3 miscari" << endl;

	cout << "\nCe operatiune ati dori sa efectuati?\n\n";
	cout << "1. Emitere Bilet \n\
2. Situatie locuri libere \n\
3. Filme\n\
4. Alte operatii \n";

}

void Cinema::emiteBilet()
{
	int index;
	Bilet b;

	int randNum = rand() % 10000 + 1;
	b.setCod(randNum);

	cout << "\nCe filme ati dorit sa vizionati?\n\n";
	for (int i = 0; i < nrFilme; i++) {
		cout << filme[i].getCod() << ". " << filme[i] << endl;
	}

	cout << "Optiunea dvs: ";
	int optiune;
	cin >> optiune;

	Film filmAles = filme[optiune - 1];

	Sala tempSala = filmAles.getSala();

	int nrSala = tempSala.getNrSala();

	b.setFilm(filmAles);

	cout << "\nIn regula. Filmul " << filmAles.getNume()
		<< " ruleaza in sala " << filmAles.getSala().getNrSala()
		<< " la urmatoarele ore:\n";

	int nrOre = filmAles.getSala().getNrOre();
	int* ore = filmAles.getSala().getOreRulare();

	for (int i = 0; i < nrOre; i++) {
		cout << ore[i] << " ";
	}

	cout << "La ce ora ati dori sa vizionati filmul?\n";
	int ora;
	cin >> ora;
	cout << endl;

	b.setOraFilm(ora);

	cout << "Aveti biletul nr. " << b.getCod()
		<< "\nFilm: " << b.getFilm().getNume()
		<< "\nSala: " << b.getFilm().getSala().getNrSala()
		<< "\nLocul: " << b.getNrLoc() 
		<< "\nOra: " << b.getOraFilm() << endl;

	cout << "Vizionare placuta!";
}




