#include "windows.h"

void windows::openwindow()
{
	sf::Clock clock;
	sf::Time elapsedTime;

	const int desiredFramerate = 100;
	const sf::Time frameTime = sf::seconds(1.f / desiredFramerate);

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
					break;
				case 1:
					std::cout << "Button Clicked: New Game" << std::endl;
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
				case 10:
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

	drawwin();

	player.movement(deltaTime);

	projectile.shoot(player.getPosition().x + (player.getSizeX()/2) - 7, player.getPosition().y - (player.getSizeY() / 2) + 3);

	updateProjectile();

	window.display();
}

void windows::drawwin()
{
	background.drawBackground(window);

	if (gameState == GameState::GAME)
	{
		player.drawPlayer(window);

		drawProjectile();

	}

	if (gameState == GameState::MENU)
	{
		player.drawPlayer(window);

		drawProjectile();

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

	for (auto& proj : projectile.getProjectiles()) {
		proj.update();
	}

	for (auto& proj : projectile.getProjectiles())
	{
		auto& proj = *iter;


		if (proj.isOutOfBounds() == true)
		{
			iter = projectiles.erase(iter);
		}

	}
}