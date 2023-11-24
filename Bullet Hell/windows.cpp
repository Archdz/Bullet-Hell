#include "windows.h"

void windows::openwindow()
{

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{ window.close(); }
			updatewin();
		}

	}
}

void windows::updatewin()
{
	drawwin();
	window.display();
	window.clear(sf::Color::Black);
}

void windows::drawwin()
{
	//draw obiektów
}
