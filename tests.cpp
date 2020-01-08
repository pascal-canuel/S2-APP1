/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"

#include "Rectangle.h"
#include "Carre.h"
#include "Cercle.h"

#include <fstream>

void Tests::tests_unitaires_formes()
{
   // Tests sur les formes geometriques
}

void Tests::tests_unitaires_vecteur()
{
   // Tests sur la classe Vecteur
}

void Tests::tests_unitaires_couche()
{
   // Tests sur la classe Couche
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   tests_unitaires_formes();
   tests_unitaires_vecteur();
   tests_unitaires_couche();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   cout << "TESTS APPLICATION (CAS 01)" << endl; 
   // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.

    filebuf fb;
    fb.open("tests_Graphicus_02.txt", ios::out);
    ostream os(&fb);

    Canevas canevas;

    canevas.activerCouche(0);
    canevas.ajouterForme(new Rectangle(2, 3));
    canevas.ajouterForme(new Carre(0, 0,1));
    canevas.ajouterForme(new Cercle(7, 8, 6));

    canevas.cacherCouche(1);

    canevas.activerCouche(2);
    canevas.ajouterForme(new Rectangle(5, 6, 3, 4));
    canevas.ajouterForme(new Carre(3, 4));
    canevas.ajouterForme(new Cercle(0, 0, 3));

    canevas.afficher(os);

    fb.close();
}
