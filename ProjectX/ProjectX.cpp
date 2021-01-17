#include <iostream>
#include <string>

#include "headers\Bilet.h"
#include "headers\Film.h"

using namespace std;

void phase1();

int main()
{
    phase1();

}

void phase1()
{
    Film f1;

    f1.setNume("Ratatouille");
    
    cout << f1.getCod() << endl;
    cout << f1.getCategorie() << endl;
    
    f1.setTip("2D");
    cout << f1.getTip() << endl << endl;

    Film f2(2, "Bee Movie", "Pentru copii", 3, 8.20);
    f2.setTip("3D");

    cout << "Nume film: " << f2.getNume() << endl; 
    cout << "Tipul filmului: " << f2.getTip() << endl;
    cout << "Categoria filmului: " << f2.getCategorie() << endl;
    cout << "Varsta minima pentru vizionare: " << f2.getMinim() << endl;
    cout << "Rating film: " << f2.getRating() << endl << endl;

    Bilet b1;
    b1.setFilm(f2);

    cout << "BILET   " << b1.getNrSala() << endl;
    cout << "BILET   " << b1.getCod() << endl;
    cout << "BILET   " << b1.getFilm().getNume() << endl;
    cout << "BILET   " << b1.getOraFilm() << endl;
    cout << "BILET   " << b1.getPret() << endl;
    cout << "BILET   " << b1.getNrLoc() << endl;


}