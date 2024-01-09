#include "Menu.h"

Menu::Menu(sf::RenderWindow& window) : window(window) {

    if (!font.loadFromFile("arial.ttf")) { std::cout << "Font Error" << std::endl; }

    std::vector<std::string> buttonLabels = { "Continue", "New Game", "Help", "Scoreboard", "Settings", "EXIT GAME", "Back to Menu"};

    for (size_t i = 0; i < buttonLabels.size(); ++i) {
        sf::Text button;
        button.setFont(font);
        button.setString(buttonLabels[i]);
        button.setCharacterSize(20);
        button.setPosition(250, 200 + i * 50);

        buttons.push_back(button);
    }

    std::vector<std::string> headerLabels = { "Main Menu", "Help Title", "Scoreboard Title", "Settings Title"};

    for (size_t i = 0; i < headerLabels.size(); ++i) {
        sf::Text header;
        header.setFont(font);
        header.setString(headerLabels[i]);
        header.setCharacterSize(40);
        header.setPosition(250, 120);

        textHeaders.push_back(header);
    }

    buttons[backButton].setPosition(250, 200);

    startButtonHovered = false;
    isMenu = true;
    isBack = false;
}

void Menu::drawMenu(sf::RenderWindow& window) {
    isMenu = true;
    isBack = false;

    updateButtonColors();
    window.draw(textHeaders[0]);
    for (const auto& button : buttons) {
        if (&button != &buttons[backButton]) {
            window.draw(button);
        }
    }
}

void Menu::drawHelp(sf::RenderWindow& window) {
    isMenu = false;
    isBack = true;

    updateButtonColors();
    window.draw(textHeaders[1]);
    window.draw(buttons[backButton]);
}

void Menu::drawScoreboard(sf::RenderWindow& window) {
    isMenu = false;
    isBack = true;

    updateButtonColors();
    window.draw(textHeaders[2]);
    window.draw(buttons[backButton]);
}

void Menu::drawSettings(sf::RenderWindow& window) {
    isMenu = false;
    isBack = true;

    updateButtonColors();
    window.draw(textHeaders[3]);
    window.draw(buttons[backButton]);
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            return static_cast<int>(10);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
        {
            return static_cast<int>(7);
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
