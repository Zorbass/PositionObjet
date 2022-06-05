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

    void deplacement();

    private:

    std::string m_nom;
    double m_x;
    double m_y;
    double m_vx;
    double m_vy;
    double m_t;
    double m_v;
    double m_a = 2.943;
    double m_ax;
    double m_ay;
    double m_r = 0.0254;
};

#endif
