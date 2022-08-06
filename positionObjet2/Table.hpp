#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Boule.hpp"
#include <vector>
#include "Vecteur.hpp"
#include "Player.hpp"


using namespace std;

class Table
{

public:
    Table();
    Table(std::string m_nom, double m_x, double m_y);
    ~Table();


    void regle();
    void innitialisation();
    void mecanique();
    void test();
    void jouer();
    void afficher();
    double temps();


private:

    string m_nom;
    double m_x;
    double m_y;

    double m_t;

    double m_f=0;//f retient le temps pass� depuis le dernier rafra�chissment
    double m_u=0;//temps du frame d'avant

    int nombreDeBoules=16;


    Boule *boules = new Boule[16];
    Player player1;
    Player player2;

};


#endif

