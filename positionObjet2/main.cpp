#include <iostream>
#include <cmath>
#include "Boule.hpp"
#include "Table.hpp"



using namespace std;

int main()
{

    Table table("m_b1",3,4);




    Boule A("A", 1, 1);
    Boule B("B", 2, 2);

    table.innitialisation();
    table.regle();

    A.afficher();
    B.afficher();

    A.shoot();
    A.collision(B);

    B.collision(A);

    A.afficher();
    B.afficher();

}
