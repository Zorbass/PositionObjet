#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Boule.hpp"
#include <vector>
#include "Vecteur.hpp"

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
    double temps();
    void afficher();


private:

    string m_nom;
    double m_x;
    double m_y;

    double m_t;

    int nombreDeBoules=16;

    double t=0;

    Boule *boules = new Boule[16];

};


#endif
