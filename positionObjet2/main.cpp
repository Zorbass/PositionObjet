#include <iostream>
#include "Boule.hpp"

using namespace std;

int main()
{
    Boule A("A", 10, 20);
    A.afficher();
    A.deplacement();
    A.afficher();
}
