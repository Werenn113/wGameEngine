//
// Created by b.marchand on 05/11/2025.
//

#ifndef WGAMEENGINE_MENUSTATE_H
#define WGAMEENGINE_MENUSTATE_H
#include "State.h"
#include "../Utils/Button.h"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"


class MenuState : public State{
public:
    MenuState(sf::RenderWindow &window);
    ~MenuState() override;

    State* handleEvents(const std::optional<sf::Event> &event) override;
    void update(const sf::Time &deltaTime) override;
    void render() override;

private:
    sf::Font m_font;
    sf::Text m_title;
    std::vector<std::unique_ptr<Button>> m_buttons;

    State* m_nextState;
};


#endif //WGAMEENGINE_MENUSTATE_H