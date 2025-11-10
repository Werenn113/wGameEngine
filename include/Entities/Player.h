//
// Created by b.marchand on 06/11/2025.
//

#ifndef WGAMEENGINE_PLAYER_H
#define WGAMEENGINE_PLAYER_H
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"


class Player {
public:
    Player();
    ~Player();

    sf::Vector2f getPosition();
    void setDirection(sf::Vector2f newDirection);

    void move(const sf::Time &deltaTime);
    void jump();
    void crouch();

    void clampToBounds();
    void gravity();

    void handleEvents();
    void update(const sf::Time &deltaTime);
    void render(sf::RenderWindow &window);


private:
    sf::RectangleShape m_playerShape;

    sf::Vector2f m_direction;
    sf::Vector2f m_position;
    sf::Vector2f m_speed;
    sf::Vector2f m_acceleration;

    bool m_isGrounded;
};


#endif //WGAMEENGINE_PLAYER_H