#include "Table.hpp"
#include <iostream>

using namespace std;

using namespace std;

Table::Table() : m_x(0), m_y(0), m_x2(11), m_y2(6)
{
}

Table::Table(int x, int y, int x2, int y2) : m_x(x), m_y(y), m_x2(x2), m_y2(y2)
{
}

void Table::innitialisation()
{
    cout << m_x2 << endl;
}
