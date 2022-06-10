#include <iostream>
#include "Boule.hpp"

using namespace std;

int main()
{
    Boule A("A", 10, 1);
    Boule B("B", 1, 5);

    A.afficher();
    B.afficher();

    A.shoot();
    A.collision(B);



    A.afficher();
    B.afficher();

}
