#include "../include/State.hpp"

/* Constructor / Destructor */
State::State(sf::RenderWindow* window) {
	this->window = window;
	this->quit = false;
}

State::~State() {}

const bool& State::getQuit() const {
	return this->quit;
}

void State::checkForQuit() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->quit = true;
	}
}
