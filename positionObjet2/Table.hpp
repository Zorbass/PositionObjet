#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED

#include "Boule.hpp"

class Table
{
public:
    Table();
    Table(double x, double y, double x2, double y2);
    Boule *m_boule;


    void regle();
    void innitialisation();

private:
    double m_x;
    double m_y;
    double m_x2;
    double m_y2;
};

#endif // TABLE_HPP_INCLUDED
