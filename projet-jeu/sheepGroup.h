#pragma once
#include <iostream>
#include "Game_Board.h"
#include "Sheep.h"
#include <vector>
#define NB_SHEEP 4
#define WIDTH 8
#define HEIGHT 8
using namespace std;


class SheepGroup
{
    public:
        SheepGroup();
        SheepGroup(bool is_playing,int,int,Game_Board& );
        ~SheepGroup();
        int choose_Move(Game_Board&);
        int choose_Move_CPU(Game_Board&);
        int choose_Move_Player(Game_Board&);
        bool isPlaying();
        void setIsPlaying(bool);
       std::vector <Sheep> get_Moutons();

    private:
         bool is_playing;
         bool player_Type;
         int level_CPU;
         int mode;
         std ::vector <Sheep> moutons;
         bool max_up(int,Game_Board&);
         bool max_down(int,Game_Board&);
         bool max_right(int,Game_Board&);
         bool max_left(int,Game_Board&);
         int count_moves_with_up_Priority(int,Game_Board&);
         int select_move_number(int,int,Game_Board&);


};
