#include"Animal.h"
#include <iostream>
using namespace std;

Animal::Animal() {}
Animal::Animal(int x, int y, Game_Board & g_board, int animal_number) {
    this -> pos = Position(x,y);
    g_board.set_Pos(x, y, animal_number);
}
int Animal::move_Right_Down(Game_Board & g_board, int animal_number)
{
    if(g_board.valid_pos(pos.get_x()+1, pos.get_y()+1))
    {
        g_board.set_Pos(pos.get_x(), pos.get_y(), 1);
        pos.set_x(pos.get_x()+1);
        pos.set_y(pos.get_y()+1);
        g_board.set_Pos(pos.get_x(), pos.get_y(), animal_number);
        return ERR_NONE;
    }
    else {
        cout<<"la nouvelle position est invalide"<<endl;
        return ERR;
    }
}

int Animal::move_Left_Down(Game_Board & g_board, int animal_number)
{
    if(g_board.valid_pos(pos.get_x()+1, pos.get_y()-1))
    {
        g_board.set_Pos(pos.get_x(), pos.get_y(), 1);
        pos.set_x(pos.get_x()+1);
        pos.set_y(pos.get_y()-1);
        g_board.set_Pos(pos.get_x(), pos.get_y(), animal_number);
        return ERR_NONE;
    }
    else {
        cout<<"la nouvelle position est invalide"<<endl;
        return ERR;
    }
}

Position Animal::get_Position()
{
    return pos;
}

 Animal::~Animal()
 {
 }
