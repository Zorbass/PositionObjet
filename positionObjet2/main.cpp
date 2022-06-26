#include <iostream>
#include "Vecteur.hpp"
#include "Boule.hpp"
#include "Table1.hpp"

using namespace std;


int main()
{

    Table1 table(1, 2, 3, 4);
    table.innitialisation();

    /*Vecteur vecteur1(7, 10), vecteur2(5, 53);
    Vecteur resultat;

    cout << vecteur1 << endl;
    cout << "+" << endl;
    cout << vecteur2 << endl;

    resultat = vecteur1 + vecteur2;

    cout << "=" << endl;
    cout << resultat << endl;*/

    Boule B("B",1,1), Z("Z",3,3);

    B.afficher();
    Z.afficher();

    B.shoot();
    B.collision(Z);
    Z.collision(B);

    B.afficher();
    Z.afficher();

    return 0;
}
