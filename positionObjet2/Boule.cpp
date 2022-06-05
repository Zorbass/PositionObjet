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
    /*cout << "Temps ??" << endl;
    cin >> m_t;*/

    m_v = sqrt(m_vx*m_vx + m_vy*m_vy);

    m_t = m_v/m_a;

    double kx = m_vx/m_v;
    double ky = m_vy/m_v;

    m_ax = kx*m_a;
    m_ay = ky*m_a;

    double f = 1;
    double n = m_t*1000/f;
    double i = 0;

    double t;
    double u;

    cout << clock() << endl;
    while(n > i)
    {
        u = clock();
        t = clock();

        while(t-u < f)
        {
            t = clock();
        }

        m_vx = m_vx - m_ax*f/1000;
        m_x = m_x - m_ax*0.5*f*f/1000000 + m_vx*f/1000;

        m_vy = m_vy - m_ay*f/1000;
        m_y = m_y - m_ay*0.5*f*f/1000000 + m_vy*f/1000;

        /*m_x = m_x + m_vx*f/1000;
        m_y = m_y + m_vy*f/1000;*/

        if(m_x+m_r >= 11 and m_y+m_r >= 6 or m_x+m_r >= 11 and m_y+m_r <= 0 or m_x+m_r <= 0 and m_y+m_r >= 6 or m_x+m_r <= 0 and m_y+m_r <= 0)
        {
            m_vx = - m_vx;
            m_vy = - m_vy;
            m_ax = - m_ax;
            m_ay = - m_ay;
        }

        else if(m_x+m_r >= 11 or m_x+m_r <= 0)
        {
            m_vx = - m_vx;
            m_ax = - m_ax;
        }

        else if(m_y+m_r >= 6 or m_y+m_r <= 0)
        {
            m_vy = - m_vy;
            m_ay = - m_ay;
        }

        i++;
    }
    cout << clock() << endl;

    }
