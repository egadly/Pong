#include <SFML/Graphics.hpp>
#include "pong.h"

int main()
{
	sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(320, 240), "Pong");
	sf::Keyboard keyboard;
	P1 player1;
	P2 player2;
	Ball ball;

	while (window->isOpen()) {

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		player1.update(keyboard);
		player2.update(keyboard);
		ball.update(player1, player2);
		player1.draw(window);
		player2.draw(window);
		ball.draw(window);
		window->display();
		sf::sleep(sf::seconds(1 / 30.0));
	}
}