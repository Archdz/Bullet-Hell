#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Fodder.h"

class Menu
{
public:
    Menu(sf::RenderWindow& window);

    void drawMenu(sf::RenderWindow& window);
    void drawHelp(sf::RenderWindow& window);
    void drawScoreboard(sf::RenderWindow& window);
    void drawSettings(sf::RenderWindow& window);

    void loadDifficulty(int a);

    void createButtons();
    int handleInput();
    void updateButtonColors();

private:
    sf::RenderWindow& window;
    sf::Font font;
    std::vector<sf::Text> textHeaders;
    std::vector<sf::Text> buttons;
    bool startButtonHovered;
    bool isMenu;
    bool isBack;
    const int backButton{ 6 };
    const int fodderButton{ 7 };
    int fodderSetting{ 1 };
};

