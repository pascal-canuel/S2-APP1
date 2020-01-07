//
// Created by Pascal on 2020-01-06.
//

#ifndef GRAPHICUS_02_CARRE_H
#define GRAPHICUS_02_CARRE_H


#include "forme.h"

class Carre : public Forme {
public:
    explicit Carre(int x = 0, int y = 0, int longueur = 1): Forme(x, y) {
        this->longueur = longueur;
    };
    ~Carre() override = default;
    int getLongueur();
    void setLongueur(int longueur);
    double aire() override;
    void afficher(ostream &s) override;

private:
    int longueur;
};


#endif //GRAPHICUS_02_CARRE_H
