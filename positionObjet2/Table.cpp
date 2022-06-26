#include "Table.hpp"
#include <ctime>
#include <cmath>
#include "Boule.hpp"

using namespace std;

Table::Table(): m_xt(0),m_yt(0), m_xt2(6), m_yt2(11)
{

}


Table::Table(int x, int y, int x2, int y2): m_xt(x), m_yt(y), m_xt2(x2), m_yt2(y2)
{

};






void Table::innitialisation()
{
    cout<<m_x<<endl;
    cout<<m_y<<endl;
    cout<<"3"<<endl;

}


