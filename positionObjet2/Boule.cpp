#include <iostream>

#include "Boule.hpp"
#include "Vecteur.hpp"
 #include <climits>

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

#define C1aX 0.0435
#define C1aY 0
#define C1bX 0.0835
#define C1bY 0.04
#define C1cX 1.1865
#define C1cY 0.04
#define C1dX 1.2265
#define C1dY 0

#define C2aX 1.3135
#define C2aY 0
#define C2bX 1.3535
#define C2bY 0.04
#define C2cX 2.4565
#define C2cY 0.04
#define C2dX 2.4965
#define C2dY 0

#define C3aX 0
#define C3aY 0.0435
#define C3bX 0.04
#define C3bY 0.0835
#define C3cX 0.04
#define C3cY 1.1865
#define C3dX 0
#define C3dY 1.2265

#define C4aX 2.54
#define C4aY 0.0435
#define C4bX 2.5
#define C4bY 0.0835
#define C4cX 2.5
#define C4cY 1.1865
#define C4dX 2.54
#define C4dY 1.2265

#define C5aX 0.435
#define C5aY 1.27
#define C5bX 0.0835
#define C5bY 1.23
#define C5cX 1.1865
#define C5cY 1.23
#define C5dX 1.2265
#define C5dY 1.27

#define C6aX 1.3135
#define C6aY 1.27
#define C6bX 1.3535
#define C6bY 1.23
#define C6cX 2.4565
#define C6cY 1.23
#define C6dX 2.4965
#define C6dY 1.27


//constructeur basique
Boule::Boule() : m_numero("0"), m_type("rayee"), m_x(20), m_y(0), vitesse(0, 0), acceleration(0, 0)
{
}

//constructeur personalisable
Boule::Boule(string numero, string type, double x, double y) : m_numero(numero), m_type(type), m_x(x), m_y(y), vitesse(0, 0), acceleration(0, 0)
{
}

//affiche le nom, la vitesse et la position de la bille.
void Boule::afficher()
{
    cout << "Boule : " << m_numero << " " << m_type << " (Position : " << m_x << ";" << m_y << ")" << endl<< endl;

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

bool Boule::boulband()
{
    return boulebande ;
}

bool Boule::empochee()
{
    return m_empochee;
}

bool Boule::bouledejaempochee()
{

    return m_dejaempochee;
}

void Boule::verificationbouledejaempochee()
{
    if(m_dejaempochee==false and m_empochee==true)
    {
        m_dejaempochee=true;
    }
}

bool Boule::boulesempochees()
{
    return m_dejaempochee;
}

bool Boule::collisionBoule()
{
    return collboule;
}

string Boule::typeBoule()
{
    return m_type;
}

double Boule::intensiteeV()
{
    return vitesse.x();
}

double Boule::intensiteeA()
{
    return acceleration.x();
}

double Boule::angle()
{
    return vitesse.y();
}

//je crois que on en a plus besoin
void Boule::changerVitesse(double x, double y)
{
    vitesse.modifier(x, y);
}

void Boule::replacementblanche()
{
    double positionx =0;
    double positiony=0;
    cout<<"Placez la blanche derriere la ligne"<<endl;
    while(positionx<0.0287 or positionx>0.655 or !(cin.good()))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<"Choisissez une position x (doit etre entre 0.0287 et 0.655)"<<endl;
        cin>>positionx;
    }
    m_x=positionx;
    while(positiony<0.0287 or positionx>1.2413 or !(cin.good()))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<"Choisissez une position y (doit etre entre 0.0287 et 1.2413)"<<endl;
        cin>>positiony;
    }
    m_y=positiony;
    m_empochee =false;

}

void Boule::deplacemelent(double f)
{
    if(vitesse.y()<0)
    {
        vitesse.modifierY(vitesse.y() + 360);
    }

    if(vitesse.x()>0)
    {
        m_d = vitesse.x()*f/1000 - acceleration.x()*0.5*f*f/1000000;

        m_x = m_x + sin(vitesse.y()*PI/180) * m_d;
        m_y = m_y + cos(vitesse.y()*PI/180) * m_d;


        vitesse.modifierX(vitesse.x() - acceleration.x()*f/1000);

        if(vitesse.x()<0)
        {
            vitesse.modifierX(0);
            acceleration.modifierX(0);
        }
        if(vitesse.y()<0)
        {
            vitesse.modifierY(vitesse.y() + 360);
        }

    }

    else
    {
        acceleration.modifierX(0);
        vitesse.modifierX(0);
    }

}

void Boule::empochage()
{
    //changer m_r par le rayon du trou.
    if(sqrt((m_x-TROU_1X) * (m_x-TROU_1X) + (m_y-TROU_1Y)*(m_y-TROU_1Y))<= R_TROU or sqrt((m_x-TROU_2X) * (m_x-TROU_2X) + (m_y-TROU_2Y)*(m_y-TROU_2Y))<= R_TROU or sqrt((m_x-TROU_3X) * (m_x-TROU_3X) + (m_y-TROU_3Y)*(m_y-TROU_3Y))<= R_TROU or sqrt((m_x-TROU_4X) * (m_x-TROU_4X) + (m_y-TROU_4Y)*(m_y-TROU_4Y))<= R_TROU or sqrt((m_x-TROU_5X) * (m_x-TROU_5X) + (m_y-TROU_5Y)*(m_y-TROU_5Y))<= R_TROU or sqrt((m_x-TROU_6X) * (m_x-TROU_6X) + (m_y-TROU_6Y)*(m_y-TROU_6Y))<= R_TROU)
    {
        m_x = 20;
        vitesse.modifierX(0);
        cout << "La boule " << m_numero << " est empochee." <<endl<< endl;
        m_empochee = true;
    }
}

