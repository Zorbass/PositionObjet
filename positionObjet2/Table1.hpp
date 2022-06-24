#ifndef TABLE1_HPP_INCLUDED
#define TABLE1_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Boule.hpp"

class Table1
{

public:
    Table1();
    Table1(int x, int y, int x2, int y2);
    void regle(Boule &boule);
private:
    int m_xt =0;
    int m_yt =0;
    int m_xt2 =6;
    int m_yt2 =11;

};


#endif

