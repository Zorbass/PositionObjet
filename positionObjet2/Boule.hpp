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
    Boule(std::string nom, double x, double y);  //ok

    void afficher();  //ok

    double positionX(); //ok

    double positionY(); //ok

    void changerVitesse(double x, double y); //ok

    void collision(Boule &cible);

    void shoot(); //ok

    private:

    std::string m_nom;
    double m_x; //Position de la bille sur l'axe x
    double m_y; //Position de la bille sur l'axe y
    double m_vx; //vitesse de la bille sur l'axe x
    double m_vy; //vitesse de la bille sur l'axe y
    double m_t; //temps de déplacement de la bille
    double m_v; //vitesse de la bille
    double m_a = 2.943; //acceleration generee par le frottement
    Vecteur acceleration;
    double m_ax; //acceleration generee par le frottement sur l'axe x
    double m_ay; //acceleration generee par le frottement sur l'axe y
    double m_r = 0.0254; //rayon de la bille
    double m_alpha; //angle entre l'axe verticale et la vitesse
    double m_d; //deplacement de la resultante
    Vecteur vitesse;

};

#endif
