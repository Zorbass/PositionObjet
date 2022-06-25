#include <iostream>
#include "Vecteur.hpp"

using namespace std;

Vecteur::Vecteur() : m_i(0), m_s(0)
{
}

Vecteur::Vecteur(double i, double s) : m_i(i), m_s(s)
{
}


void Vecteur::modifier(double i, double s)
{
    m_i = i;
    m_s = s;
}

/*void Vecteur::afficher() const
{
    cout << "(" << m_x << ";" << m_y << ")" << endl;
}*/

void Vecteur::afficher(ostream &flux) const
{
    flux << "(" << m_i << ";" << m_s << ")";
}

double Vecteur::i()
{
    return m_i;
}

double Vecteur::s()
{
    return m_s;
}


Vecteur& Vecteur::operator+=(const Vecteur &vecteur2)
{
    m_x += vecteur2.m_;
    m_y += vecteur2.m_y;

    return *this;
}

Vecteur operator+(Vecteur const& a, Vecteur const& b)
{
    Vecteur copie(a);
    copie += b;
    return copie;
}

ostream& operator<<( ostream &flux, Vecteur const& vecteur)
{
    vecteur.afficher(flux) ;
    return flux;
}
