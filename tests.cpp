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

const char* boolToString(bool ret) {
    return ret ? "PASS" : "FAIL";
}

void Tests::tests_unitaires_formes()
{
   // Tests sur les formes geometriques
    cout << "----- FORME BEGIN -----" << endl;
    Forme* forme = new Carre(1, 1);
    forme->translater(3, 4);
    cout << "translate forme: " << boolToString(forme->getAncrage().x == 4 && forme->getAncrage().y == 5) << endl;

    forme->setAncrage({6, 6});
    cout << "translate forme: " << boolToString(forme->getAncrage().x == 6 && forme->getAncrage().y == 6) << endl;
    cout << "----- FORME END -----" << endl;

    cout << "----- RECTANGLE BEGIN -----" << endl;
    Rectangle* rectangle = new Rectangle(2, 3, 4, 5);

    rectangle->setHauteur(7);
    cout << "set and get hauteur: " << boolToString(rectangle->getHauteur() == 7) << endl;

    rectangle->setLargeur(8);
    cout << "set and get hauteur: " << boolToString(rectangle->getLargeur() == 8) << endl;

    cout << "aire: " << boolToString(rectangle->aire() == 56) << endl;
    cout << "----- RECTANGLE END -----" << endl;

    cout << "----- CARRE BEGIN -----" << endl;
    Carre* carre = new Carre(6, 7, 8);

    carre->setLongueur(7);
    cout << "set and get longueur: " << boolToString(carre->getLongueur() == 7) << endl;

    cout << "aire: " << boolToString(carre->aire() == 49) << endl;
    cout << "----- CARRE END -----" << endl;

    cout << "----- CERCLE BEGIN -----" << endl;
    Cercle* cercle = new Cercle(9, 10, 11);

    cercle->setRayon(3);
    cout << "set and get rayon: " << boolToString(cercle->getRayon() == 3) << endl;

    cout << "aire: " << boolToString(round(cercle->aire()*1000)/1000 == 28.274) << endl;
    cout << "----- CERCLE END -----" << endl;
}

void Tests::tests_unitaires_vecteur()
{
    // Tests sur la classe Vecteur
    cout << "----- VECTEUR BEGIN -----" << endl;
    Vecteur formes;

    // constructor
    cout << "initial size is 0: " << boolToString(formes.size() == 0) << endl;
    cout << "initial capacity is 0: " << boolToString(formes.capacity() == 0) << endl;
    cout << "vector is empty: " << boolToString(formes.empty()) << endl;

    // push back
    Forme* cercle = new Cercle();
    formes.push_back(cercle);
    cout << "vector forme is added: " << boolToString(formes[0] == cercle) << endl;
    cout << "vector size is 1: " << boolToString(formes.size() == 1) << endl;
    cout << "vector capacity is 1: " << boolToString(formes.size() == 1) << endl;
    cout << "vector is not empty: " << boolToString(!formes.empty()) << endl;

    // capacity doubled
    Forme* carre = new Carre();
    formes.push_back(carre);
    cout << "vector capacity is doubled: " << boolToString(formes.capacity() == 2) << endl;

    // remove
    Forme* removedCarre = formes.remove(1);
    cout << "valid remove return element: " << boolToString(carre == removedCarre) << endl;

    Forme* invalidRemove = formes.remove(1);
    cout << "invalid remove return nullptr: " << boolToString(invalidRemove == nullptr) << endl;

    // at
    Forme* atCercle = formes.at(0);
    cout << "valid at return element: " << boolToString(cercle == atCercle) << endl;

    Forme* invalidAt = formes.remove(1);
    cout << "invalid at return nullptr: " << boolToString(invalidAt == nullptr) << endl;

    // clear
    formes.clear();
    cout << "clear empty vector: " << boolToString(formes.empty()) << endl;

    cout << "----- VECTEUR END -----" << endl;
}

void Tests::tests_unitaires_couche()
{
   // Tests sur la classe Couche
    cout << "----- COUCHE BEGIN -----" << endl;
    cout << "----- COUCHE END -----" << endl;
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
    cout << "----- CANEVAS BEGIN -----" << endl;
    cout << "----- CANEVAS END -----" << endl;
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

    canevas.activerCouche(3);

    canevas.afficher(os);

    fb.close();

    // Todo mem leak when vectors from couches are deleted
}
