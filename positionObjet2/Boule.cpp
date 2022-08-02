#include <iostream>

#include "Boule.hpp"
#include "Vecteur.hpp"
#include <ctime>
#include <cmath>

using namespace std;

#define LARGEUR 6//1.27
#define LONGUEUR 11//2.54
#define PI 3.141592653589793238462643383279

//constructeur basique
Boule::Boule() : m_numero("0"), m_type("rayee"), m_x(0), m_y(0), vitesse(0, 0), acceleration(2.943, 0)
{
}

//constructeur personalisable
Boule::Boule(string numero, string type, double x, double y) : m_numero(numero), m_type(type), m_x(x), m_y(y), vitesse(0, 0), acceleration(2.943, 0)
{
}

//affiche le nom, la vitesse et la position de la bille.
void Boule::afficher()
{
    cout << "Boule : " << m_numero << " " << m_type << " (Position : " << m_x << ";" << m_y << ")" << endl << "vitesse : " << vitesse << endl;
}

//retourne la position de la bille en x
double Boule::positionX()
{
    return m_x;
}

double Boule::intensiteeV()
{
    return vitesse.x();
}

double Boule::intensiteeA()
{
    return acceleration.x();
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

void Boule::deplacemelent(double f)
{
    if(vitesse.y()<0)
    {
        vitesse.modifierY(vitesse.y() + 360);
    }

    if(vitesse.x()>0)
    {
        m_d = vitesse.x()*f/1000 /*- acceleration.x()*0.5*f*f/1000000*/;
        vitesse.modifierX(vitesse.x() - acceleration.x()*f/1000); //est-ce juste??

        m_x = m_x + sin(vitesse.y()*PI/180) * m_d;
        m_y = m_y + cos(vitesse.y()*PI/180) * m_d;
        if(vitesse.x()<0)
        {
            vitesse.modifierX(0);
        }
        if(vitesse.y()<0)
        {
            vitesse.modifierY(vitesse.y() + 360);
        }
    }

    else
    {
        vitesse.modifierX(0);
    }
}

void Boule::collBoule(Boule& cible)
{
    //si la distance entre les 2 boules est <= à 2 * le rayon d'une boule et que la vitesse de la boule != 0 il y a collision
    if(sqrt((m_x-cible.m_x) * (m_x-cible.m_x) + (m_y-cible.m_y)*(m_y-cible.m_y))<= 2*m_r and vitesse.x() != 0)
        {
            //informations tests
            cout << "BOULES " << m_numero << " : " << m_x << " ; " << m_y << endl;
            cout << "collision" << cible.m_numero << endl;

            //on calcule phi, l'angle entre le centre des 2 boules lors de la collision

            double deltaX = cible.m_x-m_x;  //distance sur l'axe x entre le centre des 2 boules
            double deltaY = cible.m_y-m_y;  //distance sur l'axe y entre le centre des 2 boules

            double phi;

            //if(deltaX * deltaY < 0)
            //{
            if(deltaX > 0 and deltaY < 0)
            {
                phi = 90 + abs(atan(deltaY / deltaX)) * 180 / PI; //en degres
            }

            else if(deltaX < 0 and deltaY > 0)
            {
                phi = 270 + abs(atan(deltaY / deltaX)) * 180 / PI; //en degres
            }
            //}

            //else if(deltaX * deltaY > 0)
            //{
            else if(deltaX > 0 and deltaY > 0)
            {
                phi = abs(atan(deltaX / deltaY)) * 180 / PI; //en degres
            }

            else if(deltaX < 0 and deltaY < 0)
            {
                phi = 180 + abs(atan(deltaX / deltaY)) * 180 / PI; //en degres
            }
            //}

            //else// if(deltaY * deltaX = 0)
            //{

            //est-ce que les else if qui suivent sont nécessaires??

            else if(deltaY < 0)
            {
                phi = 180;
            }

            else if(deltaY > 0)
            {
                phi = 0;
            }

            else if(deltaX < 0)
            {
                phi = 270;
            }

            else if(deltaX > 0)
            {
                phi = 90;
            }
            //}

            double v1x = cible.vitesse.x() * sin(cible.vitesse.y()*PI/180 - phi*PI/180) * sin(phi*PI/180) + vitesse.x() * cos(vitesse.y()*PI/180 - phi*PI/180) * sin(phi*PI/180 + PI/2);

            double v1y = cible.vitesse.x() * sin(cible.vitesse.y()*PI/180 - phi*PI/180) * cos(phi*PI/180) + vitesse.x() * cos(vitesse.y()*PI/180 - phi*PI/180) * cos(phi*PI/180 + PI/2);

            double v2x = vitesse.x() * sin(vitesse.y()*PI/180 - phi*PI/180) * sin(phi*PI/180) + cible.vitesse.x() * cos(cible.vitesse.y()*PI/180 - phi*PI/180) * sin(phi*PI/180 + PI/2);

            double v2y = vitesse.x() * sin(vitesse.y()*PI/180 - phi*PI/180) * cos(phi*PI/180) + cible.vitesse.x() * cos(cible.vitesse.y()*PI/180 - phi*PI/180) * cos(phi*PI/180 + PI/2);

            vitesse.modifierX(sqrt(v1x*v1x + v1y*v1y));
            cible.vitesse.modifierX(sqrt(v2x*v2x + v2y*v2y));



            if(v1x > 0 and v1y < 0)
            {
                vitesse.modifierY(90 + abs(atan(v1y / v1x)) * 180 / PI); //en degres
            }

            else if(v1x < 0 and v1y > 0)
            {
                vitesse.modifierY(270 + abs(atan(v1y / v1x)) * 180 / PI); //en degres
            }
            //}

            //else if(deltaX * deltaY > 0)
            //{
            else if(v1x > 0 and v1y > 0)
            {
                vitesse.modifierY(abs(atan(v1x / v1y)) * 180 / PI); //en degres
            }

            else if(v1x < 0 and v1y < 0)
            {
                vitesse.modifierY(180 + abs(atan(v1x / v1y)) * 180 / PI); //en degres
            }
            //}

            //else// if(deltaY * deltaX = 0)
            //{

            //est-ce que les else if qui suivent sont nécessaires??

            else if(v1y < 0)
            {
                vitesse.modifierY(180);
            }

            else if(v1y > 0)
            {
                vitesse.modifierY(0);
            }

            else if(v1x < 0)
            {
                vitesse.modifierY(270);
            }

            else if(v1x > 0)
            {
                vitesse.modifierY(90);
            }




            if(v2x > 0 and v2y < 0)
            {
                cible.vitesse.modifierY(90 + abs(atan(v2y / v2x)) * 180 / PI); //en degres
            }

            else if(v2x < 0 and v2y > 0)
            {
                cible.vitesse.modifierY(270 + abs(atan(v2y / v2x)) * 180 / PI); //en degres
            }
            //}

            //else if(deltaX * deltaY > 0)
            //{
            else if(v2x > 0 and deltaY > 0)
            {
                cible.vitesse.modifierY(abs(atan(v2x / v2y)) * 180 / PI); //en degres
            }

            else if(v2x < 0 and v2y < 0)
            {
                cible.vitesse.modifierY(180 + abs(atan(v2x / v2y)) * 180 / PI); //en degres
            }
            //}

            //else// if(deltaY * deltaX = 0)
            //{

            //est-ce que les else if qui suivent sont nécessaires??

            else if(v2y < 0)
            {
                cible.vitesse.modifierY(180);
            }

            else if(v2y > 0)
            {
                cible.vitesse.modifierY(0);
            }

            else if(v2x < 0)
            {
                cible.vitesse.modifierY(270);
            }

            else if(v2x > 0)
            {
                cible.vitesse.modifierY(90);
            }

            if(cible.m_x-m_x < 2*m_r and cible.m_x-m_x > 0)
            {
                m_x = cible.m_x - 2*m_r - 0.00001;
            }

            else if(m_x-cible.m_x < 2*m_r and m_x-cible.m_x>0)
            {
                m_x = cible.m_x + 2*m_r + 0.00001;
            }

            if(cible.m_y-m_y < 2*m_r and cible.m_y-m_y>0)
            {
                m_y = cible.m_y - 2*m_r - 0.00001;
            }

            else if(m_y-cible.m_y< 2*m_r and m_y -cible.m_y>0)
            {
                m_y = cible.m_y + 2*m_r + 0.00001;
            }

            //ces if ne sont pas correctes


/*            if(cible.positionX()-m_x < 0 and cible.positionY()-m_y < 0)
            {
                m_gamma2 = m_gamma2 + 180;
            }
            else if(cible.positionX()-m_x > 0 and cible.positionY()-m_y < 0)
            {
                m_gamma2 = m_gamma2 + 180;
            }
*/
/*            double deltaX = cible.m_x-m_x;  //distance sur l'axe x entre le centre des 2 boules
            double deltaY = cible.m_y-m_y;  //distance sur l'axe y entre le centre des 2 boules

            double gamma2; //angle entre la verticale et la vitesse finale de la deuxième boule


            //on calcule gamma2 (angle de la vitesse de la boule choquée) en fonction de la position d'une boule relativement à l'autre

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

            //si la collision est "parfaite", on met la vitesse de la boule choquante à 0

            if(gamma2 = vitesse.y())
            {
                vitesse.modifierX(0);
            }

            //calcule de l'angle final de la vitesse de la boule choquante en fonction de l'angle de la vitesse de l'autre boule
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


            //replacement de la boule choquante (à revoir)

            if(cible.m_x-m_x < 2*m_r and cible.m_x-m_x > 0)
            {
                m_x = cible.m_x - 2*m_r - 0.00001;
            }

            else if(m_x-cible.m_x < 2*m_r and m_x-cible.m_x>0)
            {
                m_x = cible.m_x + 2*m_r + 0.00001;
            }

            if(cible.m_y-m_y < 2*m_r and cible.m_y-m_y>0)
            {
                m_y = cible.m_y - 2*m_r - 0.00001;
            }

            else if(m_y-cible.m_y< 2*m_r and m_y -cible.m_y>0)
            {
                m_y = cible.m_y + 2*m_r + 0.00001;
            }

            cible.changerVitesse(v2, gamma2);
*/
        }
}

void Boule::collTable()
{
    //si la boule touche la bande on poursuie
    if(m_x+m_r >= LONGUEUR or m_x-m_r <= 0)
    {
        //info test
        cout << "TABLE " << m_numero << " " << m_x << " ; " << m_y << endl;

        //on modifie l'angle de la vitess de la boule
        vitesse.modifierY(360 - vitesse.y());

        //on replace la boule en fonction de la bande qu'elle choque
        if(m_x-m_r < 0)
        {
            m_x = -m_x + 2*m_r;
        }

        else if(m_x+m_r > LONGUEUR)
        {
            m_x = LONGUEUR*2 - m_x - 2*m_r;
        }

    }


        //calcule de la vitesse et acceleration si la bille touche la bande haute ou basse
    if(m_y+m_r >= LARGEUR or m_y-m_r <= 0)
    {
        //info test
        cout << m_x << " ; " << m_y << endl;

        //on modifie l'angle de la vitess de la boule en fonction de son angle
        if(0 <= vitesse.y() <= 180)
        {
            vitesse.modifierY(180 - vitesse.y());
        }

        else if(180 < vitesse.y() <= 360)
        {
            vitesse.modifierY(540 - vitesse.y());
        }

        //on replace la boule en fonction de la bande qu'elle choque
        if(m_y-m_r < 0)
        {
            m_y = -m_y + 2*m_r;
        }

        else if(m_y+m_r > LARGEUR)
        {
            m_y = LARGEUR*2 - m_y - 2*m_r;
        }
    }

    if(vitesse.y() < 0)
    {
        vitesse.modifierY(vitesse.y()+360);
    }
}


void Boule::shoot()
{
    double v, alpha;
    cout << "Vitesse ??" << endl;
    cin >> v;
    cout << "Angle par rapport a la verticale ?? (jusqu'a 359 dans le sens des aiguilles d'une montre)" << endl;
    cin >> alpha;

    vitesse.modifier(v, alpha);
    //cout << vitesse << endl;
}
