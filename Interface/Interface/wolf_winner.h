#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class wolf_win {
public:

    int wolf_is_winner()
    {
        sf::RenderWindow window({ 830,480 }, "Wolf and Sheeps Game!(clic on Q)");
        sf::Texture texture[4];
        sf::Sprite sprite[4];
        texture[0].loadFromFile("wolf-with-trophy.jpg");
        texture[1].loadFromFile("completed.jpg");
        texture[2].loadFromFile("Chesswall.jpg");
        texture[3].loadFromFile("quit.png");

        sprite[0].setTexture(texture[0]);
        sprite[1].setTexture(texture[1]);
        sprite[2].setTexture(texture[2]);
        sprite[3].setTexture(texture[3]);

        sprite[0].setPosition(340, 200);
        sprite[1].setPosition(285, 15);
        sprite[3].setPosition(700, 340);

        while (window.isOpen())
        {
            Vector2i pos = Mouse::getPosition(window);
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                
                
                    if  (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    {
                        window.close();
                        return 0;
                    }
                
            }
            window.clear();
            window.draw(sprite[2]);
            window.draw(sprite[0]);
            window.draw(sprite[1]);
            window.draw(sprite[3]);
            window.display();
        }
        return 0;
    }
};