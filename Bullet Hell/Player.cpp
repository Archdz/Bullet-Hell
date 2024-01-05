#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

Player::Player() {
	playerScaleX = 0.1f;
	playerScaleY = 0.1f;
	pPosition.x = 400.0f;
    pPosition.y = 600.0f;
	movementSpeed = 30.0f;
}

void Player::loadSprite(const std::string& filename) {

	if (!pTexture.loadFromFile("playersprite.png")) {
		std::cout << "Failed to load 'playersprite.png'" << std::endl;
	}
	else {
		std::cout << "Loaded 'playersprite.png'" << std::endl;
	}

	pSprite.setTexture(pTexture);
	pSprite.setScale(playerScaleX, playerScaleY);
	pSprite.setPosition(pPosition.x - (pSprite.getGlobalBounds().width / 2), pPosition.y);
}

void Player::drawPlayer(sf::RenderWindow& window){
	window.draw(pSprite);
}

void Player::setPosition(float x, float y)
{
	pSprite.setPosition(x, y);
	std::cout << pSprite.getGlobalBounds().width << std::endl;
}

void Player::setScale(float x, float y)
{
	pSprite.setScale(x, y);
}

void Player::movement(sf::Time deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))	{
			velocity.x -= movementSpeed/sqrt(2);
		}
		else {
			velocity.x -= movementSpeed;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			velocity.x += movementSpeed / sqrt(2);
		}
		else {
			velocity.x += movementSpeed;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			velocity.y -= movementSpeed / sqrt(2);
		}
		else {
			velocity.y -= movementSpeed;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			velocity.y += movementSpeed / sqrt(2);
		}
		else {
			velocity.y += movementSpeed;
		}
	}

	pPosition.x += velocity.x * deltaTime.asSeconds();
	pPosition.y += velocity.y * deltaTime.asSeconds();

	velocity = 0.85f * velocity;

	pSprite.setPosition(pPosition.x, pPosition.y);
}

