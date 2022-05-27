#include "Boule.hpp"

using namespace std;


Boule::Boule(string nom, double x, double y) : m_nom(nom), m_x(x), m_y(y)
{
}


void Boule::afficher()
{

    cout << "Boule : " << m_nom << " (Position : " << m_x << ";" << m_y <<")" << endl;

}

void Boule::deplacement()
{
    cout << "Vitesse x ??" << endl;
    cin >> m_vix;
    cout << "Vitesse y ??" << endl;
    cin >> m_viy;




    m_x = m_x + (m_vix*m_vix) / (2*m_mu);
    m_y = m_y + (m_viy*m_viy) / (2*m_mu);
}

/*
x = x + vx * t;
    y = y + vy * t;


Arme::Arme() : m_nom("Epée rouillée"), m_degats(10)
{
}

Arme::Arme(string nom, int degats) : m_nom(nom), m_degats(degats)
{
}

void Arme::changer(string nom, int degats)
{
    m_nom = nom;
    m_degats = degats;
}

void Arme::afficher()
{
    cout << "Arme : " << m_nom << " (Dégâts : " << m_degats << ")" << endl;
}

int Arme::getDegats() const
{
    return m_degats;
}*/
