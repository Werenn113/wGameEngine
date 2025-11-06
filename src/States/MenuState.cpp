//
// Created by b.marchand on 05/11/2025.
//

#include "../../include/States/MenuState.h"
#include <iostream>
#include "../../include/States/Level1State.h"
#include "SFML/Graphics/CircleShape.hpp"


MenuState::MenuState(sf::RenderWindow &window) : State("Menu", window), m_title(m_font), m_nextState(nullptr) {
    if (!m_font.openFromFile("../../assets/fonts/arial.ttf")) {
        std::cerr << "Erreur : impossible de charger la police\n";
    }

    m_title.setFont(m_font);
    m_title.setString("Bienvenue dans le menu !");
    m_title.setCharacterSize(40);
    m_title.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = m_title.getLocalBounds();
    m_title.setOrigin({textBounds.position.x + textBounds.size.x / 2.f, 0.f});

    auto playButton = std::make_unique<Button>("Jouer", m_font, sf::Vector2f(300.f, 200.f), sf::Vector2f(200.f, 50.f), m_window);
    playButton->setCallback([this]() {
        m_nextState = new Level1State(m_window);
    });
    m_buttons.push_back(std::move(playButton));

    auto optionsButton = std::make_unique<Button>("Options", m_font, sf::Vector2f(300.f, 270.f), sf::Vector2f(200.f, 50.f), m_window);
    optionsButton->setCallback([this]() {
        std::cout << "Options cliqué\n";
    });
    m_buttons.push_back(std::move(optionsButton));

    auto quitButton = std::make_unique<Button>("Quitter", m_font, sf::Vector2f(300.f, 340.f), sf::Vector2f(200.f, 50.f), m_window);
    quitButton->setCallback([this]() {
        m_window.close();
    });
    m_buttons.push_back(std::move(quitButton));
}

MenuState::~MenuState() {
}

State* MenuState::handleEvents(const std::optional<sf::Event> &event) {
    if (!event.has_value()) {
        return nullptr;
    }

    for (const std::unique_ptr<Button> &button : m_buttons) {
        button->handleEvents(event.value());
    }

    if (event->is<sf::Event::KeyPressed>()) {
        if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Enter) {
            return new Level1State(m_window);
        }
    }

    if (m_nextState) {
        State* state = m_nextState;
        m_nextState = nullptr;
        return state;
    }

    return nullptr;
}

void MenuState::update(const sf::Time &deltaTime) {
    if (m_window.isOpen()) {
        for (const std::unique_ptr<Button> &button : m_buttons) {
            button->update();
        }
    }
}

void MenuState::render() {
    m_window.clear(sf::Color::Black);

    const sf::Vector2u windowSize = m_window.getSize();
    m_title.setPosition({windowSize.x / 2.f, 100.f});
    m_window.draw(m_title);

    for (const std::unique_ptr<Button> &button : m_buttons) {
        button->render();
    }


    m_window.display();
}