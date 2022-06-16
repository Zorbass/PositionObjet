#include <iostream>
#include "Vecteur.hpp"

using namespace std;

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
    cout <<"composante x: "<< m_x <<" composante y : " << m_y << endl;
}

Vecteur operator+(Vecteur const& a, Vecteur const& b)
{
    Vecteur copie(a);
    copie += b;
    return copie;
}


