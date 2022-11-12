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
    string m_typeBoule; //Type de boule du groupe du joueur.
    int player =0; //Joueur i.
};

#endif
