#include <iostream>
#include "Boule.hpp"

using namespace std;

int main()
{
    Boule A("A", 1, 1);
    Boule B("B", 2, 1);

    A.afficher();
    B.afficher();

    A.deplacement();

    A.afficher();
    B.afficher();

}
