//
// Created by b.marchand on 06/11/2025.
//

#include "../../include/Utils/Button.h"

#include "SFML/Graphics/Text.hpp"

Button::Button(const std::string &text, const sf::Font &font, const sf::Vector2f &position, const sf::Vector2f &size, sf::RenderWindow &window)
    : m_window(window)
    , m_text(m_font)
    , m_isHovered(false)
    , m_isPressed(false)
    , m_normalColor(sf::Color(70, 70, 70))
    , m_hoverColor(sf::Color(100, 100, 100))
    , m_pressedColor(sf::Color(50, 50, 50)) {
    m_shape.setSize(size);
    m_shape.setPosition(position);
    m_shape.setFillColor(m_normalColor);
    m_shape.setOutlineThickness(2.f);
    m_shape.setOutlineColor(sf::Color::White);

    m_text.setFont(font);
    m_text.setString(text);
    m_text.setCharacterSize(24);
    m_text.setFillColor(sf::Color::White);

    setPosition();
}

void Button::setPosition() {
    sf::FloatRect textBounds = m_text.getLocalBounds();
    sf::Vector2f buttonPos = m_shape.getPosition();
    sf::Vector2f buttonSize = m_shape.getSize();

    m_text.setOrigin({textBounds.position.x + textBounds.size.x / 2.f, textBounds.position.y + textBounds.size.y / 2.f});
    m_text.setPosition({buttonPos.x + buttonSize.x / 2.f, buttonPos.y + buttonSize.y / 2.f});
}

void Button::setCallback(std::function<void()> callback) {
    m_callback = callback;
}

void Button::handleEvents(const sf::Event &event) {
    if (event.is<sf::Event::MouseButtonPressed>()) {
        const auto &mouseEvent = *event.getIf<sf::Event::MouseButtonPressed>();
        if (mouseEvent.button == sf::Mouse::Button::Left && m_isHovered) {
            m_isPressed = true;
        }
    }

    if (event.is<sf::Event::MouseButtonReleased>()) {
        const auto &mouseEvent = *event.getIf<sf::Event::MouseButtonReleased>();
        if (mouseEvent.button == sf::Mouse::Button::Left) {
            if (m_isPressed && m_isHovered && m_callback) {
                m_callback();
            }
            m_isPressed = false;
        }
    }
}

void Button::update() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    m_isHovered = m_shape.getGlobalBounds().contains(mousePosF);

    if (m_isPressed) {
        m_shape.setFillColor(m_pressedColor);
    } else if (m_isHovered) {
        m_shape.setFillColor(m_hoverColor);
    } else {
        m_shape.setFillColor(m_normalColor);
    }
}

void Button::render() {
    m_window.draw(m_shape);
    m_window.draw(m_text);
}



