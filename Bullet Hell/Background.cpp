#include "Background.h"

Background::Background()
{
	loadSprite();
}

void Background::loadSprite()
{
    if (!backgroundTexture.loadFromFile("background.png")) { std::cout << "Background Texture Error" << std::endl; }
	backgroundSprite.setTexture(backgroundTexture);
}

void Background::drawBackground(sf::RenderWindow& window) {
	window.draw(backgroundSprite);
}