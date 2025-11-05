//
// Created by b.marchand on 05/11/2025.
//

#include "../../include/States/MenuState.h"

#include "../../include/States/Level1State.h"
#include "SFML/Graphics/CircleShape.hpp"


MenuState::MenuState() : State("Menu") {
}

MenuState::~MenuState() {
}

State* MenuState::handleEvents(const std::optional<sf::Event> &event) {
    if (!event.has_value()) {
        return nullptr;
    }

    if (event->is<sf::Event::KeyPressed>()) {
        const auto &keyEvent = *event->getIf<sf::Event::KeyPressed>();
        if (keyEvent.code == sf::Keyboard::Key::Enter) {
            return new Level1State();
        }
    }
    return nullptr;
}

void MenuState::update() {
    // TODO: Implement update logic
}

void MenuState::render(sf::RenderWindow &window) {
    window.clear(sf::Color::Black);

    // Créer un cercle de debug
    sf::CircleShape debugCircle(50.f); // Rayon de 50 pixels
    debugCircle.setFillColor(sf::Color::Red);
    debugCircle.setPosition({100.f, 100.f}); // Position x=100, y=100

    window.draw(debugCircle);
    window.display();
}