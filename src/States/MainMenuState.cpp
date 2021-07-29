#include "../../include/States/MainMenuState.hpp"

#include <fstream>
#include <iostream>

/* Initializer Functions */
void MainMenuState::initKeybinds() {
	// Give each of the supported keys a function (how they will be used in the current state)
	std::ifstream fin( "config/MainMenuStateKeybinds.conf" );
	if (fin.is_open()) {
		std::string key = "";
		std::string keyValue = "";
		while (fin >> key >> keyValue) {
			this->keybinds[key] = this->supportedKeys->at(keyValue);
		}
	}
	fin.close();
}

/* Constructor / Destructor */
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys) {
	this->initKeybinds();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState() {}

/* Functions */
void MainMenuState::endState() {
	std::cout << "Ending main menu state!\n";
}

void MainMenuState::updateInput(const float& deltaTime) {
	// Defined in State class
	this->checkForQuit();
}

void MainMenuState::update(const float& deltaTime) {
	this->updateInput(deltaTime);
}

void MainMenuState::render(sf::RenderTarget* target) {
	// Make sure target is not nullptr
	if (!target) {
		target = this->window;
	}

	target->draw(this->background);
}
