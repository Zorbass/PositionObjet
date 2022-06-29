#include <iostream>
#include "Table.hpp"
#include <ctime>
#include <cmath>
#include "Boule.hpp"
#include "Vecteur.hpp"


using namespace std;

Table::Table()
{

}


Table::Table(string nom, double x, double y): m_nom("1"), m_x(x), m_y(y)
{

}

Table::~Table()
{
    delete m_b1;
    delete m_b2;
    delete m_b3;
    delete m_b4;
    delete m_b5;
    delete m_b6;
    delete m_b7;
    delete m_b8;
    delete m_b9;
    delete m_b10;
    delete m_b11;
    delete m_b12;
    delete m_b13;
    delete m_b14;
    delete m_b15;
    delete m_b16;
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



    vector<Boule*> listeBoules;

    listeBoules.push_back(new Boule("1 pleine",1.905,0.635));
    listeBoules.push_back(new Boule("2 pleine",1.96670431,0.6065));
    listeBoules.push_back(new Boule("3 pleine",1.96670431,0.6635));
    listeBoules.push_back(new Boule("4 pleine",2.02840862,0.692));
    listeBoules.push_back(new Boule("5 pleine",2.02840862,0.578));
    listeBoules.push_back(new Boule("6 pleine",2.09011293,0.5495));
    listeBoules.push_back(new Boule("7 pleine",2.15181724,0.4925));
    listeBoules.push_back(new Boule("8 noire",2.02840862,0.635));
    listeBoules.push_back(new Boule("9 rayee",2.09011293,0.6065));
    listeBoules.push_back(new Boule("10 rayee",2.09011293,0.6635));
    listeBoules.push_back(new Boule("11 rayee",2.09011293,0.7205));
    listeBoules.push_back(new Boule("12 rayee",2.15181724,0.578));
    listeBoules.push_back(new Boule("13 rayee",2.15181724,0.635));
    listeBoules.push_back(new Boule("14 rayee",2.15181724,0.692));
    listeBoules.push_back(new Boule("15 rayee",2.15181724,0.7775));
    listeBoules.push_back(new Boule("blanche",0.635,0.635));


    listeBoules[1]->afficher();
    cout<<"position X: "<<listeBoules[1]->positionX()<<endl;




    m_b1 = listeBoules[0];
    m_b2 = listeBoules[1];
    m_b3 = listeBoules[2];
    m_b4 = listeBoules[3];
    m_b5 = listeBoules[4];
    m_b6 = listeBoules[5];
    m_b7 = listeBoules[6];
    m_b8 = listeBoules[7];
    m_b9 = listeBoules[8];
    m_b10 = listeBoules[9];
    m_b11 = listeBoules[10];
    m_b12 = listeBoules[11];
    m_b13 = listeBoules[12];
    m_b14 = listeBoules[13];
    m_b15 = listeBoules[14];
    m_b16 = listeBoules[15];



     for(int i(0); i<listeBoules.size(); ++i)
    {
        if(listeBoules[i]->deplacement() == true)
        {
            cout<<"verifier collisions avec table"<<endl;
            cout<<"cree carre autour de boule pour savoir quels boule proche"<<endl;
            cout<<"verifier colisions avec boules dans carre"<<endl;
        }
        else
        {
            cout<<"boule "<<i<<" ne se deplace pas"<<endl;
        }
    }







    for(int i(0); i<listeBoules.size(); ++i)
    {
        delete listeBoules[i];
        listeBoules[i] = 0;
    }







    /*
    //creation des 16 boules comme un chinois
    m_b1 =new Boule("1 pleine",1.905,0.635);
    m_b2 =new Boule("2 pleine",1.96670431,0.6065);
    m_b3 =new Boule("3 pleine",1.96670431,0.6635);
    m_b4 =new Boule("4 pleine",2.02840862,0.692);
    m_b5 =new Boule("5 pleine",2.02840862,0.578);
    m_b6 =new Boule("6 pleine",2.09011293,0.5495);
    m_b7 =new Boule("7 pleine",2.15181724,0.4925);
    m_b8 =new Boule("8 noire",2.02840862,0.635);
    m_b9 =new Boule("9 rayee",2.09011293,0.6065);
    m_b10 =new Boule("10 rayee",2.09011293,0.6635);
    m_b11 =new Boule("11 rayee",2.09011293,0.7205);
    m_b12 =new Boule("12 rayee",2.15181724,0.578);
    m_b13 =new Boule("13 rayee",2.15181724,0.635);
    m_b14 =new Boule("14 rayee",2.15181724,0.692);
    m_b15 =new Boule("15 rayee",2.15181724,0.7775);
    m_b16 =new Boule("blanche",0.635,0.635);


    cout<<m_b1->positionX()<<endl;
    cout<<m_b1->positionY()<<endl;
    */

}

//pour tester
void Table::test()
{

}

void Table::jouer()
{
    m_b16->shoot();
    m_b16->afficher();








    /*
    m_b16->afficher();
    m_b8->afficher();

    m_b16->shoot();

    m_b16->collision(*m_b8);
    m_b8->collision(*m_b16);

    m_b16->afficher();
    m_b8->afficher();
    */
}
