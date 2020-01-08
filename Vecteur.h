//
// Created by Pascal on 2020-01-07.
//

#ifndef GRAPHICUS_02_VECTEUR_H
#define GRAPHICUS_02_VECTEUR_H


#define MAX_SIZE 1073741823

#include "forme.h"
#include <iostream>

using namespace std;

class Vecteur {
public:
    Vecteur();
    ~Vecteur();

    bool push_back(Forme* forme);
    int size();
    int capacity();
    void clear();
    bool empty();
    Forme* remove(int i);
    Forme* at(int i);
    void print(ostream &os);

    Forme* operator [](int i) {
        if (i < 0 || i >= _size)
            return nullptr;

        return formes[i];
    }

private:
    int _size, _capacity;
    Forme** formes;
};


#endif //GRAPHICUS_02_VECTEUR_H
