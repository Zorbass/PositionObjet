#include <iostream>
#include <cmath>
#include "Boule.hpp"
#include "Table.hpp"
#include <vector>



using namespace std;

int main()
{

    Table table("m_b1",3,4);

    table.innitialisation();
    table.regle();

    table.test();



}
