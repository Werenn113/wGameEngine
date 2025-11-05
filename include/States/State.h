//
// Created by b.marchand on 05/11/2025.
//

#ifndef WGAMEENGINE_STATE_H
#define WGAMEENGINE_STATE_H

#include <string>
#include "SFML/Graphics/RenderWindow.hpp"

class State {
protected:
    std::string m_stateName;

public:
    State();
    explicit State(const std::string &name);
    virtual ~State() = default;

    virtual State* handleEvents(const std::optional<sf::Event> &event) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow &window) = 0;
};


#endif //WGAMEENGINE_STATE_H