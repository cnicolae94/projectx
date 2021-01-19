#include <iostream>
#include <string>

#include "headers\Bilet.h"
#include "headers\Film.h"
#include "headers\Sala.h"
#include "headers\Aliment.h"
#include "headers\Cinema.h"

using namespace std;

/*
 * Phase 2 - Ticket Selling Point Module
 */
void phase2(); 

Cinema initCinema();

/*
 * Phase 1 - Wrapping function to test functionality 
 */
void phase1();

Film testFilm();
Bilet testBilet(Film film);
Sala testSala();
Aliment testAliment();
Cinema testCinema(Sala* sali, int nrSali);

int main()
{
    // Simply tests class functionality
    // phase1();

    phase2();

    return 0;
}

void phase2()
{
    Cinema cinemaTix = initCinema();

    Cinema::intro(); // Welcome to CinemaTix..
    
    int n;
    bool breakLoop = true;

    do {
		cout << "\nOptiunea dvs: ";
		cin >> n;
        switch (n)
        {
        case 1:
            cinemaTix.emiteBilet();
            breakLoop = true;
            break;
        case 2:
            //Cinema::afiseazaLocuriLibere();
            breakLoop = true;
            break;
        case 3:
            //Cinema::afiseazaFilme();
            breakLoop = true;
            break;
        case 4:
            //Cinema::afiseazaMeniuCrud();
            breakLoop = true;
            break;
        default:
            cout << "Optiunea: " << n << " nu este valida.\
Va rugam selectati una din optiunile: 1 | 2 | 3 | 4\n";

            breakLoop = false;
        }
    } while (!breakLoop);

    cout << "End of phase2!";
}


Cinema initCinema()
{
    const int NR_LOCURI_S1 = 10;
    const int NR_LOCURI_S2 = 25;
    const int NR_LOCURI_S3 = 50;

    int locuriS1[NR_LOCURI_S1] = { 0 };
    int locuriS2[NR_LOCURI_S2] = { 0 };
    int locuriS3[NR_LOCURI_S3] = { 0 };

    const int NR_ORE_S1 = 4;
    const int NR_ORE_S2 = 5;
    const int NR_ORE_S3 = 6;

    int oreS1[NR_ORE_S1] = { 11, 13, 17, 20 };
    int oreS2[NR_ORE_S2] = { 9, 12, 15, 18, 21 };
    int oreS3[NR_ORE_S3] = { 10, 11, 14, 16, 19, 22 };

    Sala s1(1, NR_LOCURI_S1, locuriS1, NR_ORE_S1, oreS1);
    Sala s2(2, NR_LOCURI_S2, locuriS2, NR_ORE_S2, oreS2);
    Sala s3(3, NR_LOCURI_S3, locuriS3, NR_ORE_S3, oreS3);

    Sala sali[3] = { s1, s2, s3 };

    Film f1(1, "Ratatouille", "Pnetru copii", 3, 8.9, s1);
    f1.setTip("2D");

    Film f2(2, "Bee Movie", "Pentru copii", 3, 8.20, s2);
    f2.setTip("3D");

    Film f3(3, "Avengers", "Fantezie", 12, 7.8, s3);
    f3.setTip("3D");

    Film filme[3] = { f1, f2, f3 };

    Cinema cinema("CinemaTix", sali, 3, filme, 3);

    return cinema;
}


void phase1()
{
    Film f1 = testFilm();

    Bilet b1 = testBilet(f1);

    Sala s1 = testSala();

    Sala sali[3] = { s1 };

    Aliment a = testAliment();

    Cinema c1 = testCinema(sali, 3);
}

Film testFilm()
{
    cout << "Testare clasa Film" << endl << endl;

    Film f1;

    f1.setNume("Ratatouille");
    cout << f1.getCod() << endl;
    cout << f1.getCategorie() << endl;
    
    f1.setTip("2D");
    cout << f1.getTip() << endl << endl;

    Film f2(2, "Bee Movie", "Pentru copii", 3, 8.20);
    f2.setTip("3D");

    f1 = f2; // Works
    Film f3(f2); // Works
    cout << f1 << endl;
    cout << f2 << endl;
    cout << f3 << endl;

    cout << f2;
    cout << (int)f2;
    cout << !f2;
    //cout << f2;

    cout << "Nume film: " << f2.getNume() << endl; 
    cout << "Tipul filmului: " << f2.getTip() << endl;
    cout << "Categoria filmului: " << f2.getCategorie() << endl;
    cout << "Varsta minima pentru vizionare: " << f2.getMinim() << endl;
    cout << "Rating film: " << f2.getRating() << endl << endl;

    return f1;
}

Bilet testBilet(Film film)
{
    cout << "Testare clasa Bilet" << endl << endl;

    Bilet b1;
    b1.setFilm(film);

    cout << "BILET SALA  " << b1.getNrSala() << endl;
    cout << "BILET COD " << b1.getCod() << endl;
    cout << "BILET FILM  " << b1.getFilm().getNume() << endl;
    cout << "BILET ORA  " << b1.getOraFilm() << endl;
    cout << "BILET PRET  " << b1.getPret() << endl;
    cout << "BILET NR. LOC  " << b1.getNrLoc() << endl << endl;;

    return b1;
}

Sala testSala()
{
    cout << "Testare clasa Sala" << endl;
    
    Sala s1;
    cout << "Nr. sala: " << s1.getNrSala() << endl;
    cout << "Nr. locuri: " << s1.getNrLocuri() << endl;
    cout << "Nr. max de locuri: " << Sala::MAX_LOCURI << endl;

    const int NR_LOCURI_S2 = 25;
    int locuriS2[NR_LOCURI_S2] = { 0 }; 

    const int NR_ORE_S2 = 5;
    int oreS2[NR_ORE_S2] = { 10, 12, 14, 16, 18 };

    Sala s2(1, NR_LOCURI_S2, NR_ORE_S2);
    s2.setLocuri(locuriS2);
    s2.setOreRulare(oreS2);

    int* ore = s2.getOreRulare();

    cout << endl;
    for (int i = 0; i < NR_ORE_S2; i++) {
        cout << ore[i] << " ";
    }
    cout << endl;

    Sala s3;
    s3 = s2;
    cout << "NR ORE: " << s3.getNrOre() << endl;

    Sala s4(s3);
    cout << s4;


    const int NR_LOCURI_S3 = 50;
    int locuriS3[NR_LOCURI_S2] = { 0 };

    const int NR_ORE_S3 = 4;
    int oreS3[NR_ORE_S3] = { 11, 13, 17, 20 };

    cout << endl;

    return s2;
}

Aliment testAliment()
{
    Aliment a1(123, "Floricele", 13.5, 200);
    a1.setTip("XL");

    cout << a1.getCod() << " | " << a1.getNume() << " | "
        << a1.getTip() << " | " << a1.getPret() << endl;

    return a1;
}

Cinema testCinema(Sala* sali, int nrSali)
{
    Cinema c1;
    cout << "Cinema " << c1.getNume() << endl;

    return c1;
}