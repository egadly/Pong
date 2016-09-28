#ifndef PONG
#define PONG

#include "SFML/Graphics.hpp"

class Pong {
protected:
	sf::Vector2f pos;
	sf::Vector2i score;
	sf::RectangleShape shape;
	sf::Font font;
	sf::Text text;
public:
	Pong();
	sf::Vector2f getPos() {
		return pos;
	}
	void draw(sf::RenderWindow * window);
};

class P1 : public Pong {
public:
	P1();
	void update(sf::Keyboard keyboard);
};
class P2 : public Pong {
public:
	P2();
	void update(sf::Keyboard keyboard);
};

class Ball : public Pong {
private:
	sf::Vector2f vel;
public:
	Ball();
	void update(P1 player1, P2 player2);
	void draw(sf::RenderWindow * window);
};


#endif // !PONG