void Boule::collBoule(Boule& cible)
{
    //si la distance entre les 2 boules est <= � 2 * le rayon d'une boule et que la vitesse de la boule != 0 il y a collision

    if(sqrt((m_x-cible.m_x) * (m_x-cible.m_x) + (m_y-cible.m_y)*(m_y-cible.m_y))<= 2*m_r and vitesse.x() > 0)
        {
             collboule=true;

            //informations tests
            cout<<"Collision entre la boule "<<m_numero<<" et la boule "<<cible.m_numero<<endl<<endl;

            //on calcule phi, l'angle entre le centre des 2 boules lors de la collision

            double deltaX = cible.m_x-m_x;  //distance sur l'axe x entre le centre des 2 boules
            double deltaY = cible.m_y-m_y;  //distance sur l'axe y entre le centre des 2 boules

            double phi;

            double discriminant;
            double d1;

            double coefficient1;
            double coefficient2;
            coefficient1=1/(1+cible.vitesse.x()/vitesse.x());
            coefficient2= cible.vitesse.x()/vitesse.x()/(1+cible.vitesse.x()/vitesse.x());


            double m_sin= coefficient1*sin(vitesse.y()*PI/180);//sin et cos de l'angle
            double m_cos= coefficient1*cos(vitesse.y()*PI/180);
            double m_sin2= coefficient2*sin(cible.vitesse.y()*PI/180);//sin et cos de l'angle
            double m_cos2= coefficient2*cos(cible.vitesse.y()*PI/180);

            double a= pow(m_sin+m_sin2,2)+pow(m_cos+m_cos2,2);
            double b= 2*(-m_x+cible.m_x)*(m_sin+m_sin2) + 2*(-m_y+cible.m_y)*(m_cos+m_cos2);
            double c= pow(m_x,2)+pow(cible.m_x,2)+pow(m_y,2)+pow(cible.m_y,2)-2*m_x*cible.m_x+-2*m_y*cible.m_y -4*pow(m_r,2);
            discriminant = pow(b,2)-4*a*c;

            d1= (-b+sqrt(discriminant))/(2*a);

            double t =(-vitesse.x()+sqrt(pow(vitesse.x(),2)-2*acceleration.x()*-d1/coefficient1))/acceleration.x();//le temps pour lequel la boule a trop avance.


            vitesse.modifierX(vitesse.x()+t*0.5*acceleration.x());
            if(cible.vitesse.x()!=0)
            {cible.vitesse.modifierX(cible.vitesse.x()+t*0.5*acceleration.x());


            }



            //if(deltaX * deltaY < 0)
            //{
            if(deltaX > 0 and deltaY < 0)
            {
                m_x=m_x-d1*m_sin2;
                cible.m_x=cible.m_x+d1*m_sin2;
                m_y=m_y+d1*m_cos;
                cible.m_y=cible.m_y-d1*m_cos2;
            }

            else if(deltaX < 0 and deltaY > 0)
            {
                m_x=m_x+d1*m_sin;
                cible.m_x=cible.m_x-d1*m_sin2;
                m_y=m_y-d1*m_cos;
                cible.m_y=cible.m_y+d1*m_cos2;
            }
            //}

            //else if(deltaX * deltaY > 0)
            //{
            else if(deltaX > 0 and deltaY > 0)
            {
                m_x=m_x-d1*m_sin;
                cible.m_x=cible.m_x+d1*m_sin2;
                m_y=m_y-d1*m_cos;
                cible.m_y=cible.m_y+d1*m_cos2;
            }

            else if(deltaX < 0 and deltaY < 0)
            {
                m_x=m_x+d1*m_sin;
                cible.m_x=cible.m_x-d1*m_sin2;
                m_y=m_y+d1*m_cos;
                cible.m_y=cible.m_y-d1*m_cos2;
            }
            //}

            //else// if(deltaY * deltaX = 0)
            //{

            //est-ce que les else if qui suivent sont n�cessaires??

            else if(deltaY < 0)
            {
                m_y=m_y+d1*m_cos;
                cible.m_y=cible.m_y-d1*m_cos2;
            }

            else if(deltaY > 0)
            {
                m_y=m_y-d1*m_cos;
                cible.m_y=cible.m_y+d1*m_cos2;
            }

            else if(deltaX < 0)
            {
                m_x=m_x+d1*m_sin;
                cible.m_x=cible.m_x-d1*m_sin2;
            }

            else if(deltaX > 0)
            {
                m_x=m_x-d1*m_sin;
                cible.m_x=cible.m_x+d1*m_sin2;
            }

            /*double dc;
            double t; // temps de rectification
            dc= (px-m_x)/(m_xprime-m_x);
            t=sqrt(dc);//*table.temps();
            */



            deltaX= cible.m_x-m_x;  //distance sur l'axe x entre le centre des 2 boules
            deltaY = cible.m_y-m_y;  //distance sur l'axe y entre le centre des 2 boules

            if(deltaX > 0 and deltaY < 0)
            {
                phi = 90 + abs(atan(deltaY / deltaX)) * 180 / PI; //en degres

            }

            else if(deltaX < 0 and deltaY > 0)
            {
                phi = 270 + abs(atan(deltaY / deltaX)) * 180 / PI; //en degres

            }


            else if(deltaX > 0 and deltaY > 0)
            {
                phi = abs(atan(deltaX / deltaY)) * 180 / PI; //en degres
            }

            else if(deltaX < 0 and deltaY < 0)
            {
                phi = 180 + abs(atan(deltaX / deltaY)) * 180 / PI; //en degres
            }

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

            //faire varier les angles
            //deplacer la boule pendant "t" temps;

            double v1x = vitesse.x() * sin(phi*PI/180 - vitesse.y()*PI/180) * sin((phi-90)*PI/180) + cible.vitesse.x() * cos(cible.vitesse.y()*PI/180 - (phi+180)*PI/180) * sin((phi+180)*PI/180);

            double v1y = vitesse.x() * sin(phi*PI/180 - vitesse.y()*PI/180) * cos((phi-90)*PI/180) + cible.vitesse.x() * cos(cible.vitesse.y()*PI/180 - (phi+180)*PI/180) * cos((phi+180)*PI/180);

            double v2x = vitesse.x() * cos((phi-vitesse.y())*PI/180) * sin(phi*PI/180) + cible.vitesse.x() * sin((cible.vitesse.y()-(phi+180))*PI/180) * sin((phi+270)*PI/180);

            double v2y = vitesse.x() * cos((phi-vitesse.y())*PI/180) * cos(phi*PI/180) + cible.vitesse.x() * sin((cible.vitesse.y()-(phi+180))*PI/180) * cos((phi+270)*PI/180);

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

            else if(v1x > 0 and v1y > 0)
            {
                vitesse.modifierY(abs(atan(v1x / v1y)) * 180 / PI); //en degres
            }

            else if(v1x < 0 and v1y < 0)
            {
                vitesse.modifierY(180 + abs(atan(v1x / v1y)) * 180 / PI); //en degres
            }

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
            else if(v2x > 0 and deltaY > 0)
            {
                cible.vitesse.modifierY(abs(atan(v2x / v2y)) * 180 / PI); //en degres
            }

            else if(v2x < 0 and v2y < 0)
            {
                cible.vitesse.modifierY(180 + abs(atan(v2x / v2y)) * 180 / PI); //en degres
            }

            else if(v2x < 0)
            {
                cible.vitesse.modifierY(270);
            }

            else if(v2x > 0)
            {

                cible.vitesse.modifierY(90);
            }
            else if(v2y < 0)
            {
                cible.vitesse.modifierY(180);
            }

            else if(v2y > 0)
            {
                cible.vitesse.modifierY(0);
            }

            cible.acceleration.modifierX(2.943);
            this->deplacemelent(t);//deplace les boules
            cible.deplacemelent(t);

        }
}

