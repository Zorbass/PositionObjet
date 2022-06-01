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

    double m_ax;
    double m_ay;

    double m_t;
    double m_m = 0.162;
    double m_c = 0.5;
    double m_g = 9.81;
    double m_f = 0.3;
    double m_v;
};

#endif
