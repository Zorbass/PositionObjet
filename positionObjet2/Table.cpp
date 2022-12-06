//Ce fichier est la classe Table.
//Il inclut toutes les autres classes.
//Dans ce fichier est détaillé le déroulement d'une partie.

#include <iostream>
#include "Table.hpp"
#include <ctime>
#include <algorithm>
#include "Boule.hpp"
#include <vector>
#include "Player.cpp"

//Définition de la position de chaque boule sur les axes x et y.
//Les positions attribués sont légèrement différentes des positions parfaites dans un soucis de réalisme.
//Les positions parfaites des boules se trouvent en commentaire.


#define position1x 0.1//1.984073306
#define position2x 0.1//2.083146612
#define position3x 20//2.033609959
#define position4x 20//2.083146612
#define position5x 20//2.083146612
#define position6x 20//2.033609959
#define position7x 20//1.934536653
#define position8x 20//1.984073306
#define position9x 20//1.885
#define position10x 20//2.033609959
#define position11x 20//2.083146612
#define position12x 20//1.934536653
#define position13x 20//2.083146612
#define position14x 20//2.033609959
#define position15x 20//1.984073306
#define position16x 0.655//0.655

#define position1y 0.1//0.5778
#define position2y 1.17//0.6922
#define position3y 20//0.6064
#define position4y 20//0.5778
#define position5y 20//0.5206
#define position6y 20//0.7208
#define position7y 20.6637//0.6636
#define position8y 20.635//0.635
#define position9y 20.635//0.635
#define position10y 20.6636//0.6636
#define position11y 20.7496//0.7494
#define position12y 20.6064//0.6064
#define position13y 20.635//0.635
#define position14y 20.5490//0.5492
#define position15y 20.6922//0.6922
#define position16y 0.635//0.635


/* normale
#define position1x 1.986073306//1.984073306
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
*/
using namespace std;

//Constructeur basique.
Table::Table()
{

}

//Destructeur.
Table::~Table()
{

    delete boules;
}



