#include <iostream>
#include <cmath>
#include "Boule.hpp"
#include "Vecteur.hpp"
#include "Table.hpp"

using namespace std;

int main()
{
    Table table("m_b1",3,4);


    table.regle();
    table.innitialisation();




    table.jouer();


   /* Boule A("A", 1, 1);
    Boule B("B", 2, 2);

    A.afficher();
    B.afficher();

    A.shoot();
    A.collision(B);

    B.collision(A);

    A.afficher();
    B.afficher();
*/
}
