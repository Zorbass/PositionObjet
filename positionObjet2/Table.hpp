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
    void casse();
    bool faute();
    void reset();
    void choixGroupe();
    void numeroBouleEmpochee();




private:

    string m_nom;
    double m_x;
    double m_y;

    bool fautes= false;
    int boulbande;
    int boulesempochee=0;

    int joueur=0;
    int autrejoueur;

    bool groupeChoisi = false;
    bool blancheempochee =false;
    double m_t;

    double m_f=0;//f retient le temps passé depuis le dernier rafraîchissment
    double m_u=0;//temps du frame d'avant

    int nombreDeBoules=16;


    Boule *boules = new Boule[16];
    Player players[2];

    vector <int> boulebandes;

    vector <int> bouleEmpochee;

};


#endif

