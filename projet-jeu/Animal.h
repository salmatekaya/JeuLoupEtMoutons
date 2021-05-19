#pragma once
#define Animal_h
#include "Game_Board.h"
#include "Position.h"
using namespace std;

class Animal
{
public:
    Animal();
    Animal(int, int, Game_Board&, int);
    int move_Right_Down(Game_Board&,int);
    int move_Left_Down(Game_Board&,int);
    Position get_Position();
    virtual ~Animal();

protected:
    Position pos;

};
