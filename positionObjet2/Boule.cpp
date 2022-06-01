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

    m_tx = m_vx/m_a;
    m_ty = m_vy/m_a;

    double f = 1;
    double nx = m_tx*1000/f;
    double i = 0;

    double t;


    cout << clock() << endl;
    while(nx > i)
    {
        double u = clock();
        t = clock();

        while(t-u < f)
        {
            t = clock();
        }

        m_vx = m_vx - m_a*f/1000;
        m_x = m_x + m_a*1/2*f/1000*f/1000 + m_vx*f/1000;


        /*m_x = m_x + m_vx * m_t/n;
        m_y = m_y + m_vy * m_t/n;*/

        i++;
    }
    cout << clock() << endl;
}
