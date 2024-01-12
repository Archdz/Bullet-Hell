#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <windows.h>

class Fodder
{
public:
	Fodder();
	void loadSprite(const std::string& filename);
	void spawnFodder(sf::Time deltaTime);

	int getDifficulty();
	void loadDifficulty(int a);

	void drawFodder(sf::RenderWindow& window);
	void update();
	void setPosition(float x, float y);
	std::vector<Fodder>& getFodders();
	void loadTexture();
	bool isTextureLoaded();
	void isOutOfBounds();

	void clearSprites();

	sf::FloatRect getFodderBounds();

	void assingRemove();
	bool deleteEntity();
	void fodderSpawn2();

private:
	sf::Sprite fodderSprite;
	sf::Texture fodderTexture;
	sf::Vector2f velocity;

	std::vector<Fodder> Fodders;

	int difficulty;
	float delay;

	float movementSpeed;
	float fodderScaleX;
	float fodderScaleY;
	float spawnTimer; 
	float totalTimer;
	float timeVar;
	float delayTimer;
	float registeredTime;

	float delayBase{ 2.f };

	bool textureLoaded;
	float upper_bound;
	float lower_bound;

	float yaxis;
	float xaxis;

	bool remove;
};

