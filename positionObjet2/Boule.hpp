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
    int m_x;
    int m_y;
    int m_vx;
    int m_vy;
    int m_t;
};

#endif
