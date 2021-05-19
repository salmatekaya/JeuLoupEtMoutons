#pragma once
#include <iostream>
#include "Game_Board.h"
#include "Animal.h"
using namespace std;


class Wolf : public Animal
{
    public:
        Wolf();
        Wolf(int,int,bool is_playing,int,int,Game_Board& );
        ~Wolf();
        int choose_Move(Game_Board&);
        int choose_Move_CPU(Game_Board&);
        int choose_Move_Player(Game_Board&);
        int move_Right_Up(Game_Board&);
        int move_Left_Up(Game_Board&);
        int move_Right_Down(Game_Board&);
        int move_Left_Down(Game_Board&);
        bool isPlaying();
        void setIsPlaying(bool);

    private:
         bool is_playing;
         int mode;
         int level_CPU;
         int count_moves_with_up_Priority(int,Game_Board&);
         int select_move_number(int,int,Game_Board&);

};
