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
}



//j'ai trouve que une boule de billard a 57mm de diametre et pas ce que tu as trouve. Quand je reviens je vais continuer mes calculs pour positionner toutes les boules (j'ai deja commence mais pas mis sur le programme)
void Table::innitialisation()
{
/*
    essai d'une type de creation de boules en utilisant des tableau.
    C'est plus long a faire et n'offre pas vraiment d'avantages
    vector<int> numeroBoule(nombreDeBoules);

    int i=0;
    int z=1;

    //nombre de la boule
    while(i<nombreDeBoules)
    {
        numeroBoule[i]=z;
        i++;
        z++;

    }
    i=0;

    vector<string> nomBoule(nombreDeBoules);

    //nom de la boule (oui je sais que ils sont tous appele "1")
    while(i<nombreDeBoules)
    {
       nomBoule[i] ="1";
       i++;
    }
    cout<<nomBoule[numeroBoule[5]]<<endl;

*/

    //creation des 16 boules comme un chinois
    m_b1 =new Boule("1 pleine",1.905,0.635);
    m_b2 =new Boule("2 pleine",1.96670431,0.6065);
    m_b3 =new Boule("3 pleine",1.96670431,0.6635);
    m_b4 =new Boule("4 pleine",2.02840862,0.692);
    m_b5 =new Boule("5 pleine",2.02840862,0.578);
    m_b6 =new Boule("6 pleine",2.09011293,0.5495);
    m_b7 =new Boule("7 pleine",2.15181724,0.4925);
    m_b8 =new Boule("noire",2.02840862,0.635);
    m_b9 =new Boule("9 rayee",2.09011293,0.6065);
    m_b10 =new Boule("10 rayee",2.09011293,0.6635);
    m_b11 =new Boule("11 rayee",2.09011293,0.7205);
    m_b12 =new Boule("12 rayee",2.15181724,0.578);
    m_b13 =new Boule("13 rayee",2.15181724,0.635);
    m_b14 =new Boule("14 rayee",2.15181724,0.692);
    m_b15 =new Boule("15 rayee",2.15181724,0.7775);
    m_b16 =new Boule("blanche",0.635,0.635);

}

void Table::mecanique(Boule &cible)
{
    double f = 0;

    while(m_b1->intensiteeV() > 0 or m_b2->intensiteeV() > 0 or m_b3->intensiteeV() > 0 or m_b4->intensiteeV() > 0 or m_b5->intensiteeV() > 0 or m_b6->intensiteeV() > 0 or m_b7->intensiteeV() > 0 or m_b8->intensiteeV() > 0 or m_b9->intensiteeV() > 0 or m_b10->intensiteeV() > 0 or m_b11->intensiteeV() > 0 or m_b12->intensiteeV() > 0 or m_b13->intensiteeV() > 0 or m_b14->intensiteeV() > 0 or m_b15->intensiteeV() > 0 or m_b16->intensiteeV() > 0)
    {

        m_b1->deplacemelent(f);
        m_b2->deplacemelent(f);
        m_b3->deplacemelent(f);
        m_b4->deplacemelent(f);
        m_b5->deplacemelent(f);
        m_b6->deplacemelent(f);
        m_b7->deplacemelent(f);
        m_b8->deplacemelent(f);
        m_b9->deplacemelent(f);
        m_b10->deplacemelent(f);
        m_b11->deplacemelent(f);
        m_b12->deplacemelent(f);
        m_b13->deplacemelent(f);
        m_b14->deplacemelent(f);
        m_b15->deplacemelent(f);
        m_b16->deplacemelent(f);

        f = clock();

        m_b1->collBoule(cible);
        m_b2->collBoule(cible);
        m_b3->collBoule(cible);
        m_b4->collBoule(cible);
        m_b5->collBoule(cible);
        m_b6->collBoule(cible);
        m_b7->collBoule(cible);
        m_b8->collBoule(*m_b16);
        m_b9->collBoule(cible);
        m_b10->collBoule(cible);
        m_b11->collBoule(cible);
        m_b12->collBoule(cible);
        m_b13->collBoule(cible);
        m_b14->collBoule(cible);
        m_b15->collBoule(cible);
        m_b16->collBoule(cible);

        m_b1->collTable();
        m_b2->collTable();
        m_b3->collTable();
        m_b4->collTable();
        m_b5->collTable();
        m_b6->collTable();
        m_b7->collTable();
        m_b8->collTable();
        m_b9->collTable();
        m_b10->collTable();
        m_b11->collTable();
        m_b12->collTable();
        m_b13->collTable();
        m_b14->collTable();
        m_b15->collTable();
        m_b16->collTable();

        f = clock() - f;
    }
    cout << "fini collisions" << endl;
}

//pour tester
void Table::test()
{
    cout<<m_b10->positionX()<<endl;
    m_b10->afficher();
}

void Table::jouer()
{
    m_b16->afficher();
    m_b8->afficher();

    m_b16->shoot();

    this->mecanique(*m_b8);
//    m_b16->collision(*m_b8);
//    m_b8->collision(*m_b16);


    m_b16->afficher();
    m_b8->afficher();
}
