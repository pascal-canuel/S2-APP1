output: main.o tests.o canevas.o couche.o forme.o Rectangle.o Carre.o Cercle.o
	g++ main.o tests.o canevas.o couche.o forme.o Rectangle.o Carre.o Cercle.o -o output

main.o: main.cpp tests.h canevas.h couche.h forme.h coordonnee.h Vecteur.h
	g++ -c main.cpp

tests.o: tests.cpp tests.h canevas.h couche.h forme.h coordonnee.h Vecteur.h
	g++ -c tests.cpp

canevas.o: canevas.cpp canevas.h couche.h forme.h coordonnee.h Vecteur.h
	g++ -c canevas.cpp

couche.o: couche.cpp couche.h forme.h coordonnee.h Vecteur.h
	g++ -c couche.cpp

forme.o: forme.cpp forme.h coordonnee.h
	g++ -c forme.cpp

Rectangle.o: Rectangle.cpp Rectangle.h forme.h coordonnee.h
	g++ -c Rectangle.cpp

Carre.o: Carre.cpp Carre.h forme.h coordonnee.h
	g++ -c Carre.cpp

Cercle.o: Cercle.cpp Cercle.h forme.h coordonnee.h
	g++ -c Cercle.cpp

clean:
	rm *.o output