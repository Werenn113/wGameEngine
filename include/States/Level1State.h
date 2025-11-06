//
// Created by b.marchand on 05/11/2025.
//

#ifndef WGAMEENGINE_LEVEL_1_H
#define WGAMEENGINE_LEVEL_1_H
#include "State.h"
#include "../Entities/Player.h"


class Level1State : public State {
public:
    Level1State(sf::RenderWindow &window);
    ~Level1State() override;

    State* handleEvents(const std::optional<sf::Event> &event) override;
    void update(const sf::Time &deltaTime) override;
    void render() override;

private:
    Player m_player;
};


#endif //WGAMEENGINE_LEVEL_1_H