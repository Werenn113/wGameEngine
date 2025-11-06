//
// Created by b.marchand on 05/11/2025.
//

#ifndef WGAMEENGINE_STATE_H
#define WGAMEENGINE_STATE_H

#include <string>
#include "SFML/Graphics/RenderWindow.hpp"

class State {
public:
    State();
    explicit State(const std::string &name, sf::RenderWindow &window);
    virtual ~State() = default;

    virtual State* handleEvents(const std::optional<sf::Event> &event) = 0;
    virtual void update(const sf::Time &deltaTime) = 0;
    virtual void render() = 0;

protected:
    std::string m_stateName;
    sf::RenderWindow &m_window;
};


#endif //WGAMEENGINE_STATE_H