
#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Boule.hpp"

class Table
{

public:
    Table();
    Table(int x, int y, int x2, int y2);
    Boule *m_boule;
    void regle(Boule &boule);
    void innitialisation();
private:
    int m_xt =0;
    int m_yt =0;
    int m_xt2 =6;
    int m_yt2 =11;

};


#endif

