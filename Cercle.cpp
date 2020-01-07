//
// Created by Pascal on 2020-01-06.
//

#include "Cercle.h"

int Cercle::getRayon() {
    return rayon;
}

void Cercle::setRayon(int rayon) {
    this->rayon = rayon;
}

double Cercle::aire() {
    return M_PI * pow(rayon, 2);
}

void Cercle::afficher(ostream &s) {
    // Todo
}
