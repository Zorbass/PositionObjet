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
    void mecanique(Boule &cible);
    void test();
    void jouer();


private:

    string m_nom;
    double m_x;
    double m_y;

    double m_t;

    Boule *m_b;

    int nombreDeBoules=16;


    Boule *m_b1;
    Boule *m_b2;
    Boule *m_b3;
    Boule *m_b4;
    Boule *m_b5;
    Boule *m_b6;
    Boule *m_b7;
    Boule *m_b8;
    Boule *m_b9;
    Boule *m_b10;
    Boule *m_b11;
    Boule *m_b12;
    Boule *m_b13;
    Boule *m_b14;
    Boule *m_b15;
    Boule *m_b16;


};


#endif

