#include "../../include/States/GameState.hpp"

#include <iostream>

/* Initializer Functions */
void GameState::initKeybinds() {
	// Give each of the supported keys a function (how they will be used in the current state)
	this->keybinds["CLOSE"] = this->supportedKeys->at("ESC");
	this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
	this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
	this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
	this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
}

/* Constructor / Destructor */
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys) {
	this->initKeybinds();
}

GameState::~GameState() {}

/* Functions */
void GameState::endState() {
	std::cout << "Ending game state!\n";
}

void GameState::updateInput(const float& deltaTime) {
	// Defined in State class
	this->checkForQuit();

	// Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))) {
		this->player.move(deltaTime, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))) {
		this->player.move(deltaTime, 1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
		this->player.move(deltaTime, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))) {
		this->player.move(deltaTime, 0.f, 1.f);
	}
}

void GameState::update(const float& deltaTime) {
	this->updateInput(deltaTime);

	this->player.update(deltaTime);
}

void GameState::render(sf::RenderTarget* target) {
	// Make sure target is not nullptr
	if (!target) {
		target = this->window;
	}
	this->player.render(target);
}
