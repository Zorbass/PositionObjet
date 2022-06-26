#include <iostream>

#include "Boule.hpp"
#include "Vecteur.hpp"
#include <ctime>
#include <cmath>

using namespace std;

#define PI 3.141592653589793238462643383279

//constructeur basique
Boule::Boule() : m_nom("A"), m_x(0), m_y(0), vitesse(0, 0), acceleration(2.943, 0)
{
}

//constructeur personalisable
Boule::Boule(string nom, double x, double y) : m_nom(nom), m_x(x), m_y(y), vitesse(0, 0), acceleration(2.943, 0)
{
}

//affiche le nom, la vitesse et la position de la bille.
void Boule::afficher()
{
    cout << "Boule : " << m_nom << " (Position : " << m_x << ";" << m_y << ")" << endl << "vitesse : " << vitesse << endl;
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
void Boule::changerVitesse(double x, double y)
{
    vitesse.modifier(x, y);
}

//fait avancer la bille et effectue les contacts si il y en a.
void Boule::collision(Boule &cible)
{
    m_t = vitesse.x()/acceleration.x();

/*
    double kx = m_vx/m_v; //relation entre la resultante et l'axe x
    double ky = m_vy/m_v; //relation entre la resultante et l'axe y

    m_ax = kx*m_a; //calcule de l'accélération de la bille sur l'axe x
    m_ay = ky*m_a; //calcule de l'accélération de la bille sur l'axe y
*/
    double f = 0; //frequence de rafraichissement

    double u = 0; //temps au debut de la boucle

    double v = vitesse.x(), a = acceleration.x();

    while(m_t > u)
    {
        v = v - a*f/1000;
        vitesse.modifierX(v);
        m_d = v*f/1000 - a*0.5*f*f/1000000;


        m_x = m_x + sin(v*PI/180) * m_d;
        m_y = m_y + cos(v*PI/180) * m_d;

/*
        m_vx = m_vx - m_ax*f/1000; //calcule de la vitesse en x a chaque rafraichissement
        m_x = m_x - m_ax*0.5*f*f/1000000 + m_vx*f/1000; //calcule de la position en x a chaque rafraichissement

        m_vy = m_vy - m_ay*f/1000; //calcule de la vitesse en y a chaque rafraichissement
        m_y = m_y - m_ay*0.5*f*f/1000000 + m_vy*f/1000; //calcule de la position en y a chaque rafraichissement
*/
        f = clock(); //peut-etre pas necessaire

        if(sqrt((m_x-cible.positionX()) * (m_x-cible.positionX()) + (m_y-cible.positionY())*(m_y-cible.positionY()))<= 2*m_r)
        {
            //ces if ne sont pas correctes
            if(cible.positionX()-m_x < 2*m_r and cible.positionX()-m_x > 0)
            {
                m_x = cible.positionX() - 2*m_r - 0.00001;
            }

            else if(m_x-cible.positionX() < 2*m_r and m_x-cible.positionX()>0)
            {
                m_x = cible.positionX() + 2*m_r + 0.00001;
            }

            if(cible.positionY()-m_y < 2*m_r and cible.positionY()-m_y>0)
            {
                m_y = cible.positionY() - 2*m_r - 0.00001;
            }

            else if(m_y -cible.positionY()< 2*m_r and m_y -cible.positionY()>0)
            {
                m_y = cible.positionY() + 2*m_r + 0.00001;
            }


/*            if(cible.positionX()-m_x < 0 and cible.positionY()-m_y < 0)
            {
                m_gamma2 = m_gamma2 + 180;
            }
            else if(cible.positionX()-m_x > 0 and cible.positionY()-m_y < 0)
            {
                m_gamma2 = m_gamma2 + 180;
            }
*/
            double deltaX = cible.positionX()-m_x;
            double deltaY = cible.positionY()-m_y;

            double gamma2; //angle entre la verticale et la vitesse finale de la deuxième boule

            //if(deltaX * deltaY < 0)
            //{
            if(deltaX > 0 and deltaY < 0)
            {
                gamma2 = 90 + abs(atan(deltaY / deltaX)) * 180 / PI; //en degres
            }

            else if(deltaX < 0 and deltaY > 0)
            {
                gamma2 = 270 + abs(atan(deltaY / deltaX)) * 180 / PI; //en degres
            }
            //}

            //else if(deltaX * deltaY > 0)
            //{
            else if(deltaX > 0 and deltaY > 0)
            {
                gamma2 = abs(atan(deltaX / deltaY)) * 180 / PI; //en degres
            }

            else if(deltaX < 0 and deltaY < 0)
            {
                gamma2 = 180 + abs(atan(deltaX / deltaY)) * 180 / PI; //en degres
            }
            //}

            //else// if(deltaY * deltaX = 0)
            //{

            //est-ce que les else if qui suivent sont nécessaires??

            else if(deltaY < 0)
            {
                gamma2 = 180;
            }

            else if(deltaY > 0)
            {
                gamma2 = 0;
            }

            else if(deltaX < 0)
            {
                gamma2 = 270;
            }

            else if(deltaX > 0)
            {
                gamma2 = 90;
            }
            //}


            double theta2 = abs(gamma2 - vitesse.y()); //angle entre la vitesse finale de la boule 2 et la vitesse initaale de la boule 1
            double theta1 = 90 - theta2; //angle entre la vitesse finale de la boule 1 et la vitesse initaale de la boule 1

            double v2 = sin(theta1*PI/180) * vitesse.x(); //détermine la vitesse finale de la boule 2
            vitesse.modifierX(cos(theta1*PI/180) * vitesse.x()); //détermine la vitesse finale de la boule 1

            if(gamma2 > vitesse.y())
            {
                if(deltaX > 0 and deltaY > 0)
                {
                    vitesse.modifierY(gamma2 + 270);
                }
                else
                {
                    vitesse.modifierY(gamma2 - 90);
                }
            }

            else if(gamma2 < vitesse.y())
            {
                if(deltaX < 0 and deltaY > 0)
                {
                    vitesse.modifierY(gamma2 - 270);
                }
                else
                {
                    vitesse.modifierY(gamma2 + 90);
                }
            }

            else if(gamma2 = vitesse.y())
            {
                vitesse.modifierY(0);
            }

            cible.changerVitesse(v2, gamma2);
            u = m_t;

/*            cible.changerVitesse(m_v, m_alpha);
            m_v = 0;
            m_alpha = 0;
            u = m_t;
            cible.afficher();
*/
        }

        //calcule de la vitesse et acceleration si la bille touche la bande droit ou gauche
        if(m_x+m_r >= 11 or m_x-m_r <= 0)
        {
            vitesse.modifierY(360 - vitesse.y());
        }


        //calcule de la vitesse et acceleration si la bille touche la bande haute ou basse
        if(m_y+m_r >= 6 or m_y-m_r <= 0)
        {
            if(0 <= vitesse.y() <= 180)
            {
                vitesse.modifierY(180 - vitesse.y());
            }

            else if(180 < vitesse.y() <= 360)
            {
                vitesse.modifierY(540 - vitesse.y());
            }

        }

        f = clock() - f;

        u = u + f/1000;
    }

    cout << "fini collisions" << endl;
}

//permet de shooter la première bille
void Boule::shoot()
{
    double v, alpha;
    cout << "Vitesse ??" << endl;
    cin >> v;
    cout << "Angle par rapport a la verticale ?? (jusqu'a 359 dans le sens des aiguilles d'une montre)" << endl;
    cin >> alpha;

    vitesse.modifier(v, alpha);
}
