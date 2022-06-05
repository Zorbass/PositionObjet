#include <iostream>
#include "Boule.hpp"
#include "Table.cpp"

using namespace std;

int main()
{
    Boule A("A", 2, 2); // ne pas mettre 0,0 sinon sa beug (le programme change son sens a l'infini)
    Table T(0,0,11,6);
    A.afficher();
    A.deplacement();
    A.afficher();
}
