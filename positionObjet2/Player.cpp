#include <iostream>
#include "Boule.hpp"
#include "Vecteur.hpp"
#include <vector>
#include "Player.hpp"


using namespace std;

Player::Player()
{

}

Player::Player(string nom, string typeBoule): m_nom(nom), m_typeBoule(typeBoule)
{

}
void Player::casse()
{

}

void Player::shoot(Boule i)
{
    i.shoot();
    i.afficher();
}

void Player::choisir(string i)
{
    m_typeBoule = i;
}

string Player::choix()
{
    return m_typeBoule;
}
