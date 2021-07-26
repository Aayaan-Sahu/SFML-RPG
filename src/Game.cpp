#include "../include/Game.hpp"

#include "../include/States/GameState.hpp"

#include <fstream>
#include <iostream>

/* Initializer Functions */
void Game::initWindow() {
	this->WINDOW = new sf::RenderWindow(
		sf::VideoMode(this->WIDTH, this->HEIGHT),
		this->TITLE,
		sf::Style::Close | sf::Style::Titlebar
	);

	this->WINDOW->setFramerateLimit(this->FRAME_RATE_LIMIT);
	this->WINDOW->setVerticalSyncEnabled(this->VERTICAL_SYNC_ENABLED);
}

void Game::initVariables() {
	/* Read Window Properties */
	std::ifstream fin( "Config/WindowProperties.conf" );

	std::string title;
	std::string stringWidth;
	std::string stringHeight;
	std::string stringFrameRateLimit;
	std::string stringVerticalSyncEnabled;

	// Get each of the lines into its own variable
	std::getline(fin, title);
	std::getline(fin, stringWidth);
	std::getline(fin, stringHeight);
	std::getline(fin, stringFrameRateLimit);
	std::getline(fin, stringVerticalSyncEnabled);

	// Trim each of the lines to only include the values
	this->TITLE = title.substr(title.find("=") + 1);
	stringWidth = stringWidth.substr(stringWidth.find("=") + 1);
	stringHeight = stringHeight.substr(stringHeight.find("=") + 1);
	stringFrameRateLimit = stringFrameRateLimit.substr(stringFrameRateLimit.find("=") + 1);
	stringVerticalSyncEnabled = stringVerticalSyncEnabled.substr(stringVerticalSyncEnabled.find("=") + 1);

	// Perform necessary conversions from string to correct data type
	this->WIDTH = std::stoi(stringWidth);
	this->HEIGHT = std::stoi(stringHeight);
	this->FRAME_RATE_LIMIT = std::stoi(stringFrameRateLimit);
	this->VERTICAL_SYNC_ENABLED = (stringVerticalSyncEnabled == "1") ? true : false;

	fin.close();
}

void Game::initStates() {
	this->states.push(new GameState(this->WINDOW));
}

/* Constructor / Destructor */
Game::Game() {
	// Initialize variables before initializing window
	this->initVariables();

	// Initialize window
	this->initWindow();

	// Initialize states
	this->initStates();
}

Game::~Game() {
	/* Free up memory */
	delete this->WINDOW;

	while (this->states.empty() == false) {
		// First delete the contents of the states
		delete this->states.top();
		// Then pop the actual state
		this->states.pop();
	}
}

/* Functions */
void Game::updateDeltaTime() {
	// Updates delta time with the time it takes from one frame to the next
	this->deltaTime = this->deltaTimeClock.restart().asSeconds();
}

void Game::updateSFMLEvents() {
	// Go through all the events that are happening
	// within the window
	while (this->WINDOW->pollEvent(this->event)) {
		// Check for the window closed
		if (this->event.type == sf::Event::Closed) {
			this->WINDOW->close();
		}
	}
}

void Game::update() {
	this->updateSFMLEvents();

	// Call the update function for the top state in the states stack
	if (this->states.empty() == false) {
		this->states.top()->update(this->deltaTime);

		// Deleting a state
		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
}

void Game::render() {
	// Clear the screen with a color
	this->WINDOW->clear();

	// Call the render function for the top state in the states stack
	if (this->states.empty() == false) {
		this->states.top()->render(this->WINDOW);
	}

	// Render everything on the back buffer
	this->WINDOW->display();
}

void Game::run() {
	/* Game loop */
	while (this->WINDOW->isOpen()) {
		this->updateDeltaTime();
		this->update();
		this->render();
	}
}
