#include <iostream>
#include "Table.hpp"
#include <ctime>
/*#include <cmath>*/
#include <algorithm>
#include "Boule.hpp"
/*#include "Vecteur.hpp"*/
#include <vector>
#include "Player.cpp"

#define position1x 1.986073306//1.984073306        Les positions parfaites des boules se trouvent en commentaire
#define position2x 2.083546612//2.083146612
#define position3x 2.033909959//2.033609959
#define position4x 2.083546612//2.083146612
#define position5x 2.083546612//2.083146612
#define position6x 2.033909959//2.033609959
#define position7x 1.935536653//1.934536653
#define position8x 1.986073306//1.984073306
#define position9x 1.885//1.885
#define position10x 2.033909959//2.033609959
#define position11x 2.083546612//2.083146612
#define position12x 1.935536653//1.934536653
#define position13x 2.083546612//2.083146612
#define position14x 2.033909959//2.033609959
#define position15x 1.986073306//1.984073306
#define position16x 0.655875//0.655875

#define position1y 0.5777//0.5778
#define position2y 0.6923//0.6922
#define position3y 0.6063//0.6064
#define position4y 0.5777//0.5778
#define position5y 0.5203//0.5206
#define position6y 0.7210//0.7208
#define position7y 0.6637//0.6636
#define position8y 0.635//0.635
#define position9y 0.635//0.635
#define position10y 0.6636//0.6636
#define position11y 0.7496//0.7494
#define position12y 0.6064//0.6064
#define position13y 0.635//0.635
#define position14y 0.5490//0.5492
#define position15y 0.6922//0.6922
#define position16y 0.635//0.635

using namespace std;

Table::Table()
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

    cout << "la table a une largeur de 1.27m et une longueur de 2.54m." << endl << "la table est orientee de cette maniere :  " << endl <<  " ___________" << endl << "|           |" << endl << "|           |" << endl << "|___________|" << endl;
/*--
    boules[0] = Boule("1", "pleine",2,0.25);
    boules[1] = Boule("2", "pleine",1.27,1);
    boules[2] = Boule("3", "pleine",0.19,1);
    boules[3] = Boule("4", "pleine",0.25,1);
    boules[4] = Boule("5", "pleine",0.31,1);
    boules[5] = Boule("6", "pleine",0.37,1);
    boules[6] = Boule("7", "pleine",0.43,1);
    boules[7] = Boule("8", "noire",0.49,1);
    boules[8] = Boule("9", "rayee",0.55,1);
    boules[9] = Boule("10", "rayee",0.61,1);
    boules[10] = Boule("11", "rayee",0.67,1);
    boules[11] = Boule("12", "rayee",0.73,1);
    boules[12] = Boule("13", "rayee",0.79,1);
    boules[13] = Boule("14", "rayee",0.85,1);
    boules[14] = Boule("15", "rayee",1.27,0.2);
    boules[15] = Boule("16", "blanche",1.27,0.5);
*/

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


    boules[0] = Boule("1", "pleine",position1x,position1y);
    boules[1] = Boule("2", "pleine",position2x,position2y);
    boules[2] = Boule("3", "pleine",position3x,position3y);
    boules[3] = Boule("4", "pleine",position4x,position4y);
    boules[4] = Boule("5", "pleine",position5x,position5y);
    boules[5] = Boule("6", "pleine",position6x,position6y);
    boules[6] = Boule("7", "pleine",position7x,position7y);
    boules[7] = Boule("8", "noire",position8x,position8y);
    boules[8] = Boule("9", "rayee",position9x,position9y);
    boules[9] = Boule("10", "rayee",position10x,position10y);
    boules[10] = Boule("11", "rayee",position11x,position11y);
    boules[11] = Boule("12", "rayee",position12x,position12y);
    boules[12] = Boule("13", "rayee",position13x,position13y);
    boules[13] = Boule("14", "rayee",position14x,position14y);
    boules[14] = Boule("15", "rayee",position15x,position15y);
    boules[15] = Boule("16", "blanche",position16x,position16y);

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
void Table::replacementBoules()
{
    boules[0] = Boule("1", "pleine",position1x,position1y);
    boules[1] = Boule("2", "pleine",position2x,position2y);
    boules[2] = Boule("3", "pleine",position3x,position3y);
    boules[3] = Boule("4", "pleine",position4x,position4y);
    boules[4] = Boule("5", "pleine",position5x,position5y);
    boules[5] = Boule("6", "pleine",position6x,position6y);
    boules[6] = Boule("7", "pleine",position7x,position7y);
    boules[7] = Boule("8", "noire",position8x,position8y);
    boules[8] = Boule("9", "rayee",position9x,position9y);
    boules[9] = Boule("10", "rayee",position10x,position10y);
    boules[10] = Boule("11", "rayee",position11x,position11y);
    boules[11] = Boule("12", "rayee",position12x,position12y);
    boules[12] = Boule("13", "rayee",position13x,position13y);
    boules[13] = Boule("14", "rayee",position14x,position14y);
    boules[14] = Boule("15", "rayee",position15x,position15y);
    boules[15] = Boule("16", "blanche",position16x,position16y);
}

