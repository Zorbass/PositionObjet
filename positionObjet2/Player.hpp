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
    //void shoot(Boule i);

    void choisir(string i);
    string choix();

private:

    string m_nom;
    string m_typeBoule;
//    int m_points;
    int player =0;
//    Boule i;

};

#endif
