#ifndef BOULE_HPP_INCLUDED
#define BOULE_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Vecteur.hpp"

using namespace std;

class Boule
{
    public:

    Boule();  //ok
    Boule(std::string numero, std::string type, double x, double y,double xprime, double yprime);  //ok

    void afficher();  //ok

    void positionprime();

    double positionX(); //ok

    double positionY(); //ok

    double intensiteeV();

    double intensiteeA();

    double angle();

    void changerVitesse(double x, double y); //ok

    void deplacemelent(double f);

    void empochage();

    void collBoule(Boule &cible);

    void collTable();

    void shoot(); //ok

    private:

    std::string m_numero;
    std::string m_type;
    double m_x; //Position de la bille sur l'axe x
    double m_y; //Position de la bille sur l'axe y
    double m_xprime;
    double m_yprime;
    double m_t; //temps de d�placement de la bille
    Vecteur acceleration;
    double m_r = 0.0286; //rayon de la bille
    double m_d; //deplacement de la resultante
    Vecteur vitesse;
    bool m_empochee = false;

};

#endif
