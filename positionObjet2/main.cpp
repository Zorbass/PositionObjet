#include <iostream>
#include <cmath>
#include "Boule.hpp"
#include "Vecteur.hpp"
#include "Table.hpp"

using namespace std;

int main()
{
    Table table("m_b1",3,4);
    /*
    Vecteur a(1,3);
    Vecteur b(4,5);
    if(a<b)
    {
        cout<<"petit"<<endl;
    }
    else
    {
        cout<<"pas plut petit"<<endl;
    }
    */



    table.innitialisation();
    table.regle();

    cout<<"ok"<<endl;




    table.jouer();

    table.detruire();


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
