//
// Created by Pascal on 2020-01-06.
//

#ifndef GRAPHICUS_02_VECTEUR_H
#define GRAPHICUS_02_VECTEUR_H


#define MAX_SIZE 1073741824

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

    bool push_back(const T& val) {
        if (_size == MAX_SIZE)
            return false;

        _size++;

        if (_capacity == 0) {
            _capacity++;
            array = new T;
            array[0] = val;
        } else if (_size > _capacity) {
            T* prev_array = array;
            _capacity *= 2;
            array = new T[_capacity];

            for (int i = 0; i < _size - 1; ++i) {
                array[i] = prev_array[i];
            }

            array[_size - 1] = val;
            delete [] prev_array;
        } else {
            array[_size - 1] = val;
        }

        return true;
    };

    int size() {
        return _size;
    }

    int capacity() {
        return _capacity;
    }

    void clear() {
        if (!empty()) {
            delete [] array;
            array = nullptr;
        }

        _size = 0;
        _capacity = 0;
    }

    bool empty() {
        return size() == 0;
    }

    // Todo not good
    T remove(int i) {
        if (i < 0 || i >= _size) //  throw "index out of range";
            return nullptr;

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
        return this->operator[](i);
    }

    T operator [](int i) {
        if (i < 0 || i >= _size)    //  throw "index out of range";
            return nullptr;

        return array[i];
    }

private:
    int _size;
    int _capacity;
    T* array;
};


#endif //GRAPHICUS_02_VECTEUR_H
