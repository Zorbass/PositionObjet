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
    Boule(std::string nom, double x, double y);

    void afficher();

    double positionX();

    double positionY();

    void changerVitesse(double x, double y);

    void collision(Boule &cible);

    void shoot();

    private:

    std::string m_nom;
    double m_x; //Position de la bille sur l'axe x
    double m_y; //Position de la bille sur l'axe y
    double m_vx; //vitesse de la bille sur l'axe x
    double m_vy; //vitesse de la bille sur l'axe y
    double m_t; //temps de déplacement de la bille
    double m_v; //vitesse de la bille
    double m_a = 2.943; //acceleration generee par le frottement
    Vecteur acceleration(2.943, 0)
    double m_ax; //acceleration generee par le frottement sur l'axe x
    double m_ay; //acceleration generee par le frottement sur l'axe y
    double m_r = 0.0254; //rayon de la bille
    double m_alpha; //angle entre l'axe verticale et la vitesse
    double m_d; //deplacement de la resultante
    Vecteur vitesse;

};

#endif
