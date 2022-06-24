#include <iostream>
#include <cmath>
#include "Boule.hpp"
#include "Table1.hpp"



using namespace std;

int main()
{

    Table1();
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
