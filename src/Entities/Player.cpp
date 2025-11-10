//
// Created by b.marchand on 06/11/2025.
//

#include "../../include/Entities/Player.h"

#include <cmath>
#include <iostream>
#include <ostream>

#include "SFML/Graphics/RectangleShape.hpp"

Player::Player() : m_position(100, 100), m_speed(0, 0), m_acceleration(0, 0), m_isGrounded(false) {}

Player::~Player() {}

sf::Vector2f Player::getPosition() {
    return m_position;
}

void Player::setDirection(sf::Vector2f newDirection) {
    m_direction = newDirection;
}


void Player::handleEvents() {

}

void Player::update(const sf::Time &deltaTime) {
    //clampToBounds();
    gravity();
    move(deltaTime);
}

void Player::render(sf::RenderWindow &window) {
    m_playerShape.setSize(sf::Vector2f(40, 75));
    m_playerShape.setFillColor(sf::Color::Red);
    m_playerShape.setPosition(m_position);

    window.draw(m_playerShape);
    window.display();
}

void Player::move(const sf::Time &deltaTime) {
    const float ACCELERATION = 105.f;
    const float FRICTION = 8.0f;
    const float MAX_SPEED = 756.f;

    if (m_direction != sf::Vector2f(0.f, 0.f))
        m_acceleration.x = m_direction.x * ACCELERATION;
    else
        m_acceleration.x = -m_speed.x * FRICTION;

    if (std::abs(m_speed.x) > MAX_SPEED) {
        m_speed.x = (m_speed.x > 0) ? MAX_SPEED : -MAX_SPEED;
    }
    m_speed += m_acceleration * deltaTime.asSeconds();
    m_position += m_speed * deltaTime.asSeconds();

    //std::cout << "(" << m_acceleration.x << ", " << m_acceleration.y << ")";
    //std::cout << "(" << m_speed.x << ", " << m_speed.y << ")";
    //std::cout << "(" << m_position.x << ", " << m_position.y << ")" << std::endl;
}

void Player::gravity() {
    const sf::FloatRect terrainBounds(sf::Vector2f(0, 0), sf::Vector2f(800, 600));
    const sf::Vector2f playerSize = m_playerShape.getSize();

    if (!(m_position.y + playerSize.y > terrainBounds.position.y + terrainBounds.size.y)) {
        m_acceleration.y = 412.02;
        m_isGrounded = false;
    } else {
        m_position.y = terrainBounds.position.y + terrainBounds.size.y - playerSize.y;
        m_acceleration.y = 0;
        m_speed.y = 0;
        m_isGrounded = true;
    }
}


void Player::clampToBounds() {
    const sf::FloatRect terrainBounds(sf::Vector2f(0, 0), sf::Vector2f(800, 600));
    const sf::Vector2f playerSize = m_playerShape.getSize();

    if (m_position.x < terrainBounds.position.x) {
        m_position.x = terrainBounds.position.x;
        m_acceleration.x = 0;
        m_speed.x = 0;
    } else if (m_position.x + playerSize.x > terrainBounds.position.x + terrainBounds.size.x) {
        m_position.x = terrainBounds.position.x + terrainBounds.size.x - playerSize.x;
        m_acceleration.x = 0;
        m_speed.x = 0;
    }

    if (m_position.y < terrainBounds.position.y) {
        m_position.y = terrainBounds.position.y;
        m_acceleration.y = 0;
        m_speed.y = 0;
    } else if (m_position.y + playerSize.y > terrainBounds.position.y + terrainBounds.size.y) {
        m_position.y = terrainBounds.position.y + terrainBounds.size.y - playerSize.y;
        m_acceleration.y = 0;
        m_speed.y = 0;
    }

    m_playerShape.setPosition(m_position);
}

void Player::jump() {
    if (m_isGrounded) {
        m_speed.y = -400;
    }
}

void Player::crouch() {
    // TODO
}



