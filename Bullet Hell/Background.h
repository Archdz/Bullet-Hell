#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Background
{
public:
	Background();
	void loadSprite();
	void drawBackground(sf::RenderWindow& window);

private:
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
};

