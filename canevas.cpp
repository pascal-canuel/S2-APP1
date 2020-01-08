/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas()
{
    coucheActiveIndex = 0;
    couches[coucheActiveIndex].setEtat(Active);
}

Canevas::~Canevas() = default;

bool Canevas::reinitialiser()
{
    bool success = true;

    for (auto & couche : couches) {
        if (!couche.reinitialiser())
            success = false;
    }

    coucheActiveIndex = 0;
    couches[coucheActiveIndex].setEtat(Active);

    return success;
}

bool Canevas::activerCouche(int index)
{
    if (index < 0 || index >= MAX_COUCHES || index == coucheActiveIndex)
        return false;

    if (!couches[coucheActiveIndex].setEtat(Inactive))
        return false;

    if (couches[index].setEtat(Active))
        coucheActiveIndex = index;
    return true;
}

bool Canevas::cacherCouche(int index)
{
    if (index < 0 || index >= MAX_COUCHES)
        return false;

    if (index == coucheActiveIndex)
        coucheActiveIndex = -1 ;

    return couches[index].setEtat(Cachee);
}

bool Canevas::ajouterForme(Forme *p_forme)
{
    if (coucheActiveIndex == -1)
        return false;

    return couches[coucheActiveIndex].ajouterForme(p_forme);
}

bool Canevas::retirerForme(int index)
{
    if (coucheActiveIndex == -1)
        return false;

    return couches[coucheActiveIndex].retraitForme(index);
}

double Canevas::aire()
{
    double aire = 0;

    for (auto & couche : couches) {
        aire += couche.aire();
    }

    return aire;
}

bool Canevas::translater(int deltaX, int deltaY)
{
    if (coucheActiveIndex == -1)
        return false;

    return couches[coucheActiveIndex].translater(deltaX, deltaY);
}

void Canevas::afficher(ostream &s)
{
    for (int i = 0; i < MAX_COUCHES; ++i) {
        s << "----- Couche " << i << endl;
        couches[i].afficher(s);
    }
}
