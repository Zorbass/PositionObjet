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
    /*
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
    */
    int j=0;
    int tf=1000;
    //on regarde quel est le plus petit temps pour le porchian evenement
    for(int i=0; i<tempsboule.size(); i++)
    {
        if (tempsboule[i]<tf)
        {
            tf=tempsboule[i];
            j=i;
        }

    }
    //on deplace toutes les boules en mouvement par le plus petit temps trouver
    int z=0;
    for(int i=0; i<boulesbougent.size(); i++)
    {
        z=boulesbougent[i];
        boules[z].deplacemelent(tf);
    }




    //on fait "l'evenement"
    int z=0;
    z=boulesbougent[j]; // affecter a z le numero de boule
    if(action[j]==1)
    {
        //collision table
        boules[z].collTable();

    }
    else if(action[j]==2)
    {
        //collision boule
    }


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

        double tt=0;//temps qu'il faut pour la prochaine collision avec la bande d'une boule


        string evenement;//a redefinir

        double deltax=0; //distance separant bord de table droite ou gauche de la boule
        double deltay =0;//distance separant bord de table haute ou basse de la boule
        if(boules[i].intensiteeV()!=0)
        {
            //si c;est le cas on peut que toucher la bande haute ou droite
           if(boules[i].angle()>0 and boules[i].angle()<90)
           {
               deltax = 2,54 - boules[i].positionX();
               deltay = 1,27 - boules[i].positionY();
           }
           //on peut que toucher la bande droite ou basse
           else if(boules[i].angle()>90 and boules[i].angle()<180)
           {
               deltax = 2,54 - boules[i].positionX();
               deltay = boules[i].positionY();
               cout<<"plus petit qu 180"<<endl;
           }
           //que la bande basse ou gauche
           else if(boules[i].angle()>180 and boules[i].angle()<270)
           {
               deltax = boules[i].positionX();
               deltay = boules[i].positionY();
               cout<<"plus petit qu 270"<<endl;
           }
           //que la bande gauche ou haute
           else if(boules[i].angle()>270 and boules[i].angle()<360)
           {
               deltax = boules[i].positionX();
               deltay = 1,27 - boules[i].positionY();
               cout<<"plus petit qu 360"<<endl;
           }
           //que une des quatre bandes
           else
           {
               cout<<"cas special"<<endl;
               if(boules[i].angle()==90)
               {
                    deltax = 2,54 - boules[i].positionX();
                    deltay = 0;
               }
               else if(boules[i].angle()==180)
               {
                    deltax = 0;
                    deltay = boules[i].positionY();
               }
               else if(boules[i].angle()==270)
               {
                    deltax = boules[i].positionX();
                    deltay = 0;
               }
               else if(boules[i].angle()==360)
               {
                    deltax = 0;
                    deltay = 1,27 - boules[i].positionY();
               }
           }
           //definition du temps qu'il faut pour toucher la bande droite et gauche
           double ttx= (-boules[i].intensiteeVx() + sqrt(boules[i].intensiteeVx()*boules[i].intensiteeVx() - (2*boules[i].intensiteeAx()*deltax)))/-boules[i].intensiteeAx();
           double tty= (-boules[i].intensiteeVy() + sqrt(boules[i].intensiteeVy()*boules[i].intensiteeVy() - (2*boules[i].intensiteeAy()*deltay)))/-boules[i].intensiteeAy();
           //on touche la bande droite ou gauche
           if(ttx<tty)
           {
               tt=ttx;
               action.push_back(1);

           }
           //"tt" est la bande haute ou basse
           else if(tty<ttx)
           {
               tt=tty;
               action.push_back(1);

           }
           //cas tres special ou elle touche les deux bandes en meme temps
           else if(tty==ttx and tty!=0)
           {
               //a modifier
               tt=tty;
               //la boule est forcement empochee
           }
           // dans le cas ou la boule ne touche aucune bande
           else
           {
               tt=100;
               //juste un deplacement
           }
           //definir ensuite les evenements pour des collisions entre boules
           //verifier lequel des temps est le plus petit
            t=tt;
            tempsboule.push_back(t);




        }
        i++;



    }

    //declaration d'un tableau dynamique pour les boules qui bougent

    i=0;
    while(i<nombreDeBoules)
    {
        if(boules[i].intensiteeV()>0)
        {
            cout<<"ok"<<endl;
            boulesbougent.push_back(i);
        }
        i++;

    }

    while(boulesbougent.size()>0)
    {
        //this.mecanique();
        boulesbougent.pop_back();
    }

    //mettre dans l'ordre dans tableau quels actions en premier
    //while tableau de boules deplacement

    //allez jusqua l'evemenet

    //faire evenement

    //revnir au debut de la boucle while


    this->mecanique();

    this->afficher();
}

