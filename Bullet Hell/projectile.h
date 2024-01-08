#pragma once

#include "Entity.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class projectile : public Entity
{
public:
	projectile();
	void loadSprite(const std::string& filename);
	void shoot(float playerX, float playerY);
	void drawProjectile(sf::RenderWindow& window);
	void setPosition(float x, float y);
	void update();
	std::vector<projectile>& getProjectiles();
	bool isTextureLoaded();
	void loadTexture();
	bool isOutOfBounds();

private:
	sf::Sprite projSprite;
	sf::Texture projTexture;
	sf::Vector2f projPosition;
	float movementSpeed;
	float projScaleX;
	float projScaleY;
	int basecooldown;
	int cooldown;
	std::vector<projectile> projectiles;
	bool textureLoaded;
};

