#include "Boule.hpp"
#include <ctime>
#include <cmath>
#include "Table.hpp"

using namespace std;

Table::Table(): m_xt(0), m_xy(0), m_xt2(11), m_yt2(6)
{

}
Table::Table(int x , int y,  int x2, int y2) : m_xt(x), m_yt(y), m_xt2(x2), m_yt2(y2)
{
}

Table::innitialiser()
{
    Boule 1("1",2,3)

}
