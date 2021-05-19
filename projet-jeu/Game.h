#pragma once
#include <iostream>
#include "Wolf.h"
#include "sheepGroup.h"
#include "Sheep.h"
#include "Game_Board.h"
#include "Position.h"
#define WIDTH 8
#define HEIGHT 8

class Game
{
private:
    int difficulte ;
    int mode ;
    Wolf loup ;
    SheepGroup  moutons ;
    Game_Board board;
    bool wolf_out_of_moves();



public :
    Game();
    bool detectWinLoup();
    bool detectWinMoutons();
    bool detectWin();
    int choose_mode();
    int choose_difficulty();
    int updateGame();
    int result();
    int game_paused() ;

};

