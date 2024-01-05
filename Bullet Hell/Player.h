#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player
{
public:
	Player();
	void loadSprite(const std::string& filename);
	void drawPlayer(sf::RenderWindow& window);
	void setPosition(float x, float y);
	void setScale(float x, float y);
	void movement(sf::Time deltaTime);

private:
	sf::Sprite pSprite;
	sf::Texture pTexture;
	float playerScaleX;
	float playerScaleY;
	sf::Vector2f pPosition;
	float movementSpeed;
	sf::Vector2f velocity;
};

