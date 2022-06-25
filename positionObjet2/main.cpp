#include <iostream>
#include <cmath>
#include "Boule.hpp"
#include "Table.hpp"



using namespace std;

int main()
{

    Table table();
    table.innitialisation();


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
