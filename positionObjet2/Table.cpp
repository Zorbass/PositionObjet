#include <iostream>
#include "Table.hpp"
#include <ctime>
#include <cmath>
#include <algorithm>
#include "Boule.hpp"
#include "Vecteur.hpp"
#include <vector>
#include "Player.hpp"


using namespace std;

Table::Table()
{

}


Table::Table(string nom, double x, double y): m_nom(nom), m_x(x), m_y(y)
{

}

//destructeur
Table::~Table()
{

    delete boules;
}

/*
void Table::regle()
{
}
*/


//j'ai trouve que une boule de billard a 57mm de diametre et pas ce que tu as trouve. Quand je reviens je vais continuer mes calculs pour positionner toutes les boules (j'ai deja commence mais pas mis sur le programme)

//placement des boules
void Table::innitialisation()
{
    string nom;
    cout<<"joueur 1 choisisez un nom"<<endl;
    cin>>nom;
    players[0]=Player(nom,"aucaun");
    cout<<"joueur 2 choisisez un nom"<<endl;
    cin>>nom;
    players[1]=Player(nom,"aucaun");





    /*boules[0] = Boule("1", "pleine",0.07,1.2);//0.07,1.2
    boules[1] = Boule("2", "pleine",0.13,1.2);
    boules[2] = Boule("3", "pleine",0.19,1.2);
    boules[3] = Boule("4", "pleine",0.25,1.2);
    boules[4] = Boule("5", "pleine",0.31,1.2);
    boules[5] = Boule("6", "pleine",0.37,1.2);
    boules[6] = Boule("7", "pleine",0.43,1.2);
    boules[7] = Boule("8", "noire",0.49,1.2);
    boules[8] = Boule("9", "rayee",0.55,1.2);
    boules[9] = Boule("10", "rayee",0.61,1.2);
    boules[10] = Boule("11", "rayee",0.67,1.2);
    boules[11] = Boule("12", "rayee",0.73,1.2);
    boules[12] = Boule("13", "rayee",0.79,1.2);
    boules[13] = Boule("14", "rayee",0.85,1.2);
    boules[14] = Boule("15", "rayee",0.91,1.2);
    boules[15] = Boule("16", "blanche",2.2 ,1.0535);//2.2,1.0535*/


    boules[0] = Boule("1", "pleine",1.905,0.5778-0.0001);
    boules[1] = Boule("2", "pleine",2.004073306+0.0002,0.6922+0.0001);
    boules[2] = Boule("3", "pleine",1.954536653+0.0001,0.6064-0.0001);
    boules[3] = Boule("4", "pleine",2.004073306+0.0002,0.5778-0.0001);
    boules[4] = Boule("5", "pleine",2.004073306+0.0002,0.5206-0.0002);
    boules[5] = Boule("6", "pleine",1.954536653+0.0001,0.7208+0.0002);
    boules[6] = Boule("7", "pleine",1.85546337-0.0001,0.6636+0.0001);
    boules[7] = Boule("8", "noire",1.905,0.635);
    boules[8] = Boule("9", "rayee",1.805926694-0.0002,0.635);
    boules[9] = Boule("10", "rayee",1.954536653+0.0001,0.6636+0.0001);
    boules[10] = Boule("11", "rayee",2.004073306+0.0002,0.7494+0.0002);
    boules[11] = Boule("12", "rayee",1.85546337-0.0001,0.6064-0.0001);
    boules[12] = Boule("13", "rayee",2.004073306+0.0002,0.635);
    boules[13] = Boule("14", "rayee",1.954536653+0.0001,0.5492-0.0002);
    boules[14] = Boule("15", "rayee",1.905,0.6922+0.0001);
    boules[15] = Boule("16", "blanche",0.635,0.635);

/*
  boules[0] = Boule("1", "pleine",6-0.020223254,3.020223254);
    boules[1] = Boule("2", "pleine",2,1);
    boules[2] = Boule("3", "pleine",3,1);
    boules[3] = Boule("4", "pleine",4,1);
    boules[4] = Boule("5", "pleine",5,1);
    boules[5] = Boule("6", "pleine",6,1);
    boules[6] = Boule("7", "pleine",7,1);
    boules[7] = Boule("8", "noire",1,1);
    boules[8] = Boule("9", "rayee",8,1);
    boules[9] = Boule("10", "rayee",9,1);
    boules[10] = Boule("11", "rayee",10,1);
    boules[11] = Boule("12", "rayee",1,2);
    boules[12] = Boule("13", "rayee",1,3);
    boules[13] = Boule("14", "rayee",1,4);
    boules[14] = Boule("15", "rayee",1,5);
    boules[15] = Boule("16", "blanche",5.5,2);
*/
}

