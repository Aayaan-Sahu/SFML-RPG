#include "../../include/States/GameState.hpp"

#include <iostream>

/* Constructor / Destructor */
GameState::GameState(sf::RenderWindow* window) : State(window) {}

GameState::~GameState() {}

/* Functions */
void GameState::endState() {
	std::cout << "Ending game state!\n";
}

void GameState::updateKeybinds(const float& deltaTime) {
	// Defined in State class
	this->checkForQuit();
}

void GameState::update(const float& deltaTime) {
	this->updateKeybinds(deltaTime);

	this->player.update(deltaTime);
}

void GameState::render(sf::RenderTarget* target) {
	this->player.render(target);
}
