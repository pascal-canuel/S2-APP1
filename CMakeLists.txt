cmake_minimum_required(VERSION 3.15)
project(Graphicus_02)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graphicus_02
        main.cpp
        canevas.cpp canevas.h
        coordonnee.h
        couche.cpp couche.h
        forme.cpp forme.h
        tests.cpp tests.h
        Rectangle.cpp Rectangle.h
        Carre.cpp Carre.h
        Cercle.cpp Cercle.h
        Vecteur.h)
