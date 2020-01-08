/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche() {
    _etat = Initialisee;
}

Couche::~Couche() = default;

bool Couche::ajouterForme(Forme *forme) {
    if (_etat != Active)
        return false;

    return formes.push_back(forme);
}

Forme *Couche::retraitForme(int i) {
    if (_etat != Active)
        return nullptr;

    return formes.remove(i);
}

Forme *Couche::obtenirForme(int i) {
    return formes.at(i);
}

double Couche::aire() {
    if (_etat == Cachee)
        return 0;

    double aire = 0;

    for (int i = 0; i < formes.size(); ++i) {
        aire += formes[i]->aire();
    }

    return aire;
}

bool Couche::translater(int deltaX, int deltaY) {
    if (_etat != Active)
        return false;

    for (int i = 0; i < formes.size(); ++i)
        formes[i]->translater(deltaX, deltaY);

    return true;
}

bool Couche::reinitialiser() {
    _etat = Initialisee;
    formes.clear();

    return formes.empty();
}

bool Couche::setEtat(Etat etat) {
    if (etat == Initialisee)
        return false;

    this->_etat = etat;
    return true;
}

void Couche::afficher(ostream &s) {
    if (_etat == Initialisee)
        s << "Couche initialisee" << endl;
    else if (_etat == Cachee)
        s << "Couche cachee" << endl;
    else if (formes.empty())
        s << "Couche vide" << endl;
    else
        formes.print(s);
}
