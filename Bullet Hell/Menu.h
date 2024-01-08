#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Menu
{
public:
    Menu(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);
    int handleInput();
    bool isStartButtonClicked();
    void updateButtonColors();

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text titleText;
    std::vector<sf::Text> buttons;
    bool startButtonHovered;
};

