//
// Created by Pascal on 2020-01-06.
//

#ifndef GRAPHICUS_02_RECTANGLE_H
#define GRAPHICUS_02_RECTANGLE_H


#include "forme.h"

class Rectangle : public Forme {
public:
    explicit Rectangle(int x = 0, int y = 0, int largeur = 1, int hauteur = 1): Forme(x, y) {
        this->largeur = largeur;
        this->hauteur = hauteur;
    }
    ~Rectangle() override = default;
    int getLargeur();
    void setLargeur(int largeur);
    int getHauteur();
    void setHauteur(int hauteur);
    double aire() override;
    void afficher(ostream &s) override;

private:
    int largeur, hauteur;
};


#endif //GRAPHICUS_02_RECTANGLE_H
