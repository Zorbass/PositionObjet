#include <iostream>

#include "Boule.hpp"
#include "Vecteur.hpp"
#include <ctime>
#include <cmath>

using namespace std;

#define LARGEUR 1.27
#define LONGUEUR 2.54

#define PI 3.141592653589793238462643383279

#define TROU_1X 0
#define TROU_1Y 0
#define TROU_2X 1.27 //LONGUEUR/2
#define TROU_2Y 0
#define TROU_3X 2.54
#define TROU_3Y 0
#define TROU_4X 0
#define TROU_4Y 1.27
#define TROU_5X 1.27 //LONGUEUR/2
#define TROU_5Y 1.27
#define TROU_6X 2.54
#define TROU_6Y 1.27

#define R_TROU 0.0435

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

void Boule::empochage()
{
    //changer m_r par le rayon du trou.
    if(sqrt((m_x-TROU_1X) * (m_x-TROU_1X) + (m_y-TROU_1Y)*(m_y-TROU_1Y))<= R_TROU or sqrt((m_x-TROU_2X) * (m_x-TROU_2X) + (m_y-TROU_2Y)*(m_y-TROU_2Y))<= R_TROU or sqrt((m_x-TROU_3X) * (m_x-TROU_3X) + (m_y-TROU_3Y)*(m_y-TROU_3Y))<= R_TROU or sqrt((m_x-TROU_4X) * (m_x-TROU_4X) + (m_y-TROU_4Y)*(m_y-TROU_4Y))<= R_TROU or sqrt((m_x-TROU_5X) * (m_x-TROU_5X) + (m_y-TROU_5Y)*(m_y-TROU_5Y))<= R_TROU or sqrt((m_x-TROU_6X) * (m_x-TROU_6X) + (m_y-TROU_6Y)*(m_y-TROU_6Y))<= R_TROU)
    {
        cout << "la boule " << m_numero << " est empochee." << m_x << ";" << m_y << endl;
        m_x = 20;
        vitesse.modifierX(0);
        m_empochee = true;
    }
}

