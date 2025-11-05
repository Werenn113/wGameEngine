//
// Created by b.marchand on 05/11/2025.
//

#include "../../include/States/StateManager.h"

StateManager::StateManager(State *state) {
    if (state != nullptr) {
        m_stateStack.push(state);
    }
}

StateManager::~StateManager() {
    while (!m_stateStack.empty()) {
        delete m_stateStack.top();
        m_stateStack.pop();
    }
}

void StateManager::pushState(State *state) {
    if (state != nullptr) {
        m_stateStack.push(state);
    }
}


void StateManager::handleEvents(const std::optional<sf::Event> &event) {
    State *newState = nullptr;

    if (!m_stateStack.empty()) {
        newState = m_stateStack.top()->handleEvents(event);

        if (newState) {
            pushState(newState);
        }
    }
}

void StateManager::update() {
    if (!m_stateStack.empty()) {
        m_stateStack.top()->update();
    }
}

void StateManager::render(sf::RenderWindow &window) {
    if (!m_stateStack.empty()) {
        m_stateStack.top()->render(window);
    }
}
