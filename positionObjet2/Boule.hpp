#ifndef BOULE_HPP_INCLUDED
#define BOULE_HPP_INCLUDED

#include <iostream>
#include <string>

class Boule
{
    public:

    Boule();
    Boule(std::string nom, int x, int y);

    void afficher();

    double positionX();

    double positionY();

    void changerVitesse(int x, int y);

    void collision(Boule &cible);

    void shoot();

    void deplacement();

    private:

    std::string m_nom;
    double m_x; //Position de la bille sur l'axe x
    double m_y; //Position de la bille sur l'axe y
    double m_vx; //vitesse de la bille sur l'axe x
    double m_vy; //vitesse de la bille sur l'axe y
    double m_t; //temps de déplacement de la bille
    double m_v; //vitesse de la bille
    double m_a = 2.943; //acceleration generee par le frottement
    double m_ax; //acceleration generee par le frottement sur l'axe x
    double m_ay; //acceleration generee par le frottement sur l'axe y
    double m_r = 0.0254; //rayon de la bille
};

#endif
