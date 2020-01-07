//
// Created by Pascal on 2020-01-06.
//

#ifndef GRAPHICUS_02_VECTEUR_H
#define GRAPHICUS_02_VECTEUR_H


template <class T>
class Vecteur {
public:
    Vecteur() {
        _size = 0;
        array = new T[_size];
    }

    ~Vecteur() {
//        delete [] _array;
    }

    void push_back(const T& val) {
        _size++;

        T* prev_array = array;
        array = new T[_size];

        for (int i = 0; i < _size - 1; ++i) {
            array[i] = prev_array[i];
        }

        array[_size - 1] = val;
        delete [] prev_array;
    };

    int size() {
        return _size;
    }

    T operator [](int i) {
        if (i < 0 || i >= _size)
            throw "index out of range";

        return array[i];
    }

private:
    int _size;
    T* array;
};


#endif //GRAPHICUS_02_VECTEUR_H
