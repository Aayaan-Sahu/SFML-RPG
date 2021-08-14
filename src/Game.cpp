#include "../include/Game.hpp"

#include "../include/Parser.hpp"

#include "../include/States/GameState.hpp"
#include "../include/States/MainMenuState.hpp"

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
	Parser parser("config/WindowProperties.conf");
	this->TITLE = parser["TITLE"];
	this->WIDTH = std::stoi(parser["WIDTH"]);
	this->HEIGHT = std::stoi(parser["HEIGHT"]);
	this->FRAME_RATE_LIMIT = std::stoi(parser["FRAME_RATE_LIMIT"]);
	this->VERTICAL_SYNC_ENABLED = (parser["VERTICAL_SYNC_ENABLED"] == "1") ? true : false;
}

void Game::initKeys() {
	// Add keys with a string to reference them by
	std::ifstream fin( "config/SupportedKeys.conf" );
	if (fin.is_open()) {
		std::string key = "";
		int keyValue = 0;
		while (fin >> key >> keyValue) {
			this->supportedKeys[key] = keyValue;
		}
	}
	fin.close();
}

void Game::initStates() {
	this->states.push(new MainMenuState(this->WINDOW, &this->supportedKeys));
}

/* Constructor / Destructor */
Game::Game() {
	// Initialize variables before initializing window
	this->initVariables();

	// Initialize window
	this->initWindow();

	// Initialize keybinds
	this->initKeys();

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
void Game::endApplication() {
	std::cout << "Ending Application!\n";
}

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
	} else {
		// Application end
		this->endApplication();
		this->WINDOW->close();
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
