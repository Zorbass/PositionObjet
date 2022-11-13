//Dans ce fichier sont définis les méthodes et attributs de la classe player.

#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{

public:
    Player();
    Player(string nom, string typeBoule);
    int finDeTour();
    string nomjoueur();

    void choisir(string i);
    string choix();

private:

    string m_nom; //Nom du joueur.
    string m_typeBoule; //Nom du groupe des boule du joueur (pleines ou rayées).
    int player =0; //Détermine quel joueur est entrain de jouer.
};

#endif
