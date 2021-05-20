#pragma once
#include <vector>
#include"wolf_winner.h"
#include"sheep_winner.h"
#define PAUSE 2
#define ERR_NONE 1
#define ERR 0
#include <SFML/Graphics.hpp>
using namespace sf;

int spritepositions1[64] = {
    64,1,64,3,64,5,64,7,
    8,64,10,64,12,64,14,64,
    64,17,64,19,64,21,64,23,
    24,64,26,64,28,64,30,64,
    64,33,64,35,64,37,64,39,
    40,64,42,64,44,64,46,64,
    64,49,64,51,64,53,64,55,
    56,64,58,64,60,64,62,64 };
int board1[64] = {
   1,-2,1,-4,1,-6,1,-8,
    0,1,0,1,0,1,0,1,
    1, 0, 1, 0,1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 4, 1, 0, 1 };

class replay_board
{
private:
    int width;
    int height;
    const float WID = 650;
    const float HEI = 650;

public:

    void Mainfunctions1();
    void loadboard1(Texture texture[64], RectangleShape rectangle[64], Sprite sprite[64]);
    void loadtextures1(Texture texture[64]);
    bool pos_occupied1(int x);
};


void replay_board::Mainfunctions1()
{
    bool sheep = false;
    bool wolf = false;
    width = 8;
    height = 8;
    sf::RenderWindow window(sf::VideoMode(WID, HEI), "Wolf and Sheeps Game!(clic on enter to pause or quit)");
    sf::RectangleShape rectangle[64];
    sf::Texture texture[65];
    sf::Sprite sprite[65];
    loadtextures1(texture);
    loadboard1(texture, rectangle, sprite);
 
    int turn = 0;
    Vector2f firstposw, secondposw;
    Vector2f firstpos1, secondpos1;
    Vector2f firstpos2, secondpos2;
    Vector2f firstpos3, secondpos3;
    Vector2f firstpos4, secondpos4;
    int k = 0;
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    int s4 = 0;
    bool ismovew = false;
    bool ismoves1 = false;
    bool ismoves2 = false;
    bool ismoves3 = false;
    bool ismoves4 = false;

    int sh1 = 0; int sh2 = 0;int sh3 = 0; int sh4 = 0;int w1 = 0;
    int n = 0;
   
    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                    window.close();
                
            }


   //drag and drop

             //wolf drag & drop

            if (event.type == Event::MouseButtonPressed) {
                for (int j = 0; j < 64; ++j)
                {
                    if (sprite[j].getGlobalBounds().contains(pos.x, pos.y) && (board1[j] == 4)) {
                        k = j;
                        if (turn % 2 == 0) {

                            ismovew = true;
                            firstposw = sprite[k].getPosition();

                        }
                    }
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    for (int j = 0; j < 64; ++j) {
                        if (j == (k - 7) || j == (k - 9) || j == (k + 9) || j == (k + 7))
                        {
                            if (rectangle[j].getGlobalBounds().contains(pos.x, pos.y)) {
                                secondposw = rectangle[j].getPosition();

                                n = j;
                                if (ismovew && board1[n] == 0) {
                                    turn = turn + 1;
                                    if (k != n) {

                                        sprite[k].setPosition(secondposw);
                                        sprite[0] = sprite[n];
                                        sprite[n] = sprite[k];  
                                        sprite[k] = sprite[0];
                                        spritepositions1[n] = spritepositions1[k];
                                        spritepositions1[k] = 64;
                                        ismovew = false;
                                        board1[n] = board1[k];
                                        board1[k] = 0;
                                        int comp = 1;
                                        bool ok = false;
                                        //wolf is the winner  it works
                                        for (int l = 0;l < 64;l++) {
                                            if (n - comp >= 0) {
                                                if (board1[n - comp] == 0) {
                                                    comp = comp + 1;
                                                    ok = true;
                                                }

                                            }
                                        }
                                        if (ok == true) {
                                            wolf_win wolf;
                                            if (wolf.wolf_is_winner() == 0) {
                                                window.close();
                                            }
                                        }

                                    }
                                    /*sheeps are the winners all cases (probleeeeeem)
                                    if (n == 55 || n == 39) {
                                        if (board[n - 9] != 0 && board[n + 7] != 0)
                                        {
                                            sheep_win sheep;
                                            if (sheep.sheep_is_winner() == 0)
                                                window.close();
                                        }
                                    }
                                    if (n == 40 || n == 24) {
                                        if (board[n - 7] != 0 && board[n + 9] != 0)
                                        {
                                            sheep_win sheep;
                                            if (sheep.sheep_is_winner() == 0)
                                                window.close();
                                        }
                                    }
                                    if (board[n - 7] != 0 && board[n - 9] != 0 && board[n + 7] != 0 && board[n + 9] != 0) {
                                        sheep_win sheep;
                                        if (sheep.sheep_is_winner() == 0)
                                            window.close();
                                    } */

                                    bool winSheep = false;
                                    int l = 8;
                                    while (winSheep == false && l <= 56) {
                                        if (n == l && board1[l - 7] != 0 && board1[l - 7] != 1 && board1[l + 7] != 0 && board1[l + 7] != 1)
                                            winSheep = true;
                                        else
                                            l = l + 16;
                                    }
                                    int m = 23;
                                    while (winSheep == false && m <= 55) {
                                        if (n == m && board1[m + 7] != 0 && board1[m + 7] != 1 && board1[m - 7] != 0 && board1[m - 7] != 1)
                                            winSheep = true;
                                        else
                                            m = m + 16;
                                    }
                                    int q = 56;
                                    while (winSheep == false && q <= 63) {
                                        if (n == q && board1[q - 7] != 1 && board1[q - 7] != 0 && board1[q - 9] != 0 && board1[q - 9] != 1)
                                            winSheep = true;
                                        else
                                            q = q + 2;
                                    }
                                    if (winSheep == true) {
                                        sheep_win sheep;
                                        if (sheep.sheep_is_winner() == 0) {
                                            window.close();
                                        }
                                    }
                                    rectangle[k].setFillColor(sf::Color::Green); //pour tester

                                }

                            }
                        }
                    }

                }
                w1 = n;
            }


            if (turn % 2 != 0) {
                //sheep1 drag & drop
                if (event.type == Event::MouseButtonPressed) {
                    for (int j = 0; j < 64; ++j)
                    {
                        if (sprite[j].getGlobalBounds().contains(pos.x, pos.y) && (board1[j] == -2)) {
                            s1 = j;
                            if (ismovew == false)

                                ismoves1 = true;
                            firstpos1 = sprite[s1].getPosition();
                        }

                    }
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    for (int j = 0; j < 64; ++j) {
                        if (j == (s1 + 9) || j == (s1 + 7)) {
                            if (rectangle[j].getGlobalBounds().contains(pos.x, pos.y)) {
                                secondpos1 = rectangle[j].getPosition();
                                n = j;
                                if (ismoves1 && board1[n] == 0) {
                                    turn = turn + 1;
                                    if (s1 != n) {
                                        sprite[s1].setPosition(secondpos1);
                                        sprite[0] = sprite[n];
                                        sprite[n] = sprite[s1];
                                        sprite[s1] = sprite[0];
                                        spritepositions1[n] = spritepositions1[s1];
                                        spritepositions1[s1] = 64;
                                        ismoves1 = false;
                                        board1[n] = board1[s1];
                                        board1[s1] = 0;
                                    }
                                    rectangle[s1].setFillColor(sf::Color::Yellow); //pour tester
                                }
                            }
                        }
                    }
                }
                sh1 = n;
            }

            //sheep2 drag & drop
            if (event.type == Event::MouseButtonPressed) {
                for (int j = 0; j < 64; ++j)
                {
                    if (sprite[j].getGlobalBounds().contains(pos.x, pos.y) && (board1[j] == -4)) {
                        s2 = j;
                        if (ismovew == false) {

                            ismoves2 = true;
                            firstpos2 = sprite[s2].getPosition();
                        }
                    }
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    for (int j = 0; j < 64; ++j) {
                        if (j == (s2 + 9) || j == (s2 + 7)) {
                            if (rectangle[j].getGlobalBounds().contains(pos.x, pos.y)) {
                                secondpos2 = rectangle[j].getPosition();
                                n = j;
                                if (ismoves2 && board1[n] == 0) {
                                    turn = turn + 1;
                                    if (s2 != n) {

                                        sprite[s2].setPosition(secondpos2);
                                        sprite[0] = sprite[n];
                                        sprite[n] = sprite[s2];
                                        sprite[s2] = sprite[0];
                                        spritepositions1[n] = spritepositions1[s2];
                                        spritepositions1[s2] = 64;
                                        ismoves2 = false;
                                        board1[n] = board1[s2];
                                        board1[s2] = 0;
                                    }
                                    rectangle[s2].setFillColor(sf::Color::Yellow); //pour tester
                                }
                            }
                        }
                    }
                }
                sh2 = n;
            }
            //sheep3 drag & drop
            if (event.type == Event::MouseButtonPressed) {
                for (int j = 0; j < 64; ++j)
                {
                    if (sprite[j].getGlobalBounds().contains(pos.x, pos.y) && (board1[j] == -6)) {
                        s3 = j;
                        if (ismovew == false) {

                            ismoves3 = true;
                            firstpos3 = sprite[s3].getPosition();
                        }
                    }
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    for (int j = 0; j < 64; ++j) {
                        if (j == (s3 + 9) || j == (s3 + 7)) {
                            if (rectangle[j].getGlobalBounds().contains(pos.x, pos.y)) {
                                secondpos3 = rectangle[j].getPosition();
                                n = j;
                                if (ismoves3 && board1[n] == 0) {
                                    turn = turn + 1;
                                    if (s3 != n) {

                                        sprite[s3].setPosition(secondpos3);
                                        sprite[0] = sprite[n];
                                        sprite[n] = sprite[s3];
                                        sprite[s3] = sprite[0];
                                        spritepositions1[n] = spritepositions1[s3];
                                        spritepositions1[s3] = 64;
                                        ismoves3 = false;
                                        board1[n] = board1[s3];
                                        board1[s3] = 0;
                                    }
                                    rectangle[s3].setFillColor(sf::Color::Yellow); //pour tester
                                }
                            }
                        }
                    }
                }
                sh3 = n;
            }
            //sheep4 drag & drop
            if (event.type == Event::MouseButtonPressed) {
                for (int j = 0; j < 64; ++j)
                {
                    if (sprite[j].getGlobalBounds().contains(pos.x, pos.y) && (board1[j] == -8)) {
                        s4 = j;
                        if (ismovew == false) {

                            ismoves4 = true;
                            firstpos4 = sprite[s4].getPosition();
                        }
                    }
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    for (int j = 0; j < 64; ++j) {
                        if (j == (s4 + 9) || j == (s4 + 7)) {
                            if (rectangle[j].getGlobalBounds().contains(pos.x, pos.y)) {
                                secondpos4 = rectangle[j].getPosition();
                                n = j;
                                if (ismoves4 && board1[n] == 0) {
                                    turn = turn + 1;
                                    if (s4 != n) {

                                        sprite[s4].setPosition(secondpos4);
                                        sprite[0] = sprite[n];
                                        sprite[n] = sprite[s4];
                                        sprite[s4] = sprite[0];
                                        spritepositions1[n] = spritepositions1[s4];
                                        spritepositions1[s4] = 64;
                                        ismoves4 = false;
                                        board1[n] = board1[s4];
                                        board1[s4] = 0;
                                    }
                                    rectangle[s4].setFillColor(sf::Color::Yellow); //pour tester
                                }
                            }
                        }
                    }
                }
                sh4 = n;
            }


        }


        window.clear();
        for (int j = 0; j < 64; ++j)
            window.draw(rectangle[j]);
        for (int j = 0; j < 65; j++) {
            window.draw(sprite[j]);
        }
        window.display();

    }
}



