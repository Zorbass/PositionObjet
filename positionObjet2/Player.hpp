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

    string m_nom;
    string m_typeBoule;
    int player =0;

};

#endif // PLAYER_HPP_INCLUDED
