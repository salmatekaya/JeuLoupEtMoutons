#include "vector"
#include "Game_Board.h"
#include <iostream>
using namespace std;

Game_Board::Game_Board() {}

Game_Board::Game_Board(int w,int h) : width(w),height(h)
{
    this -> board = board;
    fill_board();
}

void Game_Board::afficher()
{
    cout<<"---------------"<<endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <width; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout<<"---------------"<<endl;
}

void::Game_Board::fill_board()
{  
     for(int row = 0; row < height; row++) {
         std::vector<int> vec;
          for(int col = 0; col < width; col++)
        {
            if (row % 2 == 0){
                if( col % 2 == 0) 
                    vec.push_back(0); //case blanche
                else vec.push_back(1);
            }
            else {
                if(col % 2 == 0)
                   vec.push_back(1); //case noireç
                else vec.push_back(0);
            }
     }
     board.push_back(vec);
     }
}
bool Game_Board::valid_pos(int x,int y)
{
    return ((x >= 0)&& (y >= 0)&& (x < width)&& (y < height)  && (board[x][y]== 1)) ;
}

void Game_Board::set_Pos(int x,int y,int valid) 
{
   board[x][y] = valid;
}

Game_Board::~Game_Board()
{
}
