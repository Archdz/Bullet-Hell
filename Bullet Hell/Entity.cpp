#include "Entity.h"

Entity::Entity()
{
}

void Entity::setPosition(float x, float y)
{
	Sprite.setPosition(x, y);
}

void Entity::setScale(float x, float y)
{
	Sprite.setScale(x, y);
}


