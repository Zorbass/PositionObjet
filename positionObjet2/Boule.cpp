#include "Boule.hpp"
#include <cmath>
#define PI 3.14159265


using namespace std;

Boule::Boule() : m_nom("A"), m_x(0), m_y(0)
{
}

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
    cin >> m_vx;
    cout << "Vitesse y ??" << endl;
    cin >> m_vy;

    m_x = m_x + (m_vx*m_vx) / (2*m_g*m_f);
    m_y = m_y + (m_vy*m_vy) / (2*m_g*m_f);

    /*
    m_x = m_x + m_vx * m_t + m_ax * m_t * m_t / 2;
    m_y = m_y + m_vy * m_t + m_ay * m_t * m_t / 2;
    */
    /*
    m_ax =
    m_ay =
    m_t =

    m_ax = -m_m * m_g * m_f * cos(atan((PI * m_vy/m_vx)/180));
    m_ay = -m_m * m_g * m_f * sin(atan((PI * m_vy/m_vx)/180));
    m_t = m_v/sqrt(m_ay*m_ay + m_ax*m_ax);

    cout << "temps : " << m_t << endl;
    cout << "ax : " << m_ax<< endl;
    cout << "ay : " << m_ay<< endl;
    */

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
