//
// Created by b.marchand on 05/11/2025.
//

#include "../../include/States/Level1State.h"

#include "SFML/Graphics/CircleShape.hpp"

Level1State::Level1State() : State("Level_1") {
}

Level1State::~Level1State() {
}

State* Level1State::handleEvents(const std::optional<sf::Event> &event) {
    return nullptr;
}

void Level1State::update() {
    // TODO: Implement update logic
}

void Level1State::render(sf::RenderWindow &window) {
    window.clear(sf::Color::Black);

    // Créer un cercle de debug
    sf::CircleShape debugCircle(50.f); // Rayon de 50 pixels
    debugCircle.setFillColor(sf::Color::Green);
    debugCircle.setPosition({100.f, 100.f}); // Position x=100, y=100

    window.draw(debugCircle);
    window.display();
}