//execute les formules de cinétique et collision pour toutes les boules à chaque rafraîchissement
void Table::mecanique()

{



    double px = 0;//position x et y de la frame d'avant
    double py = 0;

    int i = 0; //itération pour les boucles
    int z = 0; //itération pour les boucles

    //le code ci-dessous s'exécute tant que une boules est en mouvement
    while(boules[0].intensiteeV() > 0 or boules[1].intensiteeV() > 0 or boules[2].intensiteeV() > 0 or boules[3].intensiteeV() > 0 or boules[4].intensiteeV() > 0 or boules[5].intensiteeV() > 0 or boules[6].intensiteeV() > 0 or boules[7].intensiteeV() > 0 or boules[8].intensiteeV() > 0 or boules[9].intensiteeV() > 0 or boules[10].intensiteeV() > 0 or boules[11].intensiteeV() > 0 or boules[12].intensiteeV() > 0 or boules[13].intensiteeV() > 0 or boules[14].intensiteeV() > 0 or boules[15].intensiteeV() > 0)
    {

        double f=0;
        double u=0;
        u=f;

        f = clock();

        i = 0;

        while(i < nombreDeBoules)
        {
            boules[i].empochage();
            if(boules[i].empochee()==true)
            {
                boulesempochee++;
            }
            i++;
        }

        i = 0;

        //on vérifie la collision avec la table pour chaque boule
        while(i < nombreDeBoules)
        {
            boules[i].collTable();
            if(boules[i].boulband()==true)
            {
                boulebandes.push_back(i);

            }
            i++;
        }

        i = 0;
        z = 0;

        //on vérifie la collision entre boule pour chaque boule
        while(i < nombreDeBoules)
        {
            z = 0;
            while(z < nombreDeBoules)
            {
                if(z != i)
                {
                    boules[i].collBoule(boules[z]);

                }
                z++;
            }
            i++;
        }

        i = 0;

        f = clock() - f;




        //on déplace chaque boule si elle a de la vitesse
        while(i < nombreDeBoules)
        {
            boules[i].deplacemelent(f);

            i++;
        }

    }
    cout << "fini collisions" << endl;


}

//affiche l'empplacement, le nom et la vitesse de chaque boule
void Table::afficher()
{
    int i = 0;

    while(i < nombreDeBoules)
    {
        boules[i].afficher();
        i++;
    }
}

void Table::casse()
{
    sort( boulebandes.begin(), boulebandes.end() );
    boulebandes.erase( unique( boulebandes.begin(), boulebandes.end() ), boulebandes.end() );//enlever les duplicates

    cout<<"c'est au joueur "<<players[0].nomjoueur()<<" de commencer"<<endl;
    boules[15].shoot();
    this->mecanique();
    if(boules[7].empochee()==true)
    {
        cout<<"boule noir empochee"<<endl;
        fautes==true;
    }
    else if(boulebandes.size()<4 and boulesempochee<1)
    {
        cout<<"mauvaise casse"<<endl;
        fautes = true;
        cout<<"a l'autre joueur de casser"<<endl;
    }
    else if(boulesempochee==0)
    {
        joueur = players[0].finDeTour();//on change de joueur
        cout<<"c'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
    }
    else if(boules[15].empochee()==true)
    {
        fautes = true;
        cout<<"blanche empochee. Veuillez la replacez derriere la ligne"<<endl;
        joueur =players[0].finDeTour();//on change de joueur
        cout<<"c'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
    }
    else
    {
        cout<<"c'est toujours au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
    }
}
bool Table::faute()
{
    if(boules[15].empochee()==true)
    {
        fautes = true;
        cout<<"blanche empochee. Veuillez la replacez derriere la ligne"<<endl;
        joueur =players[0].finDeTour();//on change de joueur
        cout<<"c'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        return fautes;
    }

}


//permet de jouer en y incluant plusieur méthodes
void Table::jouer()
{
     //joueur 1 qui commence a shoot

    this->casse();
    while(boules[7].empochee()==false)
    {
        //players[joueur].shoot(boules[15]);//joueur shoot
        boules[15].shoot();

        this->mecanique();
        if(faute())
        {
            cout<<"fauuuuuuuuuuute"<<endl;
            joueur =players[0].finDeTour();//on change de joueur
            cout<<"c'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
            fautes = false;
        }
        else if(boulesempochee==0)
        {
            cout<<"aucune boule empochee"<<endl;
            joueur =players[0].finDeTour();//on change de joueur
            cout<<"c'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        }
        else
        {
            cout<<"c'est toujours au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;

        }

    }
    /*player1.shoot(boules[15]);
    boules[15].afficher();
*/



    //this->mecanique();




}
