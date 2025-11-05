//
// Created by b.marchand on 05/11/2025.
//

#ifndef WGAMEENGINE_LEVEL_1_H
#define WGAMEENGINE_LEVEL_1_H
#include "State.h"


class Level1State : public State {
public:
    Level1State();
    ~Level1State() override;

    State* handleEvents(const std::optional<sf::Event> &event) override;
    void update() override;
    void render(sf::RenderWindow &window) override;
};


#endif //WGAMEENGINE_LEVEL_1_H