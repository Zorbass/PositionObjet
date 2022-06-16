#include <iostream>
#include "Vecteur.hpp"

using namespace std;

Vecteur::Vecteur() : m_x(0), m_y(0)
{
}

Vecteur::Vecteur(double x, double y) : m_x(x), m_y(y)
{
}

Vecteur& Vecteur::operator+=(const Vecteur &vecteur2)
{
    m_x += vecteur2.m_x;
    m_y += vecteur2.m_y;

    return *this;
}

void Vecteur::afficher() const
{
    cout << "(" << m_x << ";" << m_y << ")" << endl;
}

Vecteur operator+(Vecteur const& a, Vecteur const& b)
{
    Vecteur copie(a);
    copie += b;
    return copie;
}


