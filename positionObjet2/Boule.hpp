#ifndef BOULE_HPP_INCLUDED
#define BOULE_HPP_INCLUDED

#include <iostream>
#include <string>

class Boule
{
    public:

    Boule();
    Boule(std::string nom, double x, double y);

    void afficher();

    void deplacement();


    private:

    std::string m_nom;//nom de la boule

    double m_x;//position y
    double m_y;// position x
    double m_vix ;// vitesse iniatiale en x
    double m_viy ; //vitesse iniatiale en y
    double m_mu = 0.3 ; //coefficient de frottement
};

#endif
