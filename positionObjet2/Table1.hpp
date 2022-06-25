#ifndef TABLE1_HPP_INCLUDED
#define TABLE1_HPP_INCLUDED

#include <iostream>
#include <string>

class Table1
{
public:
    Table1();
    Table1(int x, int y, int x2, int y2);

    void innitialisation();

private:
    int m_x;
    int m_y;
    int m_x2;
    int m_y2;
};

#endif // TABLE1_HPP_INCLUDED
