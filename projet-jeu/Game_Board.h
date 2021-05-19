#pragma once
#include <vector>
//-----------------
#define PAUSE 2
#define ERR_NONE 1
#define ERR 0
//-----------------
#define PLAY_WITH_SHEEP 2
#define PLAY_WITH_WOLF 1
#define PLAY_WITH_BOTH 0

class Game_Board
{
private:
  std::vector<std::vector<int>> board;
    int width;
    int height;
public:
    Game_Board();
    Game_Board(int,int);
     ~Game_Board();
    bool operator[](int);
    void afficher();
    void fill_board();
    bool valid_pos(int x,int y);
    void set_Pos(int x,int y,int);
};

