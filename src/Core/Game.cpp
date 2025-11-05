//
// Created by b.marchand on 05/11/2025.
//

#include "../../include/Core/Game.h"
#include "../../include/States/MenuState.h"


Game::Game()
    : m_window(sf::VideoMode({800, 600}), "wGameEngine")
    , m_isRunning(true)
    , m_stateManager(StateManager(new MenuState))
{
    m_window.setFramerateLimit(FPS_LIMIT);
}

Game::~Game() {
    if (m_window.isOpen()) {
        m_window.close();
    }
}

void Game::run() {
    while (m_isRunning && m_window.isOpen()) {
        float dt = m_clock.restart().asSeconds();

        handleEvents();
        m_stateManager.update();
        m_stateManager.render(m_window);
    }
}

void Game::handleEvents() {
    while (const std::optional<sf::Event> event = m_window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            m_isRunning = false;
            m_window.close();
        }

        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->code == sf::Keyboard::Key::Escape) {
                m_isRunning = false;
                m_window.close();
            }
        }
        m_stateManager.handleEvents(event);
    }
}