void Boule::collTable()
{
    if(m_empochee == false)
    {
        double vy=vitesse.y();
        boulebande=false;

        double x;

        if(m_y+m_r/sqrt(2)<C3bY and m_y+m_r/sqrt(2) >= C3aY + (m_x-m_r/sqrt(2) - C3aX)) //v�rification de la collision boule-bord
        {//1
            vitesse.modifierY(90 - vitesse.y()); //sens de la vitesse finale de la boule
            cout << "Collision entre la boule " << m_numero << " et la petite bande en bas tout a gauche" << endl<<endl;
            x = m_x;
            m_x = C3bX+m_r/sqrt(2) - (C3bY-m_r/sqrt(2)) + m_y; //replacement en x de la boule pour restituer l'�nergie perdue lors de l'overshoot
            m_y = C3bY-m_r/sqrt(2) - (C3bX+m_r/sqrt(2) - x); //replacement en y de la boule pour restituer l'�nergie perdue lors de l'overshoot
        }

        else if(m_x+m_r/sqrt(2) < C1bX and m_y-m_r/sqrt(2) <= C1bY - (C1bX - (m_x+m_r/sqrt(2))))
        {//2
            vitesse.modifierY(90 - vitesse.y());
            cout << "Collision entre la boule " << m_numero << " et la petite bande en bas a gauche " << endl<<endl;
            x = m_x;
            m_x = C1bX-m_r/sqrt(2) - (C1bY+m_r/sqrt(2)) + m_y; //replacement en x de la boule pour restituer l'�nergie perdue lors de l'overshoot
            m_y = C1bY+m_r/sqrt(2) - (C1bX-m_r/sqrt(2) - x);
        }

        else if(m_x-m_r/sqrt(2)<C1dX and m_x-m_r/sqrt(2) >= C1cX and m_y-m_r/sqrt(2) <= C1cY - (m_x-m_r/sqrt(2) - C1cX))
        {//3
            vitesse.modifierY(270 - vitesse.y());
            cout << "Collision entre la boule " << m_numero << " et la petite bande en bas au milieu gauche "<<endl<<endl;
            x = m_x;
            m_x = C1cX+m_r/sqrt(2) + C1cY + m_r/sqrt(2) - m_y; //replacement en x de la boule pour restituer l'�nergie perdue lors de l'overshoot
            m_y = C1cY+m_r/sqrt(2) - (x - (C1cX+m_r/sqrt(2)));
        }

        else if(m_x+m_r/sqrt(2) > C2aX and m_x+m_r/sqrt(2) < C2bX and m_y-m_r/sqrt(2) <= C2bY - (C2bX - (m_x+m_r/sqrt(2))))
        {//4
            vitesse.modifierY(90 - vitesse.y());
            cout << "Collision entre la boule " << m_numero << " et la petite bande en bas au milieu droite"<< endl<<endl;
            x = m_x;
            m_x = C2bX-m_r/sqrt(2) - (C2bY+m_r/sqrt(2)) + m_y; //replacement en x de la boule pour restituer l'�nergie perdue lors de l'overshoot
            m_y = C2bY+m_r/sqrt(2) - (C2bX-m_r/sqrt(2) - x);
        }

        else if(m_x-m_r/sqrt(2)<C2dX and m_x-m_r/sqrt(2)>C2cX and m_y-m_r/sqrt(2) <= C2cY - (m_x-m_r/sqrt(2) - C2cX))
        {//5
            vitesse.modifierY(270 - vitesse.y());
            cout << "Collision entre la boule " << m_numero << " et la petite bande en bas a droite "<< endl<<endl;
            x = m_x;
            m_x = C2cX+m_r/sqrt(2) + C2cY + m_r/sqrt(2) - m_y; //replacement en x de la boule pour restituer l'�nergie perdue lors de l'overshoot
            m_y = C2cY+m_r/sqrt(2) - (x - (C2cX+m_r/sqrt(2)));
        }

        else if(m_y+m_r/sqrt(2)<C4bY and m_y+m_r/sqrt(2) >= R_TROU + (C4aX - (m_x+m_r/sqrt(2))))
        {//6
            vitesse.modifierY(270 - vitesse.y());
            cout << "Collision entre la boule " << m_numero << "et la petite bande en bas tout a droite "<< endl<<endl;
            x = m_x;
            m_x = C4bX-m_r/sqrt(2) + C4bY-m_r/sqrt(2) - m_y; //replacement en x de la boule pour restituer l'�nergie perdue lors de l'overshoot
            m_y = C4bY-m_r/sqrt(2) - (x - (C4bX-m_r/sqrt(2)));
        }

        else if(m_y-m_r/sqrt(2)>C3cY and m_y-m_r/sqrt(2) <= C3dY - (m_x-m_r/sqrt(2) - C3dX))
        {//7
            vitesse.modifierY(270 - vitesse.y());
            cout << "Collision entre la boule " << m_numero << " et la petite bande en haut tout a gauche"<< endl<<endl; //replacement en x de la boule pour restituer l'�nergie perdue lors de l'overshoot
            x = m_x;
            m_x = C3dX+m_r/sqrt(2) + C3dY+m_r/sqrt(2) - m_y;
            m_y = C3dY+m_r/sqrt(2) - (x - (C3dX+m_r/sqrt(2)));
        }

        else if(m_x+m_r/sqrt(2)<C5bX and m_x+m_r/sqrt(2)>C5aX and m_y+m_r/sqrt(2) >= C5bY + (C5bX - (m_x+m_r/sqrt(2))))
        {//8
            vitesse.modifierY(270 - vitesse.y());
            cout << "Collision entre la boule " << m_numero << " et la petite bande en haut a gauche "<< endl<<endl;
            x = m_x;
            m_x = C5aX-m_r/sqrt(2) + C5aY-m_r/sqrt(2) - m_y; //replacement en x de la boule pour restituer l'�nergie perdue lors de l'overshoot
            m_y = C5aY-m_r/sqrt(2) - (x - (C5aX-m_r/sqrt(2)));
        }
        else if(m_x-m_r/sqrt(2)<C5dX and m_x-m_r/sqrt(2)>C5cX and m_y+m_r/sqrt(2) >= C5cY + (m_x-m_r/sqrt(2) - C5cX))
        {//9
            vitesse.modifierY(90 - vitesse.y());
            cout << "Collision entre la boule " << m_numero << " et la petite bande en haut au milieu gauche "<< endl<<endl;
            x = m_x;
            m_x = C5dX+m_r/sqrt(2) - (C5dY-m_r/sqrt(2)) + m_y; //replacement en x de la boule pour restituer l'�nergie perdue lors de l'overshoot
            m_y = C5dY-m_r/sqrt(2) - (C5dX+m_r/sqrt(2) - x);
        }
        else if(m_x+m_r/sqrt(2)<C6bX and m_x+m_r/sqrt(2)>C6aX and m_y+m_r/sqrt(2) >= C6bY + (C6bX - (m_x+m_r/sqrt(2))))
        {//10
            vitesse.modifierY(270 - vitesse.y());
            cout << "Collision entre la boule " << m_numero << " et la petite bande en bas au milieu droite "<< endl<<endl;
            x = m_x;
            m_x = C6aX-m_r/sqrt(2) + C6aY-m_r/sqrt(2) - m_y; //replacement en x de la boule pour restituer l'�nergie perdue lors de l'overshoot
            m_y = C6aY-m_r/sqrt(2) - (x - (C6aX-m_r/sqrt(2)));
        }
        else if(m_x-m_r/sqrt(2)<C6dX and m_x-m_r/sqrt(2)>C6cX and m_y+m_r/sqrt(2) >= C6cY + (m_x-m_r/sqrt(2) - C6cX))
        {//11
            vitesse.modifierY(90 - vitesse.y());
            cout << "Collision entre la boule " << m_numero << " et la petite bande en haut a droite "<< endl<<endl;
            x = m_x;
            m_x = C6dX+m_r/sqrt(2) - (C6dY-m_r/sqrt(2)) + m_y; //replacement en x de la boule pour restituer l'�nergie perdue lors de l'overshoot
            m_y = C6dY-m_r/sqrt(2) - (C6dX+m_r/sqrt(2) - x);
        }
        else if(m_y-m_r/sqrt(2)>C4cY and m_y-m_r/sqrt(2) <= C4dY - (C4dX - (m_x+m_r/sqrt(2))))
        {//12
            vitesse.modifierY(90 - vitesse.y());
            cout << "Collision entre la boule " << m_numero << "et la petite bande en haut tout a droite "<< endl<<endl;
            x = m_x;
            m_x = C4dX-m_r/sqrt(2) - (C4dY+m_r/sqrt(2)) + m_y; //replacement en x de la boule pour restituer l'�nergie perdue lors de l'overshoot
            m_y = C4dY+m_r/sqrt(2) - (C4dX-m_r/sqrt(2) - x);
        }

//collision avec les coins
        else if(m_y > C3bY-m_r/sqrt(2) and m_y < C3bY and m_r >= sqrt((m_x-C3bX)*(m_x-C3bX)+(m_y-C3bY)*(m_y-C3bY))) //v�rification de la collision avec le coin
        {//1b a revoir
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonom�trique en radian
            double a = tan(gamma)*tan(gamma) + 1; //coef de x^2 dans l'�quation quadratique
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-C3bY)-2*C3bX; //coef de x dans l'�quation quadratique
            double c = (m_y-(tan(gamma)*m_x)-C3bY)*(m_y-(tan(gamma)*m_x)-C3bY) - m_r*m_r + C3bX*C3bX;
            cout << "Collision entre la boule " << m_numero << " et le coin en bas tout a gauche "<< endl<<endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a); // premi�re coordon�e x du point de s�cance entre la trajectoire de la boule et le cercle de rayon m_x et de centre C3bX;C3bY
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a); // seconde coordon�e x du point de s�cance entre la trajectoire de la boule et le cercle de rayon m_x et de centre C3bX;C3bY
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x); // premi�re coordon�e y du point de s�cance entre la trajectoire de la boule et le cercle de rayon m_x et de centre C3bX;C3bY
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x); // seconde coordon�e y du point de s�cance entre la trajectoire de la boule et le cercle de rayon m_x et de centre C3bX;C3bY
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > C3bX+m_r/sqrt(2) and xb1 < C3bX+m_r and m_r <= sqrt((xb1-C3bX)*(xb1-C3bX)+(yb1-C3bY)*(yb1-C3bY))+0.000001 and m_r >= sqrt((xb1-C3bX)*(xb1-C3bX)+(yb1-C3bY)*(yb1-C3bY))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            vitesse.modifierY(-2*(acos((C3bY-yb)/m_r)*180/PI)+180-vitesse.y()); //sens de la vitesse finale de la boule
            double alpha = asin((C3bY-yb)/m_r)*180/PI; //angle form� par la droite s�ante au centre de la boule ainsi que le coins et l'horizontale
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl<<endl;
            double x = m_x;
            m_x = cos(alpha*PI/180) * 2*abs((xb-C3bX)/(C3bY-yb)*x - m_y + yb-(xb-C3bX)/(C3bY-yb)*xb)/sqrt(((xb-C3bX)/(C3bY-yb))*((xb-C3bX)/(C3bY-yb)) + 1) + m_x; //position x de la boule apr�s avoir restitu� l'�nergie perdu lors de l'overshoot
            m_y = -(sin(alpha*PI/180)) * 2*abs((xb-C3bX)/(C3bY-yb)*x - m_y + yb-(xb-C3bX)/(C3bY-yb)*xb)/sqrt(((xb-C3bX)/(C3bY-yb))*((xb-C3bX)/(C3bY-yb)) + 1) + m_y; //position y de la boule apr�s avoir restitu� l'�nergie perdu lors de l'overshoot
        }

        else if(m_x < 0.0835 and m_x > 0.0835-m_r/sqrt(2) and m_r >= sqrt((m_x-0.0835)*(m_x-0.0835)+(m_y-0.04)*(m_y-0.04)))
        {//2b ok
            double x0 = 0.0835;
            double y0 = 0.04;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonom�trique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "Collision entre la boule " << m_numero << " et le coin en bas a gauche"<< endl<<endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0-m_r/sqrt(2) and xb1 < x0 and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            vitesse.modifierY(-2*(acos((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((yb-y0)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl<<endl;
            double x = m_x;
            m_x = -(cos(alpha*PI/180)) * 2*abs((x0-xb)/(yb-y0)*x - m_y + yb-(x0-xb)/(yb-y0)*xb)/sqrt(((x0-xb)/(yb-y0))*((x0-xb)/(yb-y0)) + 1) + m_x;
            m_y = sin(alpha*PI/180) * 2*abs((x0-xb)/(yb-y0)*x - m_y + yb-(x0-xb)/(yb-y0)*xb)/sqrt(((x0-xb)/(yb-y0))*((x0-xb)/(yb-y0)) + 1) + m_y;
        }

        else if(m_x < 1.1865+m_r/sqrt(2) and m_x > 1.1865 and m_r >= sqrt((m_x-1.1865)*(m_x-1.1865)+(m_y-0.04)*(m_y-0.04)))
        {//3b a revoir
            double x0 = 1.1865;
            double y0 = 0.04;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonom�trique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "Collision entre la boule " << m_numero << " et le coin en bas au milieu gauche" << endl<<endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0 and xb1 < x0+m_r/sqrt(2) and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.00001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.00001 and yb1 > y0+m_r/sqrt(2))
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            vitesse.modifierY(2*(acos((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((yb-y0)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = cos(alpha*PI/180) * 2*abs((x0-xb)/(yb-y0)*x - m_y + yb-(x0-xb)/(yb-y0)*xb)/sqrt(((x0-xb)/(yb-y0))*((x0-xb)/(yb-y0)) + 1) + m_x;
            m_y = sin(alpha*PI/180) * 2*abs((x0-xb)/(yb-y0)*x - m_y + yb-(x0-xb)/(yb-y0)*xb)/sqrt(((x0-xb)/(yb-y0))*((x0-xb)/(yb-y0)) + 1) + m_y;
        }

        else if(m_x < 1.3535 and m_x > 1.3535-m_r/sqrt(2) and m_r >= sqrt((m_x-1.3535)*(m_x-1.3535)+(m_y-0.04)*(m_y-0.04)))
        {//4b ok
            double x0 = 1.3535;
            double y0 = 0.04;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonom�trique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "Collision entre la boule " << m_numero << " et le coin en bas au milieu droite" << endl<<endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0-m_r/sqrt(2) and xb1 < x0 and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            vitesse.modifierY(-2*(acos((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((yb-y0)/m_r)*180/PI;
            double x = m_x;
            m_x = -(cos(alpha*PI/180)) * 2*abs((x0-xb)/(yb-y0)*x - m_y + yb-(x0-xb)/(yb-y0)*xb)/sqrt(((x0-xb)/(yb-y0))*((x0-xb)/(yb-y0)) + 1) + m_x;
            m_y = sin(alpha*PI/180) * 2*abs((x0-xb)/(yb-y0)*x - m_y + yb-(x0-xb)/(yb-y0)*xb)/sqrt(((x0-xb)/(yb-y0))*((x0-xb)/(yb-y0)) + 1) + m_y;
        }

        else if(m_x < 2.4565+m_r/sqrt(2) and m_x > 2.4565 and m_r >= sqrt((m_x-2.4565)*(m_x-2.4565)+(m_y-0.04)*(m_y-0.04)))
        {//5b ok
            double x0 = 2.4565;
            double y0 = 0.04;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonom�trique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "Collision entre la boule " << m_numero << " et le coin en bas a droite" << endl<<endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 < x0+m_r/sqrt(2) and xb1 > x0 and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            vitesse.modifierY(2*(acos((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((yb-y0)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = cos(alpha*PI/180) * 2*abs((x0-xb)/(yb-y0)*x - m_y + yb-(x0-xb)/(yb-y0)*xb)/sqrt(((x0-xb)/(yb-y0))*((x0-xb)/(yb-y0)) + 1) + m_x;
            m_y = sin(alpha*PI/180) * 2*abs((x0-xb)/(yb-y0)*x - m_y + yb-(x0-xb)/(yb-y0)*xb)/sqrt(((x0-xb)/(yb-y0))*((x0-xb)/(yb-y0)) + 1) + m_y;
        }

        else if(m_y > 0.0835-m_r/sqrt(2) and m_y < 0.0835 and m_r >= sqrt((m_x-2.5)*(m_x-2.5)+(m_y-0.0835)*(m_y-0.0835)))
        {//6b ok
            double x0 = 2.5;
            double y0 = 0.0835;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonom�trique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "Collision entre la boule " << m_numero << " et le coin en bas tout a droite" << endl<<endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
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
            };
            vitesse.modifierY(2*(acos((y0-yb)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((y0-yb)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = -(cos(alpha*PI/180)) * 2*abs((xb-x0)/(y0-yb)*x - m_y + yb-(xb-x0)/(y0-yb)*xb)/sqrt(((xb-x0)/(y0-yb))*((xb-x0)/(y0-yb)) + 1) + m_x;
            m_y = -(sin(alpha*PI/180)) * 2*abs((xb-x0)/(y0-yb)*x - m_y + yb-(xb-x0)/(y0-yb)*xb)/sqrt(((xb-x0)/(y0-yb))*((xb-x0)/(y0-yb)) + 1) + m_y;
        }

        else if(m_y < 1.1865+m_r/sqrt(2) and m_y > 1.1865 and m_r >= sqrt((m_x-0.04)*(m_x-0.04)+(m_y-1.1865)*(m_y-1.1865)))
        {//7b a revoir
            double x0 = 0.04;
            double y0 = 1.1865;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonom�trique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "Collision entre la boule " << m_numero << " et le coin en haut tout a gauche" << endl<<endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
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
            vitesse.modifierY(2*(acos((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((yb-y0)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = cos(alpha*PI/180) * 2*abs((x0-xb)/(yb-y0)*x - m_y + yb-(x0-xb)/(yb-y0)*xb)/sqrt(((x0-xb)/(yb-y0))*((x0-xb)/(yb-y0)) + 1) + m_x;
            m_y = sin(alpha*PI/180) * 2*abs((x0-xb)/(yb-y0)*x - m_y + yb-(x0-xb)/(yb-y0)*xb)/sqrt(((x0-xb)/(yb-y0))*((x0-xb)/(yb-y0)) + 1) + m_y;
        }

        else if(m_x > 0.0835-m_r/sqrt(2) and m_x < 0.0835 and m_r >= sqrt((m_x-0.0835)*(m_x-0.0835)+(m_y-1.23)*(m_y-1.23)))
        {//8b ok
            double x0 = 0.0835;
            double y0 = 1.23;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonom�trique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "Collision entre la boule " << m_numero << " et le coin en haut a gauche" << endl<<endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
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
            vitesse.modifierY(2*(acos((y0-yb)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((y0-yb)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = -(cos(alpha*PI/180)) * 2*abs((xb-x0)/(y0-yb)*x - m_y + yb-(xb-x0)/(y0-yb)*xb)/sqrt(((xb-x0)/(y0-yb))*((xb-x0)/(y0-yb)) + 1) + m_x;
            m_y = -(sin(alpha*PI/180)) * 2*abs((xb-x0)/(y0-yb)*x - m_y + yb-(xb-x0)/(y0-yb)*xb)/sqrt(((xb-x0)/(y0-yb))*((xb-x0)/(y0-yb)) + 1) + m_y;
        }

        else if(m_x < 1.1865+m_r/sqrt(2) and m_x > 1.1865 and m_r >= sqrt((m_x-1.1865)*(m_x-1.1865)+(m_y-1.23)*(m_y-1.23)))
        {//9b ok
            double x0 = 1.1865;
            double y0 = 1.23;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonom�trique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "Collision entre la boule " << m_numero << " et le coin en haut au milieu gauche"<< endl<<endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0 and xb1 < x0+m_r/sqrt(2) and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001 and yb1 < y0-m_r/sqrt(2))
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            vitesse.modifierY(-2*(acos((y0-yb)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((y0-yb)/m_r);
            double x = m_x;
            m_x = cos(alpha) * 2*abs((xb-x0)/(y0-yb)*x - m_y + yb-(xb-x0)/(y0-yb)*xb)/sqrt(((xb-x0)/(y0-yb))*((xb-x0)/(y0-yb)) + 1) + m_x;
            m_y = -(sin(alpha)) * 2*abs((xb-x0)/(y0-yb)*x - m_y + yb-(xb-x0)/(y0-yb)*xb)/sqrt(((xb-x0)/(y0-yb))*((xb-x0)/(y0-yb)) + 1) + m_y;
        }


        else if(m_x > 1.3535-m_r/sqrt(2) and m_x < 1.3535 and m_r >= sqrt((m_x-1.3535)*(m_x-1.3535)+(m_y-1.23)*(m_y-1.23)))
        {//10b ok
            double x0 = 1.3535;
            double y0 = 1.23;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonom�trique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "Collision entre la boule " << m_numero << "et le coin en haut au milieu droite" << endl<<endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0-m_r/sqrt(2) and xb1 < x0 and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            vitesse.modifierY(2*(acos((y0-yb)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((y0-yb)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = -(cos(alpha*PI/180)) * 2*abs((xb-x0)/(y0-yb)*x - m_y + yb-(xb-x0)/(y0-yb)*xb)/sqrt(((xb-x0)/(y0-yb))*((xb-x0)/(y0-yb)) + 1) + m_x;
            m_y = -(sin(alpha*PI/180)) * 2*abs((xb-x0)/(y0-yb)*x - m_y + yb-(xb-x0)/(y0-yb)*xb)/sqrt(((xb-x0)/(y0-yb))*((xb-x0)/(y0-yb)) + 1) + m_y;
        }

        else if(m_x < 2.4565+m_r/sqrt(2) and m_x > 2.4565 and m_r >= sqrt((m_x-2.4565)*(m_x-2.4565)+(m_y-1.23)*(m_y-1.23)))
        {//11b ok
            double x0 = 2.4565;
            double y0 = 1.23;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonom�trique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "Collision entre la boule " << m_numero << " et le coin en haut a droite "<< endl<<endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
            double yb=0, xb=0; //position parfaite de la boule lors de la collision
            if(xb1 > x0 and xb1 < x0+m_r/sqrt(2) and m_r <= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))+0.000001 and m_r >= sqrt((xb1-x0)*(xb1-x0)+(yb1-y0)*(yb1-y0))-0.000001)
            {
                xb = xb1;
                yb = yb1;
            }
            else
            {
                xb = xb2;
                yb = yb2;
            }
            vitesse.modifierY(-2*(acos((y0-yb)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((y0-yb)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = cos(alpha*PI/180) * 2*abs((xb-x0)/(y0-yb)*x - m_y + yb-(xb-x0)/(y0-yb)*xb)/sqrt(((xb-x0)/(y0-yb))*((xb-x0)/(y0-yb)) + 1) + m_x;
            m_y = -(sin(alpha*PI/180)) * 2*abs((xb-x0)/(y0-yb)*x - m_y + yb-(xb-x0)/(y0-yb)*xb)/sqrt(((xb-x0)/(y0-yb))*((xb-x0)/(y0-yb)) + 1) + m_y;
        }

        else if(m_y < 1.1865+m_r/sqrt(2) and m_y > 1.1865 and m_r >= sqrt((m_x-2.5)*(m_x-2.5)+(m_y-1.1865)*(m_y-1.1865)))
        {//12b ok
            double x0 = 2.5;
            double y0 = 1.1865;
            double gamma = -(vitesse.y()-90)*PI/180; //sens de la vitesse par rapport au cercle trigonom�trique
            double a = tan(gamma)*tan(gamma) + 1; //coef de x*x
            double b = 2*tan(gamma)*(m_y-(tan(gamma)*m_x)-y0)-2*x0; //coef de x
            double c = (m_y-(tan(gamma)*m_x)-y0)*(m_y-(tan(gamma)*m_x)-y0) - m_r*m_r + x0*x0;
            cout << "Collision entre la boule " << m_numero << " et le coin en haut tout a droite" << endl<<endl;
            double xb1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            double xb2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            double yb1 = tan(gamma)*xb1 + m_y -(tan(gamma)*m_x);
            double yb2 = tan(gamma)*xb2 + m_y -(tan(gamma)*m_x);
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
            vitesse.modifierY(-2*(acos((yb-y0)/m_r)*180/PI)+180-vitesse.y());
            double alpha = asin((yb-y0)/m_r)*180/PI;
            //cout << asin((yb-y0)/m_r)*180/PI << " " << acos((xb-x0)/m_r)*180/PI << endl;
            double x = m_x;
            m_x = -(cos(alpha*PI/180)) * 2*abs((x0-xb)/(yb-y0)*x - m_y + yb-(x0-xb)/(yb-y0)*xb)/sqrt(((x0-xb)/(yb-y0))*((x0-xb)/(yb-y0)) + 1) + m_x;
            m_y = sin(alpha*PI/180) * 2*abs((x0-xb)/(yb-y0)*x - m_y + yb-(x0-xb)/(yb-y0)*xb)/sqrt(((x0-xb)/(yb-y0))*((x0-xb)/(yb-y0)) + 1) + m_y;
        }



        //on modifie l'angle de la vitess de la boule
        //on replace la boule en fonction de la bande qu'elle choque
        else if(m_y-m_r <= 0.04 and m_x >= 0.0835 and m_x <= 1.1865)
        {
            cout << "Collision entre la boule " << m_numero << " et la bande en bas a gauche " << endl<<endl;
            vitesse.modifierY(180 - vitesse.y());
            m_y = 2*0.04-m_y + 2*m_r;
        }

        else if(m_y-m_r <= 0.04 and m_x >= 1.3535 and m_x <= 2.4565)
        {
            cout << "Collision entre la boule " << m_numero << " et la bande en bas a droite " << endl<<endl;
            vitesse.modifierY(180 - vitesse.y());
            m_y = 2*0.04-m_y + 2*m_r;
        }
        else if(m_x-m_r <= 0.04 and m_y <= 1.1865 and m_y >= 0.0835)
        {
            m_x = 2*0.04-m_x + 2*m_r;
            vitesse.modifierY(360 - vitesse.y());
            cout << "Collision entre la boule " << m_numero << " et la bande verticale droite " << endl<<endl;
        }

        else if(m_x+m_r >= 2.5 and m_y <= 1.1865 and m_y >= 0.0835)
        {
            vitesse.modifierY(360 - vitesse.y());
            m_x = (LONGUEUR-0.04)*2 - m_x - 2*m_r;
            cout << "Collision entre la boule " << m_numero << " et la bande verticale gauche " <<endl<<endl;
        }


        //calcule de la vitesse et acceleration si la bille touche la bande haute ou basse

        else if(m_y+m_r >= LARGEUR-0.04 and m_x >= 0.0835 and m_x <= 1.1865)
        {
            cout << "Collision entre la boule " << m_numero << " et la bande en haut a gauche " <<endl<<endl;
            vitesse.modifierY(180 - vitesse.y());
            m_y = (LARGEUR-0.04)*2 - m_y - 2*m_r;
        }

        else if(m_y+m_r >= LARGEUR-0.04 and m_x >= 1.3535 and m_x <= 2.4565)
        {
            cout << "Collision entre la boule " << m_numero << " et la bande en haut a droite " <<endl<<endl;
            vitesse.modifierY(180 - vitesse.y());
            m_y = (LARGEUR-0.04)*2 - m_y - 2*m_r;
        }
        if(vitesse.y() < 0)
        {
            vitesse.modifierY(vitesse.y()+360);
        }
        else if(vitesse.y() >= 360)
        {
            vitesse.modifierY(vitesse.y()-360);
        }

        if(vy!=vitesse.y())
        {
            boulebande=true;
        }
    }
}

void Boule::shoot()
{
    double v(1000), alpha(1000);

    while(v<=0 or v>20 or !(cin.good()))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Vitesse ?? (de 0 a 20m/s)" << endl;
        cin >> v;
    }
    while(alpha<=0 or alpha>360 or !(cin.good()))
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Angle par rapport a la verticale ?? (de 0 (non compris) a 360 (compris) degres dans le sens des aiguilles d'une montre, le 0 etant en haut; rose des vents)" << endl;
        cin >> alpha;
    }

    vitesse.modifier(v, alpha);
    acceleration.modifierX(2.943);
    //cout << vitesse << endl;
}
