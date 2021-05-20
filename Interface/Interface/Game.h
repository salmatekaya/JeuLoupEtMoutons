#pragma once
#include <iostream>
#include "Game_Board.h"
#include"laod pages.h"
#include <SFML/Graphics.hpp>
using namespace sf;


class Game
{
private:
    int num;
    int difficulte;
    int mode;
    int page = 0;
    Game_Board g;
    download load;

public:
    Game();
    int choose_mode();
    int choose_difficulty();

};

Game::Game()
{
    sf::RenderWindow window({ 830,480 }, "Wolf and Sheeps Game!");
    sf::Texture texture[4];
    sf::Sprite sprite[4];

    texture[0].loadFromFile("play.png");
    texture[1].loadFromFile("Exit.png");
    texture[2].loadFromFile("Chesswall.jpg");
    texture[3].loadFromFile("wvss.jpg");


    sprite[0].setTexture(texture[0]);
    sprite[1].setTexture(texture[1]);
    sprite[2].setTexture(texture[2]);
    sprite[3].setTexture(texture[3]);

    sprite[0].setPosition(30, 20);
    sprite[1].setPosition(700, 20);
    sprite[3].setPosition(310, 170);
    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (sprite[1].getGlobalBounds().contains(pos.x, pos.y)) {
                    window.close();

                }
                if (sprite[0].getGlobalBounds().contains(pos.x, pos.y)) {
                    window.close();
                   choose_mode();
                   

                }
            }
        }
        window.clear();

        window.draw(sprite[2]);
        window.draw(sprite[0]);
        window.draw(sprite[1]);
        window.draw(sprite[3]);
        window.display();
    }
}

int Game::choose_mode()
{
    int m = -1;
    bool ispressed;
    sf::RenderWindow window({ 830,480 }, "Wolf and Sheeps Game!");
    sf::Texture texture[5];
    sf::Sprite sprite[5];
    texture[0].loadFromFile("pVsp.png");
    texture[1].loadFromFile("mode2-1.jpg");
    texture[2].loadFromFile("mode3-1.jpg");
    texture[4].loadFromFile("Chesswall.jpg");
    texture[3].loadFromFile("next1.png");

    sprite[0].setTexture(texture[0]);
    sprite[1].setTexture(texture[1]);
    sprite[2].setTexture(texture[2]);
    sprite[3].setTexture(texture[3]);
    sprite[4].setTexture(texture[4]);

    sprite[0].setPosition(30, 20);
    sprite[1].setPosition(350, 20);
    sprite[2].setPosition(630, 20);
    sprite[3].setPosition(650, 400);
    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Middle) || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (sprite[0].getGlobalBounds().contains(pos.x, pos.y)) {
                    m = m + 1; //if player vs player
                }
                if (sprite[1].getGlobalBounds().contains(pos.x, pos.y)) {
                    m = m + 1; // if player is wolf
                }
                if (sprite[2].getGlobalBounds().contains(pos.x, pos.y)) {
                    m = m + 1; // if player is sheep
                }
                if (sprite[3].getGlobalBounds().contains(pos.x, pos.y)) {
                    ispressed = true;
                    window.close();
                    if (load.load() == 3)
                    {
                        window.close();
                        choose_difficulty();
                    }
                  
                    //page pour choisir le niveau de difficulté
                }
            }
        }
        window.clear();
        window.draw(sprite[4]);
        window.draw(sprite[0]);
        window.draw(sprite[1]);
        window.draw(sprite[2]);
        window.draw(sprite[3]);
        window.display();
    }
    return m;
}

int Game::choose_difficulty()
{
    int d = -1;
    bool ispressed;
    sf::RenderWindow window({ 830,480 }, "Wolf and Sheeps Game!");
    sf::Texture texture[5];
    sf::Sprite sprite[5];
    texture[0].loadFromFile("Level1.png");
    texture[1].loadFromFile("Level2.png");
    texture[2].loadFromFile("Level3.png");
    texture[4].loadFromFile("Chesswall.jpg");
    texture[3].loadFromFile("play1 (2).png");

    sprite[0].setTexture(texture[0]);
    sprite[1].setTexture(texture[1]);
    sprite[2].setTexture(texture[2]);
    sprite[3].setTexture(texture[3]);
    sprite[4].setTexture(texture[4]);

    sprite[0].setPosition(30, 20);
    sprite[2].setPosition(620, 20);
    sprite[1].setPosition(350, 20);
    sprite[3].setPosition(700, 400);
    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Middle) || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (sprite[0].getGlobalBounds().contains(pos.x, pos.y)) {
                    d = d + 1; //easy 0
                }
                if (sprite[1].getGlobalBounds().contains(pos.x, pos.y)) {
                    d = d + 1; // medium 1
                }
                if (sprite[2].getGlobalBounds().contains(pos.x, pos.y)) {
                    d = d + 1; // hard 2
                }
                if (sprite[3].getGlobalBounds().contains(pos.x, pos.y)) {
                    ispressed = true;
                    window.close();
                    if(load.load()==3)
                    {
                        window.close();
                        g.Mainfunctions();
                    }
                   

                    ///echiquier
                }
            }
        }       window.clear();
        window.draw(sprite[4]);
        window.draw(sprite[0]);
        window.draw(sprite[1]);
        window.draw(sprite[2]);
        window.draw(sprite[3]);
        window.display();
    }
    return d;

}

/*int Game::updateGame()
{
    while (!detectWin())
    {
        if (loup.isPlaying()) {
            int x = 0;
            do {
                x = loup.choose_Move(board);
            } while (!x);
            if (x == PAUSE) {
                int choice = game_paused();
                if (choice != 2)
                    return choice;
            }
            board.afficher();
            loup.setIsPlaying(false);
            moutons.setIsPlaying(true);
        }
        if (moutons.isPlaying()) {
            int x = 0;
            do {
                x = moutons.choose_Move(board, num);
            } while (!x);
            if (x == PAUSE) {
                int choice = game_paused();
                if (choice != 2)
                    return choice;
            }
            loup.setIsPlaying(true);
            moutons.setIsPlaying(false);
        }
    }
    return result();
}


/*int Game::result() //cette page sera afficher a la fin du jeu s'il y a un gagnant
{
    sf::RenderWindow window({ 830,480 }, "Wolf and Sheeps Game!");
    sf::Texture texture[5];
    sf::Sprite sprite[6];
    texture[0].loadFromFile("wolf is the winner.png");
    texture[1].loadFromFile("The sheeps are the winner.png");
    texture[2].loadFromFile("replay1.png");
    texture[3].loadFromFile("exit1.png");
    texture[4].loadFromFile("Chesswall.jpg");

    sprite[0].setTexture(texture[0]);
    sprite[1].setTexture(texture[1]);
    sprite[2].setTexture(texture[2]);
    sprite[3].setTexture(texture[3]);
    sprite[4].setTexture(texture[4]);

    sprite[0].setPosition(320, 20);
    sprite[1].setPosition(320, 20);
    sprite[2].setPosition(80, 320);
    sprite[3].setPosition(620, 520);
    while (window.isOpen())
    {
        Vector2i pos = Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (sprite[2].getGlobalBounds().contains(pos.x, pos.y)) {
                    window.close();
                    return 0;
                    //affichier un nouveau echiquier
                }
                if (sprite[2].getGlobalBounds().contains(pos.x, pos.y)) {
                    window.close();
                    return 1;
                }
            }
        }
        window.clear();
        window.draw(sprite[4]);
        window.draw(sprite[5]);
        window.draw(sprite[2]);
        window.draw(sprite[3]);
        window.display();
    }
    return 1;
}*/

