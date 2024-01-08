#include "Menu.h"

Menu::Menu(sf::RenderWindow& window) : window(window) {

    if (!font.loadFromFile("arial.ttf")) { std::cout << "Font Error" << std::endl; }

    titleText.setFont(font);
    titleText.setFillColor(sf::Color::White);
    titleText.setString("Game Menu");
    titleText.setCharacterSize(30);
    titleText.setPosition(200, 100);

    std::vector<std::string> buttonLabels = { "Continue", "New Game", "Help", "Scoreboard" };

    for (size_t i = 0; i < buttonLabels.size(); ++i) {
        sf::Text button;
        button.setFont(font);
        button.setString(buttonLabels[i]);
        button.setCharacterSize(20);
        button.setPosition(250, 200 + i * 50);

        buttons.push_back(button);
    }

    startButtonHovered = false;
}

void Menu::draw(sf::RenderWindow& window) {
    updateButtonColors();
    window.draw(titleText);
    for (const auto& button : buttons) {
        window.draw(button);
    }
}

int Menu::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            // Check if a button is clicked
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            for (size_t i = 0; i < buttons.size(); ++i) {
                if (buttons[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    return static_cast<int>(i);
                }
            }
        }
    }

    return -1; // No button clicked
}

void Menu::updateButtonColors()
{
    for (int i = 0; i < 4; i++) {

        sf::FloatRect startButtonBounds = buttons[i].getGlobalBounds();
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        startButtonHovered = startButtonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        buttons[i].setFillColor(startButtonHovered ? sf::Color::Cyan : sf::Color::White);
    }
}

bool Menu::isStartButtonClicked() {
    // Implement this function to check if the start button is clicked
    // For simplicity, let's assume the start button is at (300, 200) with a width of 200 and height of 50
    sf::FloatRect startButtonBounds = startText.getGlobalBounds();
    sf::Vector2i mousePos = sf::Mouse::getPosition(menuWindow);

    return startButtonBounds.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}