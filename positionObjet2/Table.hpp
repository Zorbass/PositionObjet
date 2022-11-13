//Dans ce fichier sont d�finis les m�thodes et attributs de la classe Table.

#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Boule.hpp"
#include <vector>
#include "Player.hpp"


using namespace std;

class Table
{

public:
    Table();
    ~Table();


    void regle();
    void innitialisation();
    void replacementBoules();
    void mecanique();
    void test();
    void jouer();
    void afficher();
    void casse();
    bool faute();
    void reset();
    void choixGroupe();
    void numeroBouleEmpochee();
    void dessiner();




private:

    bool fautes= false; //Prends la valeur true lorsqu'une faute est commise.
    int boulbande; // Nombre de boules qui ont choqu�s avec la table durant le tour.
    int boulesempochee=0; //Nombre de boules empoch�es.


    int joueur=0; // Joueur "i".
    int autrejoueur; // L'autre joueur.

    bool groupeChoisi = false; //Permet de savoir si les groupes de boules des joueurs ont �t� d�termin�s.
    bool blancheempochee =false; //Permet de savoir si la blanche est empoch�e.
    bool cassereussi = false; //Pour savoir si la casse est valide ou pas.
    bool pertedepartie =false; //Si le joueur commet une faute lorsqu'il empoche la noire, il a automatiquement perdu.

    int nombreDeBoules=16;//Nombre de boules.


    Boule *boules = new Boule[16]; //Tableau des boules avec leur attributs.
    Player players[2]; // Tableau des joueurs.

    vector <int> boulebandes; //Tableau dynamique qui prend en compte les boules qui ont touch�es une bande.
    vector <int> bouleEmpochee; //Tableau dynamique qui prend en compte les boules qui ont �t� empoch�s pendant le tour actuel.
    vector <string> typeBoule; //Tableau dynamique qui prend en compte le type de boule de la cible.
    vector <int> empocheee; //tableau pour montrer quelles sont les boules empoch�es � la fin de chaque tour.

};


#endif
