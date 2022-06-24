#include "Table1.hpp"
#include <ctime>
#include <cmath>
#include "Boule.hpp"

using namespace std;

Table1::Table1(): m_xt(0),m_yt(0), m_xt2(6), m_yt2(11)
{

}


Table1::Table1(int x, int y, int x2, int y2): m_xt(x), m_yt(y), m_xt2(x2), m_yt2(y2)
{

};


//ca marche pas je n'arrive pas a faire
void Table1::regle(Boule &Boulecopier)
{

    if (Boulecopier.m_x=3 and Boulecopier.m_y =2())
    {
        cout<<"destrcutop"<<endl;
    }

}
