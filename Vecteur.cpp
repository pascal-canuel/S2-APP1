//
// Created by Pascal on 2020-01-07.
//

#include "Vecteur.h"

Vecteur::Vecteur() {
    _size = 0;
    _capacity = 0;
    formes = nullptr;
}

Vecteur::~Vecteur() {
    clear();
}

bool Vecteur::push_back(Forme *forme) {
    _size++;

    if (_capacity == 0) {
        _capacity++;
        formes = new Forme*;
        formes[0] = forme;
    } else if (_size > _capacity) {
        Forme** prev_array = formes;
        _capacity *= 2;
        formes = new Forme*[_capacity];

        for (int i = 0; i < _size - 1; ++i) {
            formes[i] = prev_array[i];
        }

        formes[_size - 1] = forme;
        delete [] prev_array;
    } else
        formes[_size - 1] = forme;

    return _size != MAX_SIZE;
}

int Vecteur::size() {
    return _size;
}

int Vecteur::capacity() {
    return _capacity;
}

void Vecteur::clear() {
    _size = 0;
    _capacity = 0;
    delete [] formes;
}

bool Vecteur::empty() {
    return size() == 0;
}

Forme *Vecteur::remove(int i) {
    if (i < 0 || i >= _size)
        return nullptr;

    _size--;

    Forme* forme = formes[i];
    Forme** prev_formes = formes;
    formes = new Forme*[_size];

    for (int j = 0; j < i; ++j) {
        formes[j] = prev_formes[j];
    }
    for (int k = i + 1; k < _size + 1; ++k) {
        formes[k - 1] = prev_formes[k];
    }

    delete [] prev_formes;

    return forme;
}

Forme *Vecteur::at(int i) {
    return this->operator[](i);
}

void Vecteur::print(ostream &os) {
    for (int i = 0; i < _size; ++i)
        formes[i]->afficher(os);
}
