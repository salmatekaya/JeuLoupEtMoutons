#include "Sheep.h"
#include "Game_Board.h"
#include "Animal.h"

Sheep::Sheep(int x, int y, Game_Board & g_board) : Animal(x,y,g_board,3) {}

int Sheep::move_Left(Game_Board & g_board)
    {
        return Animal::move_Left_Down(g_board,3) ;
    }
int Sheep::move_Right(Game_Board & g_board)
    {
        return Animal::move_Right_Down(g_board,3);
    }
Sheep::~Sheep()
{}
