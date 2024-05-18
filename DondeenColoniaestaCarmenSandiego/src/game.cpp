#include "game.h"
#include <SFML/Graphics.hpp>

Game::Game() : distanceToCarmen(100.0f) {}

void Game::start() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "¿Dónde en Colonia está Carmen Sandiego?");
    sf::RectangleShape distanceBar(sf::Vector2f(distanceToCarmen, 20));
    distanceBar.setFillColor(sf::Color::Red);
    distanceBar.setPosition(10, 10);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(distanceBar);
        window.display();
    }
}

void Game::updateDistanceBar(float distance) {
    distanceToCarmen = distance;
}
