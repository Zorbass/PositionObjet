#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Table.hpp"


using namespace std;

Player::Player()
{

}

Player::Player(string nom, string typeBoule): m_nom(nom), m_typeBoule(typeBoule)
{

}
string Player::nomjoueur()
{
    return m_nom;
}
int Player::finDeTour()
{
    if(player ==0)
    {
        player =1;
    }
    else
    {
        player = 0;
    }
    cout<<"fin du tour"<<endl;
    return player;
}


void Player::choisir(string i)
{
    m_typeBoule = i;
}

string Player::choix()
{
    return m_typeBoule;
}
