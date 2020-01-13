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

    delete forme;
    cout << "get ancrage forme: " << boolToString(forme->getAncrage().x == 4 && forme->getAncrage().y == 5) << endl;

    forme->setAncrage({6, 6});
    cout << "translate forme: " << boolToString(forme->getAncrage().x == 6 && forme->getAncrage().y == 6) << endl;
    cout << "----- FORME END -----" << endl;

    cout << "----- RECTANGLE BEGIN -----" << endl;
    Rectangle* rectangle = new Rectangle(2, 3, 4, 5);

    rectangle->setHauteur(7);
    cout << "set and get hauteur: " << boolToString(rectangle->getHauteur() == 7) << endl;

    rectangle->setLargeur(8);
    cout << "set and get largeur: " << boolToString(rectangle->getLargeur() == 8) << endl;

    cout << "aire: " << boolToString(rectangle->aire() == 56) << endl;
    delete rectangle;
    cout << "----- RECTANGLE END -----" << endl;

    cout << "----- CARRE BEGIN -----" << endl;
    Carre* carre = new Carre(6, 7, 8);

    carre->setLongueur(7);
    cout << "set and get longueur: " << boolToString(carre->getLongueur() == 7) << endl;

    cout << "aire: " << boolToString(carre->aire() == 49) << endl;
    delete carre;
    cout << "----- CARRE END -----" << endl;

    cout << "----- CERCLE BEGIN -----" << endl;
    Cercle* cercle = new Cercle(9, 10, 11);

    cercle->setRayon(3);
    cout << "set and get rayon: " << boolToString(cercle->getRayon() == 3) << endl;

    cout << "aire: " << boolToString(round(cercle->aire()*1000)/1000 == 28.274) << endl;
    delete cercle;
    cout << "----- CERCLE END -----" << endl;
}

void Tests::tests_unitaires_vecteur()
{
    // Tests sur la classe Vecteur
    cout << "----- VECTEUR BEGIN -----" << endl;
    Vecteur<Forme*> formes;

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
    cout << "valid remove return element: " << boolToString(carre == formes.remove(1)) << endl;
    cout << "invalid remove return nullptr: " << boolToString(formes.remove(1) == nullptr) << endl;

    // at
    cout << "valid at return element: " << boolToString(cercle == formes.at(0)) << endl;

    cout << "invalid at return nullptr: " << boolToString(formes.remove(1) == nullptr) << endl;

    // clear
    formes.clear();
    cout << "clear empty vector: " << boolToString(formes.empty()) << endl;

    cout << "----- VECTEUR END -----" << endl;

    delete cercle;
    delete carre;
}

