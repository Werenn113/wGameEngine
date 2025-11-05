//
// Created by b.marchand on 05/11/2025.
//

#ifndef WGAMEENGINE_GAME_H
#define WGAMEENGINE_GAME_H

#include <SFML/Graphics.hpp>
#include "../States/StateManager.h"

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    void handleEvents();

    sf::RenderWindow m_window;
    sf::Clock m_clock;
    bool m_isRunning;
    StateManager m_stateManager;
    static constexpr unsigned int FPS_LIMIT = 60;
};


#endif //WGAMEENGINE_GAME_H