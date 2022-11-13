//La classe player nous permet de faire int�ragir les joueurs avec la table ainsi que de d�terminer le joueur ayant la main.

#include <iostream>
//#include "Boule.hpp"
//#include "Vecteur.hpp"
#include <vector>
#include "Player.hpp"
#include "Table.hpp"


using namespace std;

Player::Player() //Constructeur basique
{

}

Player::Player(string nom, string typeBoule): m_nom(nom), m_typeBoule(typeBoule) //Constructeur personnalisable.
{

}
string Player::nomjoueur() // retourne le nom du joueur
{
    return m_nom;
}
int Player::finDeTour() // On change de joueur qui joue. Celui qui jouait avant ne joue plus et c'est au tour de l'autre.
{
    if(player ==0)
    {
        player =1;
    }
    else
    {
        player = 0;
    }
    return player;
}


void Player::choisir(string i) //Permet d'attribuer un groupe de boule au joueur (ray�e ou pleine).
{
    m_typeBoule = i;
}

string Player::choix() // Retourne le groupe de boule du joueur (rayee ou pleine).
{
    return m_typeBoule;
}
