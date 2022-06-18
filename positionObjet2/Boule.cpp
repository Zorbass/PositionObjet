#include "Boule.hpp"
#include <ctime>
#include <cmath>

#define PI 3.141592653589793238462643383279

using namespace std;

//constructeur basique
Boule::Boule() : m_nom("A"), m_x(0), m_y(0), m_v(0), m_alpha(0)
{
}

//constructeur personalisable
Boule::Boule(string nom, int x, int y) : m_nom(nom), m_x(x), m_y(y), m_v(0), m_alpha(0)
{
}

//affiche le nom, la vitesse et la position de la bille.
void Boule::afficher()
{
    cout << "Boule : " << m_nom << " (Position : " << m_x << ";" << m_y << ")" << endl << "vitesse : " << m_v << "; " << m_alpha << " degres" << endl;
}

//retourne la position de la bille en x
double Boule::positionX()
{
    return m_x;
}

//retourne la position de la bille en y
double Boule::positionY()
{
    return m_y;
}

//modifie la vitesse de la bille
void Boule::changerVitesse(int x, int y)
{
    m_v = x;
    m_alpha = y;
}

//fait avancer la bille et effectue les contacts si il y en a.
void Boule::collision(Boule &cible)
{
    m_t = m_v/m_a;
/*
    double kx = m_vx/m_v; //relation entre la resultante et l'axe x
    double ky = m_vy/m_v; //relation entre la resultante et l'axe y

    m_ax = kx*m_a; //calcule de l'accélération de la bille sur l'axe x
    m_ay = ky*m_a; //calcule de l'accélération de la bille sur l'axe y
*/
    double f = 0; //frequence de rafraichissement

    double u = 0; //temps au debut de la boucle

    while(m_t > u)
    {

        m_v = m_v - m_a*f/1000;
        m_d = m_v*f/1000 - m_a*0.5*f*f/1000000;

        m_x = m_x + sin(m_alpha*PI/180) * m_d;
        m_y = m_y + cos(m_alpha*PI/180) * m_d;
/*
        m_vx = m_vx - m_ax*f/1000; //calcule de la vitesse en x a chaque rafraichissement
        m_x = m_x - m_ax*0.5*f*f/1000000 + m_vx*f/1000; //calcule de la position en x a chaque rafraichissement

        m_vy = m_vy - m_ay*f/1000; //calcule de la vitesse en y a chaque rafraichissement
        m_y = m_y - m_ay*0.5*f*f/1000000 + m_vy*f/1000; //calcule de la position en y a chaque rafraichissement
*/
        f = clock(); //peut-etre pas necessaire

        if(sqrt((m_x-cible.positionX()) * (m_x-cible.positionX()) + (m_y-cible.positionY())*(m_y-cible.positionY()))<= 2*m_r)
        {
            if(m_x-cible.positionX() < 0)
            {
                m_x = cible.positionX() - 2*m_r;
            }

            else if(m_x-cible.positionX() > 0)
            {
                m_x = cible.positionX() + 2*m_r;
            }

            if(m_y-cible.positionY() < 0)
            {
                m_y = cible.positionY() - 2*m_r;
            }

            else if(m_y-cible.positionY() > 0)
            {
                m_y = cible.positionY() + 2*m_r;
            }

            cible.changerVitesse(m_v, m_alpha);
            m_v = 0;
            m_alpha = 0;
            u = m_t;
            cible.afficher();
        }

        //calcule de la vitesse et acceleration si la bille touche la bande droit ou gauche
        if(m_x+m_r >= 11 or m_x-m_r <= 0)
        {
            m_alpha = 360 - m_alpha;
            m_gamma = 360 - m_gamma;
        }


        //calcule de la vitesse et acceleration si la bille touche la bande haute ou basse
        if(m_y+m_r >= 6 or m_y-m_r <= 0)
        {
            m_alpha = 180 - m_alpha;
            m_gamma = 180 - m_gamma;
        }

        f = clock() - f;

        u = u + f/1000;
    }

    cout << "fini collisions" << endl;
    m_v = 0;
    m_alpha = 0;
}

//permet de shooter la première bille
void Boule::shoot()
{
    cout << "Vitesse ??" << endl;
    cin >> m_v;
    cout << "Angle par rapport a la verticale ?? (jusqu'a 359 dans le sens des aiguilles d'une montre)" << endl;
    cin >> m_alpha;
}
