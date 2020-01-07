//
// Created by Pascal on 2020-01-06.
//

#ifndef GRAPHICUS_02_VECTEUR_H
#define GRAPHICUS_02_VECTEUR_H


#include <iostream>

using namespace std;

template <class T>
class Vecteur {
public:
    Vecteur() {
        _size = 0;
        _capacity = 0;
        array = nullptr;
    }

    ~Vecteur() {
        clear();
    }

    // Todo memcpy
    void push_back(const T& val) {
        _size++;

        if (_capacity == 0) {
            _capacity++;
            array = new T[_capacity];
            array[_size] = val;
            return;
        } else if (_size > _capacity) {
            T* prev_array = array;
            _capacity *= 2;
            array = new T[_capacity];

            for (int i = 0; i < _size - 1; ++i) {
                array[i] = prev_array[i];
            }

            array[_size - 1] = val;
            delete [] prev_array;
        }

        array[_size - 1] = val;
    };

    int size() {
        return _size;
    }

    int capacity() {
        return _capacity;
    }

    void clear() {
        _size = 0;
        _capacity = 0;
        delete [] array;
    }

    bool empty() {
        return size() == 0;
    }

    T remove(int i) {
        if (i < 0 || i >= _size) //  return nullptr;
            throw "index out of range";

        _size--;

        T element = array[i];
        T* prev_array = array;
        array = new T[_size];

        for (int j = 0; j < i; ++j) {
            array[j] = prev_array[j];
        }
        for (int k = i + 1; k < _size + 1; ++k) {
            array[k - 1] = prev_array[k];
        }

        delete [] prev_array;

        return element;
    }

    T at(int i) {
        return this[i];
    }

    T operator [](int i) {
        if (i < 0 || i >= _size)    //  return nullptr;
            throw "index out of range";

        return array[i];
    }

    void print(ostream &os) {
        // Todo
    }

private:
    int _size;
    int _capacity;
    T* array;
};


#endif //GRAPHICUS_02_VECTEUR_H
