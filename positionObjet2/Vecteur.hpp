#ifndef VECTEUR_HPP_INCLUDED
#define VECTEUR_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Vecteur
{
public:
    Vecteur();
    Vecteur(double x, double y);
    Vecteur& operator+=(const Vecteur &vecteur);
    double x();
    double y();
    void afficher(std::ostream &flux) const;
    void modifier(double x, double y);
    void modifierX(double x);
    void modifierY(double y);

private:
    double m_x; //Composante de l'intensit� du vecteur.
    double m_y;//Composante de l'angle (par rapport � l'axe y dans le sens horaire) repr�sentant la direction du vecteur.

};

Vecteur operator+(Vecteur const& a, Vecteur const& b);
ostream& operator<<(ostream &flux, Vecteur const& vecteur);


#endif // VECTEUR_HPP_INCLUDED
