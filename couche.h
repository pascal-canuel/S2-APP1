/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe Couche gere un vecteur de pointeur de formes
 *    geometriques en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H

#include "Vecteur.h"
#include "forme.h"

enum Etat { Initialisee, Active, Inactive, Cachee };

class Couche
{
public:
    Couche();
    ~Couche();
    bool ajouterForme(Forme* forme);
    Forme* retraitForme(int i);
    Forme* obtenirForme(int i);
    double aire();
    bool translater(int deltaX, int deltaY);
    bool reinitialiser();
    bool setEtat(Etat etat);
    void afficher(ostream &s);

private:
    Vecteur<Forme*> formes;
    Etat _etat;
};

#endif
