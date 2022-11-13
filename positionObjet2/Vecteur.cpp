#include <iostream>
#include "Vecteur.hpp"

using namespace std;

Vecteur::Vecteur() : m_x(0), m_y(0) //Constructeur basique.
{
}

Vecteur::Vecteur(double x, double y) : m_x(x), m_y(y) //Constructeur personalisable.
{
}


Vecteur& Vecteur::operator+=(const Vecteur &vecteur2) // Additionne les composantes des vecteurs (Cette méthode ne nous est plus utile car elle nécessite les composantes du vecteur sur les axes x et y).
{
    m_x += vecteur2.m_x;
    m_y += vecteur2.m_y;

    return *this;
}

void Vecteur::modifier(double x, double y) // Modifie les deux composantes des vecteurs.
{
    m_x = x;
    m_y = y;
}

void Vecteur::modifierX(double x) // Modifie la norme des vecteurs.
{
    m_x = x;
}

void Vecteur::modifierY(double y) // Modifie l'angle (direction) des vecteurs.
{
    m_y = y;
}

double Vecteur::x() //Retourne la norme des vecteurs.
{
    return m_x;
}

double Vecteur::y() //Retourne l'angle (direction) des vecteurs.
{
    return m_y;
}


void Vecteur::afficher(ostream &flux) const //Affiche les composantes des vecteurs.
{
    flux << "(" << m_x << ";" << m_y << ")";
}


Vecteur operator+(Vecteur const& a, Vecteur const& b) //méthode n'étant plus utilisée
{
    Vecteur copie(a);
    copie += b;
    return copie;
}

ostream& operator<<( ostream &flux, Vecteur const& vecteur) //participe à l'affichage correcte des composantes d'un vecteur dans la console.
{
    vecteur.afficher(flux) ;
    return flux;
}
