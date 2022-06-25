#include "Table1.hpp"

using namespace std;

Table1::Table1() : m_x(0), m_y(0), m_x2(11), m_y2(6)
{
}

Table1::Table1(int x, int y, int x2, int y2) : m_x(x), m_y(y), m_x2(x2), m_y2(y2)
{
}

void Table1::innitialisation()
{
    cout << m_x2 << endl;
}
