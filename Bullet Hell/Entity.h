#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Entity
{
public:
    Entity();
    void setPosition(float x, float y);
    void setScale(float x, float y);

protected:
    sf::Sprite Sprite;
    sf::Texture Texture;
    sf::Vector2f Position;
};

