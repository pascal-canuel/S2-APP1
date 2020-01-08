/********
 * Fichier: graphicus-01.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/
#include "tests.h"
#include <fstream>
#include "Vecteur.h"
#include "forme.h"
#include "Rectangle.h"
#include "Carre.h"
#include "Cercle.h"

using namespace std;

int main()
{
//    Tests tests;
//
//    tests.tests_application();

    filebuf fb;
    fb.open("tests_Graphicus_02.txt", ios::out);
    ostream os(&fb);

    Vecteur nani;
    nani.push_back(new Rectangle());
    nani.push_back(new Carre());
    nani.push_back(new Cercle());

    nani.print(os);
    fb.close();
	cout << "Allo Christo" << endl;
	system("pause");
    return 0;
}
