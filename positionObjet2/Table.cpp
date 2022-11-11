#include <iostream>
#include "Table.hpp"
#include <ctime>
#include <algorithm>
#include "Boule.hpp"
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
#define position16x 0.655//0.655

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



void Table::innitialisation() //permet aux joueurs de choisir leur nom, ainsi que placer les boules
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

void Table::mecanique() // regroupe toute la partie mecanique du billard. Execute donc les formules de cinétique et collisions pour toutes les boules à chaque rafraîchissement
{
    double t = clock();


    int i = 0; //itération pour les boucles
    int z = 0; //itération pour les boucles

    //le code ci-dessous s'exécute tant qu'une des boules est en mouvement
    while(boules[0].intensiteeV() > 0 or boules[1].intensiteeV() > 0 or boules[2].intensiteeV() > 0 or boules[3].intensiteeV() > 0 or boules[4].intensiteeV() > 0 or boules[5].intensiteeV() > 0 or boules[6].intensiteeV() > 0 or boules[7].intensiteeV() > 0 or boules[8].intensiteeV() > 0 or boules[9].intensiteeV() > 0 or boules[10].intensiteeV() > 0 or boules[11].intensiteeV() > 0 or boules[12].intensiteeV() > 0 or boules[13].intensiteeV() > 0 or boules[14].intensiteeV() > 0 or boules[15].intensiteeV() > 0)
    {
        double f=0;

        f = clock();

        i = 0;
        z = 0;

        while(i < nombreDeBoules)
        {
            boules[i].empochage(); //on verifie si les boules sont empochees

            boules[i].collTable();  //on verfie les collisions entre la table et chaque boule
            if(boules[i].boulband()==true)
            {
                boulebandes.push_back(i); //ajoute au tableau les boules qui ont touche une bande

            }

            z = 0;
            while(z < nombreDeBoules)
            {
                if(z != i)
                {
                    boules[i].collBoule(boules[z]); //verification des collisions entre chaque boule
                    if(boules[i].collisionBoule()==true)
                    {
                        typeBoule.push_back(boules[z].typeBoule()); // ajoute au tableau le type de boule de la cible

                    }

                }
                z++;
            }

            i++;

        }


        i = 0;
        f = clock() - f;

        while(i < nombreDeBoules)
        {
            boules[i].deplacemelent(f); //on déplace chaque boule
            i++;
        }

    }
    t = clock()-t;





}


void Table::afficher() //affiche l'emplacement, le nom et la vitesse de chaque boule
{
    int i = 0;

    while(i < nombreDeBoules)
    {
        boules[i].afficher();
        i++;
    }
}

void Table::casse() // la casse (1ere phase du jeu)
{
    boules[15].replacementblanche(); // place la blanche
    this->afficher(); // affiche la position des boules
    cout<< endl << "c'est au joueur "<<players[joueur].nomjoueur()<<" de jouer"<< endl << "le triangle de casse se situe a droite de la boule blanche" << endl;
    blancheempochee=false;
    this->reset(); // remet a 0 certains parametres (nombre de boules qui ont touche une bande par exemple)
    boules[15].shoot(); //shoot la boule
    this->mecanique(); //partie mecanique du billard (collisions, deplacement...)
    this->numeroBouleEmpochee(); //pour determiner le nombre de pleines ou rayees empochees
    sort( boulebandes.begin(), boulebandes.end() );
    boulebandes.erase( unique( boulebandes.begin(), boulebandes.end() ), boulebandes.end() );//enlever les doublons

    if(boules[7].empochee()==true){//si la noire est empochee la casse n'est pas valide
        cout<<"Boule noire empochee"<<endl;
        cassereussi =false;
    }
    else if(boulebandes.size()<4 and boulesempochee<1)//si moins de 4 boules touchent la bande et aucune boule empochee la casse n'est pas valide
    {
        cout<<"Mauvaise casse"<<endl;
        cout<<endl<<"C'est a l'autre joueur de casser"<<endl;
        cassereussi =false;
    }
    else if(boulesempochee==0) //on change de joueur si aucune boule n'est empochee
    {
        joueur = players[0].finDeTour();
        cout<<"c'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        cassereussi =true;
    }
    else if(boules[15].empochee()==true)//on change de joueur si la blanche empochee
    {
        joueur =players[0].finDeTour();
        cout<<"C'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        blancheempochee=true;
        cassereussi =true;
    }
    else
    {
        cout<<"C'est toujours au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        cassereussi=true;
    }
    if(cassereussi==false)
    {
        joueur =players[0].finDeTour();//on change de joueur
        this->replacementBoules();//replace les boules a leur position innitiale

    }

}
bool Table::faute() //conditions pour qu'il y a faute
{

    if(boules[15].empochee()==true) //blanche empochee
    {
        fautes = true;
        cout<<"Faute: Blanche empochee."<<endl;
        blancheempochee=true;
    }
    else if(boulebandes.size()==0 and boulesempochee==0) //aucune boule n'a touche de bande (a part la blanche) et aucune boule n'est empochee
    {
        cout<<"Faute: aucune boule n'a touche de raille ou a ete empoche."<<endl;
        fautes = true;
    }
    else if(groupeChoisi==true and players[joueur].choix()!=typeBoule[0]) // la blanche a touche le type de boule du joueur adverse (rayee ou pleine)
    {
        fautes = true;
        cout<<"Faute: collision avec boule du joueur adverse"<<endl;
    }
    return fautes;
}

