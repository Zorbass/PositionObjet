
#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Boule.hpp"

class Table
{

public:
    Table();
    Table(std::string nom, int x, int y);
    ~Table();


    void regle();
    void innitialisation();
private:
    int m_xt =0;
    int m_yt =0;
    int m_xt2 =6;
    int m_yt2 =11;
    Boule *m_b1;;

};


#endif

