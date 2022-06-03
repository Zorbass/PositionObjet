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

    m_tx = m_vx/m_a;
    m_ty = m_vy/m_a;

    double k = m_vy/m_vx;
    m_ax = m_a / sqrt(k*k+1);
    m_ay = k * m_ax;

    double op = sqrt(m_ax*m_ax + m_ay*m_ay);
    cout << op << endl;

    m_v = sqrt(m_vx*m_vx + m_vy*m_vy);
    m_t = m_v/m_a; //sqrt(m_tx*m_tx + m_ty*m_ty);

    double px = m_x + m_vx*m_tx - m_a*m_tx*m_tx/2;
    cout << px << endl;

    double px2 = m_x + m_v*m_tx*m_tx/m_t - m_a*m_tx*m_tx*m_tx/m_t/2;
    cout << px2 << endl;

    double f = 1;
    double n = m_t*1000/f;
    double i = 0;

    double t;


    cout << clock() << endl;
    while(n > i)
    {
        double u = clock();
        t = clock();

        while(t-u < f)
        {
            t = clock();
        }

        m_v = m_v - m_a*f/1000;

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
