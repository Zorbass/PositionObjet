#include <iostream>
#include <cmath>
#include "Boule.hpp"
#include "Vecteur.hpp"
#include "Table.hpp"
#include "Player.hpp"
#include <vector>

using namespace std;

int main()
{
    Table table;

    table.jouer();

    table.~Table();

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
