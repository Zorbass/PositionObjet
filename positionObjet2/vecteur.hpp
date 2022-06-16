#ifndef Vecteur_HPP_INCLUDED
#define Vecteur_HPP_INCLUDED

#include <iostream>
#include <string>

class Vecteur
{
public:
    Vecteur();
    Vecteur(double x, double y);
    Vecteur& operator+=(const Vecteur &vecteur);
    void afficher() const;
    void afficher2(std::ostream &flux) const;
    double x();
    double y();

private:
    double m_x;
    double m_y;

};

Vecteur operator+(Vecteur const& a, Vecteur const& b);


#endif
