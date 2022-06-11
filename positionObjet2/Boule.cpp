#include "Boule.hpp"
#include <ctime>
#include <cmath>

using namespace std;

//constructeur basique
Boule::Boule() : m_nom("A"), m_x(0), m_y(0), m_vx(0), m_vy(0)
{
}

//constructeur personalisable
Boule::Boule(string nom, int x, int y) : m_nom(nom), m_x(x), m_y(y), m_vx(0), m_vy(0)
{
}

//affiche le nom, la vitesse et la position de la bille.
void Boule::afficher()
{
    cout << "Boule : " << m_nom << " (Position : " << m_x << ";" << m_y << ")" << endl << "vitesse : " << m_vx << "; " << m_vy << endl;
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
    m_vx = x;
    m_vy = y;
}

//fait avancer la bille et effectue les contacts si il y en a.
void Boule::collision(Boule &cible)
{
    m_v = sqrt(m_vx*m_vx + m_vy*m_vy); //pythagore

    //m_t = 1;

    m_t = m_v/m_a;

    double kx = m_vx/m_v; //relation entre la resultante et l'axe x
    double ky = m_vy/m_v; //relation entre la resultante et l'axe y

    m_ax = kx*m_a;
    m_ay = ky*m_a;

    double f = 1; //frequence de rafraichissement
    double n = m_t*1000/f; //nombre de rafraichissement a faire
    double i = 0; //nombre de refraichissements effectues

    double t; //temps a chaque instant
    double u; //temps au debut de la boucle

    while(n > i)
    {
        u = clock();
        t = clock();

        //tant que le temps ecoule entre le debut de la boucle et mtn est < que la freq de refraichissement : on fait la boucle
        while(t-u < f)
        {
            t = clock();
        }

        m_vx = m_vx - m_ax*f/1000; //calcule de la vitesse en x a chaque rafraichissement
        m_x = m_x - m_ax*0.5*f*f/1000000 + m_vx*f/1000; //calcule de la position en x a chaque rafraichissement

        m_vy = m_vy - m_ay*f/1000; //calcule de la vitesse en y a chaque rafraichissement
        m_y = m_y - m_ay*0.5*f*f/1000000 + m_vy*f/1000; //calcule de la position en y a chaque rafraichissement

        /*

        m_x = m_x + m_vx*f/1000;
        m_y = m_y + m_vy*f/1000;

        */


        if(sqrt((m_x-cible.positionX()) * (m_x-cible.positionX()) + (m_y-cible.positionY())*(m_y-cible.positionY()))<= 2*m_r)
        {
            cible.changerVitesse(m_vx, m_vy);
            m_vx = 0;
            m_vy = 0;
            i=n;
            cible.afficher();
        }

        //calcule de la vitesse et acceleration si la bille touche la bande droit ou gauche
        if(m_x+m_r >= 11 or m_x+m_r <= 0)
        {
            m_vx = - m_vx;
            m_ax = - m_ax;
        }


        //calcule de la vitesse et acceleration si la bille touche la bande haute ou basse
        if(m_y+m_r >= 6 or m_y+m_r <= 0)
        {
            m_vy = - m_vy;
            m_ay = - m_ay;
        }

        i++;
    }

    cout << "fini collisions" << endl;
    m_vx = 0;
    m_vy = 0;
}

//permet de shooter la première bille
void Boule::shoot()
{
    cout << "Vitesse x ??" << endl;
    cin >> m_vx;
    cout << "Vitesse y ??" << endl;
    cin >> m_vy;
}
