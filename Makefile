output: main.o tests.o canevas.o couche.o forme.o Rectangle.o Carre.o Cercle.o
	g++ main.o tests.o canevas.o couche.o forme.o Rectangle.o Carre.o Cercle.o -o output

main.o: main.cpp
	g++ -c main.cpp

tests.o: tests.cpp tests.h Vecteur.h
	g++ -c tests.cpp

canevas.o: canevas.cpp canevas.h
	g++ -c canevas.cpp

couche.o: couche.cpp couche.h Vecteur.h
	g++ -c couche.cpp

forme.o: forme.cpp forme.h coordonnee.h
	g++ -c forme.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c Rectangle.cpp

Carre.o: Carre.cpp Carre.h
	g++ -c Carre.cpp

Cercle.o: Cercle.cpp Cercle.h
	g++ -c Cercle.cpp

clean:
	rm *.o output