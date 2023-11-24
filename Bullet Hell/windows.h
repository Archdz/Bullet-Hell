#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class windows
{
public:
	void openwindow();
	void updatewin();
	void drawwin();
private:
	sf::RenderWindow window{ sf::VideoMode(800, 900), " " };
	sf::Event event;
};




