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

    void updateCamera();

private:
    Player m_player;
    sf::View m_camera;
    sf::RectangleShape m_testObject;

    static constexpr float LEVEL_WIDTH = 3200.f;
    static constexpr float LEVEL_HEIGHT = 600.f;
    static constexpr float WINDOW_WIDTH = 800.f;
    static constexpr float WINDOW_HEIGHT = 600.f;

    static constexpr float PLAYER_SCREEN_POSITION = 0.33f;
};


#endif //WGAMEENGINE_LEVEL_1_H