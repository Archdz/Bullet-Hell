#pragma once

#include "Player.h"
#include "Entity.h"
#include "projectile.h"
#include "Menu.h"
#include "Background.h"

enum GameState {
	MENU,
	GAME,
	HELP,
	SCOREBOARD,
	SETTINGS
};

class windows
{
public:
	void openwindow();
	void updatewin();
	void drawwin();
	void updateProjectile();
	void drawProjectile();

private:
	sf::RenderWindow window{ sf::VideoMode(1200, 800), " " };
	sf::Event event;
	Player player;
	projectile projectile;
	sf::Time deltaTime;
	Menu mainMenu{ window };
	Background background;
	GameState gameState{ GameState::MENU };
};




