//
// Created by b.marchand on 05/11/2025.
//

#include "../../include/States/Level1State.h"

#include "SFML/Graphics/CircleShape.hpp"

Level1State::Level1State(sf::RenderWindow &window) : State("Level_1", window) {
}

Level1State::~Level1State() {
}

State* Level1State::handleEvents(const std::optional<sf::Event> &event) {
    if (!event.has_value()) {
        return nullptr;
    }

    if (event->is<sf::Event::KeyPressed>()) {
        if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Up) {
            m_player.jump();
        }
        if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Down) {
            m_player.crouch();
        }
        if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Left) {
            m_player.setDirection(sf::Vector2f(-1, 0));
        }
        if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Right) {
            m_player.setDirection(sf::Vector2f(1, 0));
        }
    }

    if (event->is<sf::Event::KeyReleased>()) {
        if (event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Left or event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Right) {
            m_player.setDirection(sf::Vector2f(0, 0));
        }
    }

    return nullptr;
}

void Level1State::update(const sf::Time &deltaTime) {
    m_player.update(deltaTime);
}

void Level1State::render() {
    m_window.clear(sf::Color::White);

    m_player.render(m_window);
}