#pragma once

#include "Player.h"
#include "Entity.h"
#include "projectile.h"
#include "Menu.h"
#include "Background.h"
#include "Fodder.h"

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
	void updateEnemies();
	void drawEnemies();
	void checkCollision();

	void drawScore(int scr);
	int scoreNum{ 0 };

private:
	sf::RenderWindow window{ sf::VideoMode(1200, 800), " " };
	sf::Event event;
	Player player;
	projectile projectile;
	sf::Time deltaTime;
	Menu mainMenu{ window };
	Background background;
	Fodder fodder;
	GameState gameState{ GameState::MENU };

	sf::Text Score;
	sf::Font Font;
	int fodderDifficulty{ 8 };

};




