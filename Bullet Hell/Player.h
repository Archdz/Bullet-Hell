#pragma once
#include "Entity.h"
#include "Fodder.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Player : public Entity
{
public:
	Player();
	void loadSprites();
	void movement(sf::Time deltaTime);
	void drawPlayer(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	float getSizeX();
	float getSizeY();
	sf::Sprite getPlayerSprite();
	void resetPosition();
	bool checkCollision(Fodder& fodder);

private:
	sf::Sprite pSprite;
	sf::Texture pTextureBase;
	sf::Texture pTextureBoost;
	sf::Texture pTextureSlow;
	sf::Vector2f velocity;
	sf::Vector2f pPosition;
	float movementSpeed;
	float playerScaleX;
	float playerScaleY;

};

