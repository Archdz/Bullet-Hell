#include "Menu.h"

Menu::Menu(sf::RenderWindow& windowTemp) : window(windowTemp) {

    if (!font.loadFromFile("arial.ttf")) { std::cout << "Font Error" << std::endl; }

    createButtons();

    std::vector<std::string> headerLabels = { "Main Menu", "Help Title", "Scoreboard Title", "Settings Title"};

    for (size_t i = 0; i < headerLabels.size(); ++i) {
        sf::Text header;
        header.setFont(font);
        header.setString(headerLabels[i]);
        header.setCharacterSize(40);
        header.setPosition(250, 120);

        textHeaders.push_back(header);
    }

    startButtonHovered = false;
    isMenu = true;
    isBack = false;
}

void Menu::drawMenu(sf::RenderWindow& windowTemp) {
    isMenu = true;
    isBack = false;

    updateButtonColors();
    windowTemp.draw(textHeaders[0]);
    for (const auto& button : buttons) {
        if (&button != &buttons[backButton] && &button != &buttons[fodderButton]) {
            windowTemp.draw(button);
        }
    }
}

void Menu::drawHelp(sf::RenderWindow& windowTemp) {
    isMenu = false;
    isBack = true;

    updateButtonColors();
    windowTemp.draw(textHeaders[1]);
    windowTemp.draw(buttons[backButton]);
}

void Menu::drawScoreboard(sf::RenderWindow& windowTemp) {
    isMenu = false;
    isBack = true;

    updateButtonColors();
    windowTemp.draw(textHeaders[2]);
    windowTemp.draw(buttons[backButton]);
}

void Menu::drawSettings(sf::RenderWindow& windowTemp) {
    isMenu = false;
    isBack = true;

    updateButtonColors();
    windowTemp.draw(textHeaders[3]);
    windowTemp.draw(buttons[backButton]);
    windowTemp.draw(buttons[fodderButton]);
}

int Menu::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) 
        {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (isMenu == true && isBack == false) 
            {
                for (size_t i = 0; i < buttons.size(); ++i) {
                    if (buttons[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        return static_cast<int>(i);
                    }
                }
            }

            if (isMenu == false && isBack == true) 
            {
                for (size_t i = backButton; i < buttons.size(); ++i) 
                {
                    if (buttons[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) 
                    {
                        return static_cast<int>(i);
                    }
                }
            }
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
        {
            return static_cast<int>(20);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            return static_cast<int>(21);
        }
    }

    return -1;
}

void Menu::updateButtonColors()
{
    for (int i = 0; i < buttons.size(); i++) {

        sf::FloatRect startButtonBounds = buttons[i].getGlobalBounds();
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        startButtonHovered = startButtonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        buttons[i].setFillColor(startButtonHovered ? sf::Color::Cyan : sf::Color::White);
    }
}

void Menu::loadDifficulty(int a)
{
    fodderSetting = a;
}

void Menu::createButtons()
{
    buttons.clear();

    std::vector<std::string> buttonLabels = { "Continue", "New Game", "Help", "Scoreboard", "Settings", "EXIT GAME", "Back to Menu", "Fodder Difficulty: " + std::to_string(fodderSetting) };

    for (size_t i = 0; i < buttonLabels.size(); ++i) {
        sf::Text button;
        button.setFont(font);
        button.setString(buttonLabels[i]);
        button.setCharacterSize(20);
        button.setPosition(250, 200 + i * 50);

        buttons.push_back(button);
    }

    buttons[backButton].setPosition(250, 200);
    buttons[fodderButton].setPosition(250, 250);
}