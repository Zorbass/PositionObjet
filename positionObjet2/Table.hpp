#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED

class Table
{
public:
    Table();
    Table(int x, int y, int x2, int y2);
    Boule *m_boule;


    void regle();
    void innitialisation();

private:
    int m_x;
    int m_y;
    int m_x2;
    int m_y2;
};

#endif // TABLE_HPP_INCLUDED
