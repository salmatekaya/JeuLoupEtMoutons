#include <SFML/Graphics.hpp>
using namespace sf;

class Pause {
public:

    int pause() {

        bool ispressed = false;
        sf::RenderWindow window({ 830,480 }, "Wolf and Sheeps Game!");
        sf::Texture texture[4];
        sf::Sprite sprite[4];
        texture[0].loadFromFile("continue1.jpg");
        texture[1].loadFromFile("exit1.jpg");
        texture[2].loadFromFile("replay1.jpg");
        texture[3].loadFromFile("Chesswall.jpg");

        sprite[0].setTexture(texture[0]);
        sprite[1].setTexture(texture[1]);
        sprite[2].setTexture(texture[2]);
        sprite[3].setTexture(texture[3]);

        sprite[0].setPosition(50, 20);
        sprite[2].setPosition(320, 20);
        sprite[1].setPosition(600, 20);
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
                        window.close();
                        return 2;
                    }
                    if (sprite[1].getGlobalBounds().contains(pos.x, pos.y)) {  

                        return 0;

                    }

                    if (sprite[2].getGlobalBounds().contains(pos.x, pos.y)) {
                        window.close();
                        return 1;
                    }
                }
            }
            window.clear();
            window.draw(sprite[3]);
            window.draw(sprite[0]);
            window.draw(sprite[1]);
            window.draw(sprite[2]);
            window.display();
        }


        return 1;
    }

};

