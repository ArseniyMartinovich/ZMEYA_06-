#pragma once
#include "game_object.h"

class Player : public GameObject {
public:
	Player();
	unsigned int lenth;
	void init(sf::RectangleShape snake, sf::RectangleShape food);
	void draw(sf::RenderWindow& window);
	void update();
	int getSize();
	void playerControl();
	bool checkColisions();
private:      
	sf::RectangleShape snake;
	sf::RectangleShape food;
	int nTail;
	float speedx = 0.f;
	float speedy = 0.f;
};

Player snake;

void Player::init(sf::RectangleShape snake, sf::RectangleShape food) {
	snake(sf::Vector2f(10, 10));
	food(sf::Vector2f(10, 10));
}

void Player::playerControl() {
	bounds = sprite.getGlobalBounds();
	speedx = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		speedx = -PLAYER_SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		speedx = PLAYER_SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		speedx = PLAYER_SPEED;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		speedx = -PLAYER_SPEED;
	}
	sprite.move(speedx, speedy);
	sf::Vector2f playerPos = sprite.getPosition();
	if (playerPos.x < 0) {
		sprite.setPosition(0.f, playerPos.y);
	}
	else if (playerPos.x > WINDOW_WIDTH - bounds.width) {
		sprite.setPosition(WINDOW_WIDTH - bounds.width, playerPos.y);
	}
}

void Player::draw() {
	
}

void Player::reset() {
	sprite.clear();
	sprite.push_back(ZMEYA_START_POS);

}