void Table::reset() // remet a 0 le nombre de boules qui ont touchee les bandes, qui ont ete empochees et les type de boules touchee.
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

void Table::choixGroupe() // determine le groupe de boule des joueurs (rayee ou pleine) si ce n'est pas deja fait
{
    if(groupeChoisi==false)
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
            if(p>r) // si il y a plus de pleines empochees que de rayees
            {
                cout<<"Joueur " <<players[joueur].nomjoueur()<<" a les pleine"<<endl;
                players[joueur].choisir("pleine");
                players[autrejoueur].choisir("rayee");
            }
            else if(r>p) // si il y a plus de rayees empochees que de pleines
            {
                cout<<"Joueur a les rayees"<<endl;
                players[joueur].choisir("rayee");
                players[autrejoueur].choisir("pleine");
            }
            else // dans le cas ou un nombre de rayees empochees est egale au nombre de pleines
            {
                string typeboule;
                while (typeboule != "pleine" and typeboule !="rayee")
                {
                    cout<<"Quel groupe choisissez vous? (pleine ou rayee)"<<endl;//pas faire de faute d'orthographe
                    cin>>typeboule;
                }
                players[joueur].choisir(typeboule);
                cout<<"Votre choix est les : "<<players[joueur].choix()<<endl;
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


void Table::numeroBouleEmpochee() // incrementation du tableau si une boule a ete empochee pendant ce tour
{
    for(int i=0;i<nombreDeBoules-1;i++)
    {

        if(boules[i].empochee()==true and boules[i].bouledejaempochee()==false)
        {
            bouleEmpochee.push_back(i);
            boulesempochee++;
        }
        boules[i].verificationbouledejaempochee();
    }
}



void Table::jouer() // le deroulement de la partie. Regroupe toutes les fonctions
{
    this->innitialisation(); //innitialisation de la partie

    while(cassereussi==false) // la casse
    {
        this->casse();
    }

    while(boules[7].empochee()==false) // la deuxieme partie du jeu ou tant que la noire n'est pas empochee, on joue.
    {
        if(blancheempochee==true)boules[15].replacementblanche();


        boules[15].shoot();

        this->reset();//remet a 0 certains parametres

        this->mecanique(); // partie mecanique du billard
        this->numeroBouleEmpochee();
        if(faute()) //verifie si il y a faute, et si c'est le cas on change de joueur
        {
            joueur =players[0].finDeTour();
            cout<<"C'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
            fautes = false;
        }
        else if(boulesempochee==0) //change de joueur si il n'a pas empochee de boule
        {
            cout<<"Aucune boule n'est empochee"<<endl;
            joueur =players[0].finDeTour();//on change de joueur
            cout<<"C'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        }
        else
        {
            cout<<"C'est toujours au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
            choixGroupe();
        }
        string reponse;
        cout<<"est"<<endl;
        while (reponse != "y" and reponse != "n") // pour laisser au joueur le choix d'afficher ses boules
        {
            cout<<reponse<<endl;
            cout<<"Voulez-vous afficher les positions des boules ? (y/n)"<<endl;
            cin>>reponse;
        }
        if(reponse =="y")
        {
            this->afficher();
        }
    }

    //fin de la partie. Nous regardons quel joueur a gagne : si le joueur qui joue a empochee toutes les boules de son groupe, il a gagne sinon il a perdu
    if(players[joueur].choix()== "pleine")
    {
        if(boules[0].empochee()==true and boules[1].empochee()==true and boules[2].empochee()==true and boules[3].empochee()==true and boules[4].empochee()==true and boules[5].empochee()==true and boules[6].empochee()==true)
        {
            cout<<"Winner winner chicken dinner"<<endl;
            cout<<"C'est "<<joueur<<" qui a gagne"<<endl;
        }
        else
        {
            cout<<"Vous avez perdu"<<endl;
            cout<<"C'est "<<autrejoueur<<" qui a gagne"<<endl;
        }
    }
    else
    {
        if(boules[8].empochee()==true and boules[9].empochee()==true and boules[10].empochee()==true and boules[11].empochee()==true and boules[12].empochee()==true and boules[13].empochee()==true and boules[14].empochee()==true)
        {
            cout<<"Winner winner chicken dinner"<<endl;
            cout<<"c'est "<<joueur<<" qui a gagne"<<endl;
        }
        else
        {
            cout<<"Vous avez perdu"<<endl;
            cout<<"C'est "<<autrejoueur<<" qui a gagne"<<endl;
        }
    }
}
