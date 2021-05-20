#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class download {
public:
	int load() {
		sf::RenderWindow window({ 830,480 }, "Wolf and Sheeps Game! (clic on space)");
		sf::Texture texture[2];
		sf::Sprite sprite[2];

		texture[0].loadFromFile("Black.jpg");
		texture[1].loadFromFile("tick.png");

		sprite[0].setTexture(texture[0]);
		sprite[1].setTexture(texture[1]);
		sprite[1].setPosition(400, 150);

		while (window.isOpen())
		{
			Vector2i pos = Mouse::getPosition(window);
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					window.close();
					return 3;
				}
			}
			window.clear();
			window.draw(sprite[0]);
			window.draw(sprite[1]);
			window.display();
		}
		return 3;
	}
};