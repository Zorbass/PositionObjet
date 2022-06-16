#ifndef Vecteur_HPP_INCLUDED
#define Vecteur_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Vecteur
{
public:
    Vecteur();
    Vecteur(double x, double y);
    Vecteur& operator+=(const Vecteur &vecteur);
    //void afficher() const;
    double x();
    double y();
    void afficher(std::ostream &flux) const;

private:
    double m_x;
    double m_y;

};

Vecteur operator+(Vecteur const& a, Vecteur const& b);
ostream& operator<<(ostream &flux, Vecteur const& vecteur);

#endif
