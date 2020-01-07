/********
 * Fichier: graphicus-01.cpp
 * Auteurs: C.-A. Brunet
 * Date: 08 janvier 2018 (creation)
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/
#include "tests.h"
#include <vector>
#include "Vecteur.h"

using namespace std;

int main()
{
//    Tests tests;
//
//    tests.tests_application();

//    std::vector<int> myvector;
//
//    std::cout << "size: " << (int) myvector.size() << '\n';
//    std::cout << "capacity: " << (int) myvector.capacity() << '\n';
    Vecteur<int> nani;
    for (int i = 0; i < 5; ++i) {
        nani.push_back(i);
        std::cout << "size: " << (int) nani.size() << '\n';
        std::cout << "capacity: " << (int) nani.capacity() << '\n';
        std::cout << "---------" << '\n';
    }
    int asd = nani.remove(2);
    std::cout << "asd: " << (int) asd << '\n';
    std::cout << "size: " << (int) nani.size() << '\n';
    std::cout << "capacity: " << (int) nani.capacity() << '\n';
    std::cout << "---------" << '\n';

    nani.push_back(9);
    std::cout << "size: " << (int) nani.size() << '\n';
    std::cout << "capacity: " << (int) nani.capacity() << '\n';
    std::cout << "---------" << '\n';

    asd = nani.remove(4);
    std::cout << "asd: " << (int) asd << '\n';
    std::cout << "size: " << (int) nani.size() << '\n';
    std::cout << "capacity: " << (int) nani.capacity() << '\n';
    std::cout << "---------" << '\n';

    nani.clear();
    std::cout << "size: " << (int) nani.size() << '\n';
    std::cout << "capacity: " << (int) nani.capacity() << '\n';
    std::cout << "---------" << '\n';
    return 0;
}
