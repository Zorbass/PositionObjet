#include <iostream>
#include "Vecteur.hpp"
#include "Boule.hpp"

using namespace std;

int main()
{
    Vecteur vecteur1(7, 10), vecteur2(5, 53);
    Vecteur resultat;

    vecteur1.afficher2();
    cout << "+" << endl;
    vecteur2.afficher();

    resultat = vecteur1 + vecteur2;

    cout << "=" << endl;
    resultat.afficher();

    return 0;
}
