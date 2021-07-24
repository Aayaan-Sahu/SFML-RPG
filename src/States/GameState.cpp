#include "../../include/States/GameState.hpp"

/* Construct / Destructor */
GameState::GameState(sf::RenderWindow* window) : State(window) {}

GameState::~GameState() {}

/* Functions */
void GameState::endState() {}

void GameState::update(const float deltaTime) {}

void GameState::render(sf::RenderTarget* target) {}