void Tests::tests_unitaires_couche()
{
   // Tests sur la classe Couche
    cout << "----- COUCHE BEGIN -----" << endl;
    Couche couche;

    cout << "can't get forme when empty: " << boolToString(!couche.obtenirForme(0)) << endl;
    cout << "can'g remove forme when empty: " << boolToString(!couche.retraitForme(0)) << endl;

    cout << "can't set init state: " << boolToString(!couche.setEtat(Initialisee)) << endl;
    cout << "can't add forme when init: " << boolToString(!couche.ajouterForme(new Rectangle())) << endl;
    cout << "can't translate forme when init: " << boolToString(!couche.translater(2, 3)) << endl;
    cout << "can't remove forme when init: " << boolToString(!couche.retraitForme(0)) << endl;

    cout << "set inactive state: " << boolToString(couche.setEtat(Inactive)) << endl;
    cout << "can't add forme when inactive: " << boolToString(!couche.ajouterForme(new Rectangle())) << endl;
    cout << "can't translate forme when inactive: " << boolToString(!couche.translater(2, 3)) << endl;
    cout << "can't remove forme when inactive: " << boolToString(!couche.retraitForme(0)) << endl;

    cout << "set hidden state: " << boolToString(couche.setEtat(Cachee)) << endl;
    cout << "can't add forme when hidden: " << boolToString(!couche.ajouterForme(new Rectangle())) << endl;
    cout << "can't translate forme when hidden: " << boolToString(!couche.translater(2, 3)) << endl;
    cout << "can't remove forme when hidden: " << boolToString(!couche.retraitForme(0)) << endl;

    couche.setEtat(Active);

    Forme* carre = new Carre();
    Forme* rectangle = new Rectangle();
    couche.ajouterForme(carre);
    couche.ajouterForme(rectangle);

    cout << "get forme: " << boolToString(couche.obtenirForme(1) == rectangle) << endl;

    couche.translater(2, 2);
    cout << "translate formes: " << boolToString(carre->getAncrage().x == 2 && carre->getAncrage().y == 2 && rectangle->getAncrage().x == 2 && rectangle->getAncrage().y == 2) << endl;

    cout << "aire formes: " << boolToString(couche.aire() == carre->aire() + rectangle->aire()) << endl;

    cout << "remove forme: " << boolToString(rectangle == couche.retraitForme(1) && !couche.obtenirForme(1)) << endl;

    cout << "reinit couche: " << boolToString(couche.reinitialiser()) << endl;

    cout << "----- COUCHE END -----" << endl;
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
    cout << "----- CANEVAS BEGIN -----" << endl;
    Canevas canevas;
    Forme* carre = new Carre(0, 0, 2);
    Forme* rectangle = new Rectangle(0, 0, 2, 3);

    cout << "add forme: " << boolToString(canevas.ajouterForme(carre)) << endl;
    cout << "activate couche: " << boolToString(canevas.activerCouche(1)) << endl;
    canevas.ajouterForme(rectangle);

    cout << "aire canevas: " << boolToString(canevas.aire() == carre->aire() + rectangle->aire()) << endl;
    cout << "hide canevas: " << boolToString(canevas.cacherCouche(1) && canevas.aire() == carre->aire()) << endl;

    canevas.activerCouche(1);
    cout << "remove forme: " << boolToString(canevas.retirerForme(0) && canevas.aire() == carre->aire()) << endl;

    cout << "reinit canevas: " << boolToString(canevas.reinitialiser() && canevas.aire() == 0);

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

//    filebuf fb;
//    fb.open("tests_application_01.txt", ios::out);
//    ostream os(&fb);

    Canevas canevas;

    canevas.activerCouche(1);
    canevas.ajouterForme(new Rectangle());
    canevas.reinitialiser();

    canevas.activerCouche(2);
    for (int i = 0; i < 6; ++i) {
        canevas.ajouterForme(new Cercle(i, i*2, i*3));
    }

    canevas.translater(1, 2);
    canevas.retirerForme(2);

    canevas.afficher(cout);

//    fb.close();
}

void Tests::tests_application_cas_02()
{
    cout << "TESTS APPLICATION (CAS 02)" << endl;
    // Il faut ajouter les operations realisant ce scenario de test.

//    filebuf fb;
//    fb.open("tests_application_02.txt", ios::out);
//    ostream os(&fb);

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

    canevas.afficher(cout);

//    fb.close();
}

void Tests::tests_validation() {

    cout << "TESTS VALIDATION" << endl;
    // Il faut ajouter les operations realisant ce scenario de test.

//    filebuf fb;
//    fb.open("tests_validation.txt", ios::out);
//    ostream os(&fb);

    Canevas canevas;

    canevas.activerCouche(1);
    canevas.ajouterForme(new Rectangle(1, 1));
    canevas.ajouterForme(new Carre(2, 2));
    canevas.ajouterForme(new Cercle(3, 3));

    canevas.activerCouche(2);
    canevas.ajouterForme(new Rectangle(6, 6, 6, 6));

    canevas.afficher(cout);

    cout << "aire: " << canevas.aire() << endl;

    canevas.activerCouche(0);
    canevas.ajouterForme(new Rectangle(7, 7));
    canevas.ajouterForme(new Carre(8, 8));
    canevas.ajouterForme(new Cercle(9, 9));

    canevas.cacherCouche(2);

    canevas.activerCouche(1);
    canevas.translater(1, 1);

    canevas.afficher(cout);

    cout << "aire: " << canevas.aire() << endl;
    canevas.retirerForme(0);
    canevas.afficher(cout);
    cout << "aire: " << canevas.aire() << endl;

    canevas.reinitialiser();
    canevas.afficher(cout);
    cout << "aire: " << canevas.aire() << endl;

//    fb.close();
}
