#include "Fodder.h"

Fodder::Fodder()
{
	movementSpeed = 4.0f;
	fodderScaleX = 0.25f;
	fodderScaleY = 0.25f;
	spawnTimer = 0.f;
	delay = delayBase;
	difficulty = 0;
	loadSprite("fodder.png");
	textureLoaded = false;

	delayTimer = 0.f;

	lower_bound = 200.0f;
	upper_bound = 1000.0f - fodderSprite.getGlobalBounds().width;
	yaxis = -50.f;
	xaxis = 600.f;

	registeredTime = 0.f;
	remove = false;
}

void Fodder::loadSprite(const std::string& filename)
{
	if (!fodderTexture.loadFromFile(filename))
	{
		std::cout << "Failed to load " << filename << std::endl;
	}
	fodderSprite.setScale(fodderScaleX, fodderScaleY);
	fodderSprite.setTexture(fodderTexture);
}

void Fodder::drawFodder(sf::RenderWindow& window)
{
	window.draw(fodderSprite);
}

void Fodder::update()
{
	fodderSprite.move(0.0f, movementSpeed);
}

void Fodder::setPosition(float x, float y)
{
	fodderSprite.setPosition(x, y);
}

std::vector<Fodder>& Fodder::getFodders()
{
	return Fodders;
}

void Fodder::spawnFodder(sf::Time deltaTime)
{
	spawnTimer += deltaTime.asSeconds();
	delayTimer += deltaTime.asSeconds();

	if (spawnTimer > delay) 

	{
		for (int i = 0; i < difficulty; i++) {
			fodderSpawn2();
		}

		spawnTimer = 0;

	}

	if (delayTimer > 5.f && delay > 0.5 * delayBase) {
		delay = delay * 0.95;
		delayTimer = 0.f;
	}

}

void Fodder::fodderSpawn2()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_real_distribution<float> distribution(lower_bound, upper_bound);

	float xaxis = distribution(gen);
	Fodder newFodder;
	newFodder.setPosition(xaxis, yaxis);
	Fodders.push_back(newFodder);
	std::cout << "Fodder created at: " << xaxis << ", " << yaxis << std::endl;
}



void Fodder::loadTexture()
{
	if (textureLoaded == false)
	{
		fodderSprite.setTexture(fodderTexture);
	}
}
bool Fodder::isTextureLoaded()
{
	return textureLoaded;
}

void Fodder::isOutOfBounds()
{
	if (fodderSprite.getPosition().y > 850.f) {
		assingRemove();
	}
}

void Fodder::clearSprites()
{
	Fodders.clear();
}

sf::FloatRect Fodder::getFodderBounds()
{
	return fodderSprite.getGlobalBounds();
}

void Fodder::assingRemove()
{
	remove = true;
}

bool Fodder::deleteEntity()
{
	return remove;
}

int Fodder::getDifficulty()
{
	return difficulty;
}

void Fodder::loadDifficulty(int a)
{
	difficulty = a;
}
