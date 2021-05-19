#include<stdio.h>
#include<stdlib.h>
#include <string>
#include "sheepGroup.h"

SheepGroup::SheepGroup () {}
SheepGroup::SheepGroup(bool is_playing,int level_CPU,int mode,Game_Board & g_board)
{
    this -> mode = mode;
    this -> is_playing = is_playing;
    this -> level_CPU = level_CPU;
    for(int i =0;i<NB_SHEEP;i++)
    {
        if (g_board.valid_pos(2*i+1,0))
        {
             Sheep mouton(0,2*i+1,g_board);
             
             moutons.push_back(mouton);
        }
    }
}

vector <Sheep> SheepGroup::get_Moutons() {
    return moutons;
}
bool SheepGroup::isPlaying()
{
    return is_playing;
}
void SheepGroup::setIsPlaying(bool is_playing)
{
    this -> is_playing = is_playing;
}

int SheepGroup::choose_Move(Game_Board & g_board)
{
    if(is_playing)
    {
        if (mode == PLAY_WITH_WOLF)
        {   
            cout<<"Le CPU (Mouton) a joué"<<endl;
            return choose_Move_CPU(g_board);
        }
        else if ((mode == PLAY_WITH_BOTH) ||(mode == PLAY_WITH_SHEEP))
        {
            cout<<"C'est votre Tour (Moutons)"<<endl;
            return choose_Move_Player(g_board);
        }
    }
    return ERR;
}

int SheepGroup::choose_Move_Player(Game_Board & g_board)
{
    string snum; 
    int num = 0;
    while(!(snum == "0" || snum == "1" || snum == "2" || snum == "3"|| snum =="p" || snum =="P")) {
        if (!(snum =="P" || snum == "p")){
            cout<<"donner le num de mouton a deplacer"<<endl;
            cin>>snum;
        }
    } 
    if (snum =="p" || snum == "P")
            return PAUSE;
    else 
        num = stoi(snum);
    cout<<"Donnez le bouton appuye"<<endl;
    char bout;
    while(!((toupper(bout)=='P'||toupper(bout)=='A'||toupper(bout)=='E')))
                cin>>bout;
      switch(toupper(bout)) {
        case 'P':
           return PAUSE;
        case 'A':
           return moutons[num].move_Left(g_board);
        case 'E':
           return moutons[num].move_Right(g_board);
      }
    return ERR;
}

bool SheepGroup::max_up(int num_mouton,Game_Board & g_board)
{
    int nb=0;
    int max = moutons[num_mouton].get_Position().get_y();
    for(int i=1;i<NB_SHEEP;i++)
    {
        if (moutons[i].get_Position().get_y()>max){
            max = moutons[i].get_Position().get_y();
            nb = i;
        }

    }
    return (num_mouton==nb);

}

bool SheepGroup::max_down(int num_mouton,Game_Board & g_board)
{
    int nb=0;
    int max = moutons[num_mouton].get_Position().get_x();
    for(int i=1;i<NB_SHEEP;i++)
    {
        if (moutons[i].get_Position().get_x()>max){
            max = moutons[i].get_Position().get_x();
            nb = i;
        }
    }
    return (num_mouton==nb);

}

bool SheepGroup::max_right(int num_mouton,Game_Board & g_board)
{
    int nb=0;
    int max = moutons[num_mouton].get_Position().get_y();
    for(int i=1;i<NB_SHEEP;i++)
    {
        if (moutons[i].get_Position().get_y()>max){
            max = moutons[i].get_Position().get_y();
            nb = i;
        }
    }
    return (num_mouton==nb);
}

bool SheepGroup::max_left(int num_mouton,Game_Board & g_board)
{
    int nb=0;
    int max = moutons[num_mouton].get_Position().get_y();
    for(int i=1;i<NB_SHEEP;i++)
    {
        if (moutons[i].get_Position().get_y()<max){
            max = moutons[i].get_Position().get_y();
            nb = i;
        }
    }
    return (num_mouton==nb);
}

int SheepGroup::count_moves_with_up_Priority(int priority,Game_Board & g_board )
{
    int count = 0;
    for(int i =0 ;i<NB_SHEEP; i++){
        if(g_board.valid_pos(moutons[i].get_Position().get_x()+1, moutons[i].get_Position().get_y()+1)){
            if((max_left(i,g_board) &&!(max_down(i,g_board)) ||max_up(i,g_board))) {
                if ((max_left(i,g_board))&&!(max_down(i,g_board)))
                    count += priority;
                if (max_up(i,g_board))
                    count += priority;
            }
            else
                count++;
        }
        if(g_board.valid_pos(moutons[i].get_Position().get_x()+1, moutons[i].get_Position().get_y()-1)){
            if((max_left(i,g_board) &&!(max_down(i,g_board)) ||max_up(i,g_board))) {
                if ((max_left(i,g_board))&&!(max_down(i,g_board)))
                    count += priority;
                if (max_up(i,g_board))
                    count += priority;
            }
            else
                count++;
        }
    }
    return count;
}

int SheepGroup::select_move_number(int random_moves, int priority,  Game_Board & g_board)
{
    int valid = random_moves;  // 0 to 5 first case(count= 6) ----------------- 0 to 2 second case (count = 3)
    int i = 0;
    while (valid >= 0){
        if(g_board.valid_pos(moutons[i].get_Position().get_x()+1, moutons[i].get_Position().get_y()+1)){
            if((max_left(i,g_board) &&!(max_down(i,g_board)) ||max_up(i,g_board))) {
                if ((max_left(i,g_board))&&!(max_down(i,g_board)))
                    valid -= priority;
                if (max_up(i,g_board))
                    valid -= priority;
            }
            else
                valid--;
        }
        if (valid < 0)    return 2*i;
        if(g_board.valid_pos(moutons[i].get_Position().get_x()+1, moutons[i].get_Position().get_y()-1)){
            if((max_left(i,g_board) &&!(max_down(i,g_board)) ||max_up(i,g_board))) {
                if ((max_left(i,g_board))&&!(max_down(i,g_board)))
                    valid -= priority;
                if (max_up(i,g_board))
                    valid -= priority;
            }
           else
                valid--;
        }
        if (valid < 0)    return 2*i + 1;
        i++;
    }
    return 2*i;
}

int SheepGroup::choose_Move_CPU(Game_Board & g_board){
 int possible_moves = count_moves_with_up_Priority(level_CPU,g_board); //on calcule les mouvements  possibles du loup par la méthode count_moves_with_up_Priority(level)
    int random_number;
    int move_number;
    srand(time(0));
    random_number = rand() % possible_moves;
    move_number = select_move_number(random_number, level_CPU,g_board);
    switch(move_number % 2){
            case 0:
                    return moutons[move_number / 2].move_Right(g_board);
            case 1:
                    return moutons[move_number / 2].move_Left(g_board);
        }
    return ERR;
}
SheepGroup::~SheepGroup() {}