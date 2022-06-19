#include <iostream>
#include <cmath>
#include "Boule.hpp"



using namespace std;

int main()
{

    Boule A("A", 1, 1);
    Boule B("B", 2, 2);

    A.afficher();
    B.afficher();

    A.shoot();
    A.collision(B);

    B.collision(A);

    A.afficher();
    B.afficher();

}