void Table::innitialisation() //Permet de positionner les boules sur la table ainsi que laisser aux joueurs choisir leur nom.
{
    string nom;
    cout<<"joueur 1 choisisez un nom"<<endl;
    cin>>nom;
    players[0]=Player(nom,"aucaun");
    cout<<"joueur 2 choisisez un nom"<<endl;
    cin>>nom;
    players[1]=Player(nom,"aucaun");

    cout << "la table a une largeur de 1.27m et une longueur de 2.54m." << endl << "la table est orientee de cette maniere :  " << endl <<  " ___________" << endl << "|           |" << endl << "|           |" << endl << "|___________|" << endl;



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

void Table::mecanique() // Regroupe toute la partie mécanique du billard. Exécute donc les formules de cinétique et collisions pour toutes les boules à chaque rafraîchissement.
{
    double t = clock();


    int i = 0; //Itération pour les boucles.
    int z = 0; //Itération pour les boucles.

    //Le code ci-dessous s'exécute tant qu'une des boules est en mouvement.
    while(boules[0].intensiteeV() > 0 or boules[1].intensiteeV() > 0 or boules[2].intensiteeV() > 0 or boules[3].intensiteeV() > 0 or boules[4].intensiteeV() > 0 or boules[5].intensiteeV() > 0 or boules[6].intensiteeV() > 0 or boules[7].intensiteeV() > 0 or boules[8].intensiteeV() > 0 or boules[9].intensiteeV() > 0 or boules[10].intensiteeV() > 0 or boules[11].intensiteeV() > 0 or boules[12].intensiteeV() > 0 or boules[13].intensiteeV() > 0 or boules[14].intensiteeV() > 0 or boules[15].intensiteeV() > 0)
    {
        double f=0;

        f = clock();

        i = 0;
        z = 0;

        while(i < nombreDeBoules)
        {
            boules[i].empochage();


            boules[i].collTable();  //Vérfie les collisions entre la table et chaque boule.
            if(boules[i].boulband()==true)
            {
                boulebandes.push_back(i); //Ajoute au tableau les boules qui ont touché une bande.

            }

            z = 0;
            while(z < nombreDeBoules)
            {
                if(z != i)
                {
                    boules[i].collBoule(boules[z]); //Verification des collisions entre chaque boule.
                    if(boules[i].collisionBoule()==true)
                    {
                        typeBoule.push_back(boules[z].typeBoule()); // Ajoute au tableau le type de boule de la cible.

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
            boules[i].deplacemelent(f); //Déplace toutes les boules.
            i++;
        }

    }
    t = clock()-t;





}


void Table::afficher() //Affiche l'emplacement, le nom et les composantes du vecteur vitesse de chaque boule.
{
    int i = 0;

    while(i < nombreDeBoules)
    {
        boules[i].afficher();
        i++;
    }
}

void Table::casse() // Déroulement de la casse (première phase du jeu).
{
    boules[15].replacementblanche(); // Place la blanche.
    cout<< endl << "C'est au joueur "<<players[joueur].nomjoueur()<<" de jouer"<< endl << "le triangle de casse se situe a droite de la boule blanche" << endl;
    blancheempochee=false;
    this->reset(); // Remet à 0 certains paramètres (nombre de boules qui ont touché une bande par exemple).
    boules[15].shoot(); //Shoot la boule.
    this->mecanique(); //Partie mécanique du billard (collisions, déplacement...).
    this->numeroBouleEmpochee(); //Pour déterminer le nombre de pleines ou rayées empochées.
    sort( boulebandes.begin(), boulebandes.end() );
    boulebandes.erase( unique( boulebandes.begin(), boulebandes.end() ), boulebandes.end() );//Enlève les doublons.

    if(boules[7].empochee()==true){//Si la noire est empochée la casse n'est pas valide.
        cout<<"Mauvaise casse: boule noire empochee "<<endl;
        cout<<"C'est a l'autre joueur de casser"<<endl;
        cassereussi =false;
    }
    else if(boulebandes.size()<4 and boulesempochee<1)//Si moins de 4 boules touchent au moins une bande et aucune boule n'est empochée, la casse n'est pas valide.
    {
        cout<<"Mauvaise casse: moins de 4 boules ont touche une bande et aucune boule n'a ete empochee"<<endl;
        cout<<endl<<"C'est a l'autre joueur de casser"<<endl;
        cassereussi =false;
    }
    else if(boulesempochee==0) //Change de joueur si aucune boule n'est empochée.
    {
        joueur = players[0].finDeTour();
        cout<<"C'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        cassereussi =true;
    }
    else if(boules[15].empochee()==true)//Change de joueur si la blanche empochée et la noire n'est pas empochée.
    {
        blancheempochee=true;
        cassereussi =true;
        if(boules[7].empochee()==true)
        {
            pertedepartie ==true;
        }
        else
        {
            joueur =players[0].finDeTour();
            cout<<"C'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        }

    }
    else
    {
        cout<<"C'est toujours au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        cassereussi=true;
    }
    if(cassereussi==false)
    {
        joueur =players[0].finDeTour();//Change de joueur.
        this->replacementBoules();//Replace les boules à leurs positions innitiales.

    }

}
bool Table::faute() //Conditions pour qu'il y ai une faute.
{

    if(boules[15].empochee()==true) //Blanche empochée.
    {
        fautes = true;
        cout<<"Faute: Blanche empochee."<<endl;
        blancheempochee=true;
    }
    else if(boulebandes.size()==0 and boulesempochee==0) //Aucune boule n'a touché de bande (à part la blanche) et aucune boule n'est empochée.
    {
        cout<<"Faute: aucune boule n'a touche de raille ou a ete empoche."<<endl;
        fautes = true;
    }
    else if(groupeChoisi==true and players[joueur].choix()!=typeBoule[0]) // La blanche a touché le type de boule du joueur adverse (rayée ou pleine).
    {
        fautes = true;
        cout<<"Faute: collision avec boule du joueur adverse"<<endl;
    }
    if(fautes==true and boules[7].empochee()==true)
    {
        pertedepartie=true;
        fautes =false;
    }
    return fautes;
}

void Table::reset() // Remet à 0 le nombre de boules qui ont touché les bandes, qui ont été empochées et les type de boules touchées.
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
        bouleEmpochee.pop_back();
    }
    boulesempochee=0;
    blancheempochee=false;
}

void Table::choixGroupe() // Détermine le groupe de boule des joueurs (rayée ou pleine) si ce n'est pas déja fait.
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
            int p=0; //Les pleines.
            int r=0; //Les rayées.
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
            if(p>r) // S'il y a plus de pleines empochées que de rayées.
            {
                cout<<"Joueur " <<players[joueur].nomjoueur()<<" a les pleine"<<endl;
                players[joueur].choisir("pleine");
                players[autrejoueur].choisir("rayee");
            }
            else if(r>p) // S'il y a plus de rayées empochées que de pleines.
            {
                cout<<"Joueur a les rayees"<<endl;
                players[joueur].choisir("rayee");
                players[autrejoueur].choisir("pleine");
            }
            else // Dans le cas où un nombre de rayées empochées est égale au nombre de pleines.
            {
                string typeboule;
                while (typeboule != "pleine" and typeboule !="rayee")
                {
                    cout<<"Quel groupe choisissez vous? (pleine ou rayee)"<<endl;
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


void Table::numeroBouleEmpochee() // Incrémentation du tableau si une boule a été empochée pendant ce tour.
{
    for(int i=0;i<nombreDeBoules-1;i++)
    {

        if(boules[i].empochee()==true and boules[i].bouledejaempochee()==false)
        {
            bouleEmpochee.push_back(i);
            empocheee.push_back(i+1);
            boulesempochee++;
        }
        boules[i].verificationbouledejaempochee();
    }
}



void Table::jouer() // Le déroulement de la partie. Regroupe toutes les fonctions.
{
    this->innitialisation(); //Innitialisation de la partie.

    while(cassereussi==false) // La casse.
    {
        this->casse();
    }

    while(boules[7].empochee()==false) // La deuxième partie du jeu où tant que la noire n'est pas empochée, on joue.
    {

        for (int i=0;i<empocheee.size();i++)
        {
            cout<< "La boule numero "<<empocheee[i]<<" est empochee"<<endl;

        }
        string reponse;
        while (reponse != "y" and reponse != "n") // Pour laisser au joueur le choix d'afficher ses boules.
        {
            cout<<reponse<<endl;
            cout<<"Voulez-vous afficher les positions des boules ? (y/n)"<<endl;
            cin>>reponse;
        }
         if(reponse =="y")
        {
            this->afficher();
        }
        if(blancheempochee==true)boules[15].replacementblanche();


        boules[15].shoot();

        this->reset();//Remet à 0 certains paramètres.

        this->mecanique(); // Partie mécanique du billard.
        this->numeroBouleEmpochee();
        if(faute()) //Vérifie s'il y a faute, et si c'est le cas cela change de joueur.
        {
            joueur =players[0].finDeTour();
            cout<<"C'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
            fautes = false;
        }
        else if(boulesempochee==0) //Change de joueur s'il n'a pas empoché de boule.
        {
            cout<<"Aucune boule n'est empochee"<<endl;
            joueur =players[0].finDeTour();//Change de joueur
            cout<<"C'est au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
        }
        else
        {
            cout<<"C'est toujours au joueur "<< players[joueur].nomjoueur()<< " de jouer"<<endl;
            choixGroupe();
        }

    }

    //Fin de la partie. Nous regardons quel joueur a gagné : si le joueur qui joue a empoché toutes les boules de son groupe et qu'il n'a pas commis de faute pendant le tour, il a gagné, sinon il a perdu.
    if(players[joueur].choix()== "pleine")
    {
        if(boules[0].empochee()==true and boules[1].empochee()==true and boules[2].empochee()==true and boules[3].empochee()==true and boules[4].empochee()==true and boules[5].empochee()==true and boules[6].empochee()==true and pertedepartie ==false)
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
        if(boules[8].empochee()==true and boules[9].empochee()==true and boules[10].empochee()==true and boules[11].empochee()==true and boules[12].empochee()==true and boules[13].empochee()==true and boules[14].empochee()==true and pertedepartie ==false)
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
}
