
// test github
#include "Wolf.h"
#include "Game_Board.h"
#include <cstdlib>
#include <time.h>


Wolf::Wolf() {}
Wolf::Wolf(int x, int y, bool is_playing,int level_CPU,int mode, Game_Board & g_board) : Animal(x,y,g_board,2)
{
    this -> mode = mode;
    this -> is_playing = is_playing;
    this -> level_CPU = level_CPU;
}

bool Wolf::isPlaying()
{
    return is_playing;
}
void Wolf::setIsPlaying(bool is_playing)
{
    this -> is_playing = is_playing;
}

int Wolf::move_Left_Down(Game_Board & g_board)
{
    return Animal::move_Left_Down(g_board,2) ;
}
int Wolf::move_Right_Down(Game_Board & g_board)
{
    return Animal::move_Right_Down(g_board,2);
}
int Wolf::move_Right_Up(Game_Board & g_board)
{
    if(g_board.valid_pos(get_Position().get_x()-1, get_Position().get_y()+1))
    {
        g_board.set_Pos(get_Position().get_x(), get_Position().get_y(), 1);
        pos.set_x(pos.get_x()-1);
        pos.set_y(pos.get_y()+1);
        g_board.set_Pos(get_Position().get_x(), get_Position().get_y(), 2);
        return ERR_NONE;
    }
    else {
        cout<<"la nouvelle position est invalide"<<endl;
        return ERR;
    }
}
int Wolf::move_Left_Up(Game_Board & g_board)
{
    if(g_board.valid_pos(get_Position().get_x()-1, get_Position().get_y()-1))
    {
        g_board.set_Pos(get_Position().get_x(), get_Position().get_y(), 1);
        pos.set_x(pos.get_x()-1);
        pos.set_y(pos.get_y()-1);
        g_board.set_Pos(get_Position().get_x(), get_Position().get_y(), 2);
        return ERR_NONE;
    }
    else {
        cout<<"la nouvelle position est invalide"<<endl;
        return ERR;
    }
}
int Wolf::choose_Move(Game_Board & g_board) //choisir le mode du jeu
{
    if(is_playing)
    {
        if (mode == PLAY_WITH_SHEEP)
        { 
             cout<<"Le CPU (Loup) a joué"<<endl;
            return choose_Move_CPU(g_board);
        }
        else if ((mode == PLAY_WITH_BOTH) || (mode == PLAY_WITH_WOLF))
        {
            cout<<"c'est votre Tour (Loup)"<<endl;
            return choose_Move_Player(g_board);
        }
    }
    return ERR;
}
int Wolf::choose_Move_Player(Game_Board & g_board) //choisir l'avancement du joueur humain selon le bouton appuy�
{  
     char bout;
    cout<<"Donnez le bouton appuye"<<endl;
    while(!((toupper(bout)=='P'||toupper(bout)=='A'||toupper(bout)=='E'||toupper(bout)=='Q'||toupper(bout)=='D')))
                cin>>bout;
      switch(toupper(bout)) {
       case 'P':
           return PAUSE;
       case 'A':
           return move_Left_Up(g_board);
       case 'E':
           return move_Right_Up(g_board);
       case 'Q':
           return move_Left_Down(g_board);
       case 'D':
           return move_Right_Down(g_board);
          break;
      }
    return ERR;  
}

int Wolf::count_moves_with_up_Priority(int priority,Game_Board & g_board ) //priority = level_CPU
{
    int count = 0;
    if(g_board.valid_pos(get_Position().get_x()-1, get_Position().get_y()+1))
        count+= priority;
    if(g_board.valid_pos(get_Position().get_x()+1, get_Position().get_y()+1))
        count++;
    if(g_board.valid_pos(get_Position().get_x()-1, get_Position().get_y()-1))
        count+= priority;
    if(g_board.valid_pos(get_Position().get_x()+1, get_Position().get_y()-1))
        count++;
    return count;
}
int Wolf::select_move_number(int random_moves, int priority, Game_Board & g_board)
{
    int valid = random_moves;  // 0 to 5 first case(count= 6) ----------------- 0 to 2 second case (count = 3)
    //0 1 return 0 ---------------- doesnt return 0 right up not valid
    if(g_board.valid_pos(get_Position().get_x()-1, get_Position().get_y()+1))
        valid-= priority;
     if (valid < 0)    
      return 0;
    //2 return 1 ---------------- doesnt return 1 right down not valid
    if(g_board.valid_pos(get_Position().get_x()+1, get_Position().get_y()+1))
        valid-- ;
    if (valid < 0)    return 1;
    //3 4 return 2 ------------------------- 0 1 return 2 left up chosen
    if(g_board.valid_pos(get_Position().get_x()-1, get_Position().get_y()-1))
        valid-= priority;
    if (valid < 0)    return 2;
    //5 return 3 ------------------------- 2 return 3 left down chosen
    if(g_board.valid_pos(get_Position().get_x()+1, get_Position().get_y()-1))
        valid--;
    return 3;
}

//---------------------------------------Move_CPU-------------------------------------------
int Wolf::choose_Move_CPU(Game_Board & g_board)  //ca depend du niveau de difficulte de jeu, plus le niveau augmente plus la probabilite que le loup avance augmente.
{
    int possible_moves = count_moves_with_up_Priority(level_CPU * 10,g_board); //on calcule les mouvements  possibles du loup par la methode count_moves_with_up_Priority(level)
    int random_number;
    int move_number;
    srand(time(0));
    random_number = rand() % possible_moves;
    move_number = select_move_number(random_number, level_CPU * 10, g_board);
    switch(move_number){
            case 0:
                    return move_Right_Up(g_board);
        
            case 1:
                    return move_Right_Down(g_board);
        
            case 2:
                    return move_Left_Up(g_board);
        
            case 3:
                    return move_Left_Down(g_board);
        
        }
    return ERR;
}

Wolf::~Wolf()
{}
