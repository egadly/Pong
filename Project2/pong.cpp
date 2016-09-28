#include <SFML\Graphics.hpp>
#include "pong.h"
#include <string>

Pong::Pong() {
}
void Pong::draw(sf::RenderWindow * window) {
	shape.setPosition(pos);
	window->draw(shape);
}

P1::P1() {
	pos.x = 24;
	pos.y = 0;
	shape = sf::RectangleShape(sf::Vector2f(16, 32));
	shape.setFillColor(sf::Color::White);
}
void P1::update(sf::Keyboard keyboard) {
	if (keyboard.isKeyPressed(sf::Keyboard::W)) pos.y -= 4;
	if (keyboard.isKeyPressed(sf::Keyboard::S)) pos.y += 4;
	if (pos.y < 0) pos.y = 0;
	if (pos.y >(240 - 32)) pos.y = 240 - 32;
}

P2::P2() {
	pos.x = 320 - 40;
	pos.y = 240 - 32;
	shape = sf::RectangleShape(sf::Vector2f(16, 32));
	shape.setFillColor(sf::Color::White);
}
void P2::update(sf::Keyboard keyboard) {
	if (keyboard.isKeyPressed(sf::Keyboard::I)) pos.y -= 4;
	if (keyboard.isKeyPressed(sf::Keyboard::K)) pos.y += 4;
	if (pos.y < 0) pos.y = 0;
	if (pos.y >(240 - 32)) pos.y = 240 - 32;
}

Ball::Ball() {
	pos.x = 320 / 2;
	pos.y = 240 / 2;
	vel.x = 4;
	vel.y = 4;
	shape = sf::RectangleShape(sf::Vector2f(16, 16));
	shape.setFillColor(sf::Color::White);
	font.loadFromFile("num.ttf");
	text.setFont(font);
	text.setCharacterSize(16);
	score.x = 0;
	score.y = 0;
}
void Ball::update(P1 player1, P2 player2) {
	if (vel.x > 16) vel.x = 16;
	if (vel.x < -16) vel.x = -16;
	pos.x += vel.x;
	pos.y += vel.y;
	if (vel.x < 0 && (pos.x - player1.getPos().x)< 16 && (pos.x - player1.getPos().x)>-16 && (pos.y - player1.getPos().y) < 32 && (pos.y - player1.getPos().y) > -16) vel.x = -vel.x*1.1;
	if (vel.x > 0 && (pos.x - player2.getPos().x)< 16 && (pos.x - player2.getPos().x)>-16 && (pos.y - player2.getPos().y) < 32 && (pos.y - player2.getPos().y) > -16) vel.x = -vel.x*1.1;

	if (pos.x < 0 ) {
		pos.x = 320 / 2;
		vel.x = 4;
		score.y += 1;
	}
	if (pos.x > 320-16) {
		pos.x = 320 / 2;
		vel.x = -4;
		score.x += 1;
	}
	if (pos.y < 0) {
		pos.y = 0;
		vel.y = -vel.y;
	}
	if (pos.y > 240 - 16) {
		pos.y = 240 - 16;
		vel.y = -vel.y;
	}

}

void Ball::draw(sf::RenderWindow * window) {
	text.setString(std::to_string(score.x));
	text.setPosition(320 / 2, 0);
	window->draw(text);
	text.setString(std::to_string(score.y));
	text.setPosition(320 / 2, 240 - 24);
	window->draw(text);
	shape.setPosition(pos);
	window->draw(shape);
}