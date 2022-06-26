#include "Table.hpp"
#include <ctime>
#include <cmath>
#include "Boule.hpp"

using namespace std;

Table::Table(): m_b1(0)
{
    m_b1 = new Boule();

}


Table::Table(string nom, int x, int y): m_b1(0)
{
    m_b1 = new Boule(nom,x,y);
}

Table::~Table()
{
    delete m_b1;
}


void Table::regle()
{
    if(m_b1->positionX()==3)
    {
        cout<<"detruire"<<endl;


    }
}




void Table::innitialisation()
{

    cout<<m_b1->positionX()<<endl;

}


