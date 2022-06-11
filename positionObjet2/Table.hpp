#ifndef BOULE_HPP_INCLUDED
#define BOULE_HPP_INCLUDED

#include <iostream>
#include <string>

class Table()
{
    public:
    Table();
    Table(int x, int y, int x2, int y2)

    void collision();
    void afficher();

    private:

    double m_elastic = 1;
    int m_xt;
    int m_yt;
    int m_xt2;
    int m_yt2;

};

#endif

