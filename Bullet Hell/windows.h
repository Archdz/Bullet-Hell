#pragma once

#include "Player.h"
#include "Entity.h"
#include "projectile.h"
#include "Menu.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum GameState {
	MENU,
	GAME
};

class windows
{
public:
	void openwindow();
	void updatewin();
	void drawwin();


private:
	sf::RenderWindow window{ sf::VideoMode(800, 900), " " };
	sf::Event event;
	Player player;
	projectile projectile;
	sf::Time deltaTime;
	Menu mainMenu{ window };
	GameState gameState{ GameState::MENU };
};




