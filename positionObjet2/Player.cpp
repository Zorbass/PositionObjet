#include <iostream>
#include "Boule.hpp"
#include "Vecteur.hpp"
#include <vector>
#include "Player.hpp"


using namespace std;

Player::Player()
{

}

Player::Player(string nom, int points, string typeBoule): m_nom(nom), m_points(points), m_typeBoule(typeBoule)
{

}


void Player::shoot(Boule i)
{
    i.shoot();
    i.afficher();
}

void Player::gagnePoint()
{
    m_points ++;
}

void Player::choisir(string i)
{
    m_typeBoule = i;
}

string Player::choix()
{
    return m_typeBoule;
}
