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
    Boule(std::string numero, std::string type, double x, double y);  //ok

    void afficher();  //ok

    double positionX(); //ok

    double positionY(); //ok

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
    double m_t; //temps de déplacement de la bille
    Vecteur acceleration;
    double m_r = 0.0286; //rayon de la bille
    double m_d; //deplacement de la resultante
    Vecteur vitesse;
    bool m_empochee = false; //si la boule est empochee
    bool m_dejaempochee =false; //si la boule est dejaempoche
    bool boulebande = false; //si la boule a touche une bande
    bool collboule =false; //si la boule a touche une autre boule


};

#endif
