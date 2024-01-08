#include "projectile.h"


projectile::projectile() 
{
	projScaleX = 1.0f;
	projScaleY = 1.0f;
	cooldown = 0;
	basecooldown = 20;
	movementSpeed = 6.f;
	loadSprite("projectile2.png");
	textureLoaded = false;
}

void projectile::loadSprite(const std::string& filename)
{
	if (!projTexture.loadFromFile(filename)) 
	{
		std::cout << "Failed to load " << filename << std::endl;
	}

	projSprite.setScale(projScaleX, projScaleY);
	projSprite.setTexture(projTexture);
}

void projectile::drawProjectile(sf::RenderWindow& window)
{
	window.draw(projSprite);
}

void projectile::update()
{
	projSprite.move(0.0f, -movementSpeed);
}

void projectile::shoot(float playerX, float playerY)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (cooldown == 0)
		{
			projectile newProjectile;
			newProjectile.setPosition(playerX, playerY);
			projectiles.push_back(newProjectile);
			std::cout << "Projectile created at: " << playerX << ", " << playerY << std::endl;

			cooldown = basecooldown;
		}
		else
		{
			cooldown--;
		}
}
}

std::vector<projectile>& projectile::getProjectiles()
{
	return projectiles;
}

bool projectile::isTextureLoaded()
{
	return textureLoaded;
}

void projectile::setPosition(float x, float y)
{
	projSprite.setPosition(x, y);
}

void projectile::loadTexture() {
	if (textureLoaded == false)
	{
		projSprite.setTexture(projTexture);
	}
}

bool projectile::isOutOfBounds()
{
	if (projSprite.getPosition().y < -50.0f ) {
		return true;
	}
	else {
		return false;
	}
}
