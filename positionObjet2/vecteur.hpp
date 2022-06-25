#ifndef Vecteur_HPP_INCLUDED
#define Vecteur_HPP_INCLUDED

#include <iostream>

using namespace std;

class Vecteur
{
public:
    Vecteur();
    Vecteur(double i, double s);
    void modifier(double i, double s);
    void afficher(std::ostream &flux) const;
    double i();
    double s();
    Vecteur& operator+=(const Vecteur &vecteur);
    //void afficher() const;

private:
    double m_i;
    double m_s;

};

Vecteur operator+(Vecteur const& a, Vecteur const& b);
ostream& operator<<(ostream &flux, Vecteur const& vecteur);

#endif
