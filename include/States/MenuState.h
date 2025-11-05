//
// Created by b.marchand on 05/11/2025.
//

#ifndef WGAMEENGINE_MENUSTATE_H
#define WGAMEENGINE_MENUSTATE_H
#include "State.h"


class MenuState : public State{
public:
    MenuState();
    ~MenuState() override;

    State* handleEvents(const std::optional<sf::Event> &event) override;
    void update() override;
    void render(sf::RenderWindow &window) override;
};


#endif //WGAMEENGINE_MENUSTATE_H