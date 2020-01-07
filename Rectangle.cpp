//
// Created by Pascal on 2020-01-06.
//

#include "Rectangle.h"

int Rectangle::getLargeur() {
    return largeur;
}

void Rectangle::setLargeur(int largeur) {
    this->largeur = largeur;
}

int Rectangle::getHauteur() {
    return hauteur;
}

void Rectangle::setHauteur(int hauteur) {
    this->hauteur = hauteur;
}

double Rectangle::aire() {
    return largeur * hauteur;
}

void Rectangle::afficher(ostream &s) {
    s << "Rectangle (x=" << ancrage.x << ", y=" << ancrage.y << ", l=" << largeur << ", h=" << hauteur << ", aire=" << aire() << ")" << std::endl;
}
