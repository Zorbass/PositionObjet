#include "Boule.hpp"
#include <ctime>
#include <cmath>
#include "Table.hpp"

using namespace std;

Table::Table(): m_xt(0), m_xy(0), m_xt2(11), m_yt2(6)
{

}
Table::Table(int x , int y,  int x2, int y2) : m_xt(x), m_xy(y), m_xt2(x2), m_yt2(y2)
{
}

void Table::collision()
{


    double n = m_t*1000/f; //nombre de rafraichissement a faire
    double i = 0; //nombre de refraichissements effectues
    while(n > i)
    {
        u = clock();
        t = clock();

        //tant que le temps ecoule entre le debut de la boucle et mtn est < que la freq de refraichissement : on fait la boucle
        while(t-u < f)
        {
            t = clock();
        }





        //calcule de la vitesse et acceleration si la bille touche un coin
        if(m_x-m_r <= m_xt )
        {
            m_vx = - m_vx;
            m_ax = - m_ax;
            cout<<"test"

        }

        //calcule de la vitesse et acceleration si la bille touche la bande droit ou gauche
        if(m_x+m_r >= 11)
        {
            m_vx = - m_vx;
            m_ax = - m_ax;
        }


         //calcule de la vitesse et acceleration si la bille touche la bande haute ou basse
        if(m_y-m_r <= 0 )
        {
            m_vy = - m_vy;
            m_ay = - m_ay;
        }
        //calcule de la vitesse et acceleration si la bille touche la bande haute ou basse
         if(m_y+m_r >= 6 )
        {

            m_vy = - m_vy;
            m_ay = - m_ay;
        }

        i++;
    }
    cout << clock() << endl;




}
