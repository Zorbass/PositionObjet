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

}
