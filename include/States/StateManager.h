//
// Created by b.marchand on 05/11/2025.
//

#ifndef WGAMEENGINE_STATEMANAGER_H
#define WGAMEENGINE_STATEMANAGER_H

#include <stack>
#include "State.h"
#include "SFML/Graphics/RenderWindow.hpp"

class StateManager {
private:
    std::stack<State*> m_stateStack;

public:
    StateManager(State *state);
    ~StateManager();

    void pushState(State *state);
    void popState();
    void changeState();

    void handleEvents(const std::optional<sf::Event> &event);
    void update();
    void render(sf::RenderWindow &window);
};


#endif //WGAMEENGINE_STATEMANAGER_H