//execute les formules de cinétique et collision pour toutes les boules à chaque rafraîchissement
void Table::mecanique()
{
    double t = clock();


//    double px = 0;//position x et y de la frame d'avant
//    double py = 0;

    int i = 0; //itération pour les boucles
    int z = 0; //itération pour les boucles

    //le code ci-dessous s'exécute tant que une boules est en mouvement
    while(boules[0].intensiteeV() > 0 or boules[1].intensiteeV() > 0 or boules[2].intensiteeV() > 0 or boules[3].intensiteeV() > 0 or boules[4].intensiteeV() > 0 or boules[5].intensiteeV() > 0 or boules[6].intensiteeV() > 0 or boules[7].intensiteeV() > 0 or boules[8].intensiteeV() > 0 or boules[9].intensiteeV() > 0 or boules[10].intensiteeV() > 0 or boules[11].intensiteeV() > 0 or boules[12].intensiteeV() > 0 or boules[13].intensiteeV() > 0 or boules[14].intensiteeV() > 0 or boules[15].intensiteeV() > 0)
    {

        if(boules[8].intensiteeV()>0)
        {
            cout<<"test "<<boules[8].positionX()<<endl;
        }
        double f=0;


        f = clock();

        i = 0;
        z = 0;

        while(i < nombreDeBoules)
        {
            boules[i].empochage();

            boules[i].collTable();  //on vérifie la collision avec la table pour chaque boule
            if(boules[i].boulband()==true)
            {
                boulebandes.push_back(i);

            }

            z = 0;
            while(z < nombreDeBoules)
            {
                if(z != i)
                {
                    boules[i].collBoule(boules[z]);
                    if(boules[i].collisionBoule()==true)
                    {
                        typeBoule.push_back(boules[z].typeBoule());

                    }

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
    t = clock()-t;
    cout << "fini collisions " << t << endl << endl;
    this->afficher();

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
    boules[15].replacementblanche();
    this->afficher();
    cout<< endl << "c'est au joueur "<<players[joueur].nomjoueur()<<" de jouer"<< endl << "le triangle de casse se situe a droite de la boule blanche" << endl;
    if(blancheempochee==true)boules[15].replacementblanche();//replace la blanche
    blancheempochee=false;
    this->reset();
    boules[15].shoot();
    this->mecanique();
    this->numeroBouleEmpochee();
    sort( boulebandes.begin(), boulebandes.end() );
    boulebandes.erase( unique( boulebandes.begin(), boulebandes.end() ), boulebandes.end() );//enlever les duplicates

    if(boules[7].empochee()==true)//noir empochee
    {
        cout<<"boule noir empochee (mauvaise casse)"<<endl;
        cassereussi =false;
    }
    else if(boulebandes.size()<4 and boulesempochee<1)//moins de 4 boules touchent la bande et aucune boule empochee
    {
        cout<<"mauvaise casse"<<endl;
        cout<<"a l'autre joueur de casser"<<endl;
        cassereussi =false;
    }
    else if(boulesempochee==0)
    {
        joueur = players[0].finDeTour();//on change de joueur
        cout<<"c'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        cassereussi =true;
    }
    else if(boules[15].empochee()==true)//blanche empochee
    {
        joueur =players[0].finDeTour();//on change de joueur
        cout<<"c'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        blancheempochee=true;
        cassereussi =true;
    }
    else
    {
        cout<<"c'est toujours au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        cassereussi=true;
    }
    if(cassereussi==false)
    {
        joueur =players[0].finDeTour();//on change de joueur
        this->replacementBoules();//replace les boules a leur position innitiale
        cout<<"nouvelle casse"<<endl;

    }

    cout<<blancheempochee<<endl;
}
bool Table::faute()
{

    if(boules[15].empochee()==true)
    {
        fautes = true;
        cout<<"blanche empochee."<<endl;
        blancheempochee=true;
    }
    else if(boulebandes.size()==0 and boulesempochee==0)
    {
        cout<<"aucune boule n'a touche de raille ou a ete empoche. Faute."<<endl;
        fautes = true;
    }
    else if(groupeChoisi==true and players[joueur].choix()!=typeBoule[0])
    {
        fautes = true;
        cout<<"mauvaise collision"<<endl;
    }
    return fautes;
}

void Table::reset()
{
    int i=0;
    while(i<boulebandes.size())
    {
        boulebandes.pop_back();
    }

    while(i<typeBoule.size())
    {
        typeBoule.pop_back();
    }
    while(i<bouleEmpochee.size())
    {
        bouleEmpochee.pop_back();//enleve les boules du tableau
    }
    boulesempochee=0;
    blancheempochee=false;
}

void Table::choixGroupe()
{
    if(groupeChoisi==false)//si on a pas deja determiner le groupe
    {
        if(boulesempochee>0)
        {
            if(joueur==0)
            {
                autrejoueur=1;
            }
            else
            {
                autrejoueur=0;
            }
            int p=0; //les pleines
            int r=0; //les rayees
            for(int i=0;i<bouleEmpochee.size();i++)
            {
                if(boules[bouleEmpochee[i]].typeBoule()=="rayee")
                {
                    r++;
                }
                else
                {
                    p++;
                }
            }
            if(p>r)
            {
                cout<<"joueur " <<players[joueur].nomjoueur()<<" a les pleine"<<endl;
                players[joueur].choisir("pleine");
                players[autrejoueur].choisir("rayee");
            }
            else if(r>p)
            {
                cout<<"joueur a les rayees"<<endl;
                players[joueur].choisir("rayee");
                players[autrejoueur].choisir("pleine");
            }
            else // dans le cas ou un nombre de rayee empochee est egale au nombre de pleines
            {
                string typeboule;
                cout<<"quels boule choisisez vous? (pleine ou rayee)"<<endl;//pas faire de faute d'orthographe
                cin>>typeboule;
                players[joueur].choisir(typeboule);
                cout<<"votre choix est : "<<players[joueur].choix()<<endl;
                if(typeboule=="rayee")
                {
                    players[autrejoueur].choisir("pleine");
                }
                else
                {
                    players[autrejoueur].choisir("rayee");
                }
            }
            groupeChoisi=true;
        }
    }
}


void Table::numeroBouleEmpochee()
{
    for(int i=0;i<nombreDeBoules-1;i++)
    {

        if(boules[i].empochee()==true and boules[i].bouledejaempochee()==false) //and boule n'etait pas deja empochee )
        {
            bouleEmpochee.push_back(i);//ajoute numero de boule dans le tableau (pour ensuite determiner combien de raye ou de pleines sont empochees lors de la casse)
            cout<<"boule "<<i+1<<" est empochee"<<endl;
            boulesempochee++;
        }
        boules[i].verificationbouledejaempochee();
    }
}


//permet de jouer en y incluant plusieur méthodes
void Table::jouer()
{
    this->innitialisation();
     //joueur 1 qui commence a shoot
    while(cassereussi==false)
    {
        this->casse();
    }

    while(boules[7].empochee()==false)
    {
        if(blancheempochee==true)boules[15].replacementblanche();//replace la blanche


        boules[15].shoot();

        this->reset();//reset les valeurs de nombre de collisions de table et boules empochee

        this->mecanique();
        this->numeroBouleEmpochee();
        if(faute()) //verifie si il y a faute
        {
            cout<<"fauuuuuuuuuuute"<<endl;
            joueur =players[0].finDeTour();//on change de joueur
            cout<<"c'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
            fautes = false;
        }
        else if(boulesempochee==0) //si on empoche pas c'est a l'autre de jouer
        {
            cout<<"aucune boule empochee"<<endl;
            joueur =players[0].finDeTour();//on change de joueur
            cout<<"c'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        }
        else
        {
            cout<<"c'est toujours au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
            choixGroupe();
        }
    }
    //fin de partie maintenant regarder si on a gagne ou perdu

    if(players[joueur].choix()== "pleine")
    {
        if(boules[0].empochee()==true and boules[1].empochee()==true and boules[2].empochee()==true and boules[3].empochee()==true and boules[4].empochee()==true and boules[5].empochee()==true and boules[6].empochee()==true)
        {
            cout<<"winner winner chicken dinner"<<endl;
            cout<<"c'est "<<joueur<<" qui a gagne"<<endl;
        }
        else
        {
            cout<<"vous avez perdu"<<endl;
            cout<<"c'est "<<autrejoueur<<" qui a gagne"<<endl;
        }
    }
    else
    {
        if(boules[8].empochee()==true and boules[9].empochee()==true and boules[10].empochee()==true and boules[11].empochee()==true and boules[12].empochee()==true and boules[13].empochee()==true and boules[14].empochee()==true)
        {
            cout<<"winner winner chicken dinner"<<endl;
            cout<<"c'est "<<joueur<<" qui a gagne"<<endl;
        }
        else
        {
            cout<<"vous avez perdu"<<endl;
            cout<<"c'est "<<autrejoueur<<" qui a gagne"<<endl;
        }
    }
}
