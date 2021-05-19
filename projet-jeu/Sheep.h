#pragma once
#include <iostream>
#include "Animal.h"
#include "Game_Board.h"
using namespace std;

class Sheep : public Animal
{
public:
    Sheep(int x, int y,Game_Board & g_board);
    int move_Left(Game_Board&);
    int move_Right(Game_Board&);
    ~Sheep();
};