void Boule::collBoule(Boule& cible)
{
    //si la distance entre les 2 boules est <= à 2 * le rayon d'une boule et que la vitesse de la boule != 0 il y a collision
    if(sqrt((m_x-cible.m_x) * (m_x-cible.m_x) + (m_y-cible.m_y)*(m_y-cible.m_y))<= 2*m_r and vitesse.x() > 0)
        {
            //informations tests
            cout << "BOULES " << m_numero << " : " << m_x << " ; " << m_y << endl;
            cout << "collision " << cible.m_numero << endl;

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

            cout << phi << endl;


            //}

            double v1x = cible.vitesse.x() * cos(-(cible.vitesse.y()-90)*PI/180 + (phi-90)*PI/180) * cos(-(phi-90)*PI/180) + vitesse.x() * sin(-(vitesse.y()-90)*PI/180 + (phi-90)*PI/180) * cos(-(phi-90)*PI/180 + PI/2);

            double v1y = cible.vitesse.x() * cos(-(cible.vitesse.y()-90)*PI/180 + (phi-90)*PI/180) * sin(-(phi-90)*PI/180) + vitesse.x() * sin(-(vitesse.y()-90)*PI/180 + (phi-90)*PI/180) * sin(-(phi-90)*PI/180 + PI/2);

            double v2x = vitesse.x() * cos(-(vitesse.y()-90)*PI/180 + (phi-90)*PI/180) * cos(-(phi-90)*PI/180) + cible.vitesse.x() * sin(-(cible.vitesse.y()-90)*PI/180 + (phi-90)*PI/180) * cos(-(phi-90)*PI/180 + PI/2);

            double v2y = vitesse.x() * cos(-(vitesse.y()-90)*PI/180 + (phi-90)*PI/180) * sin(-(phi-90)*PI/180) + cible.vitesse.x() * sin(-(cible.vitesse.y()-90)*PI/180 + (phi-90)*PI/180) * sin(-(phi-90)*PI/180 + PI/2);

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

            cout << cible.vitesse << " " << vitesse << endl;

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
    if(m_empochee == false)
    {
        double x;

        if(m_y+m_r/sqrt(2)<0.0835 and m_y+m_r/sqrt(2) >= 0.0435 + (m_x-m_r/sqrt(2) - 0))
        {//1
            vitesse.modifierY(90 - vitesse.y());
            cout << "collision bord 1 " << m_x << ";" << m_y << endl;
            x = m_x;
            m_x = 0.04+m_r/sqrt(2) - (0.0835-m_r/sqrt(2)) + m_y;
            m_y = 0.0835-m_r/sqrt(2) - (0.04+m_r/sqrt(2) - x);
            cout << m_x << ";" << m_y << endl;
        }

        else if(m_x+m_r/sqrt(2) < 0.0835 and m_y-m_r/sqrt(2) <= 0.04 - (0.0835 - (m_x+m_r/sqrt(2))))
        {//2
            vitesse.modifierY(90 - vitesse.y());
            cout << "collision bord 2 " << m_x << ";" << m_y << endl;
            x = m_x;
            m_x = 0.0835-m_r/sqrt(2) - (0.04+m_r/sqrt(2)) + m_y;
            m_y = 0.04+m_r/sqrt(2) - (0.0835-m_r/sqrt(2) - x);
            cout << m_x << ";" << m_y << endl;
        }

        else if(m_x-m_r/sqrt(2)<1.2265 and m_x-m_r/sqrt(2) >= 1.1865 and m_y-m_r/sqrt(2) <= 0.04 - (m_x-m_r/sqrt(2) - 1.1865))
        {//3
            vitesse.modifierY(270 - vitesse.y());
            cout << "collision bord 3 " << m_x << ";" << m_y << endl;
            x = m_x;
            m_x = 1.1865+m_r/sqrt(2) + 0.04 + m_r/sqrt(2) - m_y;
            m_y = 0.04+m_r/sqrt(2) - (x - (1.1865+m_r/sqrt(2)));
            cout << m_x << ";" << m_y << endl;
        }

        else if(m_x+m_r/sqrt(2) > 1.3135 and m_x+m_r/sqrt(2) < 1.3535 and m_y-m_r/sqrt(2) <= 0.04 - (1.3535 - (m_x+m_r/sqrt(2))))
        {//4
            vitesse.modifierY(90 - vitesse.y());
            cout << "collision bord 4 " << m_x << ";" << m_y << endl;
            x = m_x;
            m_x = 1.3535-m_r/sqrt(2) - (0.04+m_r/sqrt(2)) + m_y;
            m_y = 0.04+m_r/sqrt(2) - (1.3535-m_r/sqrt(2) - x);
            cout << m_x << ";" << m_y << endl;
        }

        else if(m_x-m_r/sqrt(2)<2.4965 and m_x-m_r/sqrt(2)>2.4565 and m_y-m_r/sqrt(2) <= 0.04 - (m_x-m_r/sqrt(2) - 2.4565))
        {//5
            vitesse.modifierY(270 - vitesse.y());
            cout << "collision bord 5 " << m_x << ";" << m_y << endl;
            x = m_x;
            m_x = 2.4565+m_r/sqrt(2) + 0.04 + m_r/sqrt(2) - m_y;
            m_y = 0.04+m_r/sqrt(2) - (x - (2.4565+m_r/sqrt(2)));
            cout << m_x << ";" << m_y << endl;
        }

        else if(m_y+m_r/sqrt(2)<0.0835 and m_y+m_r/sqrt(2) >= 0.0435 + (2.54 - (m_x+m_r/sqrt(2))))
        {//6
            vitesse.modifierY(270 - vitesse.y());
            cout << "collision bord 6 " << m_x << ";" << m_y << endl;
            x = m_x;
            m_x = 2.5-m_r/sqrt(2) + 0.0835-m_r/sqrt(2) - m_y;
            m_y = 0.0835-m_r/sqrt(2) - (x - (2.5-m_r/sqrt(2)));
            cout << m_x << ";" << m_y << endl;
        }

        else if(m_y-m_r/sqrt(2)>1.27-0.0835 and m_y-m_r/sqrt(2) <= 1.27 - 0.0435 - (m_x-m_r/sqrt(2) - 0))
        {//7
            vitesse.modifierY(270 - vitesse.y());
            cout << "collision bord 7 " << m_x << ";" << m_y << endl;
            x = m_x;
            m_x = 0+m_r/sqrt(2) + 1.2265+m_r/sqrt(2) - m_y;
            m_y = 1.2265+m_r/sqrt(2) - (x - (0+m_r/sqrt(2)));
            cout << m_x << ";" << m_y << endl;
        }

        else if(m_x+m_r/sqrt(2)<0.0835 and m_x+m_r/sqrt(2)>0.0435 and m_y+m_r/sqrt(2) >= 1.27 - 0.04 + (0.0835 - (m_x+m_r/sqrt(2))))
        {//8
            vitesse.modifierY(270 - vitesse.y());
            cout << "collision bord 8 " << m_x << ";" << m_y << endl;
            x = m_x;
            m_x = 0.0435-m_r/sqrt(2) + 1.27-m_r/sqrt(2) - m_y;
            m_y = 1.27-m_r/sqrt(2) - (x - (0.0435-m_r/sqrt(2)));
            cout << m_x << ";" << m_y << endl;
        }
        else if(m_x-m_r/sqrt(2)<1.2265 and m_x-m_r/sqrt(2)>1.1865 and m_y+m_r/sqrt(2) >= 1.27 - 0.04 + (m_x-m_r/sqrt(2) - 1.1865))
        {//9
            vitesse.modifierY(90 - vitesse.y());
            cout << "collision bord 9 " << m_x << ";" << m_y << endl;
            x = m_x;
            m_x = 1.2265+m_r/sqrt(2) - (1.27-m_r/sqrt(2)) + m_y;
            m_y = 1.27-m_r/sqrt(2) - (1.2265+m_r/sqrt(2) - x);
            cout << m_x << ";" << m_y << endl;
        }
        else if(m_x+m_r/sqrt(2)<1.3535 and m_x+m_r/sqrt(2)>1.3135 and m_y+m_r/sqrt(2) >= 1.27 - 0.04 + (1.3535 - (m_x+m_r/sqrt(2))))
        {//10
            vitesse.modifierY(270 - vitesse.y());
            cout << "collision bord 10 " << m_x << ";" << m_y << endl;
            x = m_x;
            m_x = 1.3135-m_r/sqrt(2) + 1.27-m_r/sqrt(2) - m_y;
            m_y = 1.27-m_r/sqrt(2) - (x - (1.3135-m_r/sqrt(2)));
            cout << m_x << ";" << m_y << endl;
        }
        else if(m_x-m_r/sqrt(2)<2.4965 and m_x-m_r/sqrt(2)>2.4565 and m_y+m_r/sqrt(2) >= 1.27 - 0.04 + (m_x-m_r/sqrt(2) - 2.4565))
        {//11
            vitesse.modifierY(90 - vitesse.y());
            cout << "collision bord 11 " << m_x << ";" << m_y << endl;
            x = m_x;
            m_x = 2.4965+m_r/sqrt(2) - (1.27-m_r/sqrt(2)) + m_y;
            m_y = 1.27-m_r/sqrt(2) - (2.4965+m_r/sqrt(2) - x);
            cout << m_x << ";" << m_y << endl;
        }
        else if(m_y-m_r/sqrt(2)>1.1865 and m_y-m_r/sqrt(2) <= 1.27 - 0.0435 - (2.54 - (m_x+m_r/sqrt(2))))
        {//12
            vitesse.modifierY(90 - vitesse.y());
            cout << "collision bord 12 " << m_x << ";" << m_y << endl;
            x = m_x;
            m_x = 2.54-m_r/sqrt(2) - (1.2265+m_r/sqrt(2)) + m_y;
            m_y = 1.2265+m_r/sqrt(2) - (2.54-m_r/sqrt(2) - x);
            cout << m_x << ";" << m_y << endl;
        }

//collision avec les coins
        else if(m_y > 0.0835-m_r/sqrt(2) and m_y < 0.0835 and m_r >= sqrt((m_x-0.04)*(m_x-0.04)+(m_y-0.0835)*(m_y-0.0835)))
        {//1b a revoir
            double x0 = 0.04;
            double y0 = 0.0835;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonométrique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "collision coin 1 " << m_x << ";" << m_y << " " << vitesse.y() << endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            cout << xb1 << ";" << yb1 << " "<< xb2 << ";" << yb2 << endl;
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0+m_r/sqrt(2) and xb1 < x0+m_r and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            cout << xb << ";" << yb << endl;
            vitesse.modifierY(2*(90-asin((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((y0-yb)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = cos(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1) + m_x;
            m_y = -(sin(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1)) + m_y;
            cout << m_x << ";" << m_y << " ; " << vitesse.y() << endl;
        }

        else if(m_x < 0.0835 and m_x > 0.0835-m_r/sqrt(2) and m_r >= sqrt((m_x-0.0835)*(m_x-0.0835)+(m_y-0.04)*(m_y-0.04)))
        {//2b ok
            double x0 = 0.0835;
            double y0 = 0.04;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonométrique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "collision coin 2 " << m_x << ";" << m_y << " " << vitesse.y() << endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            cout << xb1 << ";" << yb1 << " "<< xb2 << ";" << yb2 << endl;
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0+m_r/sqrt(2) and xb1 < x0+m_r and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            cout << xb << ";" << yb << endl;
            vitesse.modifierY(2*(90-asin((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((yb-y0)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = -(cos(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1)) + m_x;
            m_y = sin(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1) + m_y;
            cout << m_x << ";" << m_y << " ; " << vitesse.y() << endl;
        }

        else if(m_x < 1.1865+m_r/sqrt(2) and m_x > 1.1865 and m_r >= sqrt((m_x-1.1865)*(m_x-1.1865)+(m_y-0.04)*(m_y-0.04)))
        {//3b a revoir
            double x0 = 1.1865;
            double y0 = 0.04;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonométrique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "collision coin 3 " << m_x << ";" << m_y << " " << vitesse.y() << endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            cout << xb1 << ";" << yb1 << " "<< xb2 << ";" << yb2 << endl;
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0 and xb1 < x0+m_r/sqrt(2) and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.00001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.00001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            cout << xb << ";" << yb << endl;
            vitesse.modifierY(2*(90-asin((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((yb-y0)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = cos(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1) + m_x;
            m_y = sin(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1) + m_y;
            cout << m_x << ";" << m_y << " ; " << vitesse.y() << endl;
        }

        else if(m_x < 1.3535 and m_x > 1.3535-m_r/sqrt(2) and m_r >= sqrt((m_x-1.3535)*(m_x-1.3535)+(m_y-0.04)*(m_y-0.04)))
        {//4b ok
            double x0 = 1.3535;
            double y0 = 0.04;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonométrique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "collision coin 4 " << m_x << ";" << m_y << " " << vitesse.y() << endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            cout << xb1 << ";" << yb1 << " "<< xb2 << ";" << yb2 << endl;
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0+m_r/sqrt(2) and xb1 < x0+m_r and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            cout << xb << ";" << yb << endl;
            vitesse.modifierY(2*(90-asin((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((yb-y0)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = -(cos(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1)) + m_x;
            m_y = sin(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1) + m_y;
            cout << m_x << ";" << m_y << " ; " << vitesse.y() << endl;
        }

        else if(m_x < 2.4565+m_r/sqrt(2) and m_x > 2.4565 and m_r >= sqrt((m_x-2.4565)*(m_x-2.4565)+(m_y-0.04)*(m_y-0.04)))
        {//5b ok
            double x0 = 2.4565;
            double y0 = 0.04;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonométrique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "collision coin 3 " << m_x << ";" << m_y << " " << vitesse.y() << endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            cout << xb1 << ";" << yb1 << " "<< xb2 << ";" << yb2 << endl;
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0+m_r/sqrt(2) and xb1 < x0+m_r and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            cout << xb << ";" << yb << endl;
            vitesse.modifierY(2*(90-asin((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((yb-y0)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = cos(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1) + m_x;
            m_y = sin(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1) + m_y;
            cout << m_x << ";" << m_y << " ; " << vitesse.y() << endl;
        }

        else if(m_y > 0.0835-m_r/sqrt(2) and m_y < 0.0835 and m_r >= sqrt((m_x-2.5)*(m_x-2.5)+(m_y-0.0835)*(m_y-0.0835)))
        {//6b ok
            double x0 = 2.5;
            double y0 = 0.0835;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonométrique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "collision coin 6 " << m_x << ";" << m_y << " " << vitesse.y() << endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            cout << xb1 << ";" << yb1 << " "<< xb2 << ";" << yb2 << endl;
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 < x0-m_r/sqrt(2) and xb1 > x0-m_r and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            cout << xb << ";" << yb << endl;
            vitesse.modifierY(2*(90-asin((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((y0-yb)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = -(cos(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1)) + m_x;
            m_y = -(sin(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1)) + m_y;
            cout << m_x << ";" << m_y << " ; " << vitesse.y() << endl;
        }

        else if(m_y < 1.1865+m_r/sqrt(2) and m_y > 1.1865 and m_r >= sqrt((m_x-0.04)*(m_x-0.04)+(m_y-1.1865)*(m_y-1.1865)))
        {//7b a revoir
            double x0 = 0.04;
            double y0 = 1.1865;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonométrique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "collision coin 7 " << m_x << ";" << m_y << " " << vitesse.y() << endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            cout << xb1 << ";" << yb1 << " "<< xb2 << ";" << yb2 << endl;
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0+m_r/sqrt(2) and xb1 < x0+m_r and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            cout << xb << ";" << yb << endl;
            vitesse.modifierY(2*(90-asin((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((yb-y0)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = cos(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1) + m_x;
            m_y = sin(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1) + m_y;
            cout << m_x << ";" << m_y << " ; " << vitesse.y() << endl;
        }

        else if(m_x > 0.0835-m_r/sqrt(2) and m_x < 0.0835 and m_r >= sqrt((m_x-0.0835)*(m_x-0.0835)+(m_y-1.23)*(m_y-1.23)))
        {//8b ok
            double x0 = 0.0835;
            double y0 = 1.23;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonométrique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "collision coin 8 " << m_x << ";" << m_y << " " << vitesse.y() << endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            cout << xb1 << ";" << yb1 << " "<< xb2 << ";" << yb2 << endl;
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0-m_r/sqrt(2) and xb1 < x0 and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.00001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.00001 and yb1 < y0+m_r/sqrt(2))
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            cout << xb << ";" << yb << endl;
            vitesse.modifierY(2*(90-asin((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((y0-yb)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = -(cos(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1)) + m_x;
            m_y = -(sin(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1)) + m_y;
            cout << m_x << ";" << m_y << " ; " << vitesse.y() << endl;
        }

        else if(m_x < 1.1865+m_r/sqrt(2) and m_x > 1.1865 and m_r >= sqrt((m_x-1.1865)*(m_x-1.1865)+(m_y-1.23)*(m_y-1.23)))
        {//9b ok
            double x0 = 1.1865;
            double y0 = 1.23;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonométrique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "collision coin 9 " << m_x << ";" << m_y << " " << vitesse.y() << endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            cout << xb1 << ";" << yb1 << " "<< xb2 << ";" << yb2 << endl;
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0+m_r/sqrt(2) and xb1 < x0+m_r and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            cout << xb << ";" << yb << endl;
            vitesse.modifierY(2*(90-asin((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((y0-yb)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = cos(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1) + m_x;
            m_y = -(sin(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1)) + m_y;
            cout << m_x << ";" << m_y << " ; " << vitesse.y() << endl;
        }

        else if(m_x > 1.3535-m_r/sqrt(2) and m_x < 1.3535 and m_r >= sqrt((m_x-1.3535)*(m_x-1.3535)+(m_y-1.23)*(m_y-1.23)))
        {//10b ok
            double x0 = 1.3535;
            double y0 = 1.23;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonométrique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "collision coin 10 " << m_x << ";" << m_y << " " << vitesse.y() << endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            cout << xb1 << ";" << yb1 << " "<< xb2 << ";" << yb2 << endl;
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0+m_r/sqrt(2) and xb1 < x0+m_r and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            cout << xb << ";" << yb << endl;
            vitesse.modifierY(2*(90-asin((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((y0-yb)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = -(cos(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1)) + m_x;
            m_y = -(sin(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1)) + m_y;
            cout << m_x << ";" << m_y << " ; " << vitesse.y() << endl;
        }

        else if(m_x < 2.4565+m_r/sqrt(2) and m_x > 2.4565 and m_r >= sqrt((m_x-2.4565)*(m_x-2.4565)+(m_y-1.23)*(m_y-1.23)))
        {//11b ok
            double x0 = 2.4565;
            double y0 = 1.23;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonométrique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "collision coin 11  " << m_x << ";" << m_y << " " << vitesse.y() << endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            cout << xb1 << ";" << yb1 << " "<< xb2 << ";" << yb2 << endl;
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0+m_r/sqrt(2) and xb1 < x0+m_r and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            cout << xb << ";" << yb << endl;
            vitesse.modifierY(2*(90-asin((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((y0-yb)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = cos(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1) + m_x;
            m_y = -(sin(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1)) + m_y;
            cout << m_x << ";" << m_y << " ; " << vitesse.y() << endl;
        }

        else if(m_y < 1.1865+m_r/sqrt(2) and m_y > 0.0835 and m_r >= sqrt((m_x-2.5)*(m_x-2.5)+(m_y-1.1865)*(m_y-1.1865)))
        {//12b ok
            double x0 = 2.5;
            double y0 = 1.1865;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonométrique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "collision coin 3 " << m_x << ";" << m_y << " " << vitesse.y() << endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            cout << xb1 << ";" << yb1 << " "<< xb2 << ";" << yb2 << endl;
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 < x0-m_r/sqrt(2) and xb1 > x0-m_r and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            cout << xb << ";" << yb << endl;
            vitesse.modifierY(2*(90-asin((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((yb-y0)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = -(cos(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1)) + m_x;
            m_y = sin(alpha*PI/180) * 2*abs(-tan(90*PI/180-asin((yb-y0)/m_r))*x - m_y + yb+tan(90*PI/180-asin((yb-y0)/m_r))*xb2)/sqrt(-tan(90*PI/180-asin((yb-y0)/m_r))*(-tan(90*PI/180-asin((yb-y0)/m_r))) + 1) + m_y;
            cout << m_x << ";" << m_y << " ; " << vitesse.y() << endl;
        }

        //on modifie l'angle de la vitess de la boule
        //on replace la boule en fonction de la bande qu'elle choque
        else if(m_x-m_r <= 0.04 and m_y <= 1.1865 and m_y >= 0.0835)
        {
            m_x = 2*0.04-m_x + 2*m_r;
            vitesse.modifierY(360 - vitesse.y());
            cout << "TABLE 3 BOULE : " << m_numero << " " << m_x << " ; " << m_y << endl;
        }

        else if(m_x+m_r >= LONGUEUR-0.04 and m_y <= 1.1865 and m_y >= 0.0835)
        {
            vitesse.modifierY(360 - vitesse.y());
            m_x = (LONGUEUR-0.04)*2 - m_x - 2*m_r;
            cout << "TABLE 4 BOULE : " << m_numero << " " << m_x << " ; " << m_y << endl;
        }


        //calcule de la vitesse et acceleration si la bille touche la bande haute ou basse

        else if(m_y+m_r >= LARGEUR-0.04 and m_x >= 0.0835 and m_x <= 1.1865)
        {
            cout << "TABLE 5 BOULE : " << m_numero << " " << m_x << " ; " << m_y << endl;
            vitesse.modifierY(180 - vitesse.y());
            m_y = (LARGEUR-0.04)*2 - m_y - 2*m_r;
        }

        else if(m_y+m_r >= LARGEUR-0.04 and m_x >= 1.3535 and m_x <= 2.4565)
        {
            cout << "TABLE 6 BOULE " << m_numero << " " << m_x << " ; " << m_y << endl;
            vitesse.modifierY(180 - vitesse.y());
            m_y = (LARGEUR-0.04)*2 - m_y - 2*m_r;
        }

        else if(m_y-m_r <= 0.04 and m_x >= 0.0835 and m_x <= 1.1865)
        {
            cout << "TABLE 1 BOULE " << m_numero << " " << m_x << " ; " << m_y << endl;
            vitesse.modifierY(180 - vitesse.y());
            m_y = 2*0.04-m_y + 2*m_r;
        }

        else if(m_y-m_r <= 0.04 and m_x >= 1.3535 and m_x <= 2.4565)
        {
            cout << "TABLE 2 BOULE " << m_numero << " " << m_x << " ; " << m_y << endl;
            vitesse.modifierY(180 - vitesse.y());
            m_y = 2*0.04-m_y + 2*m_r;
        }

            //on replace la boule en fonction de la bande qu'elle choque
     /*       if(m_y-m_r < 0)
            {
                m_y = 2*0.04-m_y + 2*m_r;
            }

            else if(m_y+m_r > LARGEUR)
            {
                m_y = (LARGEUR-0.04)*2 - m_y - 2*m_r;
            }
*/

        if(vitesse.y() < 0)
        {
            vitesse.modifierY(vitesse.y()+360);
        }
        else if(vitesse.y() >= 360)
        {
            vitesse.modifierY(vitesse.y()-360);
        }
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
