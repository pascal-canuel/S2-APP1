//
// Created by Pascal on 2020-01-06.
//

#include "Carre.h"

int Carre::getLongueur() {
    return longueur;
}

void Carre::setLongueur(int longueur) {
    this->longueur = longueur;
}

double Carre::aire() {
    return longueur * longueur;
}

void Carre::afficher(ostream &s) {
    s << "Carre (x=" << ancrage.x << ", y=" << ancrage.y << ", c=" << longueur << ", aire=" << aire() << ")" << endl;
}
