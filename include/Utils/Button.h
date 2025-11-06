//
// Created by b.marchand on 06/11/2025.
//

#ifndef WGAMEENGINE_BUTTON_H
#define WGAMEENGINE_BUTTON_H
#include <functional>
#include <string>

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"


class Button {
public:
    Button(const std::string &text, const sf::Font &font, const sf::Vector2f &position, const sf::Vector2f &size, sf::RenderWindow &window);

    void setPosition();
    void setCallback(std::function<void()> callback);

    void handleEvents(const sf::Event &event);
    void update();
    void render();

    bool isHovered() const { return m_isHovered; }
    bool isPressed() const { return m_isPressed; }

private:
    sf::RenderWindow &m_window;

    sf::RectangleShape m_shape;
    sf::Text m_text;
    sf::Font m_font;
    std::function<void()> m_callback;

    bool m_isHovered;
    bool m_isPressed;

    sf::Color m_normalColor;
    sf::Color m_hoverColor;
    sf::Color m_pressedColor;
};


#endif //WGAMEENGINE_BUTTON_H