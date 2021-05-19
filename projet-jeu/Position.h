#pragma once
class Position
{
private :
    int x;
    int y;
public:
    Position();
    Position(int,int);
    int get_x();
    void set_x(int);
    int get_y();
    void set_y(int);
};

