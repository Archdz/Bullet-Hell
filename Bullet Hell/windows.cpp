#include "windows.h"

void windows::openwindow()
{
	sf::Clock clock;
	sf::Time elapsedTime;

	const int desiredFramerate = 100;
	const sf::Time frameTime = sf::seconds(1.f / desiredFramerate);

	if (!Font.loadFromFile("arial.ttf")) { std::cout << "Font Error" << std::endl; }

	while (window.isOpen())
	{
		deltaTime = clock.restart();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{ window.close(); }

		}

		elapsedTime = clock.restart();
		if (elapsedTime < frameTime)
		{
			sf::sleep(frameTime - elapsedTime);
		}

		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {				
			
			int menuResult = mainMenu.handleInput();

				switch (menuResult)
				{
				case 0:
					std::cout << "Button Clicked: Continue" << std::endl;
					gameState = GameState::GAME;
					break;
				case 1:
					std::cout << "Button Clicked: New Game" << std::endl;
					player.resetPosition();
					projectile.clearSprites();
					fodder.clearSprites();

					gameState = GameState::GAME;
					break;
				case 2:
					std::cout << "Button Clicked: Help" << std::endl;
					gameState = GameState::HELP;
					break;
				case 3:
					std::cout << "Button Clicked: Scoreboard" << std::endl;
					gameState = GameState::SCOREBOARD;
					break;
				case 4:
					std::cout << "Button Clicked: Settings" << std::endl;
					gameState = GameState::SETTINGS;
					break;
				case 5:
					std::cout << "Button Clicked: EXIT GAME" << std::endl;
					window.close();
					break;
				case 6:
					std::cout << "Button Clicked: Back to Menu" << std::endl;
					gameState = GameState::MENU;
					break;
				case 7:
					std::cout << "Button Clicked: Fodder Settings" << std::endl;

					fodderDifficulty = fodder.getDifficulty() + 1;
					if (fodderDifficulty > 10)
					{
						fodderDifficulty = 0;
					}
					fodder.loadDifficulty(fodderDifficulty);
					mainMenu.loadDifficulty(fodderDifficulty);
					mainMenu.createButtons();
					break;
				case 20:
					std::cout << "Button Clicked: F1" << std::endl;
					if (gameState == GameState::HELP)
					{
						gameState = GameState::GAME;
					}
					else 
					{
						gameState = GameState::HELP;
					}
					break;
				case 21:
					std::cout << "Button Clicked: Esc" << std::endl;
					gameState = GameState::MENU;
					break;
				}
		}
		updatewin();
	}
}

void windows::updatewin()
{
	window.clear(sf::Color::Black);

	player.movement(deltaTime);

	if (gameState == GameState::GAME)
	{
		projectile.shoot(player.getPosition().x + (player.getSizeX() / 2) - 7, player.getPosition().y - (player.getSizeY() / 2) + 3);

		fodder.spawnFodder(deltaTime);

		updateEnemies();

		updateProjectile();

		checkCollision();

	}

	drawwin();

	window.display();
}

void windows::drawwin()
{
	background.drawBackground(window);

	if (gameState == GameState::GAME)
	{
		player.drawPlayer(window);

		drawEnemies();

		drawProjectile();

		drawScore(scoreNum);
	}

	if (gameState == GameState::MENU)
	{
		player.drawPlayer(window);

		mainMenu.drawMenu(window);
	}

	if (gameState == GameState::HELP)
	{
		mainMenu.drawHelp(window);
	}

	if (gameState == GameState::SCOREBOARD)
	{
		mainMenu.drawScoreboard(window);
	}

	if (gameState == GameState::SETTINGS)
	{
		mainMenu.drawSettings(window);
	}
}

void windows::drawProjectile()
{

	for (auto& proj : projectile.getProjectiles())
	{
		if (proj.isTextureLoaded() == false)
		{
			proj.loadTexture();

		}
		proj.drawProjectile(window);
	}
}

void windows::updateProjectile()
{
	auto& projectiles = projectile.getProjectiles();
	auto iter = projectiles.begin();

	while (iter != projectiles.end()) {
		auto& proj = *iter;

		proj.update();

		if (proj.deleteEntity() == true) {
			iter = projectiles.erase(iter);
		}
		else {
			++iter;
		}
	}
}

void windows::drawEnemies()
{
	for (auto& enemy : fodder.getFodders())
	{
		if (enemy.isTextureLoaded() == false)
		{
			enemy.loadTexture();
		}
		enemy.drawFodder(window);
	}
}

void windows::updateEnemies()
{
	auto& Fodders = fodder.getFodders();
	auto iter = Fodders.begin();

	while (iter != Fodders.end()) {
		auto& enemy = *iter;

		enemy.update();

		if (enemy.deleteEntity() == true) {
			iter = Fodders.erase(iter);
			scoreNum += 10;
		}
		else {
			++iter;
		}
	}
}

void windows::checkCollision()
{
	for (auto& proj : projectile.getProjectiles()) 
	{
		for (auto& enemy : fodder.getFodders()) 
		{
			proj.checkCollision(enemy);
			if (proj.checkCollision(enemy) == true) 
			{
				proj.assignRemove();
				enemy.assingRemove();
			}
		}
	}
}

void windows::drawScore(int scr)
{
	Score.setFont(Font);
	Score.setString(std::to_string(scr));
	Score.setCharacterSize(40);
	Score.setPosition(1100, 200);
	window.draw(Score);
}
