#include "Player.h"

Player::Player() {
	playerScaleX = 0.3f;
	playerScaleY = 0.3f;
	pPosition.x = 400.0f;
    pPosition.y = 600.0f;
	movementSpeed = 28.0f;
	loadSprites();
}

void Player::drawPlayer(sf::RenderWindow& window) {
	window.draw(getPlayerSprite());
}

void Player::loadSprites() {

	if (!pTextureBoost.loadFromFile("player2boost.png")) { std::cout << "Texture Error" << std::endl; }
	if (!pTextureBase.loadFromFile("player2.png")) { std::cout << "Texture Error" << std::endl; }
	if (!pTextureSlow.loadFromFile("player2slow.png")) { std::cout << "Texture Error" << std::endl; }

	pSprite.setTexture(pTextureBase);

	pSprite.setScale(playerScaleX, playerScaleY);
	pSprite.setPosition(pPosition.x - (pSprite.getGlobalBounds().width / 2), pPosition.y);
}

sf::Sprite Player::getPlayerSprite()
{
	sf::Sprite tempSprite = pSprite;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		tempSprite.setTexture(pTextureBoost);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		tempSprite.setTexture(pTextureSlow);
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		tempSprite.setTexture(pTextureBase);
	}
	return tempSprite;
}

void Player::movement(sf::Time deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))	{
			velocity.x -= movementSpeed / sqrt(2);
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

	velocity = 0.90f * velocity;

	pPosition.x = pSprite.getPosition().x;
	pPosition.y = pSprite.getPosition().y;

	if (pPosition.x < 202 && velocity.x < 0) {
		velocity.x = 0;
	}

	if (pPosition.x > (998 - pSprite.getGlobalBounds().width) && velocity.x > 0) {
		velocity.x = 0;
	}

	if (pPosition.y < 0 && velocity.y < 0) {
		velocity.y = 0;
	}

	if (pPosition.y > (800 - pSprite.getGlobalBounds().height) && velocity.y > 0) {
		velocity.y = 0;
	}

	pSprite.move(velocity.x * deltaTime.asSeconds(), velocity.y * deltaTime.asSeconds());
}

sf::Vector2f Player::getPosition()
{
	return pSprite.getPosition();
}

float Player::getSizeX()
{
	return pSprite.getGlobalBounds().width;
}

float Player::getSizeY()
{
	return pSprite.getGlobalBounds().height;
}



