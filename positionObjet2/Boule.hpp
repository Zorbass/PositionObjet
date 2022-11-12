#ifndef BOULE_HPP_INCLUDED
#define BOULE_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Vecteur.hpp"

using namespace std;

class Boule
{
    public:

    Boule();
    Boule(std::string numero, std::string type, double x, double y);  //ok

    void shoot();

    void afficher();

    double positionX();

    double positionY();

    double intensiteeV();

    double intensiteeA();

    double angle();

    string typeBoule();

    bool boulband();

    bool empochee();

    bool bouledejaempochee();

    bool boulesempochees();

    bool collisionBoule();

    void verificationbouledejaempochee();

    void replacementblanche();

    void changerVitesse(double x, double y);

    void deplacemelent(double f);

    void empochage();

    void collBoule(Boule &cible);

    void collTable();


    private:

    std::string m_numero;
    std::string m_type;
    double m_x; //Position de la boule sur l'axe x.
    double m_y; //Position de la boule sur l'axe y.
    double m_t; //Temps de d�placement de la boule.
    Vecteur acceleration;
    double m_r = 0.0286; //Rayon d'une boule.
    double m_d; //D�placement de la r�sultante.
    Vecteur vitesse;
    bool m_empochee = false; //Si la boule est empoch�e, �a devient true.
    bool m_dejaempochee =false; //Si la boule est deja empoch�e, �a devient true.
    bool boulebande = false; //Si la boule a touch� une bande, �a devient true.
    bool collboule =false; //Si la boule a touch� une autre boule, �a devient true.


};

#endif
