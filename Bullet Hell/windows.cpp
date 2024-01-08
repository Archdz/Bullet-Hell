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
			if (gameState == GameState::MENU) {
				int menuResult = mainMenu.handleInput();

				switch (menuResult)
				{
				case 0:
					// Continue
					break;
				case 1:
					// New Game
					break;
				case 2:
					// Help
					break;
				case 3:
					// Scoreboard
					break;
				default:
					// No button clicked
					break;

					if (mainMenu.isStartButtonClicked()) {
						gameState = GameState::GAME;
					}
					// Handle other menu buttons...
				}
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

	window.display();
}

void windows::drawwin()
{
	player.drawPlayer(window);
	mainMenu.draw(window);

	for (auto& proj : projectile.getProjectiles())
	{
		if (proj.isTextureLoaded() == false)
		{
			proj.loadTexture();

		}
		proj.drawProjectile(window);
	}
}
