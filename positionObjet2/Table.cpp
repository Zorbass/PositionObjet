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
    /*
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
    */
    delete boules;
}


void Table::regle()
{

    cout<<boules[1].positionX()<<endl;



}



//j'ai trouve que une boule de billard a 57mm de diametre et pas ce que tu as trouve. Quand je reviens je vais continuer mes calculs pour positionner toutes les boules (j'ai deja commence mais pas mis sur le programme)
void Table::innitialisation()
{




    /*
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
    cout<<listeBoules.size()<<endl;

    listeBoules[1]->afficher();
    cout<<"position X: "<<listeBoules[1]->positionX()<<endl;
    */
    boules[0] = Boule("1 pleine",2,3);
    boules[1] = Boule("A", 1.1, 1);//"2 pleine",1.96670431,0.6065);
    boules[2] = Boule("A", 1, 3);//"3 pleine",1.96670431,0.6635);
    boules[3] = Boule("A", 1, 4);//"4 pleine",2.02840862,0.692);
    boules[4] = Boule("A", 1, 5);//"5 pleine",2.02840862,0.578);
    boules[5] = Boule("A", 2, 1);//"6 pleine",2.09011293,0.5495);
    boules[6] = Boule("A", 3, 1);//"7 pleine",2.15181724,0.4925);
    boules[7] = Boule("noire",3,3);
    boules[8] = Boule("A", 4, 1);//"9 rayee",2.09011293,0.6065);
    boules[9] = Boule("A", 5, 1);//"10 rayee",2.09011293,0.6635);
    boules[10] = Boule("A", 6, 1);//"11 rayee",2.09011293,0.7205);
    boules[11] = Boule("A", 7, 1);//"12 rayee",2.15181724,0.578);
    boules[12] = Boule("A", 8, 1);//"13 rayee",2.15181724,0.635);
    boules[13] = Boule("A", 9, 1);//"14 rayee",2.15181724,0.692);
    boules[14] = Boule("A", 10, 1);//"15 rayee",2.15181724,0.7775);
    boules[15] = Boule("blanche",1,3);


    boules[0].shoot();
    cout<<"boule 0000000000000000000000000000000 "<<boules[0].intensiteeV()<<endl;






    /*
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
    */







}

//pour tester
void Table::test()
{

}
bool Table::bouger()
{

    /*
    tableau[0] = boules[0];
    tableau[1] = Boule("A", 1.1, 1);//"2 pleine",1.96670431,0.6065);
    tableau[2] = Boule("A", 1, 3);//"3 pleine",1.96670431,0.6635);
    tableau[3] = Boule("A", 1, 4);//"4 pleine",2.02840862,0.692);
    tableau[4] = Boule("A", 1, 5);//"5 pleine",2.02840862,0.578);
    tableau[5] = Boule("A", 2, 1);//"6 pleine",2.09011293,0.5495);
    tableau[6] = Boule("A", 3, 1);//"7 pleine",2.15181724,0.4925);
    tableau[7] = Boule("noire",3,3);
    tableau[8] = Boule("A", 4, 1);//"9 rayee",2.09011293,0.6065);
    tableau[9] = Boule("A", 5, 1);//"10 rayee",2.09011293,0.6635);
    tableau[10] = Boule("A", 6, 1);//"11 rayee",2.09011293,0.7205);
    tableau[11] = Boule("A", 7, 1);//"12 rayee",2.15181724,0.578);
    tableau[12] = Boule("A", 8, 1);//"13 rayee",2.15181724,0.635);
    tableau[13] = Boule("A", 9, 1);//"14 rayee",2.15181724,0.692);
    tableau[14] = Boule("A", 10, 1);//"15 rayee",2.15181724,0.7775);
    */





    int nbboules = 16;
    for (int i=0; i<nbboules;)
    {
        cout<<tableau[0].intensiteeV();

        int z=1;
        if (tableau[0].deplacementss(tableau[0]))
        {
            cout<<"boule bouge"<<endl;
            return true;

        }
        else
        {
            tableau[0]=tableau[z];
            cout<<tableau[0].intensiteeV()<<endl<<tableau[z].intensiteeV()<<endl;

            nbboules--;
            z++;
            cout<<"balblalbalbl"<<endl;
            if (tableau[0].positionX()==tableau[15].positionX() and tableau[0].positionY()==tableau[15].positionY() and tableau[15].deplacementss(tableau[15])== false)
            {
                cout<<"boule NOT bouge"<<endl;
                return false;
            }
        }
    }

}
void Table::jouer()
{

    int u=0;
    double f=0;
    cout<<"avant le while"<<endl;
    while(bouger())
    {
        u= clock();
        for(int i(0); i<nombreDeBoules; ++i)
        {
            //verifie si il y a deplacement de la boule
            if(boules[i].deplacementss(boules[i]))
            {
                //si c'est le cas on verifie ensuite les boules "proches" sur la positionX de cette boule

                boules[i].collTable();
                boules[i].deplacemelent(f);
                for(int z(0); z<nombreDeBoules; z++)
                {
                    if(i==z){cout<<"meme boule"<<endl;}
                    else
                    {
                        if(abs(boules[i].positionX()-boules[z].positionX())<=0.057)
                        {
                            cout<<"peu etre collision"<<endl;
                            boules[i].collBoule(boules[z]);//si une boule "z" est proche de cette boule alors on verifie la collision
                        }
                        else
                        {
                            cout<<"collision pas possible"<<endl;
                        }
                    }
                }

            }
            else{
                cout<<"pas deplacement"<<endl;

            }


        }

    }
    f= clock()-u;






}
void Table::detruire()
{
    /*
    for(int i(0); i<nombreDeBoules; ++i)
    {
        delete boules[i];
        boules[i] = 0;
    }
    */

}



