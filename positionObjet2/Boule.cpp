#include "Boule.hpp"
#include <ctime>
#include <cmath>

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

    m_v = sqrt(m_vx*m_vx + m_vy*m_vy);

    m_t = m_v/m_a;

    double kx = m_vx/m_v;
    double ky = m_vy/m_v;

    cout << clock() << endl;
    while(n > i)
    {
        double u = clock();
        t = clock();

        while(t-u < f)
        {
            t = clock();
        }

       wedwdwd m_v = m_v - m_a*f*m_tx/1000/m_t;

        //m_vx = m_vx - m_a*f*m_tx/1000/m_t;
        m_x = m_x - m_a*0.5*f*f*m_tx*m_tx*m_tx/1000000/m_t/m_t/m_t + m_v*f*m_tx*m_tx/1000/m_t/m_t;

        //m_vy = m_vy - m_ay*f/1000;
        m_y = m_y - m_a*0.5*f*f*m_ty*m_ty*m_ty/1000000/m_t/m_t/m_t + m_v*f*m_ty*m_ty/1000/m_t/m_t;

        /*m_x = m_x + m_vx * m_t/n;
        m_y = m_y + m_vy * m_t/n;*/

        i++;
    }
    cout << clock() << endl;


    }
