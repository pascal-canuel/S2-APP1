//
// Created by Pascal on 2020-01-06.
//

#ifndef GRAPHICUS_02_CERCLE_H
#define GRAPHICUS_02_CERCLE_H


#include "forme.h"
#include <math.h>

class Cercle : public Forme {
public:
    explicit Cercle(int x = 0, int y = 0, int rayon = 1): Forme(x, y) {
        this->rayon = rayon;
    };
    ~Cercle() override = default;
    int getRayon();
    void setRayon(int rayon);
    double aire() override;
    void afficher(ostream &s) override;

private:
    int rayon;
};


#endif //GRAPHICUS_02_CERCLE_H
