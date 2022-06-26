#include "Table.hpp"
#include <ctime>
#include <cmath>
#include "Boule.hpp"

using namespace std;

Table::Table(): m_b1(0)
{
    m_b1 = new Boule();

}


Table::Table(string nom, int x, int y): m_b1(0),m_b2(0)
{
    m_b1 = new Boule(nom,x,y);
    m_b2 = new Boule(nom,x,y);
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



//j'ai trouve que une boule de billard a 57mm de diametre et pas ce que tu as trouve. Quand je reviens je vais continuer mes calculs pour positionner toutes les boules (j'ai deja commence mais pas mis sur le programme)
void Table::innitialisation()
{
    m_b1 =new Boule("1",1,905,0,635);
    m_b2 =new Boule("2",4,7);
    m_b3 =new Boule("3",4,7);
    m_b4 =new Boule("4",4,7);
    m_b5 =new Boule("5",4,7);
    m_b6 =new Boule("6",4,7);
    m_b7 =new Boule("7",4,7);
    m_b8 =new Boule("8",4,7);
    m_b9 =new Boule("9",4,7);
    m_b10 =new Boule("10",4,7);
    m_b11 =new Boule("11",4,7);
    m_b12 =new Boule("12",4,7);
    m_b13 =new Boule("13",4,7);
    m_b14 =new Boule("14",4,7);
    m_b15 =new Boule("15",4,7);
    m_b16 =new Boule("16",4,7);


    cout<<m_b1->positionX()<<endl;

}


