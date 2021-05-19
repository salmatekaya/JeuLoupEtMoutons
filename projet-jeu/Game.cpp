#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include "Game.h"
Game::Game()
{   cout<<"0 : position invalide , 1 : position valide"<<endl;
    cout<<"2 : Loup , 3 : Mouton "<<endl;
    cout<<"Mode 0 : joueur vs joueur , Mode 1 : joueur vs Machine Mouton , Mode 2 : joueur vs Machine Loup"<<endl;
    mode = choose_mode();
    if (mode != 0)
        difficulte = choose_difficulty();
    else 
        difficulte = 0;
    board = Game_Board(WIDTH, HEIGHT);
    if (board.valid_pos(WIDTH-1,WIDTH/2)) {
        loup = Wolf(WIDTH-1,WIDTH/2,true, difficulte,mode,board) ;
    }
        moutons = SheepGroup(false,difficulte,mode,board);
    board.afficher();
}
int Game::choose_mode()
{
    string sm; 
    int m;
    while(!(sm == "0"|| sm == "1"|| sm == "2")) {
        cout<<"choisir le mode du jeu"<<endl;
        cin>> sm;
    }
    m = stoi(sm);
    //TO DO 
    // if player vs player select 0 
    // if player is wolf select 1
    // if player is sheep select 2
    return m ;
}

int Game::choose_difficulty()
{
    string sdiff; 
    int d;
    while(!(sdiff == "1"|| sdiff == "2"|| sdiff == "3")) {
        cout<<"choisir le niveau de diffuculte du jeu"<<endl;
        cin>> sdiff;
    }
    d = stoi(sdiff);
    return d;

}

int Game::updateGame()
{  
    cout<<"---------------"<<endl;
    cout<<"--BEGIN__GAME--"<< endl;
    while (!detectWin())
    {
        if (loup.isPlaying()){
            int x = 0;
             //tester si le loup a déplacé ou non si on ERR comme resultat donc non sinon si on a ERR_NONE tout est bon
            do {
              x = loup.choose_Move(board);
            } while (!x);
            if (x == PAUSE){  
                int choice =game_paused();
                if (choice != 2)
                    return choice;
                loup.setIsPlaying(true);
                moutons.setIsPlaying(false);
            }
            else{
                loup.setIsPlaying(false);
                moutons.setIsPlaying(true);
            }
            board.afficher();
        }
        if (moutons.isPlaying()){
            int x = 0;
            do {
              x = moutons.choose_Move(board);
            } while (!x);
            if (x == PAUSE){  
                int choice =game_paused();
                if (choice != 2)
                    return choice;
                loup.setIsPlaying(false);
                moutons.setIsPlaying(true);
            }
            else {
                loup.setIsPlaying(true);
                moutons.setIsPlaying(false);
            }
             board.afficher();
        }
    }
    return result();
}

bool Game::detectWin()
{
     
    return ((detectWinLoup()) | (detectWinMoutons()));
}
bool Game::detectWinLoup()
{
    int minimum = moutons.get_Moutons()[0].get_Position().get_x() ;
   
    for(int i=0;i<moutons.get_Moutons().size();i++)
    {
        if (minimum > moutons.get_Moutons()[i].get_Position().get_x())
            minimum=moutons.get_Moutons()[i].get_Position().get_x();
    }
   
    return(loup.get_Position().get_x()<=minimum);
}

bool Game:: wolf_out_of_moves(){
    Position pos = loup.get_Position();
    return (!board.valid_pos(pos.get_x()+1, pos.get_y()+1)&&
            !board.valid_pos(pos.get_x()+1, pos.get_y()-1)&&
            !board.valid_pos(pos.get_x()-1, pos.get_y()+1)&&
            !board.valid_pos(pos.get_x()-1, pos.get_y()-1));
}
bool Game::detectWinMoutons()
{
    return(loup.isPlaying() && wolf_out_of_moves());
}



int Game::result()
{
    char choix ;
    if(detectWinLoup())
        cout<<"le loup est gagnant"<<endl ;
    else if(detectWinMoutons())
        cout<<"les moutons sont gagnants"<< endl ;
    cout<<"R:Replay"<< endl ;
    cout<<"Q:Quitter"<<endl ;
    cin>>choix;
    if(toupper(choix)=='R')
        return 0;
    if(toupper(choix)=='Q')
        return 1;
    return 1;
}
int Game::game_paused()
{
    char choix ;
    loup.setIsPlaying(false);
    moutons.setIsPlaying(false);
    cout<<"C:continue"<<endl ;
    cout<<"R:replay"<<endl ;
    cout<<"Q:quitter"<<endl;
    cin>>choix ;
    if(toupper(choix)=='C')
        return 2;
    if(toupper(choix)=='R')
        return 0;
    if(toupper(choix)=='Q')
        return 1;
    return 1;
}