bool replay_board::pos_occupied1(int x)
{
    return ((x >= 0) && (x < 64) && (board1[x] = !0) && (board1[x] != 1));
}


void replay_board::loadboard1(Texture texture[64], RectangleShape rectangle[64], Sprite sprite[64]) {
    for (int j = 0;j < 64;j++) {
        sprite[j].setTexture(texture[j]);
        sprite[j].setScale(1.7f, 1.7f);
    }
    for (int j = 0; j < 64; ++j)
    {
        rectangle[j].setSize(sf::Vector2f(WID / 8.0f, HEI / 8.0f));
    }
    int counter = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            rectangle[counter].setPosition(j * rectangle[counter].getSize().y, i * rectangle[counter].getSize().x);  ///x,y
            sprite[counter].setPosition(j * rectangle[counter].getSize().y, i * rectangle[counter].getSize().x);
            if ((i + j) % 2 == 0)
                rectangle[counter].setFillColor(sf::Color::White);
            else
                rectangle[counter].setFillColor(sf::Color::Magenta);
            counter++;
        }
    }
}

void replay_board::loadtextures1(Texture texture[64]) {
    for (int i = 0;i < 64;i++) {

        if (board1[i] == -2)
            texture[i].loadFromFile("Sheep04.png");
        if (board1[i] == -4)
            texture[i].loadFromFile("Sheep01.png");
        if (board1[i] == -6)
            texture[i].loadFromFile("Sheep03.png");
        if (board1[i] == -8)
            texture[i].loadFromFile("Sheep02.png");
        if (board1[i] == 4)
            texture[i].loadFromFile("Wolf.png");


    }
}



