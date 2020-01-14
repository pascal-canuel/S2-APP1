output: main.o tests.o canevas.o couche.o forme.o Rectangle.o Carre.o Cercle.o
	g++ -std=c++11 main.o tests.o canevas.o couche.o forme.o Rectangle.o Carre.o Cercle.o -o output

main.o: main.cpp tests.h canevas.h couche.h forme.h coordonnee.h Vecteur.h
	g++ -std=c++11 -c main.cpp

tests.o: tests.cpp tests.h canevas.h couche.h forme.h coordonnee.h Vecteur.h
	g++ -std=c++11 -c tests.cpp

canevas.o: canevas.cpp canevas.h couche.h forme.h coordonnee.h Vecteur.h
	g++ -std=c++11 -c canevas.cpp

couche.o: couche.cpp couche.h forme.h coordonnee.h Vecteur.h
	g++ -std=c++11 -c couche.cpp

forme.o: forme.cpp forme.h coordonnee.h
	g++ -std=c++11 -c forme.cpp

Rectangle.o: Rectangle.cpp Rectangle.h forme.h coordonnee.h
	g++ -std=c++11 -c Rectangle.cpp

Carre.o: Carre.cpp Carre.h forme.h coordonnee.h
	g++ -std=c++11 -c Carre.cpp

Cercle.o: Cercle.cpp Cercle.h forme.h coordonnee.h
	g++ -std=c++11 -c Cercle.cpp

clean:
	rm *.o output
