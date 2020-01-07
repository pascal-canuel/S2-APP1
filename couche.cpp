/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

// Todo

Couche::Couche() {

}

Couche::~Couche() {

}

bool Couche::ajouterForme(Forme *forme) {
    return false;
}

Forme *Couche::retraitForme(int i) {
    return nullptr;
}

Forme *Couche::obtenirForme(int i) {
    return nullptr;
}

double Couche::aire() {
    return 0;
}

bool Couche::translater(int deltaX, int deltaY) {
    return false;
}

bool Couche::reinitialiser() {
    return false;
}

bool Couche::setEtat(Etat etat) {
    return false;
}

void Couche::afficher(ostream &s) {
    if (etat == Initialisee)
        s << "Couche initialisee" << std::endl;
    else if (etat == Cachee)
        s << "Couche cachee" << std::endl;
    else
        for (int i = 0; i < formes.size(); ++i)
            formes[i]->afficher(s);
}
