#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Boule.hpp"
#include <vector>
#include "Vecteur.hpp"

using namespace std;

class Player
{

public:
    Player();
    Player(string nom, int points, string typeBoule);

    void shoot(Boule i);
    void gagnePoint();
    void choisir(string i);
    string choix();

private:

    string m_nom;
    string m_typeBoule;
    int m_points;
    Boule i;

};

#endif
