#include "windows.h"


void windows::openwindow()
{
	player.loadSprite("playersprite.png");
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{ window.close(); }

		}

		updatewin();
	}
}

void windows::updatewin()
{
	window.clear(sf::Color::Black);

	drawwin();
	window.display();

	player.movement(deltaTime);
}

void windows::drawwin()
{
	player.drawPlayer(window);
}
