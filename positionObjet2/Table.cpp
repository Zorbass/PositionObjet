#include <iostream>
#include "Table.hpp"
#include <ctime>
#include <cmath>
#include "Boule.hpp"
#include "Vecteur.hpp"
#include <vector>


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


//placement des boules
void Table::innitialisation()
{

    boules[0] = Boule("1 pleine",1.905,0.5778-0.0001);
    boules[1] = Boule("2 pleine",2.004073306+0.0002,0.6922+0.0001);
    boules[2] = Boule("3 pleine",1.954536653+0.0001,0.6064-0.0001);
    boules[3] = Boule("4 pleine",2.004073306+0.0002,0.5778-0.0001);
    boules[4] = Boule("5 pleine",2.004073306+0.0002,0.5206-0.0002);
    boules[5] = Boule("6 pleine",1.954536653+0.0001,0.7208+0.0002);
    boules[6] = Boule("7 pleine",1.85546337-0.0001,0.6636+0.0001);

    boules[7] = Boule("noire",1.905,0.635);

    boules[8] = Boule("9 rayee",1.805926694-0.0002,0.635);
    boules[9] = Boule("10 rayee",1.954536653+0.0001,0.6636+0.0001);
    boules[10] = Boule("11 rayee",2.004073306+0.0002,0.7494+0.0002);
    boules[11] = Boule("12 rayee",1.85546337-0.0001,0.6064-0.0001);
    boules[12] = Boule("13 rayee",2.004073306+0.0002,0.635);
    boules[13] = Boule("14 rayee",1.954536653+0.0001,0.5492-0.0002);
    boules[14] = Boule("15 rayee",1.905,0.6922+0.0001);

    boules[15] = Boule("blanche",0.635,0.635);


}

//execute les formules de cinétique et collision pour toutes les boules à chaque rafraîchissement
void Table::mecanique()
{
    double f = 0; //f retient le temps passé depuis le dernier rafraîchissment

    int i = 0; //itération pour les boucles
    int z = 0; //itération pour les boucles

    //le code ci-dessous s'exécute tant que une boules est en mouvement
    while(boules[0].intensiteeV() > 0 or boules[1].intensiteeV() > 0 or boules[2].intensiteeV() > 0 or boules[3].intensiteeV() > 0 or boules[4].intensiteeV() > 0 or boules[5].intensiteeV() > 0 or boules[6].intensiteeV() > 0 or boules[7].intensiteeV() > 0 or boules[8].intensiteeV() > 0 or boules[9].intensiteeV() > 0 or boules[10].intensiteeV() > 0 or boules[11].intensiteeV() > 0 or boules[12].intensiteeV() > 0 or boules[13].intensiteeV() > 0 or boules[14].intensiteeV() > 0 or boules[15].intensiteeV() > 0)
    {
        f = clock();

        i = 0;

        //on vérifie la collision avec la table pour chaque boule
        while(i < nombreDeBoules)
        {
            boules[i].collTable();
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

//permet de jouer en y incluant plusieur méthodes
void Table::jouer()
{
    this->afficher();

    boules[15].shoot();
    int i = 0;
    while (i<nombreDeBoules)
    {
        double t =0;// temps qu'il faut pour le prochain evenement de la boule
        double deltax=0; //distance separant bord de table droite ou gauche de la boule
        double deltay =0;//distance separant bord de table haute ou basse de la boule
        if(boules[i].intensiteeV()!=0)
        {
           if(boules[i].angle()>0 and boules[i].angle()<90)
           {
               deltax = 2,54 - boules[i].positionX();
               cout<<"plus petit qu 90"<<endl;
               t= (-boules[i].intensiteeVx() + sqrt(boules[i].intensiteeVx()*boules[i].intensiteeVx() - (2*boules[i].intensiteeAx()*deltax)))/-boules[i].intensiteeAx();

               cout<<t<<endl;
           }
           else if(boules[i].angle()>90 and boules[i].angle()<180)
           {
               cout<<"plus petit qu 180"<<endl;
           }
           else if(boules[i].angle()>180 and boules[i].angle()<270)
           {
               cout<<"plus petit qu 270"<<endl;
           }
           else if(boules[i].angle()>270 and boules[i].angle()<360)
           {
               cout<<"plus petit qu 360"<<endl;
           }
           else
           {
               cout<<"cas special"<<endl;
           }
        }
        i++;
    }

    this->mecanique();

    this->afficher();
}
