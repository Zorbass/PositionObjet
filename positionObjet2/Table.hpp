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
     vector <double> tempsboule; //stock le temps minimale d'une boule
     vector <int> boulesbougent; // stock quels boules sont en mouvement
     vector <int> action;//stock quel est la prochaine action de la boule

    double t=0;

    Boule *boules = new Boule[16];

};


#endif
