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
	remove = false;
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
	isOutOfBounds();
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

void projectile::isOutOfBounds()
{
	if (projSprite.getPosition().y < -50.0f ) {
		assignRemove();
	}
}

void projectile::clearSprites()
{
	projectiles.clear();
}

bool projectile::checkCollision(Fodder& fodder)
{
	sf::FloatRect projectileBounds = getProjectileBounds();
	sf::FloatRect fodderBounds = fodder.getFodderBounds();

	return projectileBounds.intersects(fodderBounds);
}

sf::FloatRect projectile::getProjectileBounds() {
	return projSprite.getGlobalBounds();
}

void projectile::assignRemove()
{
	remove = true;
}

bool projectile::deleteEntity()
{
	return remove;
}


