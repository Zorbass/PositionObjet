#include "Boule.hpp"
#include <ctime>

using namespace std;

Boule::Boule() : m_nom("A"), m_x(0), m_y(0)
{
}

Boule::Boule(string nom, int x, int y) : m_nom(nom), m_x(x), m_y(y)
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
    cout << "Pendant combien de temps ??" << endl;
    cin >> m_t;

    m_x = m_x + m_vx * m_t;
    m_y = m_y + m_vy * m_t;

    double f = 10;
    double n = m_t*1000/f;
    double i;

    double t;
    while(m_t > f*i)
    {
        t = clock();
        t = clock() - t;
        if(t)

        i++;
    }
