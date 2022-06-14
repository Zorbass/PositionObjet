#ifndef Vecteur_HPP_INCLUDED
#define Vecteur_HPP_INCLUDED

class Vecteur
{
public:
    Vecteur(double x = 0, double y = 0);
    Vecteur& operator+=(const Vecteur &vecteur);
    void afficher() const;

private:
    double m_x;
    double m_y;

};

Vecteur operator+(Vecteur const& a, Vecteur const& b);

#